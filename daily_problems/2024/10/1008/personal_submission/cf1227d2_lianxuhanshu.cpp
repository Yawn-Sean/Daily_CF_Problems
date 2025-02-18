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
const int N = 2e5 + 10, mod = 1e9 + 7;
int n, m, k;

struct Node
{
    int id, v;
} a[N];
int b[N];
struct Query
{
    int id, k, pos;
} query[N];
int ans[N];
int tr[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int que(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].v;
        a[i].id = i;
        b[i] = a[i].v;
    }
    sort(a + 1, a + 1 + n, [&](Node A, Node B)
         {
        if(A.v==B.v)return A.id<B.id;
        return A.v>B.v; });
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> query[i].k >> query[i].pos;
        query[i].id = i;
    }
    sort(query + 1, query + 1 + m, [&](Query A, Query B)
         { return A.k < B.k; });

    int L = 1;
    for (int i = 1; i <= m; i++)
    {
        int id = query[i].id, k = query[i].k, pos = query[i].pos;
        while (L <= k)
        {
            add(a[L].id, 1);
            L++;
        }

        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (que(mid) >= pos)
                r = mid;
            else
                l = mid + 1;
        }
        ans[id] = r;
    }

    for (int i = 1; i <= m; i++)
        cout << b[ans[i]] << '\n';
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
