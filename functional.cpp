/*
? std::function — обёртка для вызываемых объектов
#include <iostream>
#include <functional>

void printHello() {
    std::cout << "Hello, World!\n";
}

int add(int a, int b) {
    return a + b;
}

int main() {
    std::function<void()> func1 = printHello;
    func1();  // Выведет: Hello, World!

    std::function<int(int, int)> func2 = add;
    std::cout << func2(3, 4) << "\n";  // Выведет: 7

    Лямбда
    std::function<int(int)> square = [](int x) { return x * x; };
    std::cout << square(5) << "\n";  // Выведет: 25
}
*/

/*
? std::bind — привязка аргументов
#include <iostream>
#include <functional>

int multiply(int a, int b) {
    return a * b;
}

int main() {
    using namespace std::placeholders;  // Для _1, _2, ...

    Фиксируем первый аргумент как 10
    auto multiplyBy10 = std::bind(multiply, 10, _1);
    std::cout << multiplyBy10(5) << "\n";  // 50

    Меняем местами аргументы
    auto multiplySwapped = std::bind(multiply, _2, _1);
    std::cout << multiplySwapped(3, 7) << "\n";  // 21 (7 * 3)
}
*/

/*
? std::placeholders — заполнители
#include <iostream>
#include <functional>

void printThree(int a, int b, int c) {
    std::cout << a << ", " << b << ", " << c << "\n";
}

int main() {
    using namespace std::placeholders;

    auto f = std::bind(printThree, _2, 100, _1);
    f(1, 2);  // Выведет: 2, 100, 1
}
*/

/*
? Стандартные функторы (std::plus, std::minus, ...)
#include <iostream>
#include <functional>

int main() {
    std::plus<int> add;
    std::cout << add(3, 4) << "\n";  // 7

    std::multiplies<int> multiply;
    std::cout << multiply(5, 6) << "\n";  // 30

    std::negate<int> neg;
    std::cout << neg(10) << "\n";  // -10
}
*/

/*
? std::mem_fn — обёртка для методов класса
#include <functional>
#include <iostream>
#include <vector>

class Person {
public:
    void greet() const {
        std::cout << "Hello!\n";
    }
};

int main() {
    std::vector<Person> people = {Person(), Person()};

    Вызов метода greet для всех объектов
    std::for_each(people.begin(), people.end(), std::mem_fn(&Person::greet));
}
    Выведет:
    Hello!
    Hello!
*/

/*
? Лямбда-выражения + std::function
#include <functional>
#include <iostream>
#include <vector>

int main() {
    std::function<int(int, int)> sum = [](int a, int b) { return a + b; };
    std::cout << sum(10, 20) << "\n";  // 30

    Лямбда с захватом переменных
    int factor = 3;
    auto multiplyByFactor = [factor](int x) { return x * factor; };
    std::cout << multiplyByFactor(5) << "\n";  // 15
}
*/

/*
? std::invoke (C++17) — универсальный вызов любого вызываемого объекта
Позволяет единообразно вызывать функции, методы, функторы и даже указатели на
члены класса.

#include <functional>
#include <iostream>

void freeFunction() {
    std::cout << "Free function called!\n";
}

class MyClass {
public:
    void method() { std::cout << "Method called!\n"; }
    static void staticMethod() { std::cout << "Static method called!\n"; }
};

int main() {
    Вызов свободной функции
    std::invoke(freeFunction);  // Free function called!

    Вызов метода объекта
    MyClass obj;
    std::invoke(&MyClass::method, obj);  // Method called!

    Вызов статического метода
    std::invoke(&MyClass::staticMethod);  // Static method called!

    Вызов лямбды
    std::invoke([]() { std::cout << "Lambda called!\n"; });  // Lambda called!
}
*/

/*
? std::reference_wrapper — обёртка для ссылок
Позволяет хранить ссылки в контейнерах (например, std::vector), которые обычно
не поддерживают ссылки напрямую.

#include <functional>
#include <iostream>
#include <vector>

int main() {
    int a = 10, b = 20, c = 30;

    Создаём вектор "ссылок" на int
    std::vector<std::reference_wrapper<int>> numbers = {a, b, c};

    Изменяем значение через reference_wrapper
    numbers[1].get() = 99;

    std::cout << b << "\n";  // Выведет 99 (значение изменилось)
}
*/

/*
? std::not_fn (C++17) — отрицание предиката
Создаёт предикат, который возвращает отрицание исходного.

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

bool isEven(int x) {
    return x % 2 == 0;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    Оставляем только нечётные числа
    auto isOdd = std::not_fn(isEven);
    auto it = std::remove_if(nums.begin(), nums.end(), isOdd);

    nums.erase(it, nums.end());

    for (int x : nums) {
        std::cout << x << " ";  // 2 4
    }
}
*/

/*
? Указатели на члены класса (std::mem_fn альтернатива)
Позволяют вызывать методы или обращаться к полям класса через указатели.

#include <functional>
#include <iostream>

class Person {
public:
    std::string name;
    void printName() const { std::cout << name << "\n"; }
};

int main() {
    Person alice{"Alice"}, bob{"Bob"};

    Указатель на метод
    auto printNameFunc = &Person::printName;
    std::invoke(printNameFunc, alice);  // Alice

    Указатель на поле
    auto namePtr = &Person::name;
    std::cout << std::invoke(namePtr, bob) << "\n";  // Bob
}
*/

/*
? std::identity (C++20) — тождественное преобразование
Просто возвращает переданный аргумент без изменений. Полезен в шаблонных
контекстах.

#include <functional>
#include <iostream>

int main() {
    std::identity id;
    std::cout << id(42) << "\n";  // 42

    Пример с алгоритмом
    std::vector<int> v = {3, 1, 4};
    std::sort(v.begin(), v.end(), std::ranges::less{}, id);  // Сортировка по
id(x) for (int x : v) std::cout << x << " ";  // 1 3 4
}
*/

/*
? std::boyer_moore_searcher (C++17) — поиск подстроки
Использует алгоритм Бойера-Мура для поиска.

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>

int main() {
    std::string text = "Hello, functional world!";
    std::string pattern = "func";

    auto searcher = std::boyer_moore_searcher(pattern.begin(), pattern.end());
    auto it = std::search(text.begin(), text.end(), searcher);

    if (it != text.end()) {
        std::cout << "Found at position: " << std::distance(text.begin(), it) << "\n"; // 7
    }
}
*/

/*
? std::bind_front (C++20) — улучшенная замена std::bind
Привязывает первые аргументы функции (без placeholders).

#include <iostream>
#include <functional>

void printSum(int a, int b, int c) {
    std::cout << a + b + c << "\n";
}

int main() {
    auto f = std::bind_front(printSum, 10, 20);
    f(30); // Выведет: 60 (10 + 20 + 30)
}
*/
#include<iostream>
#include<functional>
using namespace std;

int sum(int a, int b)
{
    return a+b;
}

int multiplication(int a, int b)
{
    return a*b;
}

int minusAB (int a, int b)
{
    return a-b;
}

int  main() 
{
    vector<function<int(int,int)>> arr;
    arr.push_back(sum);
    arr.push_back(multiplication);
    arr.push_back(minusAB);

    int a,b;
    cin>>a;
    cin>>b;
    for(auto i:arr)
    {
       cout<< i(a,b)<<'\n';
    }
}