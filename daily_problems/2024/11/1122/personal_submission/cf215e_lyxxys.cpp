#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, T b){  
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    const int N = 70;
    vector<vector<int>> divs(N+1);
    vector <long long> pow2(N, 1);
    for (int i = 1; i < 64; ++ i) pow2[i] = pow2[i-1] * 2;
    for (int i = 1; i <= N; ++ i){
        for (int j = 2*i; j <= N; j += i){
            divs[j].push_back(i);
        }
    }

    auto count = [&](long long x)->long long{
        int len = 64 - __builtin_clzll(x);  // x 的二进制长度 是 len
        vector <long long> ans(len+1);

        // 由于 1 <= k < n, 长度不可能是 1
        for (int i = 2; i < len; ++ i){
            for (auto &L : divs[i]){
                ans[i/L] += pow2[L-1];
            }
        }

        for (auto &L : divs[len]){  // 处理长度 和 x 二进制长度相同情况 的情况
            long long cur = 1, all = 0;
            for (int i = 0; i < len/L; ++ i){
                all += cur;
                cur *= pow2[L];
            }

            long long v = x / all;  // 最多是 v

            v -= (1ll << L-1) - 1;
            // cout << L << " " << all << " " << v << "\n";
            if (v < 0) v = 0;
            ans[len/L] += v;
        }
        long long res = 0;
        
        for (int i = len; i > 1; -- i){
            for (int L = 2*i; L <= len; L += i){
                ans[i] -= ans[L];
            }
            res += ans[i];
        }

        return res;
    };

    long long l, r;
    cin >> l >> r;

    cout << (count(r) - count(l-1)) << "\n";
}

