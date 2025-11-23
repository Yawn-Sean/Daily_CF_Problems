#include <bits/stdc++.h>
using namespace std;

vector<int> t;
int t_s;

void init(int s) {
    t_s = s;
    t.assign(s + 2, 0);
}

void upd(int p) {
    p++;
    while (p <= t_s) {
        t[p]++;
        p += p & -p;
    }
}

int qry(int p) {
    p++;
    int s = 0;
    while (p > 0) {
        s += t[p];
        p -= p & -p;
    }
    return s;
}

int r_qry(int l, int r) {
    if (l > r) return 0;
    return qry(r) - qry(l - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        init(n);
        unordered_map<int, vector<int>> cs;
        unordered_map<int, int> lp;
        long long ans = 0;

        for (int r = 0; r < n; ++r) {
            lp[b[r]] = r;

            int s = 0;
            if (lp.count(a[r])) s = lp[a[r]] + 1;

            cs[a[r]].push_back(r);

            if (cs.count(b[r])) {
                for (int l : cs[b[r]]) upd(l);
                cs.erase(b[r]);
            }

            ans += r_qry(s, r - 1);
        }

        cout << ans << endl;
    }

    return 0;

}
