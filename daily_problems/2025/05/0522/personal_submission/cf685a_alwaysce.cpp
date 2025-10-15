#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;
i64 qpow(i64 base, i64 exp) {
    base %= mod;
    i64 res = 1;
    while (exp) {
        if (exp & 1) {
            res = res * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    function<void(int,int,int,int,int, vector<int>&)> dfs = [&](int idx, int val, int digit, int msk, int x, vector<int>& cnt) {
        if (idx == digit) {
            if (val < x) {
                cnt[msk]++;
            }
            return;
        }

        for (int i = 0; i < 7; i++) {
            if (msk >> i & 1) {
                continue;
            }
            dfs(idx + 1, val * 7 + i, digit, msk | (1 << i), x, cnt);
        }
    };

    auto f = [&](int x) {
        vector<int> ans(128);
        int tmp = x - 1, len = 0;
        while (tmp) {
            tmp /= 7;
            len++;
        }
        len = max(len, 1);
        dfs(0, 0, len, 0, x, ans);
        return ans;
    };

    int ans = 0;
    vector<int> cnt1 = f(n), cnt2 = f(m);
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            if (i & j) continue;
            ans += cnt1[i] * cnt2[j];
        }
    }
    cout << ans << endl;
    return 0;
}
