#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, s;
    cin >> n >> s;
    vector <int> w(n);
    for (auto &x : w) cin >> x;

    multiset <int> st;
    for (int i = 0; i < n; ++ i)
        if (i != s-1) st.insert(w[i]);

    int res = w[s-1] == 0;
    // u 是 当前结点 有 u 个父节点链 的 点
    auto dfs = [&](auto &&self, int u)->void{
        if (!st.size()) return;
        bool jg = 0;
        while (st.size() && st.find(u) != st.end()){
            ++ res;
            st.erase(st.find(u));
            jg = 1;
        }
        if (jg) self(self, u+1);
        else if (st.size()){
            // 如果有 0 的， 先把 0 删除，否则再 删更大的
            if (*st.begin() < u) st.erase(st.find(*st.begin()));
            else st.erase(st.find(*st.rbegin()));
            self(self, u+1);
        }
    };

    dfs(dfs, 1);
    cout << n-res << "\n";
}
 
