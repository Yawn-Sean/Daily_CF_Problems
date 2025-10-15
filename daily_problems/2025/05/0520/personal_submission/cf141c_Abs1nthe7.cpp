#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int n;cin>>n;
   vector<string>s(n);
   vector<int>a(n);
   for(int i=0;i<n;++i)
   {
    cin>>s[i]>>a[i];
   }
   vector<int>order(n);
   iota(order.begin(),order.end(),0);
   sort(order.begin(),order.end(),[&](int i,int j){return a[i]<a[j];});//根据a[i]排序
   int cur=n;
   list<int>tmp;//使用链表暂存-方便等下插入
   vector<int>h(n);
   for(int i:order)
   {
    if(a[i]>tmp.size())//如果前面的数，小于现在要大于的数，就无法构造出来
    {
      cout<<-1<<endl;
      return;
    }
    h[i]=cur--;//从大到小构造，防止影响后面的数
    auto it=tmp.begin();
    advance(it,a[i]);//插入到第a[i]位子的后面
    tmp.insert(it,i);
   }
   for(int i:tmp)
   {
    cout<<s[i]<<' '<<h[i]<<endl;
   }
   cout<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    while(_--)sol();
    return 0;
}
