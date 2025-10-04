#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<ll> down(n, 0); 
    vector<ll> up(n, 0);   
    
    auto calculate_sqrt = [](ll x, ll y) -> ll {
        ll min_val = min(x, y);
        ll root = sqrt(min_val);
        while (root * root < min_val) root++;
        while (root * root > min_val) root--;
        return max(x, y) + root;
    };
    
    function<void(int, int)> dfs_down = [&](int node, int parent) {
        down[node] = nums[node];
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                dfs_down(neighbor, node);
                down[node] = max(down[node], calculate_sqrt(down[neighbor], nums[node]));
            }
        }
    };
    
    dfs_down(0, -1);
    
    function<void(int, int)> dfs_up = [&](int node, int parent) {
        up[node] = max(up[node], nums[node]);
        
        ll first_max = up[node], second_max = 0;
        
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                ll neighbor_val = calculate_sqrt(down[neighbor], nums[node]);
                if (neighbor_val > first_max) {
                    second_max = first_max;
                    first_max = neighbor_val;
                } else if (neighbor_val > second_max) {
                    second_max = neighbor_val;
                }
            }
        }
        
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                ll neighbor_val = calculate_sqrt(down[neighbor], nums[node]);
                if (neighbor_val == first_max) {
                    up[neighbor] = calculate_sqrt(second_max, nums[neighbor]);
                } else {
                    up[neighbor] = calculate_sqrt(first_max, nums[neighbor]);
                }
                dfs_up(neighbor, node);
            }
        }
    };
    
    dfs_up(0, -1);
    
    ll result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, max(down[i], up[i]));
    }
    
    cout << result << endl;
    
    return 0;
}
