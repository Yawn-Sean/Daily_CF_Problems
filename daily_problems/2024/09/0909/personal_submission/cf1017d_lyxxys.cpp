#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> w(n);
    vector <pair<int,int>> wst(1<<n);  //二元组，分别存 权值是多少 和 哪个状态
    vector <vector<int>> f((1<<n), vector<int>((1<<n)+1));
    for (auto &x : w) cin >> x;

    for (int i = 0; i < 1<<n; ++ i){ 
        wst[i].second = i;
        for (int j = 0; j < n; ++ j){
            if ((i>>j&1) == 0){
                wst[i].first += w[n-1-j];
            }
        }
    }
    sort(wst.begin(), wst.end());
    map <int,int> mps;
    for (int i = 0; i < m; ++ i){
        string s;
        cin >> s;
        int x = 0;
        for (int j = 0; j < s.size(); ++ j)
            if (s[s.size()-1-j] == '1') x += 1<<j;
        mps[x] += 1;
    }

    // 枚举 i 和 wst 数组(权值升序) 构成的前缀和
    for (int i = 0; i < 1<<n; ++ i){
        for (int j = 0; j < 1<<n; ++ j){
            f[i][j+1] = f[i][j] + mps[i^wst[j].second];
        }   
    }


    while (q--){
        string s;
        int x = 0, k;
        cin >> s >> k;
        for (int j = 0; j < s.size(); ++ j)
            if (s[s.size()-1-j] == '1') x += 1<<j;

        int l = 0, r = wst.size()-1;
        while (l < r){
            int mid = l+r+1 >> 1;
            if (wst[mid].first <= k) l = mid;
            else r = mid-1;
        }
        cout << f[x][l+1] << "\n";
    }
}
