/*
? std::mutex - базовый мьютекс

#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void print_block(int n, char c) {
    mtx.lock();  // Блокируем мьютекс
    for (int i = 0; i < n; ++i) { std::cout << c; }
    std::cout << '\n';
    mtx.unlock();  // Разблокируем мьютекс
}

int main() {
    std::thread th1(print_block, 50, '*');
    std::thread th2(print_block, 50, '$');

    th1.join();
    th2.join();

    return 0;
}
*/

/*
? std::lock_guard - RAII-обертка для мьютекса

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_block(int n, char c) {
    std::lock_guard<std::mutex> guard(mtx);  // Автоматически блокируется при создании и разблокируется при выходе из области видимости
    for (int i = 0; i < n; ++i) { std::cout << c; }
    std::cout << '\n';
}

int main() {
    std::thread th1(print_block, 50, '*');
    std::thread th2(print_block, 50, '$');
    
    th1.join();
    th2.join();
    
    return 0;
}
*/

/*
? std::unique_lock - более гибкая RAII-обертка

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_block(int n, char c) {
    std::unique_lock<std::mutex> lck(mtx);  // Блокировка при создании
    for (int i = 0; i < n; ++i) { std::cout << c; }
    std::cout << '\n';
    Разблокировка автоматически при разрушении lck
}

int main() {
    std::thread th1(print_block, 50, '*');
    std::thread th2(print_block, 50, '$');
    
    th1.join();
    th2.join();
    
    return 0;
}
*/

/*
? std::try_lock - попытка блокировки нескольких мьютексов

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1, mtx2;

void task() {
    while (true) {
        if (std::try_lock(mtx1, mtx2) == -1) {  // Пытаемся заблокировать оба мьютекса
            std::cout << "Thread " << std::this_thread::get_id() << " acquired locks\n";
            // Работа с защищенными данными
            mtx1.unlock();
            mtx2.unlock();
            break;
        } else {
            std::this_thread::yield();  // Если не получилось, уступаем процессорное время
        }
    }
}

int main() {
    std::thread th1(task);
    std::thread th2(task);
    
    th1.join();
    th2.join();
    
    return 0;
}
*/

/*
? std::lock - блокировка нескольких мьютексов без deadlock

#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx1, mtx2;

void task() {
    std::lock(mtx1, mtx2);  // Блокируем оба мьютекса атомарно
    std::lock_guard<std::mutex> lck1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lck2(mtx2, std::adopt_lock);

    std::cout << "Thread " << std::this_thread::get_id() << " acquired locks\n";
}

int main() {
    std::thread th1(task);
    std::thread th2(task);

    th1.join();
    th2.join();

    return 0;
}
*/

/*
? std::recursive_mutex - рекурсивный мьютекс

#include <iostream>
#include <mutex>
#include <thread>

std::recursive_mutex rmtx;

void recursive_function(int count) {
    std::lock_guard<std::recursive_mutex> lock(rmtx);
    std::cout << "Count: " << count << std::endl;
    if (count > 0) {
        recursive_function(count - 1);  // Рекурсивный вызов с тем же мьютексом
    }
}

int main() {
    std::thread th(recursive_function, 3);
    th.join();
    return 0;
}
*/

/*
? std::timed_mutex - мьютекс с таймаутом

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex tmtx;

void task() {
    auto now = std::chrono::steady_clock::now();
    if (tmtx.try_lock_until(now + std::chrono::seconds(1))) {  // Пытаемся заблокировать в течение 1 секунды
        std::cout << "Thread " << std::this_thread::get_id() << " got the lock\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        tmtx.unlock();
    } else {
        std::cout << "Thread " << std::this_thread::get_id() << " couldn't get the lock\n";
    }
}

int main() {
    std::thread th1(task);
    std::thread th2(task);
    
    th1.join();
    th2.join();
    
    return 0;
}
*/

/*
? std::recursive_timed_mutex - рекурсивный мьютекс с таймаутом

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::recursive_timed_mutex rtmtx;

void task() {
    for (int i = 0; i < 3; ++i) {
        if (rtmtx.try_lock_for(std::chrono::milliseconds(100))) {  // Пытаемся заблокировать в течение 100 мс
            std::cout << "Thread " << std::this_thread::get_id() << " got the lock (iteration " << i << ")\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            rtmtx.unlock();
        } else {
            std::cout << "Thread " << std::this_thread::get_id() << " couldn't get the lock (iteration " << i << ")\n";
        }
    }
}

int main() {
    std::thread th1(task);
    std::thread th2(task);
    
    th1.join();
    th2.join();
    
    return 0;
}
*/

/*
? std::unique_lock с отложенной блокировкой

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void worker(int id) {
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock); // Не блокируем сразу
    std::cout << "Thread " << id << " is doing some work without lock\n";
    
    / Блокируем позже, когда нужно
    lock.lock();
    std::cout << "Thread " << id << " has locked the mutex\n";
    / Критическая секция
    lock.unlock(); // Можно разблокировать вручную
}

int main() {
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    
    t1.join();
    t2.join();
    
    return 0;
}
*/

/*
? Передача владения std::unique_lock

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void worker(std::unique_lock<std::mutex> lock) {
    std::cout << "Thread has the lock\n";
    / Критическая секция
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Thread releasing the lock\n";
}

int main() {
    std::unique_lock<std::mutex> lock(mtx);
    std::thread t(worker, std::move(lock)); // Передаем владение мьютексом
    
    t.join();
    return 0;
}
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