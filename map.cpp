#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string potok;
  int deysvie;
  int id;
  string name;
  map<int, string> study;
  while (1) {
    cout << "Выберите действие:\n"
         << "1 - Добавить студента\n"
         << "2 - Найти студента по айди\n"
         << "3 - Удалить студента по айди\n"
         << "4 - Отобразить всех студентов\n"
         << "5 - Проверка на пустоту базы данных\n"
         << "6 - Очистить базу данных\n"
         << "7 - Вывести количество студентов из базы данных\n"
         << "0 - Завершить программу\n";
    cin >> deysvie;
    cin.ignore();
    if (deysvie == 1) {
      cout << "Введите айди и имя студента для добавления в базу:\n";
      getline(cin,potok);
      istringstream iss(potok);
      if(iss >> id >> name){
      if (study.count(id))
        cout << "Такой айди уже занят:\n";
      else
        study.emplace(id, name);
      }
      else
      cout<<"Ошибка ввода!\n";
    }

    if (deysvie == 2) {
      cout << "Введите айди студента для поиска по базе:\n";
      cin >> id;
      if (study.count(id)) {
        cout << "Студент найден: \n";
        auto iterator = study.find(id);
        cout << "id: " << iterator->first << "  name: " << iterator->second
             << '\n';
      } else
        cout << "Студент не найден\n";
    }

    if (deysvie == 3) {
      cout << "Введите айди студента для удаления из базы:\n";
      cin >> id;
      if (study.count(id)) {
        cout << "Студент найден и удален: \n";
        study.erase(id);
      } else
        cout << "Студент не найден\n";
    }

    if (deysvie == 4) {
      cout << "Студенты в базе данных:\n";
      for (auto i = study.begin(); i != study.end(); i++)
        cout << "id: " << i->first << "name: " << i->second << '\n';
    }

    if (deysvie == 5) {
      if (study.empty())
        cout << "База данных пустая\n";
      else
        cout << "База данных не пустая\n";
    }

    if (deysvie == 6) {
      study.clear();
      cout << "База данных удалена\n";
    }

    if (deysvie == 7)
      cout << "Количество студентов в базе: \n" << study.size() << '\n';

    if (deysvie == 0) {
      cout << "Программа завершила свою работу\n";
      break;
    }
  }
}
