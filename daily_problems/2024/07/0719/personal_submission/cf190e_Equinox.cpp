#include <bits/stdc++.h>
#define sc scanf
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 5e5 + 5, M = 2e6 + 5;

struct edge{
    int v, nxt;
} adj[M];

int head[N], idx;
int q[N], t, f;

void addEdge(int u, int v) {
    adj[idx] = { v, head[u] }, head[u] = idx ++;
}

void solve() {
    memset(head, -1, sizeof head);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0, a, b; i < m; ++ i) {
        std::cin >> a >> b;
        -- a, -- b;
        addEdge(a, b), addEdge(b, a);
    }



    std::unordered_set<int> st;
    for (int i = 0; i < n; ++ i) st.insert(i);

    std::vector<std::vector<int>> scc;

    while(st.size()) {
        int u = *st.begin();
        st.erase(u);

        f = t = 0;
        q[t ++] = u;
        std::unordered_set<int> new_st;
        std::vector<int> buf;
        while (t - f) {
            buf.push_back(u = q[f ++]);
            for (int i = head[u]; ~i; i = adj[i].nxt) {
                if (st.count(adj[i].v)) {
                    new_st.insert(adj[i].v);
                    st.erase(adj[i].v);
                }
            }

            for (int x : st)
                q[t ++] = x;
            st = std::move(new_st);
// std::cerr << "OK\n";
// std::cerr << f << ' ' << t << '\n';
// std::cerr << st.size() << ' ' << buf.size() << '\n';
// exit(0);
        }
        scc.emplace_back(std::move(buf));

    }

    std::cout << scc.size() << '\n';
    for (auto& v : scc) {
        std::cout << v.size() << ' ';
        for (int i = 0, ed = v.size(); i < ed; ++ i)
            std::cout << v[i] + 1 << " \n"[i == ed - 1];
    }
}

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}