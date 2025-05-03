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