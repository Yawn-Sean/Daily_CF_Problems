#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n), perm(n), in_circle(n), vis(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        perm[i] = x - 1;
    }

    in_circle = perm;
    for (int _ = 0; _ < log2(n) + 1; _++)
    {
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
            temp[i] = in_circle[in_circle[i]];
        in_circle = temp;
    }

    for (auto x : in_circle)
        vis[x] = 1;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            int res = INF;
            while (vis[i])
            {
                vis[i] = 0;
                res = min(res, nums[i]);
                i = perm[i];
            }
            ans += res;
        }
    }

    cout << ans << endl;

    return 0;
}
