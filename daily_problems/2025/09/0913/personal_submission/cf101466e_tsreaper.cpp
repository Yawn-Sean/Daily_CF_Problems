#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rnd(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}
 
long long MOD = 1e18 + rnd(0, 1e9);
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, p;
    int K;
    getline(cin, s);
    getline(cin, p);
    cin >> K;

    HashSeq hs(s), hp(p);
    auto count = [&](int len) {
        long long goal = hp.query(1, len);
        int ret = 0;
        for (int i = len; i <= s.size(); i++) {
            long long h = hs.query(i - len + 1, i);
            if (goal == h) ret++;
        }
        return ret;
    };

    if (count(1) < K) { cout << "IMPOSSIBLE\n"; return 0; }
    int head = 1, tail = p.size();
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (count(mid) >= K) head = mid;
        else tail = mid - 1;
    }
    cout << p.substr(0, head) << "\n";
    return 0;
}
