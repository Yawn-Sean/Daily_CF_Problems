#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
      int hp1,atk1,def1;
      int hp2,atk2,def2;
      int h,a,d;
      cin>>hp1>>atk1>>def1;
      cin>>hp2>>atk2>>def2;
      cin>>h>>a>>d;
      int ans=10000;
      int add=max(0,def2-atk1+1);
      atk1+=add;
      for(int x=0;x<=10000;x++)
      {
      	for(int y=0;y<=100;y++)
      	{
      		int damage2=atk1+y-def2;
      		int time=(hp2+damage2-1)/damage2;
      		//(hp1+x)>=(time)*(atk2-def1-z)+1
      		int z=max(0,atk2-def1-(hp1+x-1)/time);
      		ans=min(ans,x*h+y*a+z*d);
      	}
      }
      cout<<ans+add*a<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
