#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
    	cin >> s[i];
    }
        
    map<pair<int,int>, int> mp;
    for (int idx = 0; idx < n; idx++) {
    	for (int i = 0; i < 9; i++) {
    		int cur = 0;
    		for (int j = i; j < 9; j++) {
    			cur = cur * 10 + s[idx][j] - '0';
    			if (mp.find({cur, j - i}) == mp.end()) {
    				mp[{cur, j - i}] = idx;
    			} else if (mp[{cur, j - i}] != idx) {
    				mp[{cur, j - i}] = -1;
    			}
    		}
    	}
    }
    
    for (int idx = 0; idx < n; idx++) {
    	int str_len = 10, start = 0;
    	for (int i = 0; i < 9; i++) {
    		int cur = 0;
    		for (int j = i; j < 9; j++) {
    			cur = cur * 10 + s[idx][j] - '0';
    			if (j - i < str_len and mp[{cur, j - i}] == idx) {
    				start = i;
    				str_len = j - i;
    			}
    		}
    	}
    	
    	cout << s[idx].substr(start, str_len + 1) << '\n';
    }
    return 0;   
}
