#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
void solve()
{
    int a, b, x, y, t;
    cin >> a >> b >> x >> y >> t;
    if (a == t && b == t)
    {
        cout << x << ' ' << y << endl;
    }
    else if (a == t)
    {
        cout << x << ' ' << 0 << endl;
    }
    else if (b == t)
    {
        cout << 0 << ' ' << y << endl;
    }
    else
    {
        int cc = lcm(t - a, b - t);

        int x1 = cc / (t - a);
        int y1 = cc / (b - t);

        int num = min(x / x1, y / y1);
        if (num != 0)
            cout << x1 * num << ' ' << y1 * num << endl;
        else
        {
            int ans1 = 0, ans2 = y;
            int aa = a, bb = b;
            a = t - a;
            b = b - t;
            // cout << a << ' ' << b << endl;
            //  cout << a << ' ' << b << endl;
            for (int i = 1; i <= x; i++)
            {
                int num = (a * i + b - 1) / b;
                // cout << num << endl;
                if (num > y || aa * i + bb * num < t * (i + num))
                    continue;
                if (aa * i * ans2 + bb * num * ans1 < aa * ans1 * num + bb * ans2 * i)
                {
                    ans1 = i;
                    ans2 = num;
                }
                else if (aa * i * ans2 + bb * num * ans1 == aa * ans1 * num + bb * ans2 * i && i + num > ans1 + ans2)
                {
                    ans1 = i;
                    ans2 = num;
                }
                // cout << ans1 << ' ' << ans2 << endl;
            }
            cout << ans1 << ' ' << ans2 << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
