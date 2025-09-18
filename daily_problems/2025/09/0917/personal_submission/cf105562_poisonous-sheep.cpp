#include <bits/stdc++.h>

#define int long long
#define ld long double
#define ll long long
#define lowbit(x) x & -x

using namespace std;

const int N = 6000;
const int mod = 1e9+7;
const int INF = 1e18;

#define endl '\n'
#define rep(l, r) for (int i = l; i <= r; i++)
#define lep(r, l) for (int i = r; i >= l; i--)

using pii = pair<int, int>;
using i64 = int64_t;



int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define ok cout << "YES\n"
#define no cout << "NO\n"

int fid[N];


void solve()
{
    int n;
    cin>>n;
    int sum=0;
    rep(0,n-1){
        int x;cin>>x;
        sum+=x;
        sum%=mod;
    }
    int t=0;
    rep(0,n-1){
        t+=n/gcd(i,n);
        t%=mod;
    }
    int inv=qpow(n,mod-2);
    cout<<((sum*t)%mod*(inv)%mod*(inv)%mod)%mod<<endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
