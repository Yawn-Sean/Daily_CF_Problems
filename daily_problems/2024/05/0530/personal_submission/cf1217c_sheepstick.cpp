#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int n = s.length();
    i64 res = 0, zero = 0;
    for (int i = 0; i < n; i++){
    	if (s[i] == '0') zero++;
    	else {
    		i64 cur = 0;
    		for (int j = i; j < n; j++){
    			cur = cur * 2 + (s[j] - '0');
    			i64 need = cur - (__lg(cur) + 1);
    			if (zero >= need) res++;
    			else break;
    		}
    		zero = 0;
    	}
    }
    cout << res << "\n";

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