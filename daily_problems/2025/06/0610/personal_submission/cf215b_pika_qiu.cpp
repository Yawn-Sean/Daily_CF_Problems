// Author: zengyz
// 2025-06-10 09:51

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> q(n), p(n), s(n);
    for (auto &x : q)
        cin >> x, x--;
    for (auto &x : s)
        cin >> x, x--;
    auto check = [&](vector<int> &a, vector<int> &b) -> bool
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    };

    for (int i = 0; i < n; i++)
        p[q[i]] = i;
    vector<int> cur(n);
    iota(cur.begin(), cur.end(), 0);
    if (check(cur, s))
    {
        cout << "NO";
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = cur[q[i]];
        swap(ans, cur);
        // cout<<cur[i]<<"+";
        if (check(cur, s))
        {
            if ((k - i) % 2 == 0 && (i > 1 || k == 1 || !check(p, s)))
            {

                cout << "YES";
                return;
            }
            break;
        }
    }
    iota(cur.begin(), cur.end(), 0);
    for (int i = 1; i <= k; i++)
    {
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[q[i]] = cur[i];
        swap(ans, cur);

        if (check(cur, s))
        {
            if ((k - i) % 2 == 0 && (i > 1 || k == 1 || !check(q, s)))
            {

                cout << "YES";
                return;
            }
            break;
        }
    }
    cout << "NO";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _T = 1;
    // cin >> _T;
    while (_T--)
    {
        solve();
    }
    return 0;
}