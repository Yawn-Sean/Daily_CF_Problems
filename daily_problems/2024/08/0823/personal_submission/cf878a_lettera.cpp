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
	//每一位输入为0/1时，输出a1/a2
	int v0=0,v1=1023;
	while(n--)
	{
		char op;
		int x;
		cin>>op>>x;
		if(op=='&')v0&=x,v1&=x;
		else if(op=='|')v0|=x,v1|=x;
		else v0^=x,v1^=x;
	}
	cout<<2<<endl;
	cout<<"& "<<(v0^v1)<<endl;
	cout<<"^ "<<v0<<endl;
	
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









