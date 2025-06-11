#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//const int mod = 1 ? 998244353 : 1e9 + 7;
//#define int ll
void solve() 
{
	
	string s;
	cin>>s;
	int q;
	cin>>q;
	int n=s.size();
	vector<vector<int>>p(26,vector<int>(n));
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<n;j++)
		{
			p[i][j]=(j>=1?p[i][j-1]:0)+(s[j]=='a'+i);
		}
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--,r--;
		int c=0;
		for(int i=0;i<26;i++)
		{
			c+=(p[i][r]-(l>=1?p[i][l-1]:0))>0;
		}
		cout<<((l==r||(s[l]!=s[r]&&c==2)||c>2)?"Yes\n":"No\n");
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









