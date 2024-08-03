#include <bits/stdc++.h>
using namespace std;

// #define LOCAL

typedef long long ll;
typedef pair<int, int> pii;

vector<int> oracle;
vector<int> oracle_b;

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int x;

#ifdef LOCAL
    x = oracle[i] ^ oracle_b[j];
    cerr << i << "," << j << ":" << x << endl;
#else
    cin >> x;
#endif
    return x;
}

void print(int cnt, vector<int>& ret) {
    cout << "!\n";
    cout << cnt << endl;
    for (int i = 0; i < size(ret); ++i) {
        cout << ret[i] << " \n"[i == size(ret) - 1];
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

#ifdef LOCAL
    oracle.resize(n);
    oracle_b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> oracle[i];
        oracle_b[oracle[i]] = i;
    }
#endif

    vector<int> query_p0_xor_bi(n);
    vector<int> query_b0_xor_pj(n);

    for (int i = 0; i < n; ++i) {
        query_p0_xor_bi[i] = query(0, i);
    }

    query_b0_xor_pj[0] = query_p0_xor_bi[0];
    for (int j = 1; j < n; ++j) {
        query_b0_xor_pj[j] = query(j, 0);
    }

    int cnt = 0;
    auto build_b = [&](int p0) -> vector<int> {
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = query_p0_xor_bi[i] ^ p0;
        }
        return b;
    };

    auto build_p = [&](int b0) -> vector<int> {
        vector<int> p(n);
        for (int j = 0; j < n; ++j) {
            p[j] = query_b0_xor_pj[j] ^ b0;
        }
        return p;
    };

    vector<int> ret;
    auto guess = [&](int p0) -> bool {
        auto b = build_b(p0);
        auto p = build_p(b[0]);
        for (int i = 0; i < n; ++i) {
            if (b[i] >= n || p[i] >= n || p[b[i]] != i) {
                return false;
            }
        }
        ret = p;
        return true;
    };

    for (int i = 0; i < n; ++i) {
        if (guess(i)) {
            cnt++;
        }
    }

    print(cnt, ret);
    return 0;
}