#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector<int>> gro;
    map <int,vector<int>> mps;

    for (int i = 0, s,r; i < n; ++ i){
        cin >> s >> r;
        mps[s].push_back(r);
    }

    for (auto &it : mps){
        auto &vec = it.second;
        sort(vec.begin(), vec.end(), greater<int>());
        for (int i = 1; i < vec.size(); ++ i){
            vec[i] += vec[i-1];
        }
        gro.push_back(vec);
    }

    const int N = 1e5;
    vector <int> f(N+1);

    int len = gro.size();
    for (int i = 0; i < len; ++ i){
        int r = gro[i].size();
        for (int j = 0; j < r; ++ j){
            if (gro[i][j] > 0){
                f[j+1] += gro[i][j];
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= N; ++ i){
        res = max(res, f[i]);
    }

    cout << res << "\n";
}
