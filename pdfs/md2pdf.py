from markdown_pdf import MarkdownPdf, Section
import os


def get_content(file_name):
    with open(file_name, "r", encoding="UTF-8") as file:
        content = file.read()
    return content


pdf = MarkdownPdf(toc_level=2)
abspath = os.path.abspath(__file__)
os.chdir(os.path.dirname(abspath))
os.chdir("../")
pdf.add_section(Section(get_content("README.md")))
os.chdir("lessons")

md_lessons = sorted([int(file_name[:-3]) for file_name in os.listdir() if file_name[-3:] == ".md"])
for lesson_id in md_lessons:
    full_name = "{}.md".format(lesson_id)
    pdf.add_section(Section(get_content(full_name)))

pdf.meta["title"] = "Структуры данных в КЛШ-24"
pdf.meta["author"] = "Шестаков Вячеслав"
pdf.save("../pdfs/lessons.pdf")
