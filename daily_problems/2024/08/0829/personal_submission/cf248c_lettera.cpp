#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//const int mod = 1 ? 998244353 : 1e9 + 7;
#define int ll
void solve() 
{
	
	ll y1,y2,yw,xb,yb,r;
	cin>>y1>>y2>>yw>>xb>>yb>>r;
	
	y1=2*yw-y1-2*r;
	y2=2*yw-y2-2*r;
	swap(y1,y2);
	__int128_t left=(y2-y1-r)*(y2-y1-r),right=(yb-y2+r)*(yb-y2+r)+xb*xb;
	left*=xb*xb;
	right*=r*r;
	if(left<right)cout<<-1<<endl;
	else 
	cout<<setprecision(15)<<1.0*(yw-y2)*xb/(yb-y2+r)<<endl;
	
	
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









