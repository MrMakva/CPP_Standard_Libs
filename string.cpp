/*
? Создание строк разными способами.

#include <iostream>
#include <string>

int main() {
    std::string s1;                   // Пустая строка
    std::string s2("Hello");          // Из C-строки
    std::string s3(5, 'A');           // 5 символов 'A' → "AAAAA"
    std::string s4(s2);               // Копия s2 ("Hello")
    std::string s5(s2, 1, 3);         // Подстрока s2 с позиции 1, длина 3 → "ell"

    std::cout << s2 << std::endl;     // Hello
    std::cout << s3 << std::endl;     // AAAAA
    std::cout << s5 << std::endl;     // ell
    return 0;
}
*/

/*
? length() / size() - Возвращает длину строки.
std::string s = "Hello";
std::cout << s.length();  // 5
*/

/*
? empty() - Проверяет, пуста ли строка.
std::string s1 = "Test";
std::string s2;
std::cout << s1.empty();  // 0 (false)
std::cout << s2.empty();  // 1 (true)
*/

/*
? clear() - Очищает строку.
std::string s = "Hello";
s.clear();
std::cout << s.empty();  // 1 (true)
*/

/*
? append() / += Добавляет символы или строку.
std::string s = "Hello";
s.append(" World");  // "Hello World"
s += "!";            // "Hello World!"
std::cout << s;
*/

/*
? compare() - Сравнивает строки (возвращает 0 если равны).
std::string s1 = "apple";
std::string s2 = "banana";
if (s1.compare(s2) == 0) {
    std::cout << "Строки равны";
} else {
    std::cout << "Строки разные";
}
*/

/*
? substr() - Возвращает подстроку.
std::string s = "Hello World";
std::string sub = s.substr(6, 5);  // "World"
std::cout << sub;
*/

/*
? find() - Ищет подстроку и возвращает её позицию.
std::string s = "Hello World";
size_t pos = s.find("World");  // 6
if (pos != std::string::npos) {
    std::cout << "Найдено на позиции: " << pos;
}
*/

/*
? replace() - Заменяет часть строки.
std::string s = "Hello World";
s.replace(6, 5, "C++");  // "Hello C++"
std::cout << s;
*/

/*
? insert() - Вставляет строку в указанную позицию.
std::string s = "Hello World";
s.insert(5, " Beautiful");  // "Hello Beautiful World"
std::cout << s;
*/

/*
? erase() - Удаляет часть строки.
std::string s = "Hello World";
s.erase(5, 6);  // "Hello"
std::cout << s;
*/

/*
? c_str() - Возвращает C-строку (const char*).
std::string s = "Hello";
const char* cstr = s.c_str();
std::cout << cstr;  // Hello
*/

/*
? stoi(), stol(), stof(), stod() - Преобразует строку в число.
std::string numStr = "123";
int num = std::stoi(numStr);  // 123
double d = std::stod("3.14"); // 3.14
std::cout << num << ", " << d;
*/

/*
? to_string() - Преобразует число в строку.
int num = 42;
std::string s = std::to_string(num);  // "42"
std::cout << s;
*/

/*
? front() и back() - Доступ к первому и последнему символу.
std::string s = "Hello";
char first = s.front();  // 'H'
char last = s.back();    // 'o'
std::cout << first << ", " << last;
*/

/*
? push_back() и pop_back() - Добавляет / удаляет символ в конце.
std::string s = "Hell";
s.push_back('o');  // "Hello"
s.pop_back();      // "Hell"
std::cout << s;
*/

/*
? swap() - Меняет местами две строки.
std::string a = "Apple";
std::string b = "Banana";
a.swap(b);
std::cout << a << ", " << b;  // "Banana, Apple"
*/

/*
? Итераторы (begin(), end(), rbegin(), rend()) - Обход строки.
std::string s = "Hello";
for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << " ";  // H e l l o
}
for (auto rit = s.rbegin(); rit != s.rend(); ++rit) {
    std::cout << *rit << " ";  // o l l e H
}
*/

/*
? assign() - Заменяет содержимое строки.
std::string s;
s.assign("Hello");       // "Hello"
s.assign(5, 'X');        // "XXXXX"
s.assign("Hello", 1, 3); // "ell" (подстрока "Hello" с позиции 1, длина 3)
std::cout << s;          // ell
*/

/*
? copy() - Копирует часть строки в C-строку (char*).
std::string s = "Hello";
char buffer[10];
size_t len = s.copy(buffer, 3, 1);  // Копирует 3 символа, начиная с позиции 1
buffer[len] = '\0';                 // Важно добавить нуль-терминатор
std::cout << buffer;                // "ell"
*/

/*
? resize() - Изменяет размер строки (дополняет или обрезает).
std::string s = "Hello";
s.resize(3);           // Обрезает до "Hel"
s.resize(6, '!');      // Дополняет до "Hel!!!"
std::cout << s;        // Hel!!!
*/

/*
? reserve() и capacity() - Управление памятью 
(reserve выделяет память заранее, capacity возвращает текущий запас).
std::string s;
s.reserve(100);        // Выделяет память под 100 символов
std::cout << s.capacity(); // 100 (или больше, зависит от реализации)
*/

/*
? shrink_to_fit() - Освобождает неиспользуемую память.
std::string s = "Hello";
s.resize(100);         // Занимает много памяти
s.shrink_to_fit();     // Освобождает лишнее
std::cout << s.capacity(); // Теперь близко к размеру строки
*/

/*
? find_first_of() и find_last_of() - Ищет любой символ из заданного набора.
std::string s = "Hello World";
size_t pos1 = s.find_first_of("aeiou");  // Первая гласная (e) → 1
size_t pos2 = s.find_last_of("aeiou");   // Последняя гласная (o) → 7
std::cout << pos1 << ", " << pos2;       // 1, 7
*/

/*
? find_first_not_of() и find_last_not_of() - Ищет первый символ не из заданного набора.
std::string s = "123abc";
size_t pos = s.find_first_not_of("0123456789");  // Первая не цифра → 3 ('a')
std::cout << pos; // 3
*/

/*
? replace() с итераторами - Заменяет часть строки, заданную итераторами.
std::string s = "Hello World";
auto it1 = s.begin() + 6;  // Указывает на 'W'
auto it2 = s.end();        // Указывает за 'd'
s.replace(it1, it2, "C++"); // "Hello C++"
std::cout << s;
*/

/*
? operator[] и at() - Доступ к символам по индексу
(at() проверяет границы и бросает std::out_of_range).
std::string s = "Hello";
char c1 = s[1];      // 'e' (без проверки)
char c2 = s.at(1);   // 'e' (с проверкой)
s.at(10);         // Выбросит исключение!
std::cout << c1 << ", " << c2;
*/

/*
? data() - Возвращает указатель на массив символов
(аналог c_str(), но в C++17 может не заканчиваться нулём).
std::string s = "Hello";
const char* ptr = s.data();  // Указатель на массив символов
std::cout << ptr;            // Hello
*/

/*
? Лексикографическое сравнение (<, >, == и др.)
Строки можно сравнивать операторами.
std::string a = "apple";
std::string b = "banana";
if (a < b) {
    std::cout << "apple < banana";  // Верно (лексикографически)
}
*/

/*
? std::string_view (C++17) - Легковесное представление строки (без копирования).
#include <string_view>
std::string s = "Hello World";
std::string_view sv(s.c_str(), 5);  // "Hello"
std::cout << sv;
*/

/*
? Конкатенация (+ и operator+) - Склеивание строк.
std::string s1 = "Hello";
std::string s2 = " World";
std::string s3 = s1 + s2;  // "Hello World"
std::cout << s3;
*/

/*
? std::stoul(), std::stoll() и др.
Преобразование строки в беззнаковое (stoul) или длинное целое (stoll).
std::string numStr = "1234567890";
unsigned long ul = std::stoul(numStr);  // 1234567890
long long ll = std::stoll(numStr);      // 1234567890
std::cout << ul << ", " << ll;
*/

/*
?std::to_wstring() - Преобразование числа в широкую строку (std::wstring).
#include <string>
int num = 42;
std::wstring ws = std::to_wstring(num);  // L"42"
std::wcout << ws;
*/

/*
? std::string::npos - Специальное значение "не найдено"
(обычно -1 или max_size()).
std::string s = "Hello";
size_t pos = s.find("xyz");
if (pos == std::string::npos) {
    std::cout << "Подстрока не найдена!";
}
*/

/*
? std::string и алгоритмы (<algorithm>)
Использование алгоритмов, например, std::sort.
#include <algorithm>
std::string s = "hello";
std::sort(s.begin(), s.end());  // "ehllo"
std::cout << s;
*/