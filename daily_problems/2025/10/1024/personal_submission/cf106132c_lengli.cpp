#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll M, K;
    if (!(cin >> n >> M >> K)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // First pass: compute (u -> v) for each element and collect node values
    vector<pair<ll,ll>> uv; uv.reserve(n);
    vector<ll> nodes_values; nodes_values.reserve(2 * n);
    for (int i = 0; i < n; ++i) {
        // compute sq = a[i]^2 % M safely
        __int128 t = (__int128)a[i] * (__int128)a[i];
        ll sq = (ll)(t % M);
        ll u = (K - sq) % M;
        if (u < 0) u += M;
        ll v = a[i];
        uv.emplace_back(u, v);
        nodes_values.push_back(u);
        nodes_values.push_back(v);
    }

    // Coordinate compress node values
    sort(nodes_values.begin(), nodes_values.end());
    nodes_values.erase(unique(nodes_values.begin(), nodes_values.end()), nodes_values.end());
    auto get_id = [&](ll x) -> int {
        return int(lower_bound(nodes_values.begin(), nodes_values.end(), x) - nodes_values.begin());
    };
    int nodes = (int)nodes_values.size();

    // Build directed graph: edges from uid -> vid, keep original index as eid
    struct Edge { int to; int eid; };
    vector<vector<Edge>> adj(nodes);
    vector<int> indeg(nodes, 0), outdeg(nodes, 0);
    vector<pair<int,int>> und_edges; und_edges.reserve(n); // for undirected connectivity

    for (int i = 0; i < n; ++i) {
        int uid = get_id(uv[i].first);
        int vid = get_id(uv[i].second);
        adj[uid].push_back({vid, i});
        outdeg[uid] += 1;
        indeg[vid] += 1;
        und_edges.emplace_back(uid, vid);
    }

    // Check degree condition for directed Euler path
    int start = -1;
    int plus1 = 0, minus1 = 0;
    for (int i = 0; i < nodes; ++i) {
        if (outdeg[i] == indeg[i] + 1) { ++plus1; start = i; }
        else if (indeg[i] == outdeg[i] + 1) ++minus1;
        else if (indeg[i] != outdeg[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    if (!((plus1 == 0 && minus1 == 0) || (plus1 == 1 && minus1 == 1))) {
        cout << "NO\n";
        return 0;
    }
    if (start == -1) {
        // pick any node with outgoing edge
        for (int i = 0; i < nodes; ++i) if (outdeg[i] > 0) { start = i; break; }
        if (start == -1) { cout << "NO\n"; return 0; }
    }

    // Check weak connectivity among nodes that have edges (undirected)
    vector<vector<int>> und(nodes);
    for (auto &e : und_edges) {
        und[e.first].push_back(e.second);
        und[e.second].push_back(e.first);
    }
    vector<char> vis(nodes, 0);
    int any = -1;
    for (int i = 0; i < nodes; ++i) if (indeg[i] + outdeg[i] > 0) { any = i; break; }
    if (any == -1) { cout << "NO\n"; return 0; }

    // DFS/BFS
    stack<int> st;
    st.push(any);
    vis[any] = 1;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int w : und[u]) if (!vis[w]) { vis[w] = 1; st.push(w); }
    }
    for (int i = 0; i < nodes; ++i) {
        if (indeg[i] + outdeg[i] > 0 && !vis[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    // Hierholzer's algorithm to find Euler trail (store original element indices)
    vector<int> pos(nodes, 0);
    vector<int> node_stack;
    vector<int> edge_stack;
    vector<int> res_eids;
    node_stack.push_back(start);

    while (!node_stack.empty()) {
        int v = node_stack.back();
        if (pos[v] < (int)adj[v].size()) {
            Edge e = adj[v][pos[v]++];
            node_stack.push_back(e.to);
            edge_stack.push_back(e.eid);
        } else {
            node_stack.pop_back();
            if (!edge_stack.empty()) {
                res_eids.push_back(edge_stack.back());
                edge_stack.pop_back();
            }
        }
    }

    if ((int)res_eids.size() != n) {
        cout << "NO\n";
        return 0;
    }
    reverse(res_eids.begin(), res_eids.end());

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[res_eids[i]];
    }
    cout << '\n';
    return 0;
}
