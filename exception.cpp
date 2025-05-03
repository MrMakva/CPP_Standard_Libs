/*
? std::exception (базовый класс)
#include <iostream>
#include <exception>
#include <stdexcept>

int main() {
    try {
        throw std::exception();  // Базовое исключение
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
*/

/*
? std::logic_error (ошибка логики)
#include <iostream>
#include <stdexcept>

void checkPositive(int num) {
    if (num < 0) {
        throw std::logic_error("Number must be positive!");
    }
}

int main() {
    try {
        checkPositive(-5);
    } catch (const std::logic_error& e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    }
    return 0;
}
    Вывод:
Logic error: Number must be positive!
*/

/*
? std::runtime_error (ошибка времени выполнения)
#include <iostream>
#include <stdexcept>

double divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero!");
    }
    return a / b;
}

int main() {
    try {
        std::cout << divide(10, 0) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
    return 0;
}
    Вывод:
Runtime error: Division by zero!
*/

/*
? std::bad_alloc (ошибка выделения памяти)
#include <iostream>
#include <new>

int main() {
    try {
        Пытаемся выделить нереально большой блок памяти
        int* hugeArray = new int[1000000000000];
        delete[] hugeArray;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Bad alloc: " << e.what() << std::endl;
    }
    return 0;
}
    Вывод:
Bad alloc: std::bad_alloc
*/

/*
? std::bad_cast (ошибка при dynamic_cast)
#include <iostream>
#include <typeinfo>

class Base { public: virtual ~Base() {} };
class Derived : public Base {};

int main() {
    Base base;
    try {
        Derived& derived = dynamic_cast<Derived&>(base);  // Неверное приведение
    } catch (const std::bad_cast& e) {
        std::cerr << "Bad cast: " << e.what() << std::endl;
    }
    return 0;
}
    Вывод:
Bad cast: std::bad_cast
*/

/*
? std::terminate и std::set_terminate
#include <exception>
#include <iostream>

void myTerminateHandler() {
    std::cerr << "Terminate called! Aborting..." << std::endl;
    std::abort();
}

int main() {
    std::set_terminate(myTerminateHandler);  // Устанавливаем свой обработчик
    throw 42;  // Неперехваченное исключение (вызовет terminate)
    return 0;
}
    Вывод:
Terminate called! Aborting...
*/

/*
? std::uncaught_exceptions() (проверка активных исключений)
#include <exception>
#include <iostream>

int main() {
    try {
        throw std::runtime_error("Test");
    } catch (...) {
        std::cout << "Uncaught exceptions: " << std::uncaught_exceptions() <<
std::endl;
    }
    return 0;
}
    Вывод:
Uncaught exceptions: 0  // Потому что исключение перехвачено
*/

/*
? std::nested_exception (вложенные исключения)
Позволяет хранить одно исключение внутри другого (полезно для цепочек ошибок).
Используется вместе с std::throw_with_nested, std::rethrow_if_nested.

#include <iostream>
#include <exception>
#include <stdexcept>

void handleException() {
    try {
        throw std::runtime_error("Inner error");
    } catch (...) {
        std::throw_with_nested(std::runtime_error("Outer error"));
    }
}

int main() {
    try {
        handleException();
    } catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << std::endl;

        try {
            std::rethrow_if_nested(e);  // Пытаемся извлечь вложенное исключение
        } catch (const std::exception& nested) {
            std::cerr << "Nested: " << nested.what() << std::endl;
        }
    }
    return 0;
}
    Вывод:
Caught: Outer error
Nested: Inner error
*/

/*
? std::current_exception() (получение текущего исключения)
Возвращает std::exception_ptr на активное исключение (полезно для асинхронной
обработки).

#include <exception>
#include <iostream>
#include <stdexcept>

void logException(std::exception_ptr eptr) {
    try {
        if (eptr) std::rethrow_exception(eptr);
    } catch (const std::exception& e) {
        std::cerr << "Logged: " << e.what() << std::endl;
    }
}

int main() {
    std::exception_ptr eptr;
    try {
        throw std::runtime_error("Test error");
    } catch (...) {
        eptr = std::current_exception();  // Сохраняем исключение
    }
    logException(eptr);  // Логируем позже
    return 0;
}
*/

/*
? std::make_exception_ptr() (создание exception_ptr)
Создает std::exception_ptr из исключения без необходимости его бросать.

#include <exception>
#include <iostream>

int main() {
    auto eptr = std::make_exception_ptr(std::runtime_error("Error without
throw")); try { std::rethrow_exception(eptr); } catch (const std::exception& e)
{ std::cerr << "Caught: " << e.what() << std::endl;
    }
    return 0;
}
    Вывод:
Caught: Error without throw
*/

/*
? std::rethrow_exception() (повторный выброс исключения из exception_ptr)
Позволяет повторно выбросить исключение, сохранённое в std::exception_ptr.
*/

/*
? Пользовательские исключения (наследование от std::exception)
Можно создавать свои классы исключений, наследуясь от std::exception.

#include <iostream>
#include <exception>
#include <string>

class MyException : public std::exception {
    std::string msg;
public:
    MyException(const std::string& message) : msg(message) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

int main() {
    try {
        throw MyException("Custom error!");
    } catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
    return 0;
}
    Вывод:
Caught: Custom error!
*/

/*
? noexcept (спецификатор и оператор)
Хоть и не часть <exception>, но тесно связан с обработкой ошибок:
noexcept – указывает, что функция не бросает исключений.
noexcept(expr) – проверяет, является ли выражение noexcept.

#include <iostream>

void safeFunction() noexcept {
    std::cout << "This function won't throw!" << std::endl;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "Is safeFunction noexcept? " << noexcept(safeFunction()) <<
std::endl; safeFunction(); return 0;
}
Вывод:
Is safeFunction noexcept? true
This function won't throw!
*/

/*
? std::exception_ptr (для асинхронной обработки исключений)
Это умный указатель на исключение, который позволяет:
Сохранять исключение (std::current_exception).
Передавать между потоками.
Повторно бросать (std::rethrow_exception).

#include <iostream>
#include <exception>
#include <thread>
#include <stdexcept>

void worker(std::exception_ptr& eptr) {
    try {
        throw std::runtime_error("Error in worker thread");
    } catch (...) {
        eptr = std::current_exception();  // Сохраняем исключение
    }
}

int main() {
    std::exception_ptr eptr;
    std::thread t(worker, std::ref(eptr));
    t.join();

    if (eptr) {
        try {
            std::rethrow_exception(eptr);  // Бросаем сохранённое исключение
        } catch (const std::exception& e) {
            std::cerr << "Main thread caught: " << e.what() << std::endl;
        }
    }
    return 0;
}
    Вывод:
Main thread caught: Error in worker thread
*/

/*
? Пользовательский обработчик std::terminate
Можно перехватывать аварийное завершение программы через std::set_terminate.

#include <iostream>
#include <exception>
#include <cstdlib>

void myTerminate() {
    std::cerr << "My terminate handler called! Stack trace here..." << std::endl;
    std::abort();  // Обязательно завершаем программу
}

int main() {
    std::set_terminate(myTerminate);
    throw 42;  // Неперехваченное исключение → вызов terminate
}
    Вывод:
My terminate handler called! Stack trace here...
*/
#include<iostream>
#include<string>
#include<exception>
#include<sstream>
using namespace std;

class InvalidInputException : exception
{
    const char* what() const noexcept override
    {
        return "Invalid input";
    }
};

class CalculationException : exception
{
    const char* what() const noexcept override
    {
        return "Calculation ERROR";
    }
};

int parseInteger(const std::string &input)noexcept(false)
{
    for(char c: input)
    if(!isdigit(c))
    throw InvalidInputException();
    return stoi(input);
}

double divide(int a, int b)
{
    if(b==0)
    throw invalid_argument("ERROR: b = 0");
    double tmp = a/b;
    if(tmp<0)
    throw CalculationException();
    else 
    return tmp;
}

int main()
{
    string a,b;
    cin>>a;
    cin>>b;
    int aint=parseInteger(a);
    int bint=parseInteger(b);
    cout<<divide(aint,bint)<<'\n';

}