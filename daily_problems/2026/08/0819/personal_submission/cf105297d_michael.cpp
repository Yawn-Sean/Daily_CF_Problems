#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	long double x,y,z,tx,ty,tz,rds;
	cin >> x >> y >> z >> tx >> ty >> tz >> rds;
	long double l = 0,r = min({x,y,z}) / 2,mid;
	tx = max(tx,x - tx);
	ty = max(ty,y - ty);
	tz = max(tz,z - tz);
	for(int i = 0; i < 100; ++i){
		mid = (l + r) / 2;
		if((tx - mid)*(tx - mid) + (ty - mid)*(ty - mid) + (tz - mid)*(tz - mid) >= (rds + mid)*(rds + mid)) l = mid;
		else r = mid;
	}
	cout << setprecision(15) << fixed << (l + r) / 2 << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	cout << flush;
	return 0;
}