#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vector<int> next(26, -1), prev(26, -1), cnt(26, 0);
	vector<string> input(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];	
	}
	for (int i = 0; i < n; i++) {
		string& s = input[i];
		cnt[s[0] - 'a']++;
		for (int j = 1; j < s.length(); j++) {
			int a = s[j - 1] - 'a', b = s[j] - 'a';
			if (next[a] != -1 && next[a] != b) {
				cout << "NO\n";
				return 0;
			}
			if (prev[b] != -1 && prev[b] != a) {
				cout << "NO\n";
				return 0;
			}
			next[a] = b; prev[b] = a;
			cnt[b]++;
		}
	}
	vector<int> ans, vis(26, 0);
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 0 && !vis[i] && prev[i] == -1) {
			for (int cur = i; cur != -1; cur = next[cur]) {
				if (vis[cur]) {
					cout << "NO\n";
					return 0;
				}	
				vis[cur] = 1;
				ans.push_back(cur);
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 0 && !vis[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	
	string res(sz(ans), 'a');	
	for (int i = 0; i < sz(ans); i++) {
		res[i] += ans[i];
	}
	cout << res << "\n";
}
