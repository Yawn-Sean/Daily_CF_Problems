#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    string s, t;
    int n;
    cin >> s >> t >> n;
    if (s.size() != t.size()) {
    	cout << "-1\n";
    	return 0;
    }
    const int inf = 1e8;
    vector<vector<int>> d(26,vector<int>(26, inf));
    for (int i = 0; i < 26; ++i) {
        d[i][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
    	char u, v;
    	int w;
    	cin >> u >> v >> w;
    	d[u - 'a'][v - 'a'] = min(d[u - 'a'][v - 'a'], w);
    }
    
    

    for (int k = 0; k < 26; ++k) {
    	for (int i = 0; i < 26; ++i) {
    		for (int j = 0; j < 26; ++j) {
    			if (d[i][k] + d[k][j] < d[i][j]) {
    				d[i][j] = d[i][k] + d[k][j];
    			}
    		}
    	}
    }

    int ans = 0;
    string c;
    for (int i = 0; i < s.size(); ++i) {
    	int x = s[i] - 'a', y = t[i] - 'a';
    	int cu = inf, id = - 1;
    	for (int j = 0; j < 26; ++j) {
    		if (d[x][j] + d[y][j] < cu) {
    			id = j;
    			cu = d[x][j] + d[y][j];
    		}
            // if (d[])
    	}
    	if (id == -1) {
    		cout << "-1\n";
    		return 0;
    	}
    	ans += cu;
    	c += char(id + 'a');
    }
    cout << ans << '\n' << c << '\n';
    return 0;
}
