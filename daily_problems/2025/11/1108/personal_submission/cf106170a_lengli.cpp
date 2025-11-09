#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> bfs_dist(int start, const vector<vector<int>>& g) {
    int n = (int)g.size();
    vector<int> dist(n, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int argmax(const vector<int>& a) {
    int idx = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i] > a[idx]) idx = i;
    }
    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<int> us, vs;
    us.reserve(n-1);
    vs.reserve(n-1);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        us.push_back(u);
        vs.push_back(v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<int> d = bfs_dist(0, g);
    int diameter_u = argmax(d);
    vector<int> d1 = bfs_dist(diameter_u, g);
    int diameter_v = argmax(d1);
    vector<int> d2 = bfs_dist(diameter_v, g);

    int ans = n;
    int chosen = -1;
    for (int i = 0; i < n; ++i) {
        if ((int)g[i].size() == 1) {
            int v = max(d1[i], d2[i]);
            if (v < ans) {
                ans = v;
                chosen = i;
            }
        }
    }

    vector<int> cur;
    cur.push_back(diameter_v);
    while (cur.back() != diameter_u) {
        int u = cur.back();
        bool found = false;
        for (int v : g[u]) {
            if (d1[u] - d1[v] == 1) {
                cur.push_back(v);
                found = true;
                break;
            }
        }
        if (!found) break;
    }
    
    int k = (int)cur.size();
    vector<int> notes(n, INT_MIN);
    int idx = cur[k / 2];
    notes[idx] = k / 2;
    vector<int> parent(n, -1);
    
    vector<int> que;
    que.reserve(n);
    que.push_back(idx);
    for (size_t qi = 0; qi < que.size(); ++qi) {
        int u = que[qi];
        for (int v : g[u]) {
            if (notes[v] == INT_MIN) {
                if (d1[v] >= d2[v]) notes[v] = notes[u] - 1;
                else notes[v] = notes[u] + 1;
                parent[v] = u;
                que.push_back(v);
            }
        }
    }

    vector<int> find_leaf(n);
    for (int i = 0; i < n; ++i) find_leaf[i] = i;
    for (int i = (int)que.size() - 1; i >= 0; --i) {
        int u = que[i];
        if (parent[u] != -1) {
            find_leaf[parent[u]] = find_leaf[u];
        }
    }

    vector<string> outs;
    outs.reserve(n);
    outs.push_back(to_string(ans));
    
    for (int i = 0; i < n - 1; ++i) {
        int u = us[i], v = vs[i];
        if (notes[u] > notes[v]) swap(u, v);
        
        int leaf;
        if (d1[u] >= d2[u]) leaf = find_leaf[u];
        else leaf = find_leaf[v];
        
        int end_idx;
        if (notes[leaf] >= ans) {
            int pos = notes[leaf] - ans;
            // safety clamp
            if (pos < 0) pos = 0;
            if (pos >= k) pos = k-1;
            end_idx = cur[pos];
        } else {
            int pos = notes[leaf] + ans;
            if (pos < 0) pos = 0;
            if (pos >= k) pos = k-1;
            end_idx = cur[pos];
        }
        
        int modval = ans == 0 ? 0 : ((notes[u] % ans) + ans) % ans;
        outs.push_back( to_string(modval) + " " + to_string(leaf) + " " + to_string(end_idx) );
    }
    
    for (size_t i = 0; i < outs.size(); ++i) {
        cout << outs[i] << '\n';
    }
    
    return 0;
}
