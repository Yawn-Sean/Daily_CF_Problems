#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<string> strs(n);
	for (auto& s: strs) { cin >> s; }
	
	int m;
	cin >> m;
	
	vector<string> pres(n + m), sufs(n + m);
	vector<vector<int>> vis(n + m, vector<int>(1024, 0));
	for (int i = 0; i < n; i++) {
		int k = strs[i].size();
		pres[i] = strs[i].substr(0, 10);
		sufs[i] = strs[i].substr(max(0, k - 10));
		for (int l = 0; l < k; l++) {
			int cur = 0;
			// 取值为cur 长度=r-l的串存在
			for (int r = l; r < l + 10 and r < k; r++) {
				cur = cur * 2 + (strs[i][r] - '0');
				vis[i][cur] |= (1 << (r - l));
			}
		}
	}
	
	for (int i = n; i < n + m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		
		for (int j = 0; j < 1024; j++) {
			vis[i][j] |= (vis[a][j] | vis[b][j]);
		}
		// 两个字符串拼接的地方
		for (int j = 1; j <= (int)sufs[a].size(); j++) {
			int cur = 0;
			for (int k = (int)sufs[a].size() - j; k < (int)sufs[a].size(); k++) {
				cur = cur * 2 + (sufs[a][k] - '0');
			}
			
			for (int k = 0; k < (int)pres[b].size(); k++) {
				if (j + k >= 10) break;
				cur = cur * 2 + (pres[b][k] - '0');
				vis[i][cur] |= (1 << (j + k));
			}
		}
		
		pres[i] = pres[a] + pres[b];
		pres[i] = pres[i].substr(0, 10);
		
		sufs[i] = sufs[a] + sufs[b];
		sufs[i] = sufs[i].substr(max(0, (int)sufs[i].size() - 10));
		
		int ans = 0;
		for (int v = 1; v <= 10; v++) {
			bool fl = true;
			// 遍历所有长度=v的位置是否设置了
			for (int msk = 0; msk < (1 << v); msk++) {
				if ((vis[i][msk] >> (v - 1)) & 1) {
					continue;
				}
				fl = false;
			}
			if (!fl) { break; }
			ans = v;
		}
		cout << ans << '\n';
	}
	
    return 0;
}
