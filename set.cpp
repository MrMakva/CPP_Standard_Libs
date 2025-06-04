/*
? Инициализация
#include <set>
#include <iostream>

int main() {
    std::set<int> s1 = {5, 2, 8, 1}; // Уникальные элементы, сортировка по возрастанию
    std::multiset<int> ms1 = {5, 2, 5, 1}; // Могут быть дубликаты

    std::cout << "Set: ";
    for (int x : s1) std::cout << x << " "; // 1 2 5 8

    std::cout << "\nMultiset: ";
    for (int x : ms1) std::cout << x << " "; // 1 2 5 5
}
*/

/*
? insert - Добавление элементов

std::set<int> s;
s.insert(10);
s.insert(5);
s.insert(20);
/ s = {5, 10, 20}
*/

/*
? erase - Удаление элементов

std::set<int> s = {5, 10, 15, 20};
s.erase(10); // Удаляет 10
s.erase(s.begin()); // Удаляет первый элемент (5)
/ s = {15, 20}
*/

/*
? find, count - Проверка наличия элемента

std::set<int> s = {1, 2, 3, 4};
if (s.find(3) != s.end()) {
    std::cout << "3 found!" << std::endl;
}
if (s.count(5) == 0) {
    std::cout << "5 not found!" << std::endl;
}
*/

/*
? size, empty - Размер и проверка на пустоту

std::set<int> s = {1, 2, 3};
std::cout << "Size: " << s.size() << std::endl; // 3
std::cout << "Is empty? " << (s.empty() ? "Yes" : "No") << std::endl; // No
*/

/*
? clear - Очистка

std::set<int> s = {1, 2, 3};
s.clear();
std::cout << s.size(); // 0
*/

/*
? lower_bound, upper_bound - Верхняя и нижняя границы

std::set<int> s = {10, 20, 30, 40};
auto lb = s.lower_bound(20); // Первый элемент >=20 (20)
auto ub = s.upper_bound(20); // Первый элемент >20 (30)
std::cout << *lb << " " << *ub; // 20 30
*/

/*
? equal_range - Диапазон элементов

std::multiset<int> ms = {10, 20, 20, 30};
auto [first, last] = ms.equal_range(20); // Все элементы со значением 20
for (auto it = first; it != last; ++it) {
    std::cout << *it << " "; // 20 20
}
*/

/*
? begin, end, rbegin, rend - Обход элементов

std::set<int> s = {1, 2, 3, 4};
for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << " "; // 1 2 3 4
}
for (auto it = s.rbegin(); it != s.rend(); ++it) {
    std::cout << *it << " "; // 4 3 2 1 (обратный порядок)
}
*/

/*
? ==, !=, <, > - Сравнение

std::set<int> s1 = {1, 2, 3};
std::set<int> s2 = {3, 2, 1};
if (s1 == s2) {
    std::cout << "Sets are equal!"; // Да, порядок не важен
}
*/

/*
? swap - Обмен

std::set<int> s1 = {1, 2, 3};
std::set<int> s2 = {4, 5};
s1.swap(s2); // Теперь s1 = {4, 5}, s2 = {1, 2, 3}
*/

/*
? extract - Извлечение узлов (C++17)

std::set<int> s = {1, 2, 3};
auto node = s.extract(2); // Удаляет 2, но сохраняет узел
s.insert(std::move(node)); // Можно вставить обратно
*/

/*
? emplace_hint - Вставка с подсказкой

std::set<int> s = {1, 3, 5};
auto it = s.find(3);
s.emplace_hint(it, 2); // Вставляет 2 рядом с 3 (оптимизация)
/ s = {1, 2, 3, 5}
*/

/*
todo  Максимальный и минимальный элементы

std::set<int> s = {5, 2, 8, 1};
if (!s.empty()) {
    std::cout << "Min: " << *s.begin() << std::endl; // 1
    std::cout << "Max: " << *s.rbegin() << std::endl; // 8
}
*/

/*
todo Вставка нескольких элементов (insert с диапазоном)
Можно вставлять элементы из другого контейнера.

std::set<int> s = {1, 2, 3};
std::vector<int> v = {4, 5, 1}; // 1 уже есть, не добавится
s.insert(v.begin(), v.end()); // s = {1, 2, 3, 4, 5}
*/

/*
? merge - Слияние (C++17)
Можно объединять два set или multiset.
Элементы, которые уже есть в целевом контейнере, остаются в исходном.

std::set<int> s1 = {1, 2, 3};
std::set<int> s2 = {3, 4, 5};
s1.merge(s2);
/ s1 = {1, 2, 3, 4, 5}, s2 = {3} (3 уже был в s1)
*/

#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> set1;
    set1.insert(4);
    set1.insert(1);
    set1.insert(3);
    set1.insert(3);
    set1.insert(3);
    set1.insert(1);
    set1.insert(2);
    set1.insert(5);
    for(auto i=set1.begin();i!=set1.end();i++)
    cout<<*i<<' ';
    cout<<'\n';

    if(set1.count(1))
    cout<<"Элемент найден"<<'\n';
    else
    cout<<"Элемент не найден"<<'\n';

    set1.erase(1);
    for(auto i=set1.begin();i!=set1.end();i++)
    cout<<*i<<' ';
    cout<<'\n';

    auto x=set1.lower_bound(1);
    cout<<*x<<'\n';
    x=set1.upper_bound(4);
    cout<<*x<<'\n';

    set1.clear();
    if(set1.empty())
    cout<<"Пусто"<<'\n';
    else
    cout<<"Не пусто"<<'\n';

    set<int> set2{10,20,30,40,50};
    set1.swap(set2);
    for(auto i=set1.begin();i!=set1.end();i++)
    cout<<*i<<' ';
    cout<<'\n';
}