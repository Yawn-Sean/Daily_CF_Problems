#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
int ans[MAXN + 1];
void pre(){
    vector<i64> ys(MAXN + 1, 0);
    for(i64 i = 1; i <= MAXN; i++){
        for(i64 j = i * 2; j <= MAXN; j += i){
            ys[j]++;
        }
    }
    vector<i64> preys(MAXN + 1, 0);
    for(int i = 1; i <= MAXN; i++){
        preys[i] = (preys[i - 1] + ys[i]) % MOD;
    }

    vector<i64> jc(MAXN + 1, 1);
    for(int i = 3; i <= MAXN; i++){
        jc[i] = jc[i - 1] * i % MOD;
    }

    for(int i = 1; i <= MAXN; i++){
        ans[i] = preys[i] * jc[i] % MOD;
    }
}
void fujikaze(){
    int n;
    cin >> n;
    cout << ans[n] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre();

    int t = 1;
    cin >> t;
    while(t--){
        fujikaze();
    }

    return 0;
}

