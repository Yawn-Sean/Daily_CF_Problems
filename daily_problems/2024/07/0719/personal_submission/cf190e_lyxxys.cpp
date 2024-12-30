#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 500010, mod = 1070777777, inf = 1e9;
/*
    平衡树优化bfs
    维护没有被搜索过的节点的集合，从中排除与x不相邻的结点
*/
vector <int> g[N];
void solve(){
    int n, m;
    cin >> n >> m;
    unordered_set<int> st;

    while (m--){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    for (int i = 1; i <= n; ++ i) st.insert(i);

    vector<vector<int>> res;
    while (st.size()){
        auto t = *st.begin();
        st.erase(t);

        vector<int> stk = {t}, ans;
        while (stk.size()){
            int u = stk.back();
            stk.pop_back();
            ans.push_back(u);
            unordered_set <int> sts;
            // 遍历不可达点
            for (auto &x : g[u]){
                if (st.find(x) != st.end()){
                    st.erase(x);
                    sts.insert(x);
                }
            }
            swap(st, sts);
            for (auto &x : sts)
                stk.push_back(x);
        }
        res.push_back(ans);
    }

    cout << res.size() << "\n";
    for (auto &ans : res){
        cout << ans.size() << " ";
        for (auto &x : ans) cout << x << " ";
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
