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