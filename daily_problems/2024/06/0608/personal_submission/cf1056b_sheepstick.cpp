#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n, m; cin >> n >> m;
    if (m == 1){
    	cout << n * n << "\n";
    	return;
    }

    vector<i64> cnt(m, 0);

    for (i64 i = 1; i <= min(n, m); i++){
    	i64 v = i * i % m;
    	cnt[v] += (n - i) / m + 1;
    }
    i64 res = 0;
    for (i64 i = 1; i < m; i++){
    	res += cnt[i] * cnt[m - i];
    }
    res += cnt[0] * cnt[0];

    cout << res << "\n";


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}