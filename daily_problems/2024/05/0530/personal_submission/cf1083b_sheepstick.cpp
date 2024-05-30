#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, k; cin >> n >> k;
	string s,t; cin >> s >> t;
	
	i64 res = 0, node = 2;
	for (int i = 0; i < n; i++){
		node -= (s[i] == 'b');
		node -= (t[i] == 'a');
		if (node >= k){
			res += 1LL * (n - i) * k;
			break;
		}
		res += node;
		node *= 2;
	}
	cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}