 #include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
// const int mod = 1 ? 998244353 : 1e9 + 7;
// #define int ll
void solve()
{

    int n;
    cin >> n;
    vector<int> a(n), pos(n), prime, div(n + 1);
    vector<bool> isprime(n + 1, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i <= min(n, 500); i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            for (int j = i * i; j <= n; j += i)
            {
                isprime[j] = 0;
            }
        }
    }
    // 任一大于等于4的偶数可以表示成两个素数的和(哥德巴赫猜想)
    for (int i = 4; i <= n; i += 2)
    {
        for (auto x : prime)
        {
            if (isprime[i - x])
            {
                div[i] = x;
                break;
            }
        }
    }
    vector<pair<int, int>> ans;
    auto change1 = [&](int x, int y) {
        swap(pos[a[x]], pos[a[y]]);
        swap(a[x], a[y]);
        ans.push_back({x, y});
    };
    auto change = [&](int x, int y) // y>x
    {
        if (isprime[y - x + 1])
        {
            change1(x, y);
        }
        else if ((y - x) % 2 == 0)
        {
            int tm = y - x + 2;
            // 注意顺序，是把y换到x处
            change1(div[tm] + x - 1, y);
            change1(x, div[tm] + x - 1);
        }
        else
        {
            x++;
            int tm = y - x + 2;
            // 注意顺序
            change1(div[tm] + x - 1, y);
            change1(x, div[tm] + x - 1);
            change1(x - 1, x);
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (i != pos[i])
        {
            change(i, pos[i]); // y>x
        }
    }
    cout << ans.size() << "\n";
    for (auto [x, y] : ans)
    {
        cout << x + 1 << " " << y + 1 << "\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    t = 1;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
