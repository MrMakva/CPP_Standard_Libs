/*
? std::istringstream – чтение из строки
>> – извлечение данных (как при вводе с клавиатуры).
.str() – получение строки из потока.
.clear() – сброс флагов ошибок.

#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string data = "42 3.14 Hello";
    std::istringstream iss(data);  // Создаем поток ввода из строки

    int num;
    double pi;
    std::string word;

    iss >> num >> pi >> word;  // Чтение данных как из cin

    std::cout << "Число: " << num << '\n';
    std::cout << "Пи: " << pi << '\n';
    std::cout << "Слово: " << word << '\n';

    return 0;
}
    Вывод:
    Число: 42
    Пи: 3.14
    Слово: Hello
*/

/*
? std::ostringstream – запись в строку
<< – добавление данных (как при выводе в консоль).
.str() – получение строки из потока.

#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::ostringstream oss;  // Создаем поток вывода в строку

    int age = 25;
    double height = 175.5;
    std::string name = "Alice";

    oss << "Имя: " << name << ", Возраст: " << age << ", Рост: " << height;

    std::string result = oss.str();  // Получаем строку
    std::cout << result << '\n';

    return 0;
}
    Вывод:
    Имя: Alice, Возраст: 25, Рост: 175.5
*/

/*
? std::stringstream – чтение и запись
<< – запись в поток.
>> – чтение из потока.
.str() – получение строки.
.clear() – сброс состояния потока.

#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::stringstream ss;

    / Запись данных
    ss << "Количество: " << 10 << ", Цена: " << 99.9;

    / Получение строки
    std::cout << "Строка: " << ss.str() << '\n';

    / Чтение данных (если возможно)
    std::string temp;
    int quantity;
    double price;

    ss >> temp >> quantity >> temp >> temp >> price;

    std::cout << "Количество: " << quantity << '\n';
    std::cout << "Цена: " << price << '\n';

    return 0;
}
    Строка: Количество: 10, Цена: 99.9
    Количество: 10
    Цена: 99.9
*/

/*
? Преобразование числа в строку и обратно

#include <iostream>
#include <sstream>

int main() {
    / Число → строка
    std::ostringstream oss;
    oss << 123;
    std::string numStr = oss.str();
    std::cout << "Строка: " << numStr << '\n';

    / Строка → число
    std::istringstream iss("456");
    int num;
    iss >> num;
    std::cout << "Число: " << num << '\n';
    return 0;
}
    Вывод:
    Строка: 123
    Число: 456
*/

/*
? Разделение строки по запятым

#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string csv = "apple,banana,orange";
    std::stringstream ss(csv);
    std::vector<std::string> fruits;
    std::string fruit;

    while (std::getline(ss, fruit, ',')) {
        fruits.push_back(fruit);
    }

    for (const auto& f : fruits) {
        std::cout << f << '\n';
    }

    return 0;
}
    Вывод:
    apple
    banana
    orange
*/

/*
? .str() (получить строку)
Возвращает текущее содержимое потока.

#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss;
    ss << "C++ is cool!";
    std::string content = ss.str();  // Получаем строку
    std::cout << content << "\n";    // C++ is cool!
    return 0;
}
*/

/*
? .str("текст") (установить строку)
Заменяет содержимое потока.

#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss;
    ss << "Old text";
    ss.str("New text");  // Перезаписываем поток
    std::cout << ss.str() << "\n";  // New text
    return 0;
}
*/

/*
? .good() (проверка состояния)
Проверяет, что поток в рабочем состоянии.

#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss("100");
    int x;
    ss >> x;

    if (ss.good()) {
        std::cout << "Чтение успешно!\n";  // Выведется
    }
    return 0;
}
*/

/*
? .eof() (конец потока)
Проверяет, достигнут ли конец строки.

#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss("100");
    int x;
    ss >> x;

    if (ss.eof()) {
        std::cout << "Достигнут конец строки!\n";  // Выведется
    }
    return 0;
}
*/

/*
? .fail() (ошибка чтения)
Возвращает true, если произошла ошибка (например, неверный тип данных).

#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss("abc");
    int x;
    ss >> x;  // Ошибка: "abc" нельзя преобразовать в int

    if (ss.fail()) {
        std::cout << "Ошибка чтения!\n";  // Выведется
        ss.clear();  // Сбрасываем флаг ошибки
    }
    return 0;
}
*/

/*
? .clear() (сброс ошибок)
Сбрасывает флаги ошибок потока.

#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss("abc");
    int x;
    ss >> x;  // Ошибка

    ss.clear();  // Сбрасываем ошибку
    ss.str("100");
    ss >> x;  // Теперь успешно
    std::cout << x << "\n";  // 100
    return 0;
}
*/

/*
? std::getline() (чтение строки с пробелами)
Читает всю строку (включая пробелы) до \n.

#include <iostream>
#include <sstream>

int main() {
    std::stringstream ss("Hello World\nC++ is fun");
    std::string line;

    std::getline(ss, line);  // Читаем первую строку
    std::cout << line << "\n";  // Hello World

    std::getline(ss, line);  // Читаем вторую строку
    std::cout << line << "\n";  // C++ is fun
    return 0;
}
*/