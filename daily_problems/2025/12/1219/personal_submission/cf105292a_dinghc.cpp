#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2000;
char grid[N + 1][N + 1];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    vector<bool> v_lights(m, false);
    for (int i = 0; i < n; i++) {
        bool h_light = false;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                if (!h_light && !v_lights[j]) {
                    grid[i][j] = 'L';
                    h_light = true;
                    v_lights[j] = true;
                }
            } else {
                h_light = false;
                v_lights[j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", grid[i]);
    }
    return 0;
}

