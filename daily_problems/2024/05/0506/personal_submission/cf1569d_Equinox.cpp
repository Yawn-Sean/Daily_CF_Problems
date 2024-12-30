#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int xs[N], ys[N];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	unordered_map<int, int> cntx, cnty;
	unordered_map<int, unordered_map<int, int>> cntxy, cntyx;
	for(int i = 0; i < n; i ++) cin >> xs[i];
	for(int i = 0; i < m; i ++) cin >> ys[i];
	for(int i = 0, x, y; i < k; i ++){
		cin >> x >> y;
		int lx = lower_bound(xs, xs + n, x) - xs, ly = lower_bound(ys, ys + m, y) - ys;
		if(xs[lx] == x && ys[ly] == y) continue;	//É¾µô
		if(xs[lx] == x){	//vertical
			cnty[ly] ++;
			cntxy[lx][ly] ++;
		} 
		else{	//horizontal
			cntx[lx] ++;
			cntyx[ly][lx] ++;		
		}
	}
	int res = 0;
	for(int i = 0; i < n; i ++){
		int t = cntx[i];
		res += t * (t - 1) / 2;
		for(auto& p : cntxy[i]){
			t = p.second;
			res -= t * (t - 1) / 2;
		}
	}
	for(int i = 0; i < m; i ++){
		int t = cnty[i];
		res += t * (t - 1) / 2;
		for(auto& p : cntyx[i]){
			t = p.second;
			res -= t * (t - 1) / 2;
		}
	}	
	cout << res << '\n';
}


signed main(){
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _  = 1;
	cin >> _;
	while(_ --)
		solve();	
	
	return 0;
}
