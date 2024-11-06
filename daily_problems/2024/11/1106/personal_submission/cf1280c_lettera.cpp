#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
	int n=1000;
	//注意到小偷每次都会改变所在列的奇偶
	cout<<2*n<<"\n";
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" "<<1<<" "<<i<<" "<<2<<"\n";
	}
	for(int i=n;i>=1;i--)
	{
		cout<<i<<" "<<1<<" "<<i<<" "<<2<<"\n";
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
