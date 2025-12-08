#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, S, T;
    if (!(cin >> N >> M >> S >> T)) return 0;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int INF = 1e9;
    vector<int> dist(N + 1, INF);
    queue<int> q;

    dist[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (dist[T] == INF) {
        cout << 0 << endl;
        return 0;
    }

    long long MOD = 1000000009 + 7 - 2; 
    // Wait, the problem says 10^9 + 7. 
    MOD = 1000000007;

    vector<vector<int>> dp(N + 1, vector<int>(2, 0));
    vector<vector<bool>> in_queue(N + 1, vector<bool>(2, false));
    queue<pair<int, int>> dp_q;

    dp[S][0] = 1;
    dp_q.push({S, 0});
    in_queue[S][0] = true;

    while (!dp_q.empty()) {
        pair<int, int> curr = dp_q.front();
        dp_q.pop();
        int u = curr.first;
        int k = curr.second;
        
        long long current_count = dp[u][k];
        int current_dist = dist[u] + k;

        for (int v : adj[u]) {
            int new_dist = current_dist + 1;
            int diff = new_dist - dist[v];

            if (diff == 0) {
                dp[v][0] = (dp[v][0] + current_count) % MOD;
                if (!in_queue[v][0]) {
                    dp_q.push({v, 0});
                    in_queue[v][0] = true;
                }
            } else if (diff == 1) {
                dp[v][1] = (dp[v][1] + current_count) % MOD;
                if (!in_queue[v][1]) {
                    dp_q.push({v, 1});
                    in_queue[v][1] = true;
                }
            }
        }
    }

    cout << dp[T][1] << endl;

    return 0;
}
