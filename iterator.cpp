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
