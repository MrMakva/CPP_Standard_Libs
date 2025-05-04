/*
? list<T>() – создает пустой список.
list<T>(size_type n) – создает список из n элементов.
list<T>(size_type n, const T& value) – создает список из n элементов со
значением value.
list<T>(InputIterator first, InputIterator last) – создает список из диапазона
итераторов.

#include <list>
#include <iostream>

int main() {
    std::list<int> l1;                  // Пустой список
    std::list<int> l2(5);               // Список из 5 нулей
    std::list<int> l3(3, 10);           // Список из трех десяток
    std::list<int> l4(l3.begin(), l3.end());  // Копия l3

    for (int x : l3) std::cout << x << " ";  // 10 10 10
    return 0;
}
*/

/*
? push_back(const T& value) – добавляет элемент в конец.
? push_front(const T& value) – добавляет элемент в начало.
? insert(iterator pos, const T& value) – вставляет элемент перед позицией pos.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums = {1, 2, 3};
    nums.push_back(4);      // [1, 2, 3, 4]
    nums.push_front(0);     // [0, 1, 2, 3, 4]
    auto it = nums.begin();
    ++it;
    nums.insert(it, 99);    // [0, 99, 1, 2, 3, 4]

    for (int x : nums) std::cout << x << " ";  // 0 99 1 2 3 4
    return 0;
}
*/

/*
? pop_back() – удаляет последний элемент.
? pop_front() – удаляет первый элемент.
? erase(iterator pos) – удаляет элемент на позиции pos.
? erase(iterator first, iterator last) – удаляет диапазон.
? clear() – очищает весь список.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums = {1, 2, 3, 4, 5};
    nums.pop_back();        // [1, 2, 3, 4]
    nums.pop_front();       // [2, 3, 4]
    auto it = nums.begin();
    ++it;
    nums.erase(it);         // [2, 4]
    nums.clear();           // []

    std::cout << nums.size();  // 0
    return 0;
}
*/

/*
? front() – возвращает первый элемент.
? back() – возвращает последний элемент.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums = {10, 20, 30};
    std::cout << nums.front() << "\n";  // 10
    std::cout << nums.back() << "\n";   // 30
    return 0;
}
*/

/*
? size() – возвращает количество элементов.
? empty() – проверяет, пуст ли список.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums = {1, 2, 3};
    std::cout << nums.size() << "\n";  // 3
    std::cout << nums.empty() << "\n"; // 0 (false)
    return 0;
}
*/

/*
? sort() – сортирует список.
? reverse() – переворачивает список.
? unique() – удаляет дубликаты (только если они идут подряд).
? merge(list& other) – сливает два отсортированных списка.
? splice(iterator pos, list& other) – перемещает элементы из other в текущий список.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums = {3, 1, 2};
    nums.sort();                     // [1, 2, 3]
    nums.reverse();                  // [3, 2, 1]
    
    std::list<int> other = {5, 4};
    nums.merge(other);               // [3, 2, 1, 5, 4] (если не отсортированы, merge может вести себя неожиданно)
    
    auto it = nums.begin();
    ++it;
    nums.splice(it, other);          // other теперь пуст, nums содержит все элементы
    
    for (int x : nums) std::cout << x << " ";  // 3 5 4 2 1
    return 0;
}
*/

/*
? begin(), end() – возвращают итераторы на начало и конец.
? rbegin(), rend() – возвращают обратные итераторы.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums = {1, 2, 3};
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        std::cout << *it << " ";  // 1 2 3
    }
    for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
        std::cout << *it << " ";  // 3 2 1
    }
    return 0;
}
*/

/*
? assign(size_type n, const T& value) – заменяет содержимое списка n копиями value.
? assign(InputIterator first, InputIterator last) – заменяет содержимое диапазоном элементов.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums = {1, 2, 3};
    nums.assign(3, 10);  // [10, 10, 10]
    
    std::list<int> other = {4, 5, 6};
    nums.assign(other.begin(), other.end());  // [4, 5, 6]
    
    for (int x : nums) std::cout << x << " ";  // 4 5 6
    return 0;
}
*/

/*
? remove(const T& value) – удаляет все элементы, равные value.
? remove_if(Predicate pred) – удаляет элементы, для которых pred возвращает true.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums = {1, 2, 3, 2, 4};
    nums.remove(2);  // Удаляет все двойки → [1, 3, 4]
    
    nums.remove_if([](int x) { return x % 2 == 0; });  // Удаляет чётные → [1, 3]
    
    for (int x : nums) std::cout << x << " ";  // 1 3
    return 0;
}
*/

/*
? swap(list& other) – обменивает содержимое двух списков.

#include <list>
#include <iostream>

int main() {
    std::list<int> a = {1, 2, 3};
    std::list<int> b = {4, 5};
    
    a.swap(b);  // Теперь a = [4, 5], b = [1, 2, 3]
    
    std::cout << "a: ";
    for (int x : a) std::cout << x << " ";  // 4 5
    
    std::cout << "\nb: ";
    for (int x : b) std::cout << x << " ";  // 1 2 3
    return 0;
}
*/

/*
? resize(size_type n) – изменяет размер списка. Если n больше текущего размера, добавляются нули.
? resize(size_type n, const T& value) – аналогично, но новые элементы инициализируются value.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums = {1, 2, 3};
    nums.resize(5);      // [1, 2, 3, 0, 0]
    nums.resize(2);      // [1, 2]
    nums.resize(4, 10);  // [1, 2, 10, 10]
    
    for (int x : nums) std::cout << x << " ";  // 1 2 10 10
    return 0;
}
*/

/*
? unique() – удаляет подряд идущие дубликаты (список должен быть отсортирован для
удаления всех дубликатов).
? sort() – сортирует элементы в порядке возрастания.
? reverse() – переворачивает список.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums = {1, 2, 2, 3, 2, 1};
    nums.sort();          // [1, 1, 2, 2, 2, 3]
    nums.unique();        // [1, 2, 3] (удаляет только подряд идущие дубли)
    
    nums.reverse();       // [3, 2, 1]
    
    for (int x : nums) std::cout << x << " ";  // 3 2 1
    return 0;
}
*/

/*
? merge(list& other) – сливает два отсортированных списка в один (после операции
other станет пустым).

? merge(list& other, Compare comp) – сливает с использованием компаратора.

#include <iostream>
#include <list>

int main() {
    std::list<int> a = {1, 3, 5};
    std::list<int> b = {2, 4, 6};

    a.merge(b);  // a = [1, 2, 3, 4, 5, 6], b = []

    std::cout << "a: ";
    for (int x : a) std::cout << x << " ";  // 1 2 3 4 5 6

    std::cout << "\nb.size(): " << b.size();  // 0
    return 0;
}
*/

/*
? splice(iterator pos, list& other) – перемещает все элементы из other в текущий
список перед pos.
? splice(iterator pos, list& other, iterator it) – перемещает только элемент, на
который указывает it.
? splice(iterator pos, list& other, iterator first, iterator last) – перемещает
диапазон.

#include <list>
#include <iostream>

int main() {
    std::list<int> a = {1, 4};
    std::list<int> b = {2, 3, 5};
    
    auto it = a.begin();
    ++it;  // Указывает на 4
    
    a.splice(it, b, b.begin(), --b.end());  // Перемещает 2 и 3 в a перед 4
    
    std::cout << "a: ";
    for (int x : a) std::cout << x << " ";  // 1 2 3 4
    
    std::cout << "\nb: ";
    for (int x : b) std::cout << x << " ";  // 5
    return 0;
}
*/

/*
? Метод sort() может принимать функцию сравнения.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums = {3, 1, 4, 2};
    nums.sort([](int a, int b) { return a > b; });  // Сортировка по убыванию
    
    for (int x : nums) std::cout << x << " ";  // 4 3 2 1
    return 0;
}
*/

/*
? Списки можно сравнивать операторами ==, !=, <, >, <=, >=.

#include <list>
#include <iostream>

int main() {
    std::list<int> a = {1, 2, 3};
    std::list<int> b = {1, 2, 3};
    std::list<int> c = {4, 5};
    
    std::cout << (a == b) << "\n";  // 1 (true)
    std::cout << (a < c) << "\n";   // 1 (true, лексикографическое сравнение)
    return 0;
}
*/

/*
? get_allocator() – возвращает аллокатор, используемый списком.

#include <list>
#include <iostream>

int main() {
    std::list<int> nums;
    auto alloc = nums.get_allocator();
    int* p = alloc.allocate(1);  // Выделяем память под 1 int
    alloc.deallocate(p, 1);      // Освобождаем
    return 0;
}
*/

/*
? emplace_front(Args&&... args) – создает элемент в начале списка без копирования.
? emplace_back(Args&&... args) – создает элемент в конце списка без копирования.
? emplace(iterator pos, Args&&... args) – вставляет элемент перед pos без
копирования.

#include <list>
#include <iostream>

struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
};

int main() {
    std::list<Point> points;
    points.emplace_back(1, 2);    // Эквивалентно points.push_back(Point(1, 2))
    points.emplace_front(3, 4);   // Эквивалентно points.push_front(Point(3, 4))
    
    auto it = points.begin();
    points.emplace(it, 5, 6);     // Вставляем перед первым элементом
    
    for (const auto& p : points) {
        std::cout << "(" << p.x << ", " << p.y << ") ";  // (5,6) (3,4) (1,2)
    }
    return 0;
}
*/

/*
? Особые случаи splice
Можно перемещать элементы между разными списками.
Можно перемещать один элемент или диапазон.

#include <list>
#include <iostream>

int main() {
    std::list<int> a = {1, 2, 3};
    std::list<int> b = {4, 5, 6};
    
    auto it_a = std::next(a.begin(), 1);  // Указывает на 2
    auto it_b = std::next(b.begin(), 1);  // Указывает на 5
    
    a.splice(it_a, b, it_b);  // Перемещаем 5 из b в a перед 2
    
    std::cout << "a: ";
    for (int x : a) std::cout << x << " ";  // 1 5 2 3
    
    std::cout << "\nb: ";
    for (int x : b) std::cout << x << " ";  // 4 6
    return 0;
}
*/
#include<iostream>
#include<list>

using namespace std;
int main()
{
    list<int> list1;
    for(int i=1;i<=5;i++)
    list1.push_back(i*10);
    auto indif=list1.begin();
    cout<<*indif<<' ';
    for(int i=1;i<5;i++)
    {
        indif++;
        cout<<*indif<<' ';
    }
    cout<<'\n';

    list1.push_front(5);
    advance(indif,3);
    list1.insert(indif,25);
    list1.pop_back();
    list1.remove(30);
    for(auto it=list1.begin();it!=list1.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<'\n';

    list1.sort();
    list1.reverse();
    for(auto it=list1.begin();it!=list1.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<'\n';

    list<int>list2({100,200,300});
    list1.merge(list2);
        for(auto it=list1.begin();it!=list1.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<'\n';

    list<int>list3({10,10,10,10,20,10,20,10,20});
    list1.merge(list3);
    list1.unique();
        for(auto it=list1.begin();it!=list1.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<'\n';
    list1.sort();
    list1.unique();
        for(auto it=list1.begin();it!=list1.end();it++)
    {
        cout<<*it<<' ';
    }
    cout<<'\n';
}