#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//有什么情况没有考虑到呢？
//1.成立条件是ans>a?-只要最后转化的沙子比原来多的话
//a==0,看后面的值
//b==0，如果c不等于0的话，那就不成立,如果c==0，就看d
//c==0，如果d是0的话那就不成立，其他成立
//d==0,实现不了
//e==0，如果f==0也不行
void sol()
{
   double a,b,c,d,e,f;
   cin>>a>>b>>c>>d>>e>>f;
   if(d==0)//如果变成的物质是0的话，那直接就不可能
   {
    cout<<"Hermione\n";
    return;
   }
   else//d不是0;
   {
     if(b==0&&c!=0)
     {
        cout<<"Hermione\n";
        return;
     }
     if(c==0)
     {
        cout<<"Ron\n";
        return;
     }
     if(e==0&&f==0&&a!=0)
     {
        cout<<"Hermione\n";
        return;
     }
     else if(e==0)
     {
        cout<<"Ron\n";
        return;
     }
   }
   double ans=b/c*d/e*f;
   if(ans>a)
   {
    cout<<"Ron\n";
   }
   else
   {
    if(a==0&&ans==0)
    {
        cout<<"Ron\n";
    }
    else cout<<"Hermione\n";
   }
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
