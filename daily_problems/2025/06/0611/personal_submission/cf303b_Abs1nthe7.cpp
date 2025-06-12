#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
   int n,m,x,y,a,b;
   cin>>n>>m>>x>>y>>a>>b;
   int gcd=__gcd(a,b);
   a/=gcd;
   b/=gcd;
   int tmp=min(n/a,m/b);//9/2-4;
   a=tmp*a,b=tmp*b;//8,4--找到最大的长宽
   //然后我们需要将矩阵平移到包含点的位置
   //要求字典序最小的情况下，我们尽可能让x1，y1小
   //尽可能的离点进的话
   //我们考虑中心点在点，x1,y1就应该在点的a/2,b/2;
   int x1=min(n-a,max(0ll,x-(a+1)/2));
   int y1=min(m-b,max(0ll,y-(b+1)/2));
   cout<<x1<<' '<<y1<<' '<<x1+a<<' '<<y1+b<<endl;
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
