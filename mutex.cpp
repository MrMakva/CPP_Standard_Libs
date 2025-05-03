/*
std::mutex – базовый мьютекс(нерекурсивный).

void function() {
  mtx.lock(); // Блокировка
  // Критическая секция
  mtx.unlock(); // Разблокировка
}

Опасность: Если между lock() и unlock() выбросится исключение – мьютекс останется заблокированным (deadlock).
*/

/*
std::lock_guard – автоматическое управление блокировкой (RAII).

{
    std::lock_guard<std::mutex> lock(mtx); // Блокировка при создании
    // Критическая секция
} // Автоматическая разблокировка при разрушении lock_guard

Безопасно: Разблокировка даже при исключении.
*/

/*
std::unique_lock – более гибкая версия lock_guard.
std::defer_lock //Не блокировать мьютекс сразу при создании unique_lock.
                //Блокировку нужно выполнить вручную позже (lock(), try_lock()).

std::try_to_lock    //Попытаться захватить мьютекс без блокировки потока (не ждать, если он занят).
                    //Проверить успешность через owns_lock().

std::adopt_lock //Принять уже заблокированный мьютекс (предполагается, что он был заблокирован ранее, например, через mtx.lock() или std::lock).
                //unique_lock не будет пытаться заблокировать его снова, но разблокирует при разрушении.

Использовать с std::condition_variable.

std::mutex mtx;
std::unique_lock<std::mutex> ulock(mtx, std::defer_lock); // Не блокирует сразу
ulock.lock(); // Блокировка вручную
// ...
ulock.unlock(); // Можно разблокировать раньше

Гибкость: Подходит для сложных сценариев.
*/

/*
std::recursive_mutex – рекурсивный мьютекс (один поток может блокировать его несколько раз).

std::recursive_mutex rmtx;

void foo() {
    std::lock_guard<std::recursive_mutex> lock(rmtx);
    bar(); // Может снова заблокировать тот же мьютекс
}

void bar() {
    std::lock_guard<std::recursive_mutex> lock(rmtx);
}
*/

/*
std::timed_mutex и std::recursive_timed_mutex – мьютексы с таймаутом.

std::timed_mutex tmtx;

if (tmtx.try_lock_for(std::chrono::milliseconds(100))) {
    // Успешная блокировка
    tmtx.unlock();
} else {
    // Не удалось заблокировать за 100 мс
}
*/

/*
std::lock(mutex1, mutex2, ...) – безопасно блокирует несколько мьютексов без deadlock.
std::try_lock(mutex1, mutex2, ...) – пытается заблокировать несколько мьютексов.

std::mutex mtx1, mtx2;
{
    std::lock(mtx1, mtx2); // Блокировка обоих атомарно
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock); // Принимает владение
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    // ...
} // Автоматическая разблокировка
*/

#include<iostream>
#include<mutex>
#include<thread>
#include<vector>
using namespace std;

class BankAccount
{
    public:
    double balance;
    mutex mtx;

    BankAccount(double balance):balance(balance){}

    void deposit(double amount)
    {
        lock_guard<mutex> lock(mtx);
        balance+=amount;
        cout<<"Счет пополнен, сумма на счете: "<<balance<<'\n';
    }

    void withdraw(double amount)
    {
      lock_guard<mutex> lock(mtx);
      if (balance < amount)
        cout<<"Недостаточно средств!"<<'\n';
        else
        {
          balance -= amount;
          cout << "Сумма списания: " << amount << '\n'
               << "Средств на счете: " << balance << '\n';
        }
    }

    void transfer(BankAccount &to,double amount)
    {
      lock_guard<mutex> lock(mtx, adopt_lock);
      lock_guard<mutex> lock1(to.mtx, adopt_lock);
      // unique_lock<mutex> ulock(mtx3,defer_lock);
      // ulock.lock();
      if (balance < amount)
        cout << "Недостаточно средств!" << '\n';
        else {
            balance-=amount;
            to.balance+=amount;
            cout<<"Средства переведены"<<'\n';
        }
        // ulock.unlock();
    }
};

void tmpdip(BankAccount& acc,double n)
{
    acc.deposit(n);
}

void tmpwith(BankAccount& acc,double n)
{
    acc.withdraw(n);
}

void tmptran(BankAccount& acc,BankAccount& to,double n)
{
    acc.transfer(to,n);
}

int main()
{
    BankAccount Dima(50);
    BankAccount Oleg(0);
    vector<thread> th;

    th.emplace_back([&Dima](){
        for(int i=0;i<100;i++)
        Dima.deposit(1.0);
    });

    th.emplace_back([&Dima](){
        for(int i=0;i<100;i++)
        Dima.withdraw(1.0);
    });

    th.emplace_back([&Dima,&Oleg](){
        for(int i=0;i<40;i++)
        Dima.transfer(Oleg,1.0);
    });

    for(auto& i:th)
    i.join();

    cout<<Dima.balance<<'\n';
    cout<<Oleg.balance<<'\n';
}