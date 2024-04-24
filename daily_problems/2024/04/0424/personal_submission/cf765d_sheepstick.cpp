#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1E5 + 10;
void solve() {
	int n; cin >> n;

	vector<int> g(n + 1), h(M);
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		if (!g[x]){
			cnt++;
			g[x] = cnt;
			g[i] = cnt;
			h[g[i]] = x; 
		}
		else {
			if (h[g[x]] == x) g[i] = g[x];
			else {
				cout << "-1\n";
				return;
			}
		}
	}
	cout << cnt << "\n";
	for (int i = 1; i <= n; i++){
		cout << g[i] << " \n"[i == n];
	}
	for (int i = 1; i <= cnt; i++){
		cout << h[i] << " \n"[i == cnt];
	}

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}