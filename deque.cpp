/*
? Создание deque

int main() {
    Пустой deque
    std::deque<int> d1;
    Deque с 5 элементами (значение 10)
    std::deque<int> d2(5, 10);
    Deque из другого контейнера
    std::deque<int> d3(d2.begin(), d2.end());
    Копирование deque
    std::deque<int> d4(d3);
    return 0;
}
*/

/*
? push_back() - добавление в конец
std::deque<int> d;
d.push_back(1);
d.push_back(2);
d.push_back(3); // d: [1, 2, 3]
*/

/*
? push_front() - добавление в начало
std::deque<int> d;
d.push_front(3);
d.push_front(2);
d.push_front(1); // d: [1, 2, 3]
*/

/*
? pop_back() - удаление с конца
std::deque<int> d{1, 2, 3};
d.pop_back(); // d: [1, 2]
*/

/*
? pop_front() - удаление с начала
std::deque<int> d{1, 2, 3};
d.pop_front(); // d: [2, 3]
*/

/*
? front() - доступ к первому элементу
std::deque<int> d{1, 2, 3};
int first = d.front(); // first = 1
*/

/*
? back() - доступ к последнему элементу
std::deque<int> d{1, 2, 3};
int last = d.back(); // last = 3
*/

/*
? size() - текущий размер
std::deque<int> d{1, 2, 3};
std::cout << d.size(); // Выведет: 3
*/

/*
? empty() - проверка на пустоту
std::deque<int> d;
if (d.empty()) {
    std::cout << "Deque is empty";
}
*/

/*
? clear() - очистка deque
std::deque<int> d{1, 2, 3};
d.clear(); // d: []
*/

/*
? begin(), end() - итераторы
std::deque<int> d{1, 2, 3};
for (auto it = d.begin(); it != d.end(); ++it) {
    std::cout << *it << " ";
} // Выведет: 1 2 3
*/

/*
? rbegin(), rend() - реверсивные итераторы
std::deque<int> d{1, 2, 3};
for (auto it = d.rbegin(); it != d.rend(); ++it) {
    std::cout << *it << " ";
} // Выведет: 3 2 1
*/

/*
? insert() - вставка элементов
std::deque<int> d{1, 3};
auto it = d.begin() + 1;
d.insert(it, 2); // d: [1, 2, 3]
*/

/*
? erase() - удаление элементов
std::deque<int> d{1, 2, 3, 4};
auto it = d.begin() + 1;
d.erase(it); // d: [1, 3, 4]
*/

/*
? resize() - изменение размера
std::deque<int> d{1, 2, 3};
d.resize(5);    // [1, 2, 3, 0, 0]
d.resize(2);    // [1, 2]
*/

/*
? swap() - обмен содержимым
std::deque<int> d1{1, 2, 3};
std::deque<int> d2{4, 5, 6};
d1.swap(d2); // d1: [4, 5, 6], d2: [1, 2, 3]
*/

/*
? at() - доступ с проверкой границ
std::deque<int> d{1, 2, 3};
try {
    int val = d.at(10); // Выбросит исключение
} catch (const std::out_of_range& e) {
    std::cout << "Out of range: " << e.what();
}
*/

/*
? operator[] - доступ по индексу
std::deque<int> d{1, 2, 3};
int val = d[1]; // val = 2
*/

/*
? assign() - перезапись содержимого deque
std::deque<int> d;
Заменяем содержимое тремя копиями числа 5
d.assign(3, 5);  // d: [5, 5, 5]

Заменяем содержимое элементами из другого контейнера
int arr[] = {1, 2, 3};
d.assign(arr, arr + 3);  // d: [1, 2, 3]
*/

/*
? emplace_front() и emplace_back() - эффективное создание элементов

struct Task {
    std::string name;
    int priority;
    Task(std::string n, int p) : name(n), priority(p) {}
};

std::deque<Task> tasks;
tasks.emplace_front("Fix bug", 1);  // Создает объект Task на месте
tasks.emplace_back("Write docs", 2);

Эквивалентно push_front(Task("Fix bug", 1)), но более эффективно
*/

/*
? emplace() - эффективная вставка в произвольную позицию
std::deque<std::pair<int, std::string>> d;
d.emplace_back(1, "one");
Вставляем элемент перед первым элементом
auto it = d.begin();
d.emplace(it, 0, "zero");  // d: [{0, "zero"}, {1, "one"}]
*/

/*
? max_size() - максимально возможный размер
std::deque<int> d;
std::cout << "Max size: " << d.max_size() << "\n";
Выведет максимальное количество элементов, которое может содержать deque
*/

/*
? shrink_to_fit() - уменьшение используемой памяти
std::deque<int> d(1000);
d.resize(10);
d.shrink_to_fit();  // Пытается уменьшить используемую память
*/

/*
? Операторы сравнения
std::deque<int> d1 = {1, 2, 3};
std::deque<int> d2 = {1, 2, 4};

if (d1 == d2) std::cout << "Equal\n";
if (d1 < d2) std::cout << "d1 is less than d2\n";  // Лексикографическое сравнение
*/

/*
? get_allocator() - получение аллокатора
std::deque<int> d;
auto alloc = d.get_allocator();
int* p = alloc.allocate(1);  // Выделяем память для одного int
alloc.deallocate(p, 1);      // Освобождаем память
*/

#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> deque1;
    for(int i=1;i<=5;i++)
    {
        deque1.push_back(i*10);
    }
    deque1.push_front(100);
    for(int i=0;i<deque1.size();i++)
    {
        cout<<deque1[i]<<' ';
    }
    cout<<'\n';

    deque1.pop_back();
    deque1.pop_front();
    for(int i=0;i<deque1.size();i++)
    {
        cout<<deque1[i]<<' ';
    }
    cout<<'\n';

    int size=deque1.size();
    cout<<size<<'\n';
    if(deque1.empty())
    cout<<"Пустой"<<'\n';
    else
    cout<<"Не пустой"<<'\n';

    int front=deque1.front();
    int back=deque1.back();
    cout<<"Первый элемент: "<<front<<'\n';
    cout<<"Последний элемент: "<<back<<'\n';

    int x=deque1[3];
    cout<<x<<'\n';
    x=deque1.at(3);
    cout<<x<<'\n';

    auto inter=deque1.begin();
    advance(inter,3);
    deque1.insert(inter,200);
        for(int i=0;i<deque1.size();i++)
    {
        cout<<deque1[i]<<' ';
    }
    cout<<'\n';

    deque1.erase(inter);
        for(int i=0;i<deque1.size();i++)
    {
        cout<<deque1[i]<<' ';
    }
    cout<<'\n';
    deque1.clear();
        if(deque1.empty())
    cout<<"Пустой"<<'\n';
    else
    cout<<"Не пустой"<<'\n';
}