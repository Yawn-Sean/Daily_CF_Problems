#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int M = 100000 + 1;
    vector<vector<int>> factors(M);
    for(int i = 1; i < M; ++i){
        for(int j = i; j < M; j += i){
            factors[j].push_back(i);
        }
    }

    int n, mn, mx;
    cin >> n >> mn >> mx;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<long long> cnt(M, 0);
    for(int x : a){
        cnt[x]++;
    }

    long long ans = 0;

    for(int l = mn; l <= mx; ++l){
        ans += cnt[l] * (cnt[l] - 1) / 2;
        auto &fs = factors[l];
        int sz = fs.size();
        for(int i = 0; i < sz; ++i){
            int x = fs[i];
            for(int j = 0; j < i; ++j){
                int y = fs[j];
                int g = std::gcd(x, y);
                if(g >= mn && 1LL * x * y == 1LL * g * l){
                    ans += cnt[x] * cnt[y];
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
