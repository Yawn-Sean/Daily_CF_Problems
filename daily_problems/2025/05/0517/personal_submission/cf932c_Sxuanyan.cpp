#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int inf = 1e9;
typedef pair<int, int> pii;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> e[N];
/*
    a*x+b*y=n;
    找有没有x 和 y成立。
    如果能找到直接构造即可
    构造原理：
    用cur来记录vector中的起始值
    然后len就是环的大小->ans[i]=i+1
    最后一个指向起始点就可以形成环了。
    构造x次a大小的环和y次b大小的环即可
*/
void solve()
{
    int n = 0, a = 0, b = 0;
    cin >> n >> a >> b;
    int x = -1, y = -1;
    bool f = 1;
    for (int i = 0; i * a <= n; i++)
    {
        int k = n - i * a;
        if (k % b == 0)
        {
            x = i;
            y = k / b;
            f = 0;
            break;
        }
    }
    if (f)
    {
        cout << -1 << endl;
        return;
    }
    // 构造
    vector<int> ans(n, 0);

    int cur = 0;
    auto make_cycle = [&](int len)
    {
        int sta = cur;
        for (int i = 0; i < len - 1; i++)
        {
            ans[cur + i] = cur + i + 1;
        }
        ans[cur + len - 1] = sta;//最后一个位置指向起点。
        cur += len;
    };
    //构造x次a大小的循环
    while (x--)
    {
        make_cycle(a);
    }
    //构造y次b大小的循环
    while (y--)
    {
        make_cycle(b);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " ";
    }
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
