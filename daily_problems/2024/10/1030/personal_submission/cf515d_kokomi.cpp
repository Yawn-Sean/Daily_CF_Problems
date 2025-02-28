#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAXN = 2005;
char grid[MAXN][MAXN];
int n, m;
int ds[MAXN][MAXN];
stack<pair<int, int>> s;

const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool is_valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }

    // Initialize ds array and push cells with only one adjacent empty cell into stack
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] == '.') {
                int adjacent_empty = 0;
                for (auto dir : directions) {
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if (is_valid(x, y) && grid[x][y] == '.') {
                        adjacent_empty++;
                    }
                }
                ds[i][j] = adjacent_empty;
                if (adjacent_empty == 1) {
                    s.push({i, j});
                }
            }
        }
    }

    // Process the stack
    while (!s.empty()) {
        auto now = s.top();
        s.pop();
        int i = now.first;
        int j = now.second;

        // Find the adjacent empty cell and place the tile
        for (auto dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;
            if (is_valid(x, y) && grid[x][y] == '.') {
                if (dir == make_pair(1, 0)) {
                    grid[i][j] = '^';
                    grid[x][y] = 'v';
                } else if (dir == make_pair(-1, 0)) {
                    grid[i][j] = 'v';
                    grid[x][y] = '^';
                } else if (dir == make_pair(0, 1)) {
                    grid[i][j] = '<';
                    grid[x][y] = '>';
                } else if (dir == make_pair(0, -1)) {
                    grid[i][j] = '>';
                    grid[x][y] = '<';
                }
                // Update adjacent counts for neighboring cells
                for (auto dir2 : directions) {
                    int nx = x + dir2.first;
                    int ny = y + dir2.second;
                    if (is_valid(nx, ny) && grid[nx][ny] == '.') {
                        ds[nx][ny]--;
                        if (ds[nx][ny] == 1) {
                            s.push({nx, ny});
                        }
                    }
                }
                for (auto dir2 : directions) {
                    int nx = i + dir2.first;
                    int ny = j + dir2.second;
                    if (is_valid(nx, ny) && grid[nx][ny] == '.') {
                        ds[nx][ny]--;
                        if (ds[nx][ny] == 1) {
                            s.push({nx, ny});
                        }
                    }
                }
                break;
            }
        }
    }

    // Check if all cells are covered
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] == '.') {
                cout << "Not unique" << endl;
                return 0;
            }
        }
    }

    // Output the resulting grid
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}
