vector<int> h2(int root, vector<vector<pair<int, int>>> &g, int color, vector<int> &vis) {
    int n = g.size();
    vector<int> ans = {-1};
    for(int i=0; i<2; i++) {
        unordered_set<int> st, local_vis;
        local_vis.insert(root);
 
        vector<int> tmp;
        if(i == 1) {
            st.insert(root);
            tmp.push_back(root);
        }
        queue<int> q;
        q.push(root);
        while(!q.empty()) {
            int t = q.front();
            vis[t] = 1;
            q.pop();
            for(auto& son: g[t]) {
                if((son.second + st.count(t) + st.count(son.first)) % 2 != color) {
                    if(local_vis.count(son.first)) {
                        tmp[0] = -1;
                    } else {
                        st.insert(son.first);
                        tmp.push_back(son.first);
                    }
                }
 
                if(local_vis.count(son.first) == 0) {
                    q.push(son.first);
                    local_vis.insert(son.first);
                }
            }
        }
 
        if(tmp.size() > 0 && tmp[0] == -1) {
            continue;
        }
        if((ans.size() > 0 && ans[0] == -1) || tmp.size() < ans.size()) {
            ans = tmp;
        }
    }
    return ans;    
}
 
vector<int> h(vector<vector<pair<int, int>>> &g, int color) {
    int n = g.size();
    vector<int> vis(n);
    vector<int> ans;
    for(int i=0; i<n; i++) {
        if(vis[i] == 0) {
            auto tmp = h2(i, g, color, vis);
            if(tmp.size() > 0 && tmp[0] == -1) {
                ans.resize(n);
                return ans;
            }
            for(int num: tmp) {
                ans.emplace_back(num);
            }
        }
    }
    return ans;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<int, int>>> g(n);
 
    for(int i=0; i<m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if(c == 'R') c = 0;
        else c = 1;
        g[u-1].push_back({v-1, c});
        g[v-1].push_back({u-1, c});
    }
 
    vector<int> ans1 = h(g, 0), ans2 = h(g, 1);
    if(ans2.size() < ans1.size()) ans1 = ans2;
    if(ans1.size() >= n) cout << -1 << endl;
    else {
        cout << ans1.size() << endl;
        for(int i: ans1) printf("%d ", i+1);
    }
}
