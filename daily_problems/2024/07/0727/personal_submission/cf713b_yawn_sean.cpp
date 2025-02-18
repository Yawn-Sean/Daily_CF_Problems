#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

vector<int> ans;

int query(int x1, int y1, int x2, int y2) {
    cout << '?' << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void solve(int x1, int y1, int x2, int y2) {
    int l, r;

    l = x1, r = x2;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (query(m, y1, x2, y2)) l = m + 1;
        else r = m - 1;
    }
    ans.emplace_back(r);

    l = y1, r = y2;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (query(x1, m, x2, y2)) l = m + 1;
        else r = m - 1;
    }
    ans.emplace_back(r);

    l = x1, r = x2;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (query(x1, y1, m, y2)) r = m - 1;
        else l = m + 1;
    }
    ans.emplace_back(l);

    l = y1, r = y2;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (query(x1, y1, x2, m)) r = m - 1;
        else l = m + 1;
    }
    ans.emplace_back(l);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ans.clear();

    int n;
    cin >> n;

    int l, r;
    l = 1, r = n;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (query(1, 1, m, n)) r = m - 1;
        else l = m + 1;
    }

    if (l < n && query(l + 1, 1, n, n)) {
        solve(1, 1, l, n);
        solve(l + 1, 1, n, n);
    }
    else {
        l = 1, r = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (query(1, 1, n, m)) r = m - 1;
            else l = m + 1;
        }
        solve(1, 1, n, l);
        solve(1, l + 1, n, n);
    }

    cout << '!';
    for (auto &x: ans)
        cout << ' ' << x;

    return 0;
}