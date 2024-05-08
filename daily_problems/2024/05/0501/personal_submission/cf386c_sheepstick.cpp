#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int n = s.length();

    //f(j): at most j characters
    vector<i64> res(27, 0);
    auto gao = [&](int lim) -> void {
    	vector<int> state(26, 0);
    	int cnt = 0;
    	for (int i = 0, j = 0; i < n; i++){
    		while(j < n && (cnt < lim || (cnt == lim && state[s[j] - 'a']))){
    			if (++state[s[j] - 'a'] == 1) cnt++;
    			j++;
    		}
    		res[lim] += j - i;
    		if (--state[s[i] - 'a'] == 0) cnt--;
    	}
    };
    int ans = 26;
    for (int i = 1; i <= 26; i++) gao(i);
    for (int i = 26; i >= 2; i--) {
    	res[i] -= res[i - 1];
    	if (res[i] == 0) ans = i - 1;
    }
    cout << ans << "\n";
    for (int i = 1; i <= ans; i++){
    	cout << res[i] << "\n";
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}