#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    //minus one
    int n = s.length();

    string tmp;
    for (int i = n - 1, rem = 1; i >= 0; i--){
    	if (rem){
    		rem = 0;
    		if (s[i] == '0') {
    			tmp.push_back('9');
    			rem++;
    		}
    		else tmp.push_back(char(s[i] - 1));
    	}
    	else tmp.push_back(s[i]);
    }
    while(tmp.back() == '0') tmp.pop_back();
    reverse(tmp.begin(), tmp.end());
    swap(tmp, s);
    n = s.length();

    //cout << s << "---\n";

    string res, cur;
    int mask = 0;
    auto dfs = [&](auto self, int i, bool bound) -> bool {
    	if (i == n){
    		res = cur;
    		return true;
    	}
    	int toUse = __builtin_popcount(mask);
    	if (toUse == n - i){ //must use existing numbers
    		for (int j = 9; j >= 0; j--) if (mask & (1 << j)){
    			if (!bound || (bound && (s[i] - '0' >= j))){
    				cur += ('0' + j);
    				mask ^= 1 << j;
    				if (self(self, i + 1, bound && (s[i] - '0' == j))) return true;
    				cur.pop_back();
    				mask ^= 1 << j;
    			}
    		}
    	}
    	else {
    		if (!bound) {
    			cur += '9';
    			mask ^= 1 << 9;
    			if (self(self, i + 1, bound)) return true;
    		}
    		else {
    			for (int j = (s[i] - '0'); j >= 0; j--){
    				cur += ('0' + j);
    				mask ^= 1 << j;
    				if (self(self, i + 1, (s[i] - '0' == j))) return true;
    				cur.pop_back();
    				mask ^= 1 << j;
    			}
    		}
    	}
    	return false;
    };
    if (n % 2 == 0) dfs(dfs, 0, true);
    if (res.empty() || res[0] == '0'){
    	res = string(n - 2 + (n % 2), '9');
    }
    cout << res << "\n";


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}