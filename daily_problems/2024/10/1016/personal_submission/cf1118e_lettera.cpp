#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
       int n, k;
    cin >> n >> k;
    if (n > 1ll * k * (k - 1))
    {
        cout << "NO\n";
    }
    else
    {
    	cout<<"YES\n";
    	for(int i=1;i<=k;i++)
    	{
    		for(int j=i+1;j<=k;j++)
    		{
    			if(n>1)
    			{
    				cout<<i<<" "<<j<<"\n";
    				cout<<j<<" "<<i<<"\n";
    				n-=2;
    			}
    			else if(n==1)
    			{
    				cout<<i<<" "<<j<<"\n";
    				n--;
    			}
    			if(!n)
    			{
    				return;
    			}
    		}
    	}
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
   // cin >> t;
    while (t--)
    {
        solve();
    }
}
