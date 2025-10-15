#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define PII pair<int, int>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128=__int128;
using ld=long double;
const int N = 2e6 + 10, M = 3e5 + 10, mod = 1e9+7, inf = 1e18;
double PI = acos(-1);
int qim(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1)
            res = res * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return res;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int e[N], ne[N], h[N], w[N],idx;
// int top[N], rnk[N], dfn[N], fa[N][18], id;
// int dep[N], son[N], sz[N], l[N], r[N];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a],h[a] = idx++;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        int n,r;cin>>n>>r;
        ld mi=1e18,ans=0,sum=PI*r*r;
        for(int i=1;i<=n;i++){
            ld a,b,c;cin>>a>>b>>c;
            ld k=abs(c)/sqrtl(a*a+b*b);
            if(k<mi){
                mi=k;
                ans=r*r*acos(k/r)-k*sqrtl(r*r-k*k);
            }
        }
        printf("%.10Lf %.10Lf\n",ans/sum,(sum-ans)/sum);
    }
    return 0;
}
