#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sz(s) ((int)s.size())
#define ms(s, x) memset(s, x, sizeof(s))
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 200010;

/*
树状数组
*/
template <typename T>
struct Fenwick
{
    int n;
    std::vector<T> a;

    Fenwick(int n = 0)
    {
        init(n);
    }

    void init(int n)
    {
        this->n = n;
        a.assign(n + 1, T());
    }

    void add(int x, T v)
    {
        for (; x <= n; x += x & (-x))
        {
            a[x] += v;
        }
    }

    T sum(int x)
    {
        auto ans = T();
        for (; x; x -= x & (-x))
        {
            ans += a[x];
        }
        return ans;
    }

    T rangeSum(int l, int r)
    {
        return sum(r) - sum(l);
    }
    // 求小于等于 s 的最小下标
    int kth(T s)
    {
        int pos = 0;
        for (int j = 18; j >= 0; j--)
        {
            if (pos + (1 << j) <= n && a[pos + (1 << j)] <= s)
            {
                pos += (1 << j);
                s -= a[pos];
            }
        }
        return pos;
    }
};
void solve()
{
    int n;
    cin >> n;

    Fenwick<int> tr(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ans += tr.rangeSum(x, n);
        tr.add(x, 1);
    }

    cout << (ans % 2 == n % 2 ? "Petr" : "Um_nik") << '\n';
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
