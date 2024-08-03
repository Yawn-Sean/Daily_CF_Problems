#include <bits/stdc++.h>
using namespace std;

struct DF_Graph {
    vector<vector<int>> graph;
    int sz;

    DF_Graph(int n) {
        sz = n;
        graph.resize(n + 2);
        for (int i = 0; i < n + 2; i++) {
            graph[i].resize(n + 2);
        }
    }

    void arr_add (int px, int py, int lx, int ly) {
        if (px < 0) { lx += px; px = 0; }
        if (px >= sz) { return; }
        if (py < 0) { ly += py; py = 0; }
        if (py >= sz) { return; }

        if (px + lx - 1 >= sz) { lx = sz - px + 1; } 
        if (lx < 1) { return; } 
        if (py + ly - 1 >= sz) { ly = sz - py + 1; } 
        if (ly < 1) { return; } 

        graph[px][py] ++;
        graph[px + lx][py + ly] ++;
        graph[px][py + ly] --;
        graph[px + lx][py] --;
    }

    int get_max() {
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                graph[i + 1][j] += graph[i][j]; 
            }
        }
        for (int j = 0; j < sz; j++) {
            for (int i = 0; i < sz; i++) {
                graph[i][j + 1] += graph[i][j]; 
                ans = max(ans, graph[i][j]);
            }
        }
        return ans;
    }
};

void work() {
    int n, m;
    cin >> n >> m;

    DF_Graph dfgraph(n);

    vector<vector<int>> mmp(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string line_str; cin >> line_str;
        for (int j = 0; j < n; j++) {
            mmp[i][j] = ( line_str[j] == 'B');
        }
    }

    for (int i = 0; i < n; i++) {
        int min_pos = 1e9, max_pos = -1;
        for (int j = 0; j < n; j++) {
            if (mmp[i][j] == 1) {
                min_pos = min(min_pos, j);
                max_pos = max(max_pos, j);
            }
        }
        if (min_pos > max_pos) {
            dfgraph.arr_add(0, 0, n, n);
        } else if (max_pos - min_pos + 1 <= m) {
            dfgraph.arr_add(i - m + 1, max_pos - m + 1, m, m - (max_pos - min_pos));
        }
    }

    for (int j = 0; j < n; j++) {
        int min_pos = 1e9, max_pos = -1;
        for (int i = 0; i < n; i++) {
            if (mmp[i][j] == 1) {
                min_pos = min(min_pos, i);
                max_pos = max(max_pos, i);
            }
        }
        if (min_pos > max_pos) {
            dfgraph.arr_add(0, 0, n, n);
        } else if (max_pos - min_pos + 1 <= m) {
            dfgraph.arr_add(max_pos - m + 1, j - m + 1, m - (max_pos - min_pos), m);
        }
    }

    cout << dfgraph.get_max() << endl;
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("./input.txt", "r", stdin);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}