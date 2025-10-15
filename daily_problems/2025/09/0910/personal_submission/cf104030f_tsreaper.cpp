#include <bits/stdc++.h>
#define MAXN 500
using namespace std;
typedef pair<long long, int> pli;

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

int n;
string s[MAXN][MAXN];

int si, sj;
vector<vector<HashSeq>> seq;
vector<string> ans;

void check(int l) {
    long long goal = seq[si][sj].query(1, l);
    for (int j = 0; j < n; j++) if (j != si) {
        long long h = seq[si][j].query(1, l);
        if (h != goal) return;
    }

    vector<pli> vec;
    for (int i = 0; i < n; i++) {
        if (i == si) {
            vec.push_back({goal, l});
            continue;
        }

        int ll = s[si][i].size() - l;
        long long h = seq[si][i].query(l + 1, l + ll);
        vec.push_back({h, ll});
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) {
        if (s[i][j].size() != vec[i].second + vec[j].second) return;
        long long h1 = seq[i][j].query(1, vec[i].second);
        long long h2 = seq[i][j].query(vec[i].second + 1, vec[i].second + vec[j].second);
        if (h1 != vec[i].first || h2 != vec[j].first) return;
    }

    if (!ans.empty()) { cout << "MANY\n"; exit(0); }
    for (int i = 0; i < n; i++) {
        if (i == 0) ans.push_back(s[0][1].substr(0, vec[0].second));
        else ans.push_back(s[i][0].substr(0, vec[i].second));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    si = 0; sj = 1;
    for (int i = 0; i < n; i++) {
        seq.push_back({});
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
            seq.back().push_back(HashSeq(s[i][j]));
            if (i != j && s[i][j].size() < s[si][sj].size()) si = i, sj = j;
        }
    }

    for (int l = 1; l < s[si][sj].size(); l++) check(l);
    if (ans.empty()) cout << "NONE\n";
    else {
        cout << "UNIQUE\n";
        for (auto &t : ans) cout << t << "\n";
    }
    return 0;
}
