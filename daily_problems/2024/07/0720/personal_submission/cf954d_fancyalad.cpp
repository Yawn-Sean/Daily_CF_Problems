// submission link: https://codeforces.com/contest/954/submission/271502851
// 今天也来跟上双语学校

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, s, t, x, y;
    cin >> n >> m >> s >> t;
    s --; t --;
    
    vector<vector<int>> g (n);
    for (int i = 0; i < m; i ++) {
        cin >> x >> y;
        g[x - 1].emplace_back(y - 1);
        g[y - 1].emplace_back(x - 1);
    }

    vector<int> q (n), dis1 (n, -1), dis2 (n, -1);
    dis1[s] = 0; dis2[t] = 0;
    int l = 0, r = 1;
    q[0] = s;
    while (l < r) {
        int cur = q[l ++];
        int new_dis = dis1[cur] + 1;
        for (auto z: g[cur]) {
            if (dis1[z] == -1) {
                dis1[z] = new_dis;
                q[r ++] = z;
            }
        }
    }
    l = 0, r = 1;
    q[0] = t;
    while (l < r) {
        int cur = q[l ++];
        int new_dis = dis2[cur] + 1;
        for (auto z: g[cur]) {
            if (dis2[z] == -1) {
                dis2[z] = new_dis;
                q[r ++] = z;
            }
        }
    }
    int target = dis1[t], ans = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            if (min(dis1[i] + dis2[j], dis1[j] + dis2[i]) + 1 >= target) {
                ans ++;
            }
        }
    }

    cout << ans - m << endl;
    
    return 0;
}