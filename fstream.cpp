/*
? open() – открытие файла

#include <fstream>

int main() {
    std::ofstream file;
    file.open("example.txt");  // Открываем файл для записи

    if (file.is_open()) {
        file << "Файл успешно открыт!";
        file.close();
    }
    return 0;
}
*/

/*
? close() – закрытие файла

#include <fstream>

int main() {
    std::ofstream file("example.txt");
    file << "Данные в файле";
    file.close();  // Закрываем файл (все изменения сохраняются)
    return 0;
}
*/

/*
? is_open() – проверка, открыт ли файл

#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("nonexistent.txt");

    if (!file.is_open()) {  // Проверяем, открылся ли файл
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }
    return 0;
}
*/

/*
? >> – чтение данных (как cin)

#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("data.txt");
    int number;

    if (file >> number) {  // Читаем число из файла
        std::cout << "Прочитано: " << number << std::endl;
    }
    file.close();
    return 0;
}
*/

/*
? << – запись данных (как cout)

#include <fstream>

int main() {
    std::ofstream file("output.txt");
    file << "Записываем строку" << std::endl;  // Запись в файл
    file << 123 << std::endl;
    file.close();
    return 0;
}
*/

/*
? get() – чтение одного символа

#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("text.txt");
    char ch;

    if (file.get(ch)) {  // Читаем 1 символ
        std::cout << "Первый символ: " << ch << std::endl;
    }
    file.close();
    return 0;
}
*/

/*
? put() – запись одного символа

#include <fstream>

int main() {
    std::ofstream file("char.txt");
    file.put('A');  // Записываем символ 'A'
    file.close();
    return 0;
}
*/

/*
? getline() – чтение строки

#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("lines.txt");
    std::string line;

    while (std::getline(file, line)) {  // Читаем построчно
        std::cout << line << std::endl;
    }
    file.close();
    return 0;
}
*/

/*
? read() – чтение блока данных

#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("data.bin", std::ios::binary);
    char buffer[100];

    file.read(buffer, 100);  // Читаем 100 байт
    std::cout << "Прочитано: " << file.gcount() << " байт" << std::endl;
    file.close();
    return 0;
}
*/

/*
? write() – запись блока данных

#include <fstream>

int main() {
    std::ofstream file("data.bin", std::ios::binary);
    const char* data = "Binary data!";

    file.write(data, 12);  // Записываем 12 байт
    file.close();
    return 0;
}
*/

/*
? tellg() – текущая позиция чтения

#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("example.txt");
    file.seekg(0, std::ios::end);  // Перемещаемся в конец файла

    std::streampos size = file.tellg();  // Получаем размер файла
    std::cout << "Размер файла: " << size << " байт" << std::endl;

    file.close();
    return 0;
}
*/

/*
? tellp() – текущая позиция записи

#include <fstream>
#include <iostream>

int main() {
    std::ofstream file("example.txt");
    file << "Текст";

    std::streampos pos = file.tellp();  // Текущая позиция записи
    std::cout << "Позиция записи: " << pos << std::endl;

    file.close();
    return 0;
}
*/

/*
? seekg() – перемещение позиции чтения

#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("example.txt");
    file.seekg(5, std::ios::beg);  // Перемещаемся на 5-й байт от начала

    char ch;
    file.get(ch);
    std::cout << "5-й символ: " << ch << std::endl;

    file.close();
    return 0;
}
*/

/*
? seekp() – перемещение позиции записи

#include <fstream>

int main() {
    std::fstream file("example.txt", std::ios::in | std::ios::out);
    file << "Hello, World!";

    file.seekp(7, std::ios::beg);  // Перемещаемся на 7-й байт
    file << "C++";  // Перезаписываем часть строки

    file.close();
    return 0;
}
*/

/*
? eof() – проверка конца файла

#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("example.txt");
    char ch;

    while (file.get(ch)) {  // Читаем посимвольно
        std::cout << ch;
    }

    if (file.eof()) {  // Проверяем, достигнут ли конец файла
        std::cout << "\nКонец файла достигнут." << std::endl;
    }
    file.close();
    return 0;
}
*/

/*
? good(), fail(), bad() – проверка состояния потока

#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("example.txt");

    if (file.fail()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
    }

    int num;
    file >> num;  // Пытаемся прочитать число

    if (file.fail()) {
        std::cerr << "Ошибка чтения данных!" << std::endl;
    }

    if (file.bad()) {
        std::cerr << "Критическая ошибка!" << std::endl;
    }

    if (file.good()) {
        std::cout << "Поток в хорошем состоянии." << std::endl;
    }
    file.close();
    return 0;
}
*/