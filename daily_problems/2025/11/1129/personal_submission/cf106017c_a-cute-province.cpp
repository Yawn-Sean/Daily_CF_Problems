#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 2e5 + 10;
int val[N], M[N], A[N];
int qpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1)res = res * a %mod;
        b >>= 1;
        a = a * a%mod;
    }
    return res;
}
int inv(int x){
    return qpow(x, mod-2)%mod;
}
void solve()
{
    int Q;
    cin >> Q;
    M[0] = 1;
    for(int i = 1; i <= Q; i ++){
        int op, p, q, x, j;
        cin >> op;
        if(op == 1){
            cin >> x;
            M[i] = M[i-1];
            A[i] = A[i-1];
            val[i] = (x-A[i] + mod)%mod * inv(M[i]) %mod;
        }
        else if(op == 2){
            cin >> x;
            M[i] = M[i-1];
            A[i] = A[i-1] + x;
        }
        else if(op == 3){
            cin >> p >> q;
            M[i] = M[i-1] * p%mod * inv(q)%mod;
            A[i] = A[i-1] * p%mod * inv(q)%mod; 
        }
        else{
            cin >> j;
            M[i] = M[i-1];
            A[i] = A[i-1];
            cout << (val[j] * M[i]%mod + A[i])%mod << '\n';
        }
    }
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
