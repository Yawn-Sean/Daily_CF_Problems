#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using pi = pair<int, int>;

struct nod {
    int len, l, r;
    bool operator <(const nod& a) const {
        return len > a.len;
    }
};

inline int red() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = red(), k = red(), cnt = 0, i;
    vector<int> a(n), b(n);
    generate(all(a), red);
    for (int x : a) {
        if (x < 0) {
            cnt++;
        }
    }
    if (cnt > k) {
        cout << "-1\n";
    } else {
        int t = 0;
        bool ok = false;
        priority_queue<nod> q;
        for (i = 0; i < n; i++) {
            if (a[i] < 0) {
                b[i] = 1;
                k--;
            }
            if (!ok && a[i] < 0) {
                ok ^= true;
                t++;
            }
            if (ok && a[i] >= 0) {
                ok ^= true;
                ++t;
            }
        }
        int l = 0, r = 0;
        i = 0;
        while (!b[i] && i < n) {
            i++;
        }
        for (; i < n; i++) {
            if (!b[i]) {
                l = i;
                while (!b[i] && i < n) {
                    i++;
                }
                r = i - 1;
                nod cur;
                cur.l = l, cur.r = r, cur.len = r - l + 1;
                q.push(cur);
                i -= 1;
            }
        }
        int tt = t, kk = k;
        while (!q.empty()) {
            auto tot = q.top();
            q.pop();
            if (k < tot.len && kk < tot.len) {
                break;
            } else {
                if (k >= tot.len) {
                    k -= tot.len;
                    if (tot.r != n - 1) {
                        t -= 2;
                    } else {
                        t -= 1;
                    }
                }
                if (kk >= tot.len) {
                    if (tot.r != n - 1) {
                        kk -= tot.len;
                        tt -= 2;
                    }
                }
            }
        }
        cout << min(t, tt) << '\n';
    }
    
    return 0;
}

