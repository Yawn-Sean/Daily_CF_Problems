
#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    const int mod = 1e9+7;

    int n, k;
    long long l;
    cin >> n >> l >> k;
    vector <int> A(n), p(n);
    for (auto &x : A) cin >> x;
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int &x, int &y){
        return A[x] < A[y];
    });

    vector <long long> f(n*k);

    auto Id = [&](int i, int j)->int{
        return i*n + j;
    };
    // f[Id(i, j)] 以 第 i 个循环节结尾，连续选 j 个的方案
    long long res = 0;
    for (int i = 0; i < k; ++ i){
        int j = 0;
        long long cur = 0;

        for (auto u : p){
            int idx = Id(i, u);
            if (idx >= l) continue;

            if (i==0) f[idx] = 1;
            else {
                while (j < n && A[p[j]] <= A[u]){
                    cur += f[Id(i-1, p[j])];
                    cur %= mod;
                    j += 1;
                }
                f[idx] = cur;
            }
            long long t = (l - (idx+1)) / n + 1;
            t %= mod;
            if (t > 0){
                res += t * f[idx] % mod;
                res %= mod;
            }
        }
    }

    cout << res << "\n";
}
