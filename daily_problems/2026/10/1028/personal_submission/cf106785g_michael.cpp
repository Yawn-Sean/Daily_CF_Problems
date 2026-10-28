#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int INF = 1e9+1;

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int>> cys(n);
	for(auto &[x,y] : cys) cin >> x >> y;
	int mnx = INF,mxx = -INF,mny = INF,mxy = -INF;
	for(auto &[x,y] : cys){
		mnx = min(x,mnx);
		mxx = max(x,mxx);
		mny = min(y,mny);
		mxy = max(y,mxy);
	}

	auto check = [&](int cx,int cy) -> bool{
		for(auto &[x,y] : cys){
			if(cx == x && cy == y){
				return true;
			}
		}
		return false;
	};
	bool ans = check(mnx,mny) && check(mnx,mxy) && check(mxx,mny) && check(mxx,mxy);
	cout << (ans ? "YES" : "NO") << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}