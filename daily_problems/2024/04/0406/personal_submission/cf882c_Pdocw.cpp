#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<map<int, int>> left(2 * 1e5 + 1), right(2 * 1e5 + 1);
    int inf = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        if (left[l].count(r - l + 1) == 0 || left[l][r - l + 1] > c)
            left[l][r - l + 1] = c;
        if (right[r].count(r - l + 1) == 0 || right[r][r - l + 1] > c)
            right[r][r - l + 1] = c;
    }

    int ans = INT_MAX;
    map<int, int> cur;
    for (int i = 0; i < 2 * 1e5; i++)
    {
        for (auto v : right[i])
            if (cur.count(v.first) == 0 || cur[v.first] > v.second)
                cur[v.first] = v.second;

        for (auto v : left[i + 1])
            if (cur.count(x - v.first) > 0)
                ans = min(ans, cur[x - v.first] + v.second);
    }

    cout << (ans < INT_MAX ? ans : -1) << endl;

    return 0;
}
