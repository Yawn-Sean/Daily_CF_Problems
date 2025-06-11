#include <bits/stdc++.h>
using namespace std;
struct fenwick {
    vector <int> info;
    int n;
    fenwick(){}
    fenwick(int n): info(n+1), n(n){}
    void add(int x, int c){
        if (x <= 0) return;
        while (x <= n) info[x] += c, x += x&-x;
    }
    int query(int x) {
        if (x < 0) return 0;
        int res = 0;
        while (x) res += info[x], x -= x & -x;
        return res;
    }
};

void solve(){
    int n;
    cin >> n;
    vector <array<int,3>> qys(n);
    map <int,int> mps;
    map <int, vector<int>> vec;
    set <int> st;
    int c = 0;
    for (auto &it : qys){
        cin >> it[0] >> it[1] >> it[2];
        mps[it[1]] = 0;
        if (it[0] == 3){
            st.insert(it[2]);  // 记录询问点
            c += 1;
        }
    }
    int tot = mps.size(), idx = 0;
    for (auto &it : mps){
        it.second = ++ idx;
    }
    fenwick Y(tot);

    vector <int> ps(n, -1), ans(c);
    for (int i = 0, idx = -1; i < n; ++ i){
        int x = qys[i][0], y = qys[i][1], z = qys[i][2];
        if (st.find(z) == st.end()) continue;
        vec[z].push_back(i); // 对每个询问点 分别模拟 操作序列
        if (x == 3) ps[i] = ++ idx;  // 记录第几个询问
    }

    for (auto &it : vec){
        auto &tmp = it.second;
        for (auto &i : tmp){
            auto &j = qys[i];
            // 只对大于它的时间戳有影响
            if (j[0] == 1){
                Y.add(mps[j[1]], 1);
            } else if (j[0] == 2){
                Y.add(mps[j[1]], -1);
            } else {
                ans[ps[i]] = Y.query(mps[j[1]]);
            }
        }
        // 清空树状数组, 倒序操作，防止时间复杂度退化
        for (auto &i : tmp){
            auto &j = qys[i];
            if (j[0] == 1){
                Y.add(mps[j[1]], -1);
            } else if (j[0] == 2){
                Y.add(mps[j[1]], 1);
            }
        }
    }

    for (auto &x : ans){
        cout << x << "\n";
    }
}
