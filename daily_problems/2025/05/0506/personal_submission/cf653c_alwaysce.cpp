#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](int i) {
        if (i % 2 == 0) {
            return (a[i] < a[i + 1]);
        } else {
            return (a[i] > a[i + 1]);
        }
    };

    int tot = 0;
    vector<int> vis(n);
    vector<int> ok(n - 1);
    for (int i = 0; i < n - 1; i++) {
        ok[i] = check(i);
        tot += ok[i];
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (ok[i] == 0) {
            for (int u = i; u <= i + 1; u ++) {
                for (int v = 0; v < n; v++) {
                    if (u == i && v == i + 1) continue;
                    swap(a[u], a[v]);

                    int new_tot = tot;
                    for (int nu = u - 1; nu <= u; nu++) {
                        if (nu >= 0 && nu < n - 1 && !vis[nu]) {
                            vis[nu] = 1;
                            new_tot -= ok[nu];
                            new_tot += check(nu);
                        }
                    }

                    for (int nv = v - 1; nv <= v; nv++) {
                        if (nv >= 0 && nv < n - 1 && !vis[nv]) {
                            vis[nv] = 1;
                            new_tot -= ok[nv];
                            new_tot += check(nv);
                        }
                    }

                    if (new_tot == n - 1) { ++ans; }
                    
                    for (int nu = u - 1; nu <= u; nu++) {
                        if (nu >= 0 && nu < n - 1) {
                            vis[nu] = 0;
                        }
                    }
                    for (int nv = v - 1; nv <= v; nv++) {
                        if (nv >= 0 && nv < n - 1) {
                            vis[nv] = 0;
                        }
                    }

                    swap(a[u], a[v]);
                }
            }
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
