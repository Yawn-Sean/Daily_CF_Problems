#include <bits/stdc++.h>
using namespace std;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> perm(n);
    vector<int> pos(n);
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++)
    {
        cin >> perm[i];
        perm[i]--;
        pos[perm[i]] = i;
    }

    function<void(int, int)> op = [&](int u, int v)
    {
        ans.push_back({u, v});
        swap(pos[perm[u]], pos[perm[v]]);
        swap(perm[u], perm[v]);
    };

    for (int i = 1; i < n - 1; i++)
    {
        if (pos[i] != i)
        {
            int start = pos[i], target = i;
            if (start < n / 2)
            {
                op(start, n - 1);
                start = n - 1;
            }
            else
            {
                op(0, start);
                start = 0;
            }
            if (abs(target - start) < n / 2)
            {
                op(0, n - 1);
                start ^= n - 1;
            }
            op(start, target);
        }
    }

    if (perm[0] != 0)
        op(0, n - 1);

    cout << ans.size() << '\n';

    for (auto &[x, y] : ans)
        cout << x + 1 << ' ' << y + 1 << '\n';

    return 0;
}