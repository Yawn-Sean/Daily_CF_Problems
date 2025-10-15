#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
const int inf = 1e18;
typedef pair<int, int> pii;
vector<pii> e[N];
/*
    这边就是从十字路口 i 走到十字路口 j 需要 |i - j| 个能量单位，这个建图如果每两个点之间
    都建一条边是o（n^2）这样是不行的所以我们只要建i与i+1，i+1与i的这样的就行了
    应为 i->i+3==3 ==== i->i+1->i+2->i+3这样的话复杂度就是o(n-1)的复杂度了
    然后后面跑个dij就行了
*/
void solve()
{
    int n = 0, m = 0;
    string s;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        e[i].push_back({a[i], 1});
    }
    //主要注意细节
    for (int i = 1; i < n; i++)
    {
        e[i].push_back({i + 1, 1});
        e[i + 1].push_back({i, 1});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dis(n + 1, inf);
    vector<int> vis(n + 1, 0);
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto [v, w] : e[u])
        {
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
