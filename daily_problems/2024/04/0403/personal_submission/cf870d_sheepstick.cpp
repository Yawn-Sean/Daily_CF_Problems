#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;

	auto ask = [&](int i, int j) -> int {
		cout << "? "<<i <<" "<< j << endl;
		int res; cin >> res;
		return res;
	};

	vector<vector<int>> a(n, vector<int>(n, 0));
	for (int j = 0; j < n; j++){
		a[0][j] = ask(0, j);
	}
	for (int i = 1; i < n; i++){
		a[i][0] = ask(i, 0);
	}
	//for any i, j we have pi ^ bj = (pi ^ b0) ^ (p0 ^ bj) ^ (p0 ^ b0);
	int idx = -1, cnt = 0;

	for (int i = 0; i < n; i++){
		vector<int> p(n, 0), b(n, 0);
		bool ok = true;

		p[0] = i;
		for (int j = 1; j < n; j++){
			p[j] = a[j][0] ^ (a[0][0] ^ p[0]);
		}
		//p has to be a permutation
		auto check = [&](vector<int> &x) -> bool {
			vector<int> visited(n, 0);
			for (int i = 0; i < n; i++){
				if (x[i] >= n) return false;
				if (visited[x[i]]) return false;
				visited[x[i]] = 1;
			}
			return true;
		};
		if (!check(p)) continue;

		for (int j = 0; j < n; j++){
			b[j] = a[0][j] ^ i;
		}
		if (!check(b)) continue;

		for (int i = 0; i < n; i++){
			if (p[b[i]] != i) ok = false;
		}
		if (ok){
			if (idx < 0) idx = i;
			cnt++;
		}
	}
	cout << "!\n";
	cout << cnt << "\n";
	cout << idx <<" ";
	for (int j = 1; j < n; j++){
		cout << (a[j][0] ^ (a[0][0] ^ idx)) <<" ";
	}
	cout << endl;


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}