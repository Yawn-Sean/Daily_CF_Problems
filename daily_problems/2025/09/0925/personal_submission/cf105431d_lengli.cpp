#include <bits/stdc++.h>
using namespace std;

struct BITMax {
    int n; vector<int> t;
    BITMax(int n=0): n(n), t(n+1, 0) {}
    void reset(int n2){ n=n2; t.assign(n+1, 0); }
    void update(int i, int v){          
        for (; i<=n; i+=i&-i) if (t[i] < v) t[i] = v;
    }
    int query(int i) const {              
        int res = 0;
        for (; i>0; i-=i&-i) res = max(res, t[i]);
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;
    int M = N * K;

    vector<int> A(M+1), B(M+1);
    for (int i = 1; i <= M; ++i) cin >> A[i];
    for (int i = 1; i <= M; ++i) cin >> B[i];

    vector<vector<int>> pos(N+1);
    for (int j = 1; j <= M; ++j) pos[B[j]].push_back(j);

    BITMax bit(M);
    for (int i = 1; i <= M; ++i) {
        int v = A[i];
        auto &lst = pos[v];
        for (int t = (int)lst.size() - 1; t >= 0; --t) {
            int j = lst[t];
            int best = bit.query(j - 1) + 1;
            bit.update(j, best);
        }
    }
    cout << bit.query(M) << '\n';
    return 0;
}
