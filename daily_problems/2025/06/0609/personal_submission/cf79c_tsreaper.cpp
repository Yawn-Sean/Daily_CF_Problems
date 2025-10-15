#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXM 10
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(long long x, long long y) {
    return uniform_int_distribution<long long>(x, y)(rng);
}

long long MOD = 1e18 + rnd(1, 1e18);
int BASE = 233 + rnd(0, 1e3);
struct HashSeq {
    vector<__int128> P, H;

    HashSeq(string &s) {
        int n = s.size();
        P.resize(n + 1);
        P[0] = 1;
        for (int i = 1; i <= n; i++) P[i] = P[i - 1] * BASE % MOD;
        H.resize(n + 1);
        H[0] = 0;
        for (int i = 1; i <= n; i++) H[i] = (H[i - 1] * BASE + s[i - 1]) % MOD;
    }

    long long query(int l, int r) {
        return (H[r] - H[l - 1] * P[r - l + 1] % MOD + MOD) % MOD;
    }
};

int n, m;
string s[MAXM + 1];

long long goal[MAXM + 1];
int f[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s[0] >> m;
    for (int i = 1; i <= m; i++) cin >> s[i];
    n = s[0].size();
    HashSeq hs(s[0]);
    for (int i = 1; i <= m; i++) {
        HashSeq hs(s[i]);
        goal[i] = hs.query(1, s[i].size());
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        if (i >= s[j].size() && hs.query(i - s[j].size() + 1, i) == goal[j])
            f[i] = max(f[i], i - (int) s[j].size() + 1);
    
    int len = 0, pos = 0;
    for (int i = 1, mx = 0; i <= n; i++) {
        mx = max(mx, f[i]);
        if (i - mx > len) len = i - mx, pos = mx;
    }
    cout << len << " " << pos << "\n";
    return 0;
}
