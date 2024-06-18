#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> z_function(string& s) {
    int n = s.size();
    vector<int> z(n, n);
    for (int i = 1, l = 0, r = 0; i < n; i += 1) {
        if (i <= r and z[i - l] < r - i + 1) z[i] = z[i - l];
        else for (z[i] = max(0, r - i + 1); i + z[i] < n && s[z[i]] == s[i + z[i]]; z[i] += 1);
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
    	cin >> a[i];
    	a[i]--;
    }
    int k = s.size();
    auto z = z_function(s);

    for (int i = 1; i < m; ++i) {
    	int idx = a[i] - a[i - 1];
    	if (idx >= k) continue;
    	if (z[idx] + idx != k) {
    		cout << "0\n";
    		return 0;
    	}
    }

    vector<int> d(n + 1);
    for (auto &x : a) {
    	d[x]++;
    	d[x + k]--;
    }

    long long ans = 1, mod = 1e9 + 7;
    for (int i = 0; i < n; ++i) {
    	d[i + 1] += d[i];
    	if (!d[i]) {
    		ans = (ans * 26) % mod;
    	}
    }
    cout << ans << '\n';

    return 0;
}
