#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector <int> ans(n+1, 2e9);

    for (int i = 1; i <= n; i <<= 1){
        vector <int> qrys;
        for (int j = 1; j <= n; ++ j)
            if (j&i) qrys.push_back(j);
        if (!qrys.size()) continue;
        cout << qrys.size() << "\n";
        for (auto &x : qrys) cout << x << " ";
        cout << "\n" << flush;
        for (int j = 1, x; j <= n; ++ j){
            cin >> x;
            if ((j&i) == 0){
                ans[j] = min(ans[j], x);
            }
        }
    }

    for (int i = 1; i <= n; i <<= 1){
        vector <int> qrys;
        for (int j = 1; j <= n; ++ j)
            if ((j&i) == 0) qrys.push_back(j);
        if (!qrys.size()) continue;
        cout << qrys.size() << "\n";
        for (auto &x : qrys) cout << x << " ";
        cout << "\n" << flush;
        for (int j = 1, x; j <= n; ++ j){
            cin >> x;
            if (j&i){
                ans[j] = min(ans[j], x);
            }
        }
    }

    cout << -1 << "\n";
    for (int i = 1; i <= n; ++ i){
        cout << ans[i] << "\n "[i < n];
    }
    cout << flush;
}
