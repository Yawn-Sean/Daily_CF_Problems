#include <bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;
typedef pair<int, int> PII;
typedef long long LL;


const int N = 1e6 + 10;

int n, m;

int a[N];

int f[N];


void solve()
{
    int A, B;
    cin >> A >> B >> n;
    for (int i = 1; i <= 1e6; i ++ )
    {
        a[i] = A + (LL)(i-1) * B;
        f[i] = f[i-1] + a[i];
    }
    int L, t;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> L >> t >> m;
        int l = L, r = 1e6;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (a[mid] > t) r = mid - 1;
            else l = mid;
        }
        
        l = L;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (f[mid] - f[L - 1] <= m * t) l = mid;
            else r = mid - 1;
        }
        
        if (a[r] <= t && f[r] - f[L - 1] <= m * t)
            cout << r << '\n';
        else cout << -1 << '\n';
    }
}

signed main()
{
	cin.tie(0) -> ios::sync_with_stdio(false);
	int t = 1;
	while (t -- ) solve();
}
