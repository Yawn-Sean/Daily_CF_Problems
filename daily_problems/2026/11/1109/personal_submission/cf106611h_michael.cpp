#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int hx,hy,cx,cy,d,u;
	cin >> hx >> hy >> cx >> cy >> d >> u;
	if(abs(hx - cx) + abs(hy - cy) <= 1) cout << 1;
	else{
		long double pi = acosl(-1);
		long double ch = atan2l(hy - cy,hx - cx);
		long double gp = asinl(1/hypotl(hy - cy,hx - cx));
		long double l1 = ch - gp, r1 = ch + gp;
		long double l2 = (d - u) * pi / 180,r2 = (d + u) * pi / 180;

		long double ol = 0;
		for(int i = -1; i <= 1; ++i){
			ol += max((long double)0,min(r1,r2 + i * 2 * pi) - max(l1,l2 + i * 2 * pi));
		}
		cout << fixed << setprecision(20) << ol / (2 * u * pi / 180);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}