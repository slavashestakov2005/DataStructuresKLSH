В этом файле собрано описание к файлам стилей из данной папки.


# Назначение файлов
Файлов всего три, кажется достаточно терпимо:
- В файле `course.sty` нужно описать метаинформацию о курсе (название, автор и т.д.).
- В файле `packages.sty` содержится список подключаемых $\LaTeX$ библиотек.
- В файле `style.sty` содержится содержательный код, отвечающий за стили, в начале документа нужно обязательно прописать `\header`.

Подключать их нужно ровно в таком порядке, то есть основной файл будет выглядеть так:
```tex
\documentclass[10pt, a5paper]{article}
\usepackage{_services/course}
\usepackage{_services/packages}
\usepackage{_services/style}

\begin{document}
\header

Ла-ла-ла

\end{document}
```


# Файл `course.sty`
В этом файле нужно прописать всё метаинформацию, в формате:
```tex
\def\courseinfoschool{Место проведения курса}
\def\courseinfolongname{Длинное название для курса}
\def\courseinfoshortname{Короткое название для курса}
\def\courseinfoauthor{Автор или авторы}
\def\courseinfoyear{Год}
\def\courseinfoschoolyear{\courseinfoschool\ \courseinfoyear}
\def\courseinfoanswer{Ответы}
% Склейку школы и года можно определить как-то по другому, если хочется
% Также можно писать что-то другое вместо слова "Ответы" в заголовках страниц
```


# Файл `style.sty`
В этом файле собраны разные полезные (мне) и удобные сокращения:
- Задание верхнего колонтитула (переданные аргументы выводятся курсивом через $\bullet$):
```tex
\def\courseooter#1{\renewcommand\mymark{\foreach{\oneout}{\sepout}{#1}}}
% передаются аргументы через запятую    КЛШ ∙ Теория чисел ∙ 2023
\def\coursefooterinfo#1{\coursefooter{\courseinfoschoolyear, \courseinfolongname, #1}}
% передаётся название раздела:          КЛШ 2023 ∙ Факультатив ТЧ ∙ Ответы
\def\coursefooterdate#1{\coursefooter{\courseinfoschool, \courseinfoshortname, #1}}
% передаётся дата:                      КЛШ ∙ ТЧ ∙ 18.07.2023
\def\coursefooterans#1{\coursefooter{\courseinfoschoolyear, \courseinfolongname, \courseinfoanswer, #1}}
% передаётся название урока:            КЛШ ∙ ТЧ ∙ Ответы ∙ Урок 1
```
- Заголовки и подзаголовки
```tex
\head{abc}
\subhead{def}
```
- Окружение `points` - выводит пункты задачи с переводом строки, нумерация вида `a) b) ...`:
```tex
Какие-то общие вводные к задаче.
\begin{points}
    \point Первый большой кусок задачи.
    \point Второй большой кусок задачи.
\end{points}
```
- Окружение `steps` - выводит пункты задачи через пробел, нумерация вида `(a) (b) ...`:
```tex
Посчитайте и сравните:
\begin{steps}
    \step $2+2$;
    \step $2 \times 2$;
    \step $2^2$;
\end{steps}
```
- Разные сокращения
```tex
\sepline        % горизонтальная черта с отступами до и после
\set{N}         % множество натуральных чисел
```
