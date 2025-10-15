#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    int capacity;
    int flow;
    int cost;
    int rev;
};

vector<vector<Edge>> adj;
vector<long long> h;
vector<long long> dist;
vector<int> prev_v, prev_e;
int V;

void add_edge(int u, int v, int cap, int cost) {
    adj[u].push_back({v, cap, 0, cost, (int)adj[v].size()});
    adj[v].push_back({u, 0, 0, -cost, (int)adj[u].size() - 1});
}


long long min_cost_flow(int s, int t, int f) {
    long long res = 0;
    h.assign(V, 0);
    while (f > 0) {
        dist.assign(V, INF);
        dist[s] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (dist[u] < d) {
                continue;
            }

            for (size_t i = 0; i < adj[u].size(); ++i) {
                Edge &e = adj[u][i];
                if (e.capacity - e.flow > 0 && dist[e.to] > dist[u] + e.cost + h[u] - h[e.to]) {
                    dist[e.to] = dist[u] + e.cost + h[u] - h[e.to];
                    prev_v[e.to] = u;
                    prev_e[e.to] = i;
                    pq.push({dist[e.to], e.to});
                }
            }
        }

       
        if (dist[t] == INF) {
            return -1;
        }

        for (int i = 0; i < V; ++i) {
            if (dist[i] != INF) {
                h[i] += dist[i];
            }
        }

        int d = f;
        for (int v = t; v != s; v = prev_v[v]) {
            d = min(d, adj[prev_v[v]][prev_e[v]].capacity - adj[prev_v[v]][prev_e[v]].flow);
        }
        
        f -= d;
        res += (long long)d * h[t];
        
        for (int v = t; v != s; v = prev_v[v]) {
            Edge &e = adj[prev_v[v]][prev_e[v]];
            e.flow += d;
            adj[v][e.rev].flow -= d;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    long long initial_ones = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                initial_ones++;
            }
        }
    }

    vector<int> A(n);
    long long sum_A = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        sum_A += A[i];
    }

    vector<int> B(m);
    long long sum_B = 0;
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
        sum_B += B[i];
    }

    if (sum_A != sum_B) {
        cout << -1 << endl;
        return 0;
    }

    int s = 0, t = n + m + 1;
    V = n + m + 2;
    adj.assign(V, vector<Edge>());
    prev_v.resize(V);
    prev_e.resize(V);

    for (int i = 0; i < n; ++i) {
        add_edge(s, i + 1, A[i], 0);
    }
    for (int j = 0; j < m; ++j) {
        add_edge(n + j + 1, t, B[j], 0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1) {
                add_edge(i + 1, n + j + 1, 1, 0);
            } else {
                add_edge(i + 1, n + j + 1, 1, 1);
            }
        }
    }

    long long flips_0_to_1 = min_cost_flow(s, t, sum_A);
    
    if (flips_0_to_1 == -1) {
        cout << -1 << endl;
    } else {
        long long total_ops = 2 * flips_0_to_1 + initial_ones - sum_A;
        cout << total_ops << endl;
    }

    return 0;
}
