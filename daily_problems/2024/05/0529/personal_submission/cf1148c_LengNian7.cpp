#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
// #define int long long

void swap(vector<int> &perm, vector<int> &pos, vector<string> &ans, int u, int v)
{
    swap(pos[perm[u]], pos[perm[v]]);
    swap(perm[u], perm[v]);
    ans.push_back(to_string(u + 1) + " " + to_string(v + 1));
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos(n, -1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        pos[a[i]] = i;
    }

    vector<string> ans;

    for (int i = 1; i < n / 2; ++i)
    {
        if (pos[i] != i)
        {
            if (pos[i] < n / 2)
            {
                swap(a, pos, ans, pos[i], n - 1);
                swap(a, pos, ans, i, n - 1);
            }
            else
            {
                swap(a, pos, ans, 0, pos[i]);
                swap(a, pos, ans, 0, n - 1);
                swap(a, pos, ans, i, n - 1);
            }
        }
    }

    for (int i = n / 2; i < n; ++i)
    {
        if (pos[i] != i)
        {
            if (pos[i] >= n / 2)
            {
                swap(a, pos, ans, 0, pos[i]);
                swap(a, pos, ans, 0, i);
            }
            else
            {
                swap(a, pos, ans, pos[i], n - 1);
                swap(a, pos, ans, 0, n - 1);
                swap(a, pos, ans, 0, i);
            }
        }
    }

    if (a[0] != 0)
    {
        swap(a, pos, ans, 0, n - 1);
    }

    cout << ans.size() << endl;
    for (const string &s : ans)
    {
        cout << s << endl;
    }

    return 0;
}
