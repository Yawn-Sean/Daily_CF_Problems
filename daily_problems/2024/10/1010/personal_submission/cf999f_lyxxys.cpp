#include <bits/stdc++.h>
using namespace std;

void solve(){
    const int N = 1e5+1;

    int num, k;
    cin >> num >> k;

    vector <int> cnt(N), w(k+1);
    map <int,int> mps;
    for (int i = 0, x; i < num*k; ++ i){
        cin >> x;
        cnt[x] += 1;
    }
    for (int i = 0, x; i < num; ++ i){
        cin >> x;
        mps[x] += 1;
    }
    for (int i = 1; i <= k; ++ i){
        cin >> w[i];
    }

    int res = 0;
    for (auto &it : mps){
        int n = it.second, m = cnt[it.first];
        if (m == 0) continue;
        vector <int> f(m+1);
        for (int i = 1; i <= n; ++ i){
            for (int j = m; j >= 1; -- j){
                for (int t = j-1; t >= max(0, j-k); -- t){
                    f[j] = max(f[j], f[t] + w[j-t]);
                }
            }
        }
        res += f[m];
    }

    cout << res << "\n";
}
