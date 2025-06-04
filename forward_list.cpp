/*
? forward_list() – создает пустой список

#include <forward_list>
#include <iostream>

int main() {
    std::forward_list<int> flist;  // Пустой список
    std::cout << "Empty: " << std::boolalpha << flist.empty() << std::endl;
    return 0;
}
    Вывод: Empty: true
*/

/*
? forward_list(size_type n) – создает список из n элементов

std::forward_list<int> flist(5);  // Список из 5 нулей
for (int x : flist) std::cout << x << " ";
Вывод: 0 0 0 0 0
*/

/*
? forward_list(size_type n, const T& value) – создает список из n элементов со значением value

std::forward_list<int> flist(3, 42);  // 3 элемента со значением 42
for (int x : flist) std::cout << x << " ";
Вывод: 42 42 42
*/

/*
? empty() – проверяет, пуст ли список

std::forward_list<int> flist;
std::cout << flist.empty();  // true
flist.push_front(10);
std::cout << flist.empty();  // false
*/

/*
? max_size() – возвращает максимально возможный размер списка
std::cout << flist.max_size();
*/

/*
? front() – доступ к первому элементу

std::forward_list<int> flist = {10, 20, 30};
std::cout << flist.front();  // 10
*/

/*
? push_front(const T& value) – добавляет элемент в начало

std::forward_list<int> flist;
flist.push_front(10);
flist.push_front(20);
Вывод: flist: 20 → 10
*/

/*
? pop_front() – удаляет первый элемент
flist.pop_front();  // Удаляет 20, остается {10}
*/

/*
? insert_after() – вставляет элемент после указанной позиции

auto it = flist.begin();  // Итератор на первый элемент
flist.insert_after(it, 30);  // 10 → 30
flist.insert_after(it, 20);  // 10 → 20 → 30
*/

/*
? erase_after() – удаляет элемент после указанной позиции
flist.erase_after(it);  // Удаляет 20, остается 10 → 30
*/

/*
? clear() – очищает список
flist.clear();
*/

/*
? merge() – объединяет два отсортированных списка

std::forward_list<int> list1 = {1, 3, 5};
std::forward_list<int> list2 = {2, 4, 6};
list1.merge(list2);  // list1: 1 → 2 → 3 → 4 → 5 → 6
*/

/*
? sort() – сортирует список
std::forward_list<int> flist = {3, 1, 2};
flist.sort();  // 1 → 2 → 3
*/

/*
? reverse() – переворачивает список
flist.reverse();  // 3 → 2 → 1
*/

/*
? unique() – удаляет повторяющиеся элементы
std::forward_list<int> flist = {1, 1, 2, 3, 3};
flist.unique();  // 1 → 2 → 3
*/

/*
? remove(const T& value) – удаляет все элементы со значением value
flist.remove(2);  // Удаляет все двойки
*/

/*
? splice_after() – перемещает элементы из другого списка

std::forward_list<int> list1 = {1, 2, 3};
std::forward_list<int> list2 = {4, 5};
auto it = list1.begin();
list1.splice_after(it, list2);  // list1: 1 → 4 → 5 → 2 → 3
*/

/*
? begin(), end() – возвращают итераторы

std::forward_list<int> flist = {10, 20, 30};
for (auto it = flist.begin(); it != flist.end(); ++it) {
    std::cout << *it << " ";
}
    Вывод: 10 20 30
*/

/*
? assign() – заменяет содержимое списка
Есть две версии:

assign(size_type n, const T& value) – заполняет n элементов значением value.

assign(InputIt first, InputIt last) – копирует элементы из диапазона [first,
last).

Пример 1: Заполнение n одинаковых элементов
std::forward_list<int> flist;
flist.assign(3, 100);  // 100 → 100 → 100

Пример 2: Копирование из другого контейнера
std::vector<int> vec = {1, 2, 3};
flist.assign(vec.begin(), vec.end());  // 1 → 2 → 3

Пример 3: Копирование из initializer_list
flist.assign({4, 5, 6});  // 4 → 5 → 6
*/

/*
? resize() – изменяет количество элементов
Если новый размер больше, добавляются элементы с значением по умолчанию.
Если меньше – лишние элементы удаляются.

std::forward_list<int> flist = {1, 2, 3};
flist.resize(5);      // 1 → 2 → 3 → 0 → 0
flist.resize(2);      // 1 → 2
*/

/*
? insert_after() с диапазоном

std::forward_list<int> flist = {1, 2, 3};
auto it = flist.begin();
std::vector<int> vec = {10, 20};
flist.insert_after(it, vec.begin(), vec.end());  // 1 → 10 → 20 → 2 → 3
*/

/*
? erase_after() с диапазоном

auto it2 = flist.begin();
std::advance(it2, 2);  // Перемещаем итератор на 2 позиции
flist.erase_after(it, it2);  // Удаляет элементы после `it` до `it2`: 1 → 20 → 2 → 3
*/

/*
? swap - Обмен содержимого

std::forward_list<int> list1 = {1, 2, 3};
std::forward_list<int> list2 = {4, 5};
list1.swap(list2);  // Теперь list1 = {4, 5}, list2 = {1, 2, 3}
*/

/*
? remove_if - Удаление элементов по условию
std::forward_list<int> flist = {1, 2, 3, 4, 5};
flist.remove_if([](int x) { return x % 2 == 0; });  // Удаляет четные: 1 → 3 → 5
*/

/*
? ==, !=, <, >, <=, >= - Сравнение списков
std::forward_list<int> list1 = {1, 2, 3};
std::forward_list<int> list2 = {1, 2, 3};
std::cout << (list1 == list2);  // true
*/