#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N = 200005;
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int cal(int num, int m)
{
    int ans = 0;
    while (num <= m)
    {
        ans += m - num;
        num *= 2;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        ans = gcd(ans, a);
    }
    int sum = 0;
    for (int i = 1; i * i <= ans; i++)
    {
        if (ans % i == 0)
        {
            if (i % 2 == 1)
            {
                sum += cal(i, m);
            }
            if (ans / i != i && (ans / i) % 2 == 1)
            {
                sum += cal(ans / i, m);
            }
        }
    }
    cout << sum << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while (T--)
        solve();
    return 0;
}
