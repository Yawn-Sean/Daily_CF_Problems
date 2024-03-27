#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 19;
void solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> perm(n);
	for (auto &pi : perm){
		cin >> pi;
	}
	vector<int> pos(n + 1);
	for (int i = 0; i < n; i++){
		pos[perm[i]] = i;
	}
	vector<int> a(m);
	for (auto &ai : a){
		cin >> ai;
	}

	vector<array<int,3>> ask(q);
	for (int i = 0; i < q; i++){
		int l, r; cin >> l >> r;
		l--; r--;
		ask[i] = {r, l, i};
	}
	sort(ask.begin(), ask.end());
	vector<vector<int>> par(M, vector<int>(m, -1));
	
	vector<int> last(n + 1, -1);
	for (int i = 0; i < m; i++){
		int tar = perm[(pos[a[i]] - 1 + n) % n];
		if (last[tar] != -1) par[0][i] = last[tar];
		last[a[i]] = i; 
	}

	for (int i = 1; i < M; i++){
		for (int j = 0; j < m; j++){
			if (par[i - 1][j] != -1) par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}


	auto f = [&](int i) -> int {
		//n - 1 (th) ancestor
		int res = i;
		for (int i = 0; i < M && res != -1; i++) if (((n - 1) >> i) & 1){
			res = par[i][res];
		}
		return res;
	};

	int best = -1;
	vector<int> res(q, 0);
	for (int i = 0, j = 0; i < m; i++){
		best = max(best, f(i));
		while(j < q && ask[j][0] == i){
			if (best >= ask[j][1]) res[ask[j][2]] = 1;
			j++;
		}
	}
	for (auto &v : res){
		cout << v;
	}
	cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}