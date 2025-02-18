#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	// ?个数前缀和
	vector<int> wh(n + 1);
	for (int i = 0; i < n; i++) {
		wh[i + 1] = wh[i] + (s[i] == '?');
	}
	
	// pows = i^j
	vector<vector<i64>> pows(18, vector<i64>(n + 1, 1));
	for (int i = 1; i <= 17; i++) {
		for (int j = 0; j < n; j++) {
			pows[i][j + 1] = 1ll * pows[i][j] * i % mod;
		}
	}
	
	// cnt[l][r]: [l:r]内 ?对的数量
	// dp[l][r]: [l:r]变成回文串的最小字符集合二进制bitmask
	vector<vector<int>> dp(n, vector<int>(n, 0)), cnt(n, vector<int>(n, 0));

    for (int l = n - 1; l >= 0; l --) {
        if (s[l] == '?') {
        	cnt[l][l] = 1;
        }

        for (int r = l + 1; r < n; r ++) {
            if (dp[l + 1][r - 1] == -1 || (s[l] != '?' && s[r] != '?' && s[l] != s[r]))
                dp[l][r] = -1;
            else {
                dp[l][r] = dp[l + 1][r - 1];
                cnt[l][r] = cnt[l + 1][r - 1];

                if (s[l] != '?' && s[r] == '?') {
                    dp[l][r] |= 1 << (s[l] - 'a');
                }
                else if (s[l] == '?' && s[r] != '?') {
                    dp[l][r] |= 1 << (s[r] - 'a');
                }
                else if (s[l] == '?' && s[r] == '?') {
                    cnt[l][r] ++;
                }
            }
        }
    }
    
    vector<vector<i64>> calc(18, vector<i64>(1 << 17, 0));
    for (int l = 0; l < n; l++) {
    	for (int r = l; r < n; r++) {
    		if (dp[l][r] != -1) {
    			for (int i = 1; i <= 17; i++) {
    				// ?对可以随便取 + 剩下不在[l, r]范围内的?可以随便取
    				// i^{pow}
    				calc[i][dp[l][r]] += pows[i][cnt[l][r] + (wh[l] + wh[n] - wh[r + 1])] % mod;
    			}
    		}
    	}
    }
	
	// 用了i种字符 字符集合msk的方案累计
	for (int i = 1; i <= 17; i ++) {
        for (int j = 0; j < 17; j ++) {
            for (int msk = 0; msk < (1 << 17); msk ++) {
                if ((msk >> j) & 1) {
                    calc[i][msk] += calc[i][msk ^ (1 << j)] % mod;
                }
            }
        }
    }
    
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		int msk = 0;
		for (auto& c: s) {
			msk |= (1 << (c - 'a'));
		}
		cout << calc[s.size()][msk] % mod << '\n';
	}
	return 0;
}
