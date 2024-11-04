#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector <int> per(n+1), vis(n+1);
    for (int i = 1; i <= n; ++ i){
        cin >> per[i];
    }

    int res = 0, all = 0;
    for (int i = 0, x; i < n; ++ i){
        cin >> x;
        all += x;
    }
    res += all % 2 == 0;

    all = 0;
    
    for (int i = 1; i <= n; ++ i){
        if (vis[i]) continue;
        int j = i;
        all += 1;
        while (!vis[j]){
            vis[j] = 1;
            j = per[j];
        }
    }

    if (all > 1){
        res += all;
    }

    cout << res << "\n";
}
