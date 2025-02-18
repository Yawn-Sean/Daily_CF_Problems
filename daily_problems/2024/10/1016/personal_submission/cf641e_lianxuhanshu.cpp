#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10, mod = 1e9 + 7;
int n, m, k;

struct Node
{
    int id, a, t;
};
struct Operator
{
    int a, t, x;
} op[N];
int tr[N];
int ans[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i < N; i += lowbit(i))
        tr[i] += c;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
void solve()
{
    cin >> n;
    map<int, vector<Node>> mp;
    for (int i = 1; i <= n; i++)
    {
        int a, t, x;
        cin >> a >> t >> x;
        op[i] = {a, t, x};
        mp[x].push_back({i, a, t});
    }

    map<int, int> time;
    for (auto [u, vec] : mp)
    {
        time.clear();
        for (auto tt : vec)
        {
            time[tt.t]++;
        }
        int cnt = 0;
        for (auto &[x, y] : time)
            y = ++cnt;
        for (int i = 1; i <= vec.size(); i++)
            tr[i] = 0;
        for (auto v : vec)
        {
            int id = v.id, a = v.a, t = time[v.t];
            if (a == 1)
            {
                add(t, 1);
            }
            else if (a == 2)
            {
                add(t, -1);
            }
            else
            {
                ans[id] = query(t);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (op[i].a == 3)
        {
            cout << ans[i] << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
