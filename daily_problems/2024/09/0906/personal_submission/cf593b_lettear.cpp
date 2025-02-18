#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//const int mod = 1 ? 998244353 : 1e9 + 7;
//#define int ll
void solve() 
{
	int n;
	cin>>n;
	int x1,x2;
	cin>>x1>>x2;
	vector<pair<ll,ll>>a(n);
	for(int i=0;i<n;i++)
	{
		auto &[x,y]=a[i];
		int k,b;
		cin>>k>>b;
		x=1ll*k*x1+b;
		y=1ll*k*x2+b;
		//cerr<<x<<" "<<y<<"\n";
	}
	sort(begin(a),end(a));
	bool flag=0;
	for(int i=1;i<n;i++)
	{
		if(a[i].second<a[i-1].second)
		{
			//cerr<<a[i].first<<" "<<a[i].second<<"c\n";
			flag=1;
			break;
		}
	}
	cout<<(flag?"YES\n":"NO\n");
	
}
signed main() {
  ios::sync_with_stdio(false),cin.tie(0);
  int t;
  t = 1;
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  //cin >> t;
  while (t--) {
    solve();
  }
}









