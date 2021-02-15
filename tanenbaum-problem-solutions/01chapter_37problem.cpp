// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 01chapter_37problem.cpp
// программа, моделирующая сетевую архитектуру

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <iostream>
using namespace std;

const int MAX_MES = 80; // максимальный размер сообщения прикладного уровня
const int MAX_H = 64;   // максимальный размер заголовков

void layer7_function_send(wchar_t [], int); // объявление функции (прототип)

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	int res = _setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	res = _setmode(_fileno(stdin), _O_U16TEXT);

	wchar_t message[MAX_MES + 1]; // сообщение прикладного уровня

	// получим от пользователя текст сообщения прикладного уровня
	wcout << L"Введите текст сообщения (не более " << MAX_MES << L" символов): " << endl;
	wcin.get(message, MAX_MES + 1);

	// передаем сообщение прикладного уровня по сети
	layer7_function_send(message, wcslen(message));
	
	wcout << endl << endl;

	return 0;
}

// обработка сообщения по протоколу уровня 1
void layer1_function_send(wchar_t buffer[], int size)
{
	// в нашей модели обработка сообщения на этом уровне не производится, на этом
	// уровне оно отправляется по физической среде сети (электрический провод,
	// оптоволокно, беспроводным методом по воздуху или в космосе)

	wcout << L"\nУровень 1: ...передаю по физической среде пакет \"" << buffer << L"\"...";
}

// обработка сообщения по протоколу уровня 2
void layer2_function_send(wchar_t buffer[], int size)
{
	wchar_t tmp[MAX_H + MAX_MES + 1];       // обработка по протоколу уровня 2
	wcscpy_s(tmp, L"Заг2");                 // длина заголовка: 4 символа
	wcscat_s(tmp, buffer);

	wcout << L"\nУровень 2: " << tmp;       // покажем на дисплее, что получилось
	layer1_function_send(tmp, wcslen(tmp)); // отправим сообщение на уровень, лежащий ниже
}

// обработка сообщения по протоколу уровня 3
void layer3_function_send(wchar_t buffer[], int size)
{
	wchar_t tmp[MAX_H + MAX_MES + 1];       // обработка по протоколу уровня 3
	wcscpy_s(tmp, L"Заголовок3");           // длина заголовка: 10 символов
	wcscat_s(tmp, buffer);

	wcout << L"\nУровень 3: " << tmp;       // покажем на дисплее, что получилось
	layer2_function_send(tmp, wcslen(tmp)); // отправим сообщение на уровень, лежащий ниже
}

// обработка сообщения по протоколу уровня 4
void layer4_function_send(wchar_t buffer[], int size)
{
	wchar_t tmp[MAX_H + MAX_MES + 1];       // обработка по протоколу уровня 4
	wcscpy_s(tmp, L"Заго4");                // длина заголовка: 5 символов
	wcscat_s(tmp, buffer);

	wcout << L"\nУровень 4: " << tmp;       // покажем на дисплее, что получилось
	layer3_function_send(tmp, wcslen(tmp)); // отправим сообщение на уровень, лежащий ниже
}

// обработка сообщения по протоколу уровня 5
void layer5_function_send(wchar_t buffer[], int size)
{
	wchar_t tmp[MAX_H + MAX_MES + 1];       // обработка по протоколу уровня 5
	wcscpy_s(tmp, L"Заголовок5");           // длина заголовка: 10 символов
	wcscat_s(tmp, buffer);

	wcout << L"\nУровень 5: " << tmp;       // покажем на дисплее, что получилось
	layer4_function_send(tmp, wcslen(tmp)); // отправим сообщение на уровень, лежащий ниже
}

// обработка сообщения по протоколу уровня 6
void layer6_function_send(wchar_t buffer[], int size)
{
	wchar_t tmp[MAX_H + MAX_MES + 1];       // обработка по протоколу уровня 6
	wcscpy_s(tmp, L"Заголовок_6");          // длина заголовка: 11 символов
	wcscat_s(tmp, buffer);

	wcout << L"\nУровень 6: " << tmp;       // покажем на дисплее, что получилось
	layer5_function_send(tmp, wcslen(tmp)); // отправим сообщение на уровень, лежащий ниже
}

// обработка сообщения по протоколу уровня 7 (прикладной уровень)
void layer7_function_send(wchar_t buffer[], int size)
{
	// в нашей модели обработка сообщения на этом уровне не производится, потому что
	// получение сообщения прикладного уровня и проверка его длины уже выполнены
	// в главной функции программы main()

	wcout << L"\nУровень 7: " << buffer;    // покажем на дисплее, что получилось
	layer6_function_send(buffer, size);     // отправим сообщение на уровень, лежащий ниже
}