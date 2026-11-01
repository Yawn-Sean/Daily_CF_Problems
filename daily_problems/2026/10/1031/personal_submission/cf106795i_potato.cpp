#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using ll=long long;
using PII=pair<int,int>;
using ld=long double;
using u32=unsigned int;
using u64=unsigned long long;
using i128=__int128_t;
using u128=__uint128_t;
mt19937_64 rnd(
    static_cast<u64>(
        chrono::steady_clock::now().time_since_epoch().count()
    )
);
const int mod=1e9+7;//998244353;
const ll inf=0x3f3f3f3f3f3f3f3f;//0x3f3f3f3f;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const ld PI = acos(-1);
const ld eps = 1e-12L;
const ld INF = numeric_limits<ld>::max();
// //质数筛
vector<int> prime, minp;
void sieve(int n = 2510) {
    minp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) 
        {
            minp[i] = i;
            prime.push_back(i);
        }
        for (auto j : prime) 
        {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
        }
    }
}
void solve()
{
    /*
    核心：大于sqrt(m)的质因数只会出现一个
    */
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    a.erase(unique(a.begin()+1,a.end()),a.end());
    int nn=a.size()-1;

    int ans=nn;
    for(int i=0;i<(1LL<<15);i++)
    {
        int res=__builtin_popcountll(i);
        set<int> mp;
        bool flag=1;
        for(int j=1;j<=nn;j++)
        {

            int t=a[j];
            for(int k=0;k<=14;k++)
            {
                if(!((i>>k)&1))continue;
                while(t%prime[k]==0)t/=prime[k];
            }

            if(t!=a[j])continue;

            while(t!=minp[t])
            {
                t/=minp[t];
            }
            if(t>47)mp.insert(t);
            else 
            {
                flag=0;
                break;
            }
        }

        if(flag)
        {
            // for(int j=0;j<=14;j++)
            // {
            //     if(((i>>j)&1))cout<<j<<' ';
            // }
            // cout<<endl;
            res+=mp.size();
            ans=min(ans,res);
        }
    }
    cout<<ans<<endl;
    // for(int i=0;i<=14;i++)
    // {
    //     cout<<prime[i]<<' ';
    // }
    // cout<<endl;//p[0]=2,p[14]=47
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    sieve();
    while(t--)
    {
        solve();
    }
    return 0;
}
