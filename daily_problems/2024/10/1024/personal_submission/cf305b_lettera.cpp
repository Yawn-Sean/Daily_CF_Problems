#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
      ll p,q;
      cin>>p>>q;
      vector<ll>c;
      c.push_back(-1);
      while(q)
      {
      	c.push_back(p/q);
      	p%=q;
      	swap(p,q);
      }
      int n;
      cin>>n;
      vector<ll>a(n+1);
      for(int i=1;i<=n;i++)
      {
      	cin>>a[i];
      }
      for(int i=n;i>1;i--)
      {
      	if(a[i]==1)
      	{
      		a[i-1]++;
      		n--;
      	}
      	else
      	{
      		break;
      	}
      }
      if(c.size()==n+1)
      {
      	for(int i=1;i<=n;i++)
      	{
      		if(a[i]!=c[i])
      		{
      			cout<<"NO\n";
      			return;
      		}
      	}
      	cout<<"YES\n";
      }
      else
      {
      	cout<<"NO\n";
      }
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
