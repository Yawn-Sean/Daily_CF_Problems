#include <bits/stdc++.h>
using namespace std;

void solve(){
    int h, m, n;
    cin >> h >> m >> n;

    auto mo = [&](int x){
        return (x%h + h) % h;
    };

    vector <int> g_idx(h, -1), g_pos(h, -1);
    vector <vector<int>> tmps;
    int all = 0;
    for (int i = 0, j; i < h; ++ i){  // 预处理环
        if (g_idx[i] == -1){
            int j = i, c = 0;  // 变量 c 是环上结点的编号，tmps[i][j]表示第i个环的第j个结点原来的下标 
            vector <int> tmp;
            while (g_idx[j] == -1){
                g_idx[j] = all;
                g_pos[j] = c;
                tmp.push_back(j);
                c += 1;
                j = mo(j + m);
            }
            tmps.push_back(tmp);
            all += 1;
        }
    }
    map <int,int> ps;
    vector <set<int>> st(all);
    for (int i = 0; i < h; ++ i){
        st[g_idx[i]].insert(g_pos[i]);
    }
    long long res = 0;

    for (int i = 0, id, ha1; i < n; ++ i){
        char ch;
        cin >> ch;
        if (ch == '+'){
            cin >> id >> ha1;
            int x = g_idx[ha1];
            ha1 = g_pos[ha1];
            if (st[x].find(ha1) != st[x].end()){
                st[x].erase(ha1);
                ps[id] = tmps[x][ha1];
            } else {
                auto it = st[x].lower_bound(ha1);
                // 考虑环形，如果在set的末尾位置 检查 最前面
                if (it == st[x].end()) it = st[x].begin();
                assert(it != st[x].end());
                int ha2 = *it;
                st[x].erase(ha2);
                ps[id] = tmps[x][ha2];
                int mod = tmps[x].size();
                res += (ha2-ha1 + mod) % mod;
            }
        } else {
            cin >> id;
            int p = ps[id];
            st[g_idx[p]].insert(g_pos[p]);
        }
    }

    cout << res << "\n";
}
