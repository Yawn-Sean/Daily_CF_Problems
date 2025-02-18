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
    int h, w, id;
} a[N];
int ans[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].h >> a[i].w;
        a[i].id = i;
    }

    sort(a + 1, a + 1 + n, [&](Node A, Node B)
         {
        if (min(A.h, A.w) == min(B.h, B.w))
            return max(A.h, A.w) < max(B.h, B.w);
        return min(A.h, A.w) < min(B.h, B.w); });

    int l = 1, mn = 2e9, id1 = -1;
    for (int i = 1; i <= n; i++)
    {
        int h = a[i].h, w = a[i].w, id = a[i].id;
        while (l <= i && min(a[l].h, a[l].w) < min(h, w))
        {
            if (mn > max(a[l].h, a[l].w))
                mn = max(a[l].h, a[l].w), id1 = a[l].id;
            l++;
        }
        if (mn < max(h, w))
            ans[id] = id1;
        else
            ans[id] = -1;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
