#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

int main()
{
    vector<int> data={1,2,5,7,3,9,6,4,10,8};
    vector<int> base={10,20,30,40,50};
    vector<int> rezult(data.size());
    int tmp = accumulate(data.begin(),data.end(),0);
    cout<<tmp<<'\n';

    tmp = inner_product(data.begin(),data.end(),base.begin(),0);
    cout << tmp << '\n';

    partial_sum(data.begin(),data.end(),rezult.begin());
    for(auto i=rezult.begin();i!=rezult.end();i++)
    cout<<*i<<' ';
    cout<<'\n';

    vector<int> sqeue(5);
    iota(sqeue.begin(),sqeue.end(),10);
    for(auto i=sqeue.begin();i!=sqeue.end();i++)
    cout<<*i<<' ';
    cout<<'\n';

    tmp = gcd(10,15);
    cout << tmp << '\n';

    tmp=lcm(3,4);
    cout << tmp << '\n';

    tmp =transform_reduce(data.begin(),data.end(),0,plus<>(),[](int x){return x*x;});
    cout << tmp << '\n';
}