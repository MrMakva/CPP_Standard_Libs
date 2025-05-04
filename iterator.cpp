/*
Функции для работы с итераторами
std::advance(it, n) – перемещает итератор it на n позиций.
std::distance(first, last) – возвращает количество элементов между first и last.
std::next(it, n) – возвращает итератор, сдвинутый на n позиций вперёд.
std::prev(it, n) – возвращает итератор, сдвинутый на n позиций назад.

Адаптеры итераторов
std::back_inserter(container) – создаёт итератор, добавляющий элементы в конец
контейнера (через push_back).
std::front_inserter(container) – создаёт итератор, добавляющий элементы в начало
(через push_front).
std::inserter(container, pos) – вставляет элементы в произвольную позицию.

Stream-итераторы (для работы с потоками)
std::istream_iterator<T> – итератор для чтения данных из потока (например, cin).
std::ostream_iterator<T> – итератор для вывода данных в поток (например, cout).

Обратные итераторы
std::reverse_iterator – позволяет обходить контейнер в обратном порядке.
rbegin(), rend() – возвращают обратные итераторы.

Итераторы перемещения (C++11)
std::make_move_iterator(it) – превращает итератор в перемещающий (полезно для семантики перемещения).
*/

//zzzz

/*
? std::advance(it, n)
Увеличивает (или уменьшает, если n отрицательное) итератор на n позиций.

#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin();
    std::advance(it, 2); // Перемещаем итератор на 2 позиции вперёд
    std::cout << *it << std::endl; // Выведет: 3
    return 0;
}
*/

/*
? std::distance(it1, it2)
Возвращает количество элементов между двумя итераторами.

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    auto it1 = vec.begin();
    auto it2 = vec.end();
    std::cout << "Distance: " << std::distance(it1, it2) << std::endl; //
Выведет: 5 return 0;
}
*/

/*
? std::next(it, n)
Возвращает итератор, сдвинутый на n позиций вперёд (по умолчанию n = 1).

#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec = {5, 6, 7, 8, 9};
    auto it = vec.begin();
    auto next_it = std::next(it, 3); // Сдвигаем на 3 позиции
    std::cout << *next_it << std::endl; // Выведет: 8
    return 0;
}
*/

/*
? std::prev(it, n)
Возвращает итератор, сдвинутый на n позиций назад (по умолчанию n = 1).

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> vec = {100, 200, 300, 400};
    auto it = vec.end();
    auto prev_it = std::prev(it, 2); // Сдвигаем на 2 позиции назад
    std::cout << *prev_it << std::endl; // Выведет: 300
    return 0;
}
*/

/*
? std::begin(container) и std::end(container)
Возвращают итераторы на начало и конец контейнера (работают и с массивами).

#include <iostream>
#include <iterator>
#include <array>

int main() {
    std::array<int, 3> arr = {7, 8, 9};
    auto first = std::begin(arr); // Итератор на начало
    auto last = std::end(arr);    // Итератор на конец
    std::cout << *first << " " << *(last - 1) << std::endl; // Выведет: 7 9
    return 0;
}
*/

/*
? std::rbegin(container) и std::rend(container)
Возвращают обратные итераторы (для обхода контейнера в обратном порядке).
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};
    for (auto it = std::rbegin(vec); it != std::rend(vec); ++it) {
        std::cout << *it << " "; // Выведет: 4 3 2 1
    }
    return 0;
}
*/

/*
? std::back_inserter(container)
Создает итератор для вставки в конец контейнера (используется с алгоритмами).

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> src = {1, 2, 3};
    std::vector<int> dest;
    std::copy(src.begin(), src.end(), std::back_inserter(dest));
    for (int x : dest) std::cout << x << " "; // Выведет: 1 2 3
    return 0;
}
*/

/*
? std::front_inserter(container)
Создает итератор для вставки в начало (работает с std::list, std::deque).

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

int main() {
    std::list<int> lst = {3, 4, 5};
    std::front_inserter inserter(lst);
    *inserter = 2; // Вставляем в начало
    *inserter = 1;
    for (int x : lst) std::cout << x << " "; // Выведет: 1 2 3 4 5
    return 0;
}
*/

/*
? std::inserter(container, pos)
Вставляет элементы в произвольную позицию.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

int main() {
    std::set<int> s = {1, 3, 5};
    auto it = s.find(3);
    std::inserter inserter(s, it);
    *inserter = 2; // Вставляем перед 3
    *inserter = 4;
    for (int x : s) std::cout << x << " "; // Выведет: 1 2 3 4 5
    return 0;
}
*/

/*
? std::make_reverse_iterator(it)
Создает обратный итератор из обычного (можно использовать для реверсного
обхода).

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40};
    auto it = vec.end();
    auto rev_it = std::make_reverse_iterator(it); // Создаем обратный итератор
    std::cout << *rev_it << std::endl; // Выведет: 40 (последний элемент)
    return 0;
}
*/

/*
? std::size(container) и std::empty(container) (C++17)
Возвращают размер и проверяют пустоту контейнера (работают и с массивами).

#include <array>
#include <iostream>
#include <iterator>

int main() {
    std::array<int, 4> arr = {1, 2, 3, 4};
    std::cout << "Size: " << std::size(arr) << std::endl; // Выведет: 4
    std::cout << "Empty? " << std::empty(arr) << std::endl; // Выведет: 0
(false) return 0;
}
*/

/*
? std::data(container) (C++17)
Возвращает указатель на начало данных контейнера (аналог .data() у вектора).

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> vec = {5, 6, 7, 8};
    int* ptr = std::data(vec); // Указатель на данные
    std::cout << ptr[2] << std::endl; // Выведет: 7
    return 0;
}
*/

/*
? Итерационные категории (Iterator Tags)
Теги для классификации итераторов:

std::input_iterator_tag
std::output_iterator_tag
std::forward_iterator_tag
std::bidirectional_iterator_tag
std::random_access_iterator_tag
метапрограммирование

#include <iostream>
#include <iterator>
#include <vector>

template <typename Iter>
void check_iterator_type(Iter it) {
    using Category = typename std::iterator_traits<Iter>::iterator_category;
    if constexpr (std::is_same_v<Category, std::random_access_iterator_tag>) {
        std::cout << "Random Access Iterator" << std::endl;
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    check_iterator_type(vec.begin()); // Выведет: "Random Access Iterator"
    return 0;
}
*/

/*
? std::iterator_traits<Iter>
Позволяет получить свойства итератора (тип значения, категорию и т.д.).

#include <iostream>
#include <iterator>
#include <list>

int main() {
    using Iter = std::list<int>::iterator;
    using ValueType = typename std::iterator_traits<Iter>::value_type;
    std::cout << "Value type: " << typeid(ValueType).name() << std::endl; //
Выведет: int return 0;
}
*/

/*
? std::move_iterator
Обертка для итератора, которая перемещает элементы (вместо копирования).

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<std::string> src = {"Hello", "World"};
    std::vector<std::string> dest;
    auto move_it = std::make_move_iterator(src.begin());
    dest.push_back(*move_it); // Перемещаем "Hello"
    std::cout << "Src after move: " << src[0] << std::endl; // Пустая строка
    std::cout << "Dest: " << dest[0] << std::endl; // Выведет: Hello
    return 0;
}
*/

/*
? std::ostream_iterator
Итератор для вывода элементов в поток (например, std::cout).

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};
    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<int>(std::cout, " ")); // Выведет: 1 2 3 4
    return 0;
}
*/

/*
? std::istream_iterator
Итератор для чтения данных из потока (например, std::cin).

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::istream_iterator<int> input_it(std::cin); // Чтение чисел из ввода
    std::istream_iterator<int> end_it;
    std::vector<int> numbers(input_it, end_it); // Заполняем вектор до конца ввода
    for (int x : numbers) std::cout << x << " ";
    return 0;
}
*/

/*
? std::reverse_iterator
Обертка для обратного обхода контейнера.

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};
    std::reverse_iterator<std::vector<int>::iterator> rev_it(vec.end());
    std::cout << *rev_it << std::endl; // Выведет: 4
    return 0;
}
*/

/*
? std::move_sentinel (C++20)
Парный элемент для std::move_iterator, обозначающий конец диапазона перемещения.

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<std::string> src = {"A", "B", "C"};
    std::vector<std::string> dest;
    auto move_first = std::make_move_iterator(src.begin());
    auto move_last = std::make_move_iterator(src.end());
    dest.assign(move_first, move_last); // Перемещаем все элементы
    std::cout << "Src after move: " << src[0] << std::endl; // Пустая строка
    std::cout << "Dest: " << dest[0] << std::endl; // Выведет: A
    return 0;
}
*/

/*
? std::common_iterator (C++20)
Обертка для итераторов разных типов (например, итератора и
std::default_sentinel).

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};
    auto it = std::common_iterator(vec.begin(), std::default_sentinel);
    while (it != std::default_sentinel) {
        std::cout << *it++ << " "; // Выведет: 1 2 3
    }
    return 0;
}
*/

/*
? std::counted_iterator (C++20)
Итератор, отслеживающий оставшееся количество элементов.

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    auto counted_it = std::counted_iterator(vec.begin(), 3); // Ограничиваем 3 элементами
    while (counted_it.count() > 0) {
        std::cout << *counted_it++ << " "; // Выведет: 10 20 30
    }
    return 0;
}
*/

/*
? std::unreachable_sentinel (C++20)
Специальный sentinel, обозначающий "бесконечный" диапазон (используется для
оптимизации).

#include <iostream>
#include <iterator>
#include <algorithm>

int main() {
    int arr[] = {5, 10, 15};
    auto it = std::begin(arr);
    Предполагаем, что диапазон не проверяется (опасно, но быстро)
    while (it != std::unreachable_sentinel) {
        std::cout << *it++ << " "; // Выведет: 5 10 15 (но может привести к UB!)
        if (it == std::end(arr)) break; // Вручную проверяем конец
    }
    return 0;
}
*/

/*
? std::back_insert_iterator и std::front_insert_iterator
Альтернативные имена для std::back_inserter и std::front_inserter.

#include <deque>
#include <iostream>
#include <iterator>

int main() {
    std::deque<int> dq;
    auto back_it = std::back_insert_iterator(dq);
    *back_it = 42; // Вставляет 42 в конец
    auto front_it = std::front_insert_iterator(dq);
    *front_it = 7; // Вставляет 7 в начало
    for (int x : dq) std::cout << x << " "; // Выведет: 7 42
    return 0;
}
*/

/*
? std::insert_iterator
Альтернативное имя для std::inserter.

#include <iostream>
#include <iterator>
#include <set>

int main() {
    std::set<int> s = {1, 3, 5};
    auto it = s.insert(2).first; // Вставляем 2 и получаем итератор
    auto insert_it = std::insert_iterator(s, it);
    *insert_it = 4; // Вставляем 4 после 2
    for (int x : s) std::cout << x << " "; // Выведет: 1 2 3 4 5
    return 0;
}
*/

/*
? std::default_sentinel (C++20)
Sentinel по умолчанию для обозначения конца диапазона.

#include <array>
#include <iostream>
#include <iterator>

int main() {
    std::array<int, 3> arr = {8, 9, 10};
    auto it = std::begin(arr);
    while (it != std::default_sentinel) {
        std::cout << *it++ << " "; // Выведет: 8 9 10
        if (it == std::end(arr)) break;
    }
    return 0;
}
*/

/*
? std::iter_value_t, std::iter_reference_t (C++20)
Утилиты для получения типа значения и ссылки итератора.

#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<float> vec = {1.1f, 2.2f};
    using Iter = decltype(vec.begin());
    std::cout << std::boolalpha;
    std::cout << "Same as float? " 
              << std::is_same_v<std::iter_value_t<Iter>, float> << std::endl; // true
    return 0;
}
*/

/*
? std::contiguous_iterator концепт (C++20)
Проверяет, является ли итератор контейнера с непрерывным хранением данных (как у
vector, array).

#include <iterator>
#include <vector>
#include <list>

int main() {
    static_assert(std::contiguous_iterator<std::vector<int>::iterator>); // OK
    static_assert(!std::contiguous_iterator<std::list<int>::iterator>); // Ошибка: list не непрерывный
    return 0;
}
*/

/*
? std::indirectly_readable и std::indirectly_writable концепты (C++20)
Проверяют, можно ли читать/писать значение через итератор.

#include <iterator>
#include <vector>

int main() {
    static_assert(std::indirectly_readable<std::vector<int>::iterator>); // OK
    static_assert(std::indirectly_writable<std::vector<int>::iterator, int>); // OK
    return 0;
}
*/

/*
? std::iter_move и std::iter_swap (C++20)
Оптимизированные операции перемещения/обмена через итераторы.

#include <iterator>
#include <vector>

int main() {
    std::vector<std::string> vec = {"A", "B"};
    std::iter_swap(vec.begin(), vec.begin() + 1); // Обмен
    // vec = {"B", "A"}

    auto moved = std::iter_move(vec.begin()); // Перемещение
    // moved = "B", vec[0] - в valid but unspecified state
    return 0;
}
*/
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

int main() {
  vector<int> data = {1, 2, 3, 4, 5};
  auto it = data.begin();

  // Простые перемещения
  //Чтобы it сдвинулся с помощью next, prev нужно использовать присвоение
  advance(it, 3);
  cout << "Итератор указывает на элемент: " << *it << '\n';
  it = next(it, 1);
  cout << "Итератор указывает на элемент: " << *it << '\n';
  it = prev(it, 2);
  cout << "Итератор указывает на элемент: " << *it << '\n';
  int tmp = distance(data.begin(), it);
  cout << "Расстояние от начало вектора и до итератора " << tmp << '\n';

  /*Копирование из одного массива в другой с помощью:
    back_inserter, front_inserter, inserter
    с помощью inserter можно вставить элемент в точку куда указывает итератор
    */
list<int> list;
it = data.begin();
it = next(it, 1);
copy(data.begin(), it, back_inserter(list));
cout << "Элементы list: ";
for (auto i = list.begin(); i != list.end(); i++) {

  cout << *i;
  }
  cout << '\n';

  it=data.begin();
  it=next(it,4);
  copy(it, data.end(), front_inserter(list));
  cout << "Элементы list: ";
  for (auto i = list.begin(); i != list.end(); i++) {

    cout << *i;
  }
  cout << '\n';

  it = data.begin();
  it = next(it,2);
  copy(it, next(it,1), inserter(list,list.end()));
  cout << "Элементы list: ";
  for (auto i = list.begin(); i != list.end(); i++) {

    cout << *i;
  }
  cout << '\n';

  //Потоковый ввод (через пробел числа записываются в ячейки по порядку)
  vector<int> in;
  copy(
  istream_iterator<int>(cin),
  istream_iterator<int>(),
  back_inserter(in)
  );
  for (auto i = in.begin(); i != in.end(); i++) {

    cout << *i << ", ";
  }
  cout << '\n';

  // Обратный вывод с помощью rbegin, rend
  vector<int> d = { 10, 20, 30, 40, 50 };
  cout<<"Обратный вывод: ";
  for (auto i = d.rbegin(); i != d.rend(); i++) {

    cout << *i<<", ";
  }
  cout << '\n';

  //Пернос из данных из вектора в вектор
  //При переносе int, char, float массив донор не будет очищен
  vector<string> s = { "A", "B", "C" };
  vector<string> s1;
  auto its=s.begin();
  copy(
  make_move_iterator(s.begin()),
  make_move_iterator(s.end()),
  back_inserter(s1)
  );

  cout << "Изначальный массив: ";
  for (auto i = s.begin(); i != s.end(); i++) {

    cout << *i << ", ";
  }
  cout << '\n';

  cout<<"Массив получатель: ";
  for(auto i =s1.begin();i!=s1.end();i++)
  {
    cout << *i << ", ";
  }
  cout << '\n';
}
