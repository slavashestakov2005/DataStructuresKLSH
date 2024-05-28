import enum
import re


def filename_to_link(filename):
    return 'md2tex' + filename.rsplit('/', 1)[-1].rsplit('.', 1)[0]


class MdElements(enum.Enum):
    newline = -1
    text = 0
    h1 = 1
    h2 = 2
    # h3 = 3
    # h4 = 4
    # h5 = 5
    # h6 = 6
    code = 7
    num_list = 8
    mark_list = 9


class MdParser:
    def __init__(self, filename: str):
        self.filename = filename
        self.content = ''
        self.parsed = []
        self.pos = 0
        self.n = 0
    
    def get_pos(self, pos: int):
        if pos < self.n:
            return self.content[pos]
        return '@'
        
    
    def inline_elements(self, text: str):
        # image
        pattern = '\!\[(?P<text>.*?)\]\((?P<file>.*?)\)'
        repl = r'\\includegraphics[scale=0.4]{\g<file>}'
        text = re.sub(pattern, repl, text)
        # inline code
        pattern = '`(?P<code>.*?)`'
        repl = r'\\mintinline{cpp}{\g<code>}'
        text = re.sub(pattern, repl, text)
        # md href
        pattern = '\[(?P<text>.*?)\]\(.*?\/(?P<file>.*?)\.md\)'
        repl = r'\\hyperref[md2tex\g<file>]{\g<text>}'
        text = re.sub(pattern, repl, text)
        # outside href
        pattern = '\[(?P<text>.*?)\]\((?P<url>.*?)\)'
        repl = r'\\href[\g<url>]{\g<text>}'
        text = re.sub(pattern, repl, text)
        return text

    def parse(self):
        with open(self.filename, 'r', encoding='UTF-8') as f:
            self.content = f.read()
        self.pos = 0
        self.n = len(self.content)
        while self.pos < self.n:
            c = self.get_pos(self.pos)
            if c == '#':        # heading
                sharps = 0
                while self.pos < self.n and self.get_pos(self.pos) == '#':
                    sharps += 1
                    self.pos += 1
                if self.get_pos(self.pos) == ' ':
                    self.pos += 1
                if sharps == 1:
                    self.parsed.append((MdElements.h1, self.parse_text('\n')))
                elif sharps == 2:
                    self.parsed.append((MdElements.h2, self.parse_text('\n')))
                else:
                    raise ValueError("Too much #")
                continue
            elif c == '`' and self.get_pos(self.pos + 1) == '`' and self.get_pos(self.pos + 2) == '`':      # code
                self.pos += 3
                lang = self.parse_text('\n', False)
                source = self.parse_text('```\n', False)
                self.parsed.append((MdElements.code, lang, source))
            elif c == '1' and self.get_pos(self.pos + 1) == '.' and self.get_pos(self.pos + 2) == ' ':      # numerated list
                self.parsed.append((MdElements.num_list, self.parse_num_list()))
                continue
            elif c == '-' and self.get_pos(self.pos + 1) == ' ':        # marked list
                self.parsed.append((MdElements.mark_list, self.parse_mark_list()))
                continue
            elif c == '\n':
                self.parsed.append((MdElements.newline, ))
                self.pos += 1
                continue
            else:
                self.parsed.append((MdElements.text, self.parse_text('\n')))
                self.parsed.append((MdElements.newline, ))
                continue

    def parse_text(self, stop: str, inline_elements=True):
        s = ''
        while self.pos < self.n:
            part = ''
            for i in range(len(stop)):
                part += self.get_pos(self.pos + i)
            if part == stop:
                break
            s += self.get_pos(self.pos)
            self.pos += 1
        self.pos += len(stop)
        if inline_elements:
            s = self.inline_elements(s)
        return s
    
    def parse_num_list(self):
        nums = []
        while self.pos < self.n:
            if self.get_pos(self.pos).isdigit() and self.get_pos(self.pos + 1) == '.' and self.get_pos(self.pos + 2) == ' ':
                self.pos += 3
                nums.append(self.parse_text('\n'))
            elif self.get_pos(self.pos).isdigit() and self.get_pos(self.pos + 1).isdigit() and self.get_pos(self.pos + 2) == '.' and self.get_pos(self.pos + 3) == ' ':
                self.pos += 4
                nums.append(self.parse_text('\n'))
            else:
                break
        return nums

    def parse_mark_list(self):
        marks = []
        while self.pos < self.n:
            if self.get_pos(self.pos) == '-' and self.get_pos(self.pos + 1) == ' ':
                self.pos += 2
                marks.append(self.parse_text('\n'))
            else:
                break
        return marks


class TexWriter:
    def __init__(self, parts):
        self.parts = parts
    
    def write(self, filename: str, print_footer=True):
        with open(filename, 'w', encoding='UTF-8') as f:
            label = '\\label{{{}}}\n'.format(filename_to_link(filename))
            for part in self.parts:
                if part[0] == MdElements.newline:
                    f.write('\n')
                elif part[0] == MdElements.text:
                    f.write(part[1])
                elif part[0] == MdElements.h1:
                    if print_footer:
                        f.write('\coursefooterdate{?.06.2024}')
                    f.write('\\head{{\Large {}}}\n'.format(part[1]))
                    f.write(label)
                elif part[0] == MdElements.h2:
                    f.write('\\subhead{{{}}}\n'.format(part[1]))
                elif part[0] == MdElements.num_list:
                    f.write('\\begin{enumerate}\n')
                    for x in part[1]:
                        f.write('    \\item ' + x + '\n')
                    f.write('\\end{enumerate}\n')
                elif part[0] == MdElements.code:
                    f.write('\\begin{{minted}}{{{}}}\n'.format(part[1]))
                    f.write(part[2])
                    f.write('\\end{minted}\n')
                elif part[0] == MdElements.mark_list:
                    f.write('\\begin{itemize}\n')
                    for x in part[1]:
                        f.write('    \\item ' + x + '\n')
                    f.write('\\end{itemize}\n')
                elif part[0] == MdElements.code:
                    f.write('\\begin{{minted}}{{{}}}\n'.format(part[1]))
                    f.write(part[2])
                    f.write('\\end{minted}\n')
