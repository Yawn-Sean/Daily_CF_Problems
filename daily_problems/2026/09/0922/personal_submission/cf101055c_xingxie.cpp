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

int N = 200005; // 最大筛到 N

vector<int> primes;                  // 存储所有质数
vector<bool> isPrime(N + 1, true);   // isPrime[i] = true 表示 i 是质数
vector<int> min_p(N + 1);            // min_p[i] = i 的最小质因子

// 莫比乌斯函数 mu
// mu[1] = 1
// mu[n] = 0   ：n 含有平方质因子，例如 4 | n、9 | n
// mu[n] = (-1)^k：n 是 k 个不同质数的乘积
vector<int> mu(N + 1);

auto init = []
{
    isPrime[0] = isPrime[1] = false;
    mu[1] = 1;

    for (int i = 2; i <= N; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            min_p[i] = i;
            mu[i] = -1;
        }
        for (int p : primes)
        {
            if (1LL * i * p > N) break;
            isPrime[i * p] = false; // 标记为合数
            min_p[i * p] = p;
            if (i % p == 0)
            {
                mu[i * p] = 0;
                break;
            }
            else
            {
                mu[i * p] = -mu[i];
            }
        }
    }

    return 0;
}();

void solve()
{
    ll n;
    cin >> n;
    vll a;
    for (int p : primes)
    {
        if (1LL * p * p > n) break;
        a.push_back(1LL * p * p);
    }
    ll l = 0,r = (ll)4e10;
    auto check = [&](ll x)
    {
        ll sum = 0;
        for (ll i = 1;i * i <= x;i++)
        {
            sum += 1LL * mu[i] * (x / (i * i));
        }
        return sum >= n;
    };
    while (l + 1 < r)
    {
        ll m = l + r >> 1;
        if (check(m)) r = m;
        else l = m;
    }
    cout << r << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}