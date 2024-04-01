#include <bits/stdc++.h>

using namespace std;
constexpr int MX_N = 200001;
int c[MX_N];
int a[MX_N];
int indeg[MX_N];
bool vis[MX_N]{};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i != a[i]) {
            indeg[a[i]]++;
        } else {
            ans += c[i];
            vis[i] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        int u = i;
        while (vis[u] == false && indeg[u] == 0) {
            vis[u] = true;
            u = a[u];
            indeg[u]--;
        }
    }

    for (int i = 1; i <= n; i++) {
        int u = i;
        if (vis[u] == true) continue;
        int mi = c[u];
        while (vis[u] == false) {
            vis[u] = true;
            u = a[u];
            mi = min(mi, c[u]);
        }
        ans += mi;
    }

    cout << ans << "\n";

    return 0;
}

