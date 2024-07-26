#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

 
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), minv(q + 1, n + 1), maxv(q + 1, 0);
    set<int> seq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) {
            minv[a[i]] = min(minv[a[i]], i);
            maxv[a[i]] = max(maxv[a[i]], i);
        }
        seq.insert(i);
    }
    seq.insert(n + 1);
    bool missq = (minv[q] == n + 1);
    for (int i = q; i >= 1; i--) {
        if (minv[i] != n + 1) {
            auto it = seq.lower_bound(minv[i]);
            while (it != seq.end() && *it <= maxv[i]) {
                if (a[*it] == 0) {
                    if (missq) { a[*it] = q; missq = false; }
                    else a[*it] = i;
                } else if (a[*it] < i) {
                    cout << "NO\n";
                    return 0;
                }
                seq.erase(it++);
            }
        }
    }
    bool has0 = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            has0 = true;
            if (missq) { a[i] = q; missq = false; }
            else a[i] = 1;
        }
    }
    if (!has0 && missq) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
