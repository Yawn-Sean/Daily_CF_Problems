#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

const int N = 5e5 + 10;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int now = 1, ans = 1;
    int l = 1, r = 1;
    vector<int> v;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] != a[i - 1])
            now++, r++, ans = max(ans, now);
        else
        {
            now = 1;
            for (int j = l; j <= r; j++)
            {
                if (j - l + 1 <= (r - l + 1) / 2)
                    v.push_back(a[l]);
                else
                    v.push_back(a[r]);
            }
            l = r = i;
        }
    }
    for (int j = l; j <= r; j++)
    {
        if (j - l + 1 <= (r - l + 1) / 2)
            v.push_back(a[l]);
        else
            v.push_back(a[r]);
    }
    cout << ((ans - 1) >> 1) << endl;
    for (auto x : v)
        cout << x << ' ';
    cout << endl;
}

signed main()
{
    int tt = 1;

    while (tt--)
    {
        solve();
    }
}
