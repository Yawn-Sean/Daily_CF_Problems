#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<vector<vector<int>>> saved(2, vector<vector<int>>(10, vector<int>(n)));
	vector<vector<vector<int>>> query(2, vector<vector<int>>(10, vector<int>()));
	int mx = 32 - __builtin_clz(n);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < mx; j++) {
			int val = (i >> j) & 1;
			query[val][j].push_back(i);
		}
	}
	
	auto ask = [&](int bit_rank, int bit_val, vector<int>& q) {
		cout << q.size() << '\n';
		for (auto& v: q) {
			cout << v << ' ';
		}
		cout << '\n';
		cout.flush();
		
		for (int i = 1; i <= n; i++) {
			cin >> saved[bit_val][bit_rank][i - 1];
		}
	};
	
	for (int i = 0; i < mx; i++) {
		for (int j = 0; j <= 1; j++) {
			ask(i, j, query[j][i]);
		}
	}
    
    cout << -1 << '\n';
    for (int i = 1; i <= n; i++) {
    	int cur = 1e9;
    	for (int j = 0; j < mx; j++) {
    		if ((i >> j) & 1) {
    			cur = min(cur, saved[0][j][i - 1]);
    		} else {
    			cur = min(cur, saved[1][j][i - 1]);
    		}
    	}
    	cout << cur << ' ';
    }
    cout.flush();

    return 0;
}
