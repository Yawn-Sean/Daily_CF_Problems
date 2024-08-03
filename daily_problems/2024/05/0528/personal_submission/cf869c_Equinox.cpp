
#include <bits/stdc++.h>
const int mod = 998'244'353, N = 5005;

int fac[N], invfac[N], ab, ac, bc;

int qp(int a,int b)
{
    int res = 1;
    while(b)
    {
        if(b & 1)
            res = 1LL * res * a % mod;
        b >>= 1, a = 1LL * a * a % mod;
    }
    return res;
}

int C(int n,int m)
{
    if(n == m)
        return 1;
    
    return ((1LL * fac[n] * invfac[m] % mod) * invfac[n - m]) % mod;
}

int calc(int a, int b) {
    int res = 1;
    for(int k = 1, ed = std::min(a, b); k <= ed; k ++) 
        res = (res + (((1LL * C(a, k) * C(b, k)) % mod) * fac[k]) % mod) % mod;
    return res;
}

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int n = std::max( {a, b, c} );


    fac[0] = 1;
    for(int i = 1; i <= n; i ++)
        fac[i] = 1LL * fac[i - 1] * i % mod;
    
    invfac[n] = qp(fac[n], mod - 2);

    for(int i = n - 1; i; i --)
        invfac[i] = 1LL * invfac[i + 1] * (i + 1) % mod;
    
    ab = calc(a, b), ac = calc(a, c), bc = calc(b, c);
    std::cout << ((((1LL * ab * ac) % mod) * bc) % mod);
    return 0;
}