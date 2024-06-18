#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, k, m;
    cin >> n >> k;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < 2; ++j) {
    		cin >> a[i][j];
    	}
    	a[i][2] = i + 1;
    }
    sort(a.begin(), a.end());

    set<pair<int,int>> s;
    
    vector<int> c;
    for (int i = 0, j = 0; i < n; ++i) {
    	while (j < n && a[j][0] <= a[i][0]) {
    		s.insert({a[j][1], a[j][2]});
    		j++;
    	}
    	while (!s.empty() && s.begin()->first < a[i][0]) {
    		s.erase(s.begin());
    	}
    	while (s.size() > k) {
    		auto it = prev(s.end());
    		c.push_back(it->second);
    		s.erase(it);
    	}
    }
    m = c.size();
    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
    	cout << c[i] << " \n"[i == m - 1];
    }
    return 0;
}
