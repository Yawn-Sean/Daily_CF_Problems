#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> acc13(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> acc22(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> acc31(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j + 2 < m; j++){
            if(grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2]){
                acc13[i + 1][j + 1] = 1;
            }
        }
    }

    for(int i = 0; i + 1 < n; i++){
        for(int j = 0; j + 1 < m; j++){
            if(grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 1][j + 1]){
                acc22[i + 1][j + 1] = 1;
            }
        }
    }

    for(int i = 0; i + 2 < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j]){
                acc31[i + 1][j + 1] = 1;
            }
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < m; j++){
            acc13[i][j + 1] += acc13[i][j];
            acc22[i][j + 1] += acc22[i][j];
            acc31[i][j + 1] += acc31[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++){
            acc13[i + 1][j] += acc13[i][j];
            acc22[i + 1][j] += acc22[i][j];
            acc31[i + 1][j] += acc31[i][j];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        bool flg = true;

        if(y2 >= y1 + 2){
            int v = acc13[x1][y1] - acc13[x2 + 1][y1] - acc13[x1][y2 - 1] + acc13[x2 + 1][y2 - 1];
            if(v) flg = false;
        }

        if(x2 > x1 && y2 > y1){
            int v = acc22[x1][y1] - acc22[x2][y1] - acc22[x1][y2] + acc22[x2][y2];
            if(v) flg = false;
        }

        if(x2 >= x1 + 2){
            int v = acc31[x1][y1] - acc31[x2 - 1][y1] - acc31[x1][y2 + 1] + acc31[x2 - 1][y2 + 1];
            if(v) flg = false;
        }

        cout << (flg ? "YES\n" : "NO\n");
    }

    return 0;
}
