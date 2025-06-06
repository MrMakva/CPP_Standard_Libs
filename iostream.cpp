/*
? std::cout — вывод в консоль
Используется для вывода данных в стандартный поток вывода (обычно консоль).

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;  // Вывод строки
    int num = 42;
    std::cout << "Number: " << num << std::endl;  // Вывод переменной
    return 0;
}
*/

/*
? std::cin — ввод с консоли
Используется для считывания данных из стандартного потока ввода (обычно клавиатура).

#include <iostream>

int main() {
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;  // Считывание числа
    std::cout << "You are " << age << " years old." << std::endl;

    / Считывание нескольких значений
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    std::cout << "Sum: " << (a + b) << std::endl;
    return 0;
}
*/

/*
? std::cerr — вывод ошибок
Используется для вывода сообщений об ошибках (небуферизированный вывод).

#include <iostream>

int main() {
    int value;
    std::cout << "Enter a positive number: ";
    std::cin >> value;
    if (value <= 0) {
        std::cerr << "Error: Number must be positive!" << std::endl;
        return 1;
    }
    std::cout << "You entered: " << value << std::endl;
    return 0;
}
*/

/*
? std::clog — логирование
Аналогичен std::cerr, но используется для логирования (буферизированный вывод).

#include <iostream>

int main() {
    std::clog << "This is a log message." << std::endl;
    return 0;
}
*/

/*
? std::endl — перевод строки и сброс буфера
Добавляет символ новой строки (\n) и сбрасывает буфер вывода.

#include <iostream>

int main() {
    std::cout << "First line" << std::endl;
    std::cout << "Second line" << std::endl;
    return 0;
}
*/

/*
? std::ws — пропуск пробельных символов
Используется для пропуска пробелов, табуляций и переводов строк при вводе.

#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> std::ws;  // Пропуск пробелов перед вводом
    std::getline(std::cin, name);  // Считывание всей строки
    std::cout << "Hello, " << name << "!" << std::endl;
    return 0;
}
*/

/*
? std::flush — принудительный сброс буфера вывода
Используется для немедленного вывода данных без перевода строки.

#include <chrono>
#include <iostream>
#include <thread>

int main() {
    std::cout << "Loading...";
    std::cout.flush();  // или std::flush
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Имитация загрузки
    std::cout << " Done!" << std::endl;
    return 0;
}
    todo Примечание:
std::endl включает std::flush, поэтому если не нужен перевод строки, лучше
использовать '\n' + std::flush вручную.
*/

/*
? std::getline() — чтение строки с пробелами
Считывает всю строку (включая пробелы) до символа перевода строки.

#include <iostream>
#include <string>

int main() {
    std::string fullName;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);  // Считывает всю строку
    std::cout << "Hello, " << fullName << "!" << std::endl;
    return 0;
}
*/

/*
? std::cin.ignore() — очистка буфера ввода
Пропускает символы в буфере ввода (например, после std::cin >> перед std::getline()).

#include <iostream>
#include <string>

int main() {
    int age;
    std::string name;

    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cin.ignore(1000, '\n');  // Пропустить оставшиеся символы до '\n'

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
    return 0;
}
*/

/*
? std::noskipws и std::skipws — управление пропуском пробелов
std::skipws (по умолчанию) — игнорирует пробелы при вводе.
std::noskipws — не игнорирует пробелы.

#include <iostream>

int main() {
    char a, b;
    std::cout << "Enter two characters (with space): ";
    std::cin >> std::noskipws >> a >> b;  // Считает пробел как символ
    std::cout << "You entered: '" << a << "' and '" << b << "'" << std::endl;
    return 0;
}
*/

/*
? Проверка состояния потока
Флаги для проверки ошибок ввода/вывода:

std::cin.fail() — возвращает true, если ввод некорректен.
std::cin.eof() — конец файла/потока (Ctrl+D/Ctrl+Z).
std::cin.good() — поток в хорошем состоянии.

#include <iostream>

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (std::cin.fail()) {
        std::cerr << "Invalid input!" << std::endl;
        std::cin.clear();  // Сброс флагов ошибок
        std::cin.ignore(1000, '\n');  // Очистка буфера
    } else {
        std::cout << "Number: " << number << std::endl;
    }
    return 0;
}
*/