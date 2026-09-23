#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

// 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
// 根据题目用 FenwickTree<int> t(n) 或者 FenwickTree<long long> t(n) 初始化
template<typename T = int >
class FenwickTree {
    vector<T> tree;

public:
    // 使用下标 1 到 n
    FenwickTree(int n) : tree(n + 1) {}

    // a[i] 增加 val
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    void update(int i, T val) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += val;
        }
    }

    // 求前缀和 a[1] + ... + a[i]
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    T pre(int i) const {
        T res = 0;
        for (; i > 0; i &= i - 1) {
            res += tree[i];
        }
        return res;
    }

    // 求区间和 a[l] + ... + a[r]
    // 1 <= l <= r <= n
    // 时间复杂度 O(log n)
    T query(int l, int r) const {
        if (r < l) {
            return 0;
        }
        return pre(r) - pre(l - 1);
    }

    // 找到最小的下标 pos，满足 a[1] + ... + a[pos] >= k
    // 要求树状数组中维护的是频率/个数，并且 k >= 1 且 k <= pre(n)
    // 时间复杂度 O(log n)
    int kth(T k) const {
        int pos = 0;
        int bit = 1;

        while ((bit << 1) < tree.size()) {
            bit <<= 1;
        }

        for (; bit; bit >>= 1) {
            int nxt = pos + bit;

            if (nxt < tree.size() && tree[nxt] < k) {
                pos = nxt;
                k -= tree[nxt];
            }
        }

        return pos + 1;
    }
};

struct Query
{
    int l, r, k, id;
};

void solve()
{
    int n,q;
    cin >> n >> q;
    int K = 100005;
    vll a(n + 1),b(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) cin >> b[i];
    int B = sqrt(n) + 1;
    vector<Query> qs(q);
    for (int i = 0;i < q;i++)
    {
        cin >> qs[i].l >> qs[i].r >> qs[i].k;
        qs[i].id = i;
    }
    sort(qs.begin(), qs.end(), [&](auto& x,auto& y)
    {
        int bx = x.l / B;
        int by = y.l / B;

        if (bx != by) return bx < by;

        if (bx & 1) return x.r > y.r;
        return x.r < y.r;
    });
    FenwickTree<ll> tr1(K),tr2(K);
    vll c1(K),c2(K);
    int L = 1,R = 0;
    vll ans(q);
    auto add = [&](int x) 
    {
        if (x > K) return ;
        c1[x]++;
        c2[x]++;
        tr1.update(x,1);
        tr2.update(x,1);
    };
    for (auto&[l, r, k, id] : qs)
    {
        while (L > l) 
        {
            --L;
            if (a[L] < K)
            {
                int x = a[L];
                c1[x]++;
                tr1.update(x,1);
            }
            if (b[L] < K)
            {
                int x = b[L];
                c2[x]++;
                tr2.update(x,1);
            }
        }
        while (R < r) 
        {
            R++;
            if (a[R] < K)
            {
                int x = a[R];
                c1[x]++;
                tr1.update(x,1);
            }
            if (b[R] < K)
            {
                int x = b[R];
                c2[x]++;
                tr2.update(x,1);
            }
        }
        while (L < l) 
        {
            if (a[L] < K)
            {
                int x = a[L];
                c1[x]--;
                tr1.update(x,-1);
            }
            if (b[L] < K)
            {
                int x = b[L];
                c2[x]--;
                tr2.update(x,-1);
            }
            L++;
        }
        while (R > r) 
        {
            if (a[R] < K)
            {
                int x = a[R];
                c1[x]--;
                tr1.update(x,-1);
            }
            if (b[R] < K)
            {
                int x = b[R];
                c2[x]--;
                tr2.update(x,-1);
            }
            R--;
        }
        ll w1 = 0,w2 = 0;
        ll res = 0;
        for (int i = 1;i <= sqrt(k);i++)
        {
            res += c1[i] * tr2.pre(k / i);
            res += c2[i] * tr1.pre(k / i);
            w1 += c1[i];
            w2 += c2[i];
        }
        res -= w1 * w2;
        ans[id] = res;
    }
    for (ll x : ans) cout << x << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}