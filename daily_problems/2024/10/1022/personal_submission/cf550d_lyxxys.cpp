#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k;
    cin >> k;
    if (k%2 == 0){
        cout << "NO\n";
        return;
    }
    vector <array<int,2>> edges = {{1,2}};

    auto build = [&](int father, int low, int up){
        if (k == 1) return;
        int v1 = low, v2 = low+k-1;
        for (int d = 0; d < k-1; ++ d){
            int i = v1+d;
            edges.push_back({father, i});
        }

        for (int d = 1; d <= k-1; d += 2){
            int i = v2+d-1, j = v2+d;
            edges.push_back({i, j});
        }

        for (int d1 = 0; d1 < k-1; ++ d1){
            int i = v1+d1;
            for (int d2 = 0; d2 < k-1; ++ d2){
                int j = v2+d2;
                edges.push_back({i, j});
            }
        }
    };

    build(1, 3, 2*k);
    build(2, 2*k+1, 4*k-2);
    cout << "YES\n";
    cout << 4*k-2 << " " << edges.size() << "\n";
    for (auto &it : edges){
        cout << it[0] << " " << it[1] << "\n";
    }
}
