#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sz(s) ((int)s.size())
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 200010;

// 尽量把 1 全选，再随便加个数 x，满足 1+x 为质数
std::vector<int> minp, primes;
set<int> s;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++)
    {
        if (minp[i] == 0)
        {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes)
        {
            if (i * p > n)
            {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i])
            {
                break;
            }
        }
    }
    for (auto v : primes)
    {
        s.insert(v);
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            cnt++;
        }
    }

    if (cnt > 1)
    {
        for (int i = 0; i < n; ++i)
        {
            if (a[i] > 1 && s.count(a[i] + 1))
            {
                cout << cnt + 1 << '\n';
                cout << a[i] << " ";
                for (int j = 0; j < cnt; ++j)
                {
                    cout << 1 << " ";
                }
                return;
            }
        }
        cout << cnt << '\n';
        for (int j = 0; j < cnt; ++j)
        {
            cout << 1 << " ";
        }
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (s.count(a[i] + a[j]))
                {
                    cout << 2 << '\n';
                    cout << a[i] << " " << a[j];
                    return;
                }
            }
        }
        cout << 1 << '\n';
        cout << a[0] << " ";
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    sieve(2E6 + 10);
    while (t--)
    {
        solve();
    }
    return 0;
}
