# tanenbaum-book-problems
Решения вопросов-задач из книги «Компьютерные сети. 5-я редакция» Эндрю Таненбаума и Дэвида Уэзеролла (перевод с английского на русский язык). Книга впервые издана на английском языке в 2011 году, перевод на русский язык вышел в 2012 году (речь именно о 5-й редакции).

В книге 9 глав, из которых к 1-й главе, после ее окончания, дан список из 37 вопросов (в оригинале «problems»). Многие из этих вопросов требуют просто текстового ответа, другие — математического решения, и только один, последний, требует написания программы. Я ответил на все вопросы к 1-й главе, но здесь пока буду размещать только решения вопросов, требующих написания программы.

Таким образом, пока здесь размещена только одна программа — решение 37-го вопроса к 1-й главе. Смотрите в папке [Tanenbaum-problem-solutions](https://github.com/ilyachalov/tanenbaum-book-problems/tree/main/Tanenbaum-problem-solutions).

Данный проект начат в 2021 году.

В программе используется Юникод (широкие символы). Она работает в контексте интерфейса командной строки (программа «Windows PowerShell»). Программа собрана без ошибок в среде «Visual Studio Community 2019», запускалась и тестировалась в операционной системе «Windows 10 Pro».

Текст программы сохранен в файле с расширением «.cpp» в кодировке UTF-8 с сигнатурой (BOM). Завершения строк выполнены в формате Windows (CR LF).

Переключение стандартных потоков ввода и вывода в режим Юникода выполнено с помощью нестандартной для языка C++ функции \_setmode, поэтому в Linux, видимо, работать не будет.

Разбор 1-й главы книги и 37 вопросов-заданий к ней можно в моем блоге по [этой ссылке](https://ilyachalov.livejournal.com/156038.html).
