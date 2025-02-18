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
	vector<int>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<vector<int>>ans;
	vector<int>mx;
	for(int i=0;i<n;i++)
	{
		int k=upper_bound(begin(mx),end(mx),a[i],
		greater<int>())-begin(mx);
		if(k==mx.size())
		{
			ans.push_back({a[i]});
			mx.push_back(a[i]);
		}
		else
		{
			mx[k]=a[i];
			ans[k].push_back(a[i]);
		}
	}
	for(auto a:ans)
	{
		for(auto x:a)
		{
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	
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









c
