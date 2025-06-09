#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
// #define int long long
#define itn int

void solve()
{
    int n;
	cin>>n;
	vector<int> a(n), b(n);
	for(int i = 0; i<n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(),b.end());
	int ans=0;
	int cnt=0;
	for(int i = 0; i<n; i++){
		cnt+=(a[i]-b[i]);
		ans+=!cnt;
	}
	cout<<ans;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
//   cin >> tt;
  tt = 1;
  while (tt--)
  {
    solve();
  }
  return 0;
}