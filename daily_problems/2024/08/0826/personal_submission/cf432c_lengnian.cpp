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
#define int long long

const int N = 1e5 + 7;
int mk[N], n, a[N], pos[N];
bool isP(int d)
{
    for (int i = 2; i * i <= d; i++)
    {
        if (d % i == 0)
            return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i < N; i++)
        mk[i] = isP(i) ? i : mk[i - 1];
    cin >> n;
    for (int i = 1; i < n + 1; i++)
        cin >> a[i], pos[a[i]] = i;
    vector<pii> ans;
    for (int i = 1; i < n + 1; i++)
    {
        int p = pos[i];
        while (p != i)
        {
            int l = mk[p - i + 1];
            ans.pb({p, p - l + 1});
            swap(a[p], a[p - l + 1]);
            pos[a[p]] = p;
            p = p - l + 1;
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].se << " " << ans[i].fi << "\n";
    return 0;
}
