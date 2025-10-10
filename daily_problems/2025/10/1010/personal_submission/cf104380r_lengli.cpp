#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1'000'000'007LL;

long long modpow(long long a,long long e){
    long long r=1%MOD;
    while(e){ if(e&1) r=r*a%MOD; a=a*a%MOD; e>>=1; }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L, R;
    if(!(cin >> n >> L >> R)) return 0;
    vector<long long> A(n+1);
    for(int i=1;i<=n;i++) cin >> A[i];

    // 预处理阶乘与逆元，便于 C(m,k)
    vector<long long> fac(n+1), ifac(n+1), pow2(n+1,1);
    fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%MOD;
        pow2[i]=pow2[i-1]*2%MOD;
    }
    ifac[n]=modpow(fac[n], MOD-2);
    for(int i=n;i>0;i--) ifac[i-1]=ifac[i]*i%MOD;

    auto C = [&](int m, long long k)->long long{
        if(k<0 || k>m || m<0) return 0LL;
        return fac[m]*ifac[(int)k]%MOD*ifac[m-(int)k]%MOD;
    };

    // 记号
    const int a = L-1, b = R-1;          // X_j 的区间 [a,b]
    const int s = L-n, t = R-n;          // Y_j 的区间 [s+j, t+j]

    // 初值 j=0
    long long X = (a <= 0 && 0 <= b) ? 1 : 0;     // 即 L==1 ? 1:0
    long long Y = (s <= 0 && 0 <= t) ? 1 : 0;     // 即 L<=n<=R ? 1:0

    long long ans = 0;

    for(int j=0; j<=n-1; ++j){
        int i = n - j;                               // 当前处理 A_i
        long long coef = (X + Y) % MOD;              // 区间和
        long long w = ((A[i]%MOD+MOD)%MOD) * pow2[i-1] % MOD;
        ans = (ans + w * coef) % MOD;

        // 推到 j+1（最后一次循环后这步无效，也无妨）
        long long Xn = (2*X % MOD - C(j, b) + C(j, L-2)) % MOD;
        if (Xn < 0) Xn += MOD;
        long long Yn = (2*Y % MOD + C(j, t + j + 1) - C(j, s + j)) % MOD;
        if (Yn < 0) Yn += MOD;
        X = Xn; Y = Yn;
    }

    cout << ans % MOD << '\n';
    return 0;
}
