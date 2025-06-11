#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1050, mod = 1e9+7, inf = 1e9;

void solve(){
    int n, m;
    cin >> n;
    vector <int> cows(n+1);
    for (int i = 1; i <= n; ++ i) cin >> cows[i];

    int limit = sqrt(n);
    vector <array<int,3>> blo1, blo2;
    cin >> m;
    // 以(n-1)/b 分成两块，一块大于sqrt(n), 一块小于sqrt(n)
    for (int i = 1; i <= m; ++ i){
        int a, b;
        cin >> a >> b;
        if ((n-a)/b > limit) blo1.push_back({a,b,i});
        else blo2.push_back({a,b,i});
    }
    sort(blo1.begin(), blo1.end(), [&](array<int,3>& x, array<int,3>& y){
       return  x[1] < y[1];
    });

    vector<ll> ans(m+1);
    for (auto [a, b, id] : blo2){
        ll sum = 0;
        while (a <= n) sum += cows[a], a += b;
        ans[id] = sum;
    }
    {
        int now = -1;
        vector <ll> Suf(n+1);
        for (auto [a, b, id]: blo1) {
            if (b != now){
                now = b;
                for (int i = n; i >= 1; -- i)
                    Suf[i] = cows[i] + (i+b <= n ? Suf[i+b] : 0);
            }
            ans[id] = Suf[a];
        }
    }
    for (int i = 1; i <= m; ++ i)
        cout << ans[i] << "\n";
}
