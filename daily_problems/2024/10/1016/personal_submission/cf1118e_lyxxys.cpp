#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    if (n > 1ll*k*(k-1)){
        cout << "NO\n";
        return;
    }
    vector <int> ps(k+2, 1);
    auto add = [&](int x){
        ps[x] += 1;
        if (ps[x] == x) ps[x] += 1;
    };

    vector <array<int,2>> ans = {{1, 2}, {2, 1}};
    n -= 2;
    int x = 2, y = 1, cur = 1;
    ps[1] = 3, ps[2] = 3;
    while (n--){
        int i = y;
        bool jg = ps[i] <= k;
        if (jg){
            ans.push_back({i, ps[i]});
            if (!n) break;
            ans.push_back({ps[i], i});
            x = ps[i], y = i;
            add(ps[i]);
            add(i);
        } else {
            while (ps[cur] > k) cur += 1;
            assert(cur <= k);
            int j = cur;
            ans.push_back({j, ps[j]});
            if (!n) break;
            ans.push_back({ps[j], j});
            x = ps[j], y = j;
            add(ps[j]);
            add(j);
        }
        n -= 1;
    }

    cout << "YES\n";
    for (auto &it : ans){
        cout << it[0] << " " << it[1] << "\n";
    }
}
