#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;

    if (n % 2 != 0 || s[0] == ')' || s[n - 1] == '(') {
    	cout << ":(" << '\n';
    	return 0;
    }

    int xl = 0, p = 0;
    for (auto c : s) {
    	if (c == '(') xl++;
    	else if (c == '?') p++;
    }
    p = n / 2 - xl;

    for (int i = 0; i < n; ++i) {
    	if (s[i] == '?') {
    		if (p > 0) {
    			s[i] = '(';
    			p--;
    		} else s[i] = ')';
    	}
    }

    for (int i = 0, t = 0; i < n; ++i) {
    	if (s[i] == '(') t++;
    	else t--;
    	if ((i < n - 1 && t <= 0) || (i == n - 1 && t != 0)) {
    		cout << ":(" << '\n';
    		return 0;
    	}
    }

    cout << s << '\n';

    return 0;
}
