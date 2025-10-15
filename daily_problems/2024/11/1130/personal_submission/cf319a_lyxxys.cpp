#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    const int mod = 1e9+7;
    auto pows = [&](long long a, int b)->int{
        long long res = 1;
        while (b){
            if (b&1) res = res*a % mod;
            a = a*a % mod;
            b >>= 1;
        }
        return res;
    };
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    int d = pows(2, n-1);

    int res = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '0') continue;
        int j = pows(2, i);
        res += 1ll * j * d % mod;
        if (res >= mod) res -= mod;
    }

    cout << res << "\n";
}
