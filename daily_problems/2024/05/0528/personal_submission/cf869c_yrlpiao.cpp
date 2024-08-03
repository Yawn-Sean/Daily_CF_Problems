#include <iostream>
using namespace std;
#define int long long

int mod = 998'244'353;
int fac[5050], infac[5050];

int qmi(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}

void init() {
    fac[0] = infac[0] = 1;
    for (int i = 1; i <= 5000; i++) {
        fac[i] = fac[i - 1] * i % mod;
        infac[i] = infac[i - 1] * qmi(i, mod - 2) % mod;
    }
    return;
}

int get(int a, int b) {
    int ret = 0;
    for (int i = 0; i <= min(a, b); i++) {
        int t1 = fac[a] * infac[i] % mod * infac[a - i] % mod;
        int t2 = fac[b] * infac[i] % mod * infac[b - i] % mod;
        ret += t1 * t2 % mod * fac[i] % mod; ret %= mod;
    }
    return ret;
}

void yrlpSolve() {
    init();
    int a, b, c; cin >> a >> b >> c;
    cout << get(a, b) * get(a, c) % mod * get(b, c) % mod;
    return; 
}    

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
