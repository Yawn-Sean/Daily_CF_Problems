#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int a;
    string s;
    cin >> a;
    cin >> s;
    int n = s.size();
    vector <int> cnt(9*n+1);
    for (int i = 0; i < n; ++ i){
        int cur = 0;
        for (int j = i; j < n; ++ j){
            cur += s[j]-'0';
            cnt[cur] += 1;
        }
    }

    long long res = 0;  // 子数组 和 相乘为0 的有序对数
    if (a){
        for (int i = 1; i <= 9*n; ++ i){
            if (cnt[i] == 0 || a%i) continue;
            int j = a/i;
            if (j > 9*n) continue;
            res += 1ll * cnt[i] * cnt[j];
        }
    } else {
        int all = 1ll*n*(n+1)/2;
        res += 2ll * cnt[0] * (all - cnt[0]);
        res += 1ll * cnt[0] * cnt[0];
    }

    cout << res << "\n";
}
