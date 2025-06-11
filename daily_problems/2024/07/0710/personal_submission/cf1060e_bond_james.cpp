#include <iostream>
#include <vector>
#include <functional>

using namespace std;
using li = long long;

int main() {
    int n;
    cin >> n;

    // Initialize adjacency list for the tree
    vector<vector<int>> g(n);

    // Read tree edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;  // Convert to 0-based index
        g[u].push_back(v);
        g[v].push_back(u);
    }

    li ans = 0;
    vector<int> sz(n, 0);  // Store subtree sizes
    int colors[2] = {0, 0};  // Count nodes of each color (0 and 1)

    // DFS function to calculate subtree sizes and update ans
    function<int(int, int, int)> dfs = [&](int u, int parent, int color) {
        sz[u] = 1;  // Initial size of the subtree rooted at u
        colors[color]++;  // Count the current node's color
        for (int v : g[u]) {
            if (v != parent) {
                sz[u] += dfs(v, u, color ^ 1);  // Recurse and add subtree sizes
            }
        }
        if (parent != -1) {
            ans += static_cast<li>(sz[u]) * (n - sz[u]);  // Calculate the contribution
        }
        return sz[u];
    };

    dfs(0, -1, 0);  // Start DFS from node 0 with no parent and color 0

    // Adjust the final answer by adding the cross-color pairs contribution
    ans = (ans + static_cast<li>(colors[0]) * colors[1]) / 2;

    cout << ans << endl;

    return 0;
}
