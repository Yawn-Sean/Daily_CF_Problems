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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

int N = 2000005; // 最大筛到 N
vector<int> primes;// 存储质数
vector<bool> isPrime(N + 1, true); // isPrime[i] = true 表示 i 是质数
vector<int> min_p(N + 1);// i的最小质因子
vector<ll> cnt(N + 1);
vector<ll> pre(N + 2);
auto init = [] 
{
    isPrime[0] = isPrime[1] = false; 
    for (int i = 2; i <= N; ++i) 
    {
        if (isPrime[i]) 
        {
            primes.push_back(i);
            min_p[i] = i;
        }
        for (int p : primes) 
        {
            if (1LL * i * p > N) break; 
            isPrime[i * p] = false; // 标记为合数
            min_p[i * p] = p;
            if (i % p == 0) break;  // 保证每个合数只被最小质因子筛掉一次
        }
    }
    for (int i = 1;i <= N;i++) 
    {
        int x = i;
        ll ans = 1;
        while (x > 1) 
        {
            int p = min_p[x];
            int cc = 0;
            while (x % p == 0)
            {
                x /= p;
                cc++;
            }
            ans = ans * (2 * cc + 1);
        }
        cnt[i] = ans;
    }
    for (int i = 2;i <= N;i++) pre[i] = pre[i - 1] + (cnt[i] - 1) / 2;

    return 0;
}();
void solve()
{
    int n;
    cin >> n;
    cout << pre[n] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}