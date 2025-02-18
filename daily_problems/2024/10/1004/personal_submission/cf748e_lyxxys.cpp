#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int limi = 1e9, N = 1e7+1;
long long cnt[N];

void solve(){
    long long n, k;
    cin >> n >> k;
    long long all = 0;
    for (int i = 0, x; i < n; ++ i){
        cin >> x;
        all += x;
        cnt[x] += 1;
    }
    if (all < k){
        cout << -1 << "\n";
        return;
    }

    long long cur = 0;
    for (int i = N; i >= 1; -- i){
        cur += cnt[i];
        if (2*i-1 <= N){
            cnt[i] += cnt[2*i-1];
            cnt[i-1] += cnt[2*i-1];
        }
        if (2*i <= N){
            cur += cnt[2*i];
            cnt[i] += 2*cnt[2*i];
        }
        if (cur >= k){
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}
 
