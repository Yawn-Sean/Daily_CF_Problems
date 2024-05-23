#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

i64 qpow(i64 x, i64 p)
{
    i64 ret = 1;
    while (p)
    {
        if (p & 1)
            ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x, mod - 2)

std::vector<int> fact(1, 1);
std::vector<int> inv_fact(1, 1);
i64 comb(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    while ((int)fact.size() < n + 1)
    {
        fact.push_back(1ll * fact.back() * (int)fact.size() % mod);
        inv_fact.push_back(inv(fact.back()));
    }
    return 1ll * fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::vector<int> res(1000);
    res[1] = 0;
    for (int i = 2; i < 1000; ++i)
    {
        int pcnt = std::__popcount(i);
        res[i] = res[pcnt] + 1;
    }
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;
    if (k == 0)
    {
        std::cout << 1;
        return 0;
    }
    else if (k == 1)
    {
        std::cout << s.length() - 1;
        return 0;
    }
    int n = s.length();
    bool f = false;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '1')
            s[i] = '0';
        else
        {
            s[i] = '1';
            f = true;
            break;
        }
    }
    if (!f)
        s = '1' + s;
    n = s.length();
    // std::cout << s << '\n';
    i64 ans = 0;
    for (int i = 1; i < 1000; ++i)
        if (res[i] == k - 1)
        {
            int c = i;
            for (int j = 0; j < n; ++j)
                if (s[j] == '1')
                {
                    ans = (ans + comb(n - j - 1, c)) % mod;
                    // std::cout << i << ' ' << n - j - 1 << ' ' << ans << '\n';
                    c--;
                }
        }
    std::cout << ans;
    return 0;
}