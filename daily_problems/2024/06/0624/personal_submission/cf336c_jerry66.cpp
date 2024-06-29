#include <bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;
typedef pair<int, int> PII;
typedef long long LL;


const int N = 2e5 + 10;

int n, m;

int a[N];



void solve()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int v = 30; v >= 0; v -- )
    {
        int s = INT_MAX;
        vector<int> res;
        for (int i = 0; i < n; i ++ )
            if (a[i] >> v & 1)
            {
                s &= a[i];
                res.push_back(a[i]);
            }
        if (s % (1 << v) == 0)
        {
            cout << res.size() << endl;
            for (int x : res) cout << x << ' ';
            return;
        }
    }
    cout << -1 << endl;
}

signed main()
{
	cin.tie(0) -> ios::sync_with_stdio(false);
	int t = 1;
	while (t -- ) solve();
}
