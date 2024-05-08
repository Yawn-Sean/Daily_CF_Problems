#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n; cin >> n;
    string s; cin >> s;
    i64 res = 0;
    int len = s.length();
    array<i64,2> cur{0, 0};
    for (int i = 0; i < len; i++){
    	if (s[i] == 'R') cur[0]++;
    	else cur[1]++;
    }
    if (cur[0] == 0 || cur[1] == 0){
    	cout << n << "\n";
    	return;
    }

    int i = 1;
    while(s[i] == s[i - 1]){
    	res++;
    	i++;
    }
    cur[0] = n - cur[0];
    cur[1] = n - cur[1];
    for (; i < len; i++){
    	if (s[i] == 'R') res += cur[1];
    	else res += cur[0];
    }
    res += 1LL * cur[0] * cur[1];
    
    cout << res + 1 << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}