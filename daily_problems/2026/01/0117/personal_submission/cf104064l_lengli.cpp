#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, i, k;
    cin >> n >> i >> k;

    long double ans = 0.0L;

    auto pw = [&](long double x){
        return pow(x, k);
    };

    ans += pw((long double)(i - 1) / n) * i;

    for(long long M = i; M <= n; ++M){
        long double cur = pw((long double)M / n);
        long double prev = pw((long double)(M - 1) / n);
        ans += (cur - prev) * (M + 1) / 2.0L;
    }

    cout << fixed << setprecision(12) << (double)ans << "\n";
    return 0;
}
