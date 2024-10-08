import os
import shutil
from md2tex import MdParser, TexWriter


def convert_file(src_file, dist_file, print_footer=True):
    parser = MdParser(src_file)
    parser.parse()
    tw = TexWriter(parser.parsed)
    tw.write(dist_file, print_footer)


abspath = os.path.abspath(__file__)
os.chdir(os.path.dirname(abspath))
os.chdir("../")
convert_file('README.md', 'tex/README.tex', False)
os.chdir("lessons")

lessons_files = os.listdir()
md_files = [file_name for file_name in lessons_files if file_name[-3:] == '.md']
other_files = [file_name for file_name in lessons_files if file_name[-3:] != '.md']

os.chdir("../tex")
for md_file in md_files:
    convert_file('../lessons/' + md_file, 'lessons/' + md_file.replace('.md', '.tex'))
for other_file in other_files:
    shutil.copyfile('../lessons/' + other_file, 'lessons/' + other_file)

with open('main.tex', 'w', encoding='UTF-8') as f:
    f.write(r'''\documentclass[10pt,a4paper]{article}
\usepackage{_services/course}
\usepackage{_services/packages}
\usepackage{_services/style}

\begin{document}
\header

\maketitle
\clearpage
\tableofcontents
\clearpage

\coursefooterinfo{Описание}
\section{\Large Описание}
\include{about}
\newpage

''')
    f.write('\include{README}\n')
    f.write('''\coursefooterinfo{Занятия}
\section{\Large Занятия}
\\newpage

''')

    md_lessons = sorted(int(file_name[:-3]) for file_name in md_files)
    for lesson in md_lessons:
        f.write('\include{{lessons/{}}}\n'.format(lesson))
    f.write('\n\include{final_control}\n')
    f.write('\include{final_control_answers}\n\n')
    f.write('\end{document}\n')

os.system('pdflatex -synctex=1 -interaction=nonstopmode --shell-escape -output-directory="..\\build_tex" main.tex & copy "..\\build_tex\\main.pdf" "..\pdfs\lessons.pdf"')
