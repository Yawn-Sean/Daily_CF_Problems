#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1001, mod = 1e9 + 7, inf = 1e9;

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> Cnt(31);
    int tot = 0;
    for (int i = 0; i < 30; ++ i){
        if (n>>i & 1) ++ Cnt[i], ++ tot;
    }

    if (tot > k){
        cout << "NO\n";
        return;
    }

    for (int i = 29; i >= 1; -- i){
        while (tot < k && Cnt[i]) Cnt[i-1] += 2, -- Cnt[i], ++ tot;
    }
    if (tot < k){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i <= 29; ++ i)
            while (Cnt[i]--) cout << (1<<i) << " ";
    }
}
