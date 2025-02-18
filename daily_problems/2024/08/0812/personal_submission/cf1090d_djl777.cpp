#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<pair<int, int>> st;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        st.emplace(x, y);
    }

    if ((ll)n * (n - 1) / 2 == m) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<int> ans(n + 1);
    int x, y;
    bool flag = false;

    for (int i = 1; i <= n && !flag; i++)
        for (int j = 1; j < i && !flag; j++)
            if (!st.count({j, i})) {
                flag = true;
                x = i, y = j;
            }

    ans[x] = n - 1; ans[y] = n;
    for (int i = 1, t = 1; i <= n; i++)
        if (!ans[i])
            ans[i] = t++;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    ans[x] = n;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}