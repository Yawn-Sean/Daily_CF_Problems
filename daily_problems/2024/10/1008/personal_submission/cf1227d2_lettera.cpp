#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
template <typename T> struct Fenwick
{
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0)
    {
        init(n_);
    }

    void init(int n_)
    {
        n = n_;
        a.assign(n + 1, T{});
    }

    void add(int x, const T &v)
    { // f[x]+=v
        for (int i = x; i <= n; i += i & -i)
        {
            a[i] = a[i] + v;
        }
    }

    T sum(int x)
    { // f[1]+f[2]+...+f[x]
        T ans{};
        for (int i = x; i; i -= i & -i)
        {
            ans = ans + a[i];
        }
        return ans;
    }

    T binary_search(int x) // 查找数组前缀和>=x的位置
    {
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (sum(mid) >= x)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
    T rangeSum(int l, int r)
    {
        return sum(r) - sum(l);
    }
};
bool cmp(array<int, 2> a, array<int, 2> b)
{
    return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
}
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    vector<int>val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
        a[i][1] = i;
        val[i]=a[i][0];
    }
    sort(a.begin(), a.end(), cmp);
    int q;
    cin >> q;
    vector<int> ans(q);
    vector<vector<array<int, 2>>> K(n);
    for (int i = 0; i < q; i++)
    {
        int k, pos;
        cin >> k >> pos;
        k--;
        K[k].push_back({pos, i});
    }
    Fenwick<int> tree(n);
    for (int i = 0; i < n; i++)
    {
        tree.add(a[i][1] + 1, 1);
        auto tmp = K[i];
        for (int j = 0; j < tmp.size(); j++)
        {
            auto [x, y] = tmp[j];
            ans[y]=val[tree.binary_search(x)-1];
        }
    }
    for(int i=0;i<q;i++)
    {
    	cout<<ans[i]<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
