#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//构造
//任意两排的树的相邻两颗树高度之差的绝对值大于1
//问题在于如何特判
void sol()
{
   int n,m;cin>>n>>m;
   int _min=1,_max=n*m/2+1;
   int now=1;
   vector<vector<int>>ans(n+1,vector<int>(m,0));
   if(n+m>2&&n+m<5)
   {
     cout<<-1<<endl;
   }
   else
   {
     for(int i=1;i<=n;++i)
       for(int j=1;j<=m;++j)
       {
          if(j%2==0)
          {
            if(i%2==1)
            {
                cout<<_min<<' ';
                _min++;
            }
            else
            {
                cout<<_max<<' ';
                _max++;
            }
          }
          else
          {
            if(i%2==1)
            {
                cout<<_max<<' ';
                _max++;
            }
            else
            {
                cout<<_min<<' ';
                _min++;
            }
          }
          if(j==m)cout<<endl;
       }
   }
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
