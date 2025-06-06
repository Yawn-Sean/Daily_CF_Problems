#include <bits/stdc++.h>

using std::cin, std::cout, std::ios;

constexpr int maxn = 55;
int n, m; 
std::string g[maxn];

bool check(int x, int y, int a, int b) {
    // (x, y) -> (a, b)
    
    bool ok1 = false, ok2 = false;

    bool cur = true;
    for(int i = std::min(x, a); i <= std::max(x, a) and cur; i++) {
        if(g[i][std::min(b, y)] == 'W') {
            cur = false;
            break;
        }
    }
    ok1 |= cur;
    cur = true;
    for(int i = std::min(x, a); i <= std::max(x, a) and cur; i++) {
        if(g[i][std::max(b, y)] == 'W') {
            cur = false;
            break;
        }
    }
    ok1 |= cur;

    cur = true;
    for(int i = std::min(b, y); i <= std::max(b, y) and cur; i++) {
        if(g[std::min(a, x)][i] == 'W') {
            cur = false;
            break;
        }
    }
    ok2 |= cur;
    cur = true;
    for(int i = std::min(b, y); i <= std::max(b, y) and cur; i++) {
        if(g[std::max(a, x)][i] == 'W') {
            cur = false;
            break;
        }
    }
    ok2 |= cur;

    return ok1 and ok2;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> g[i];

    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            for(int a = 0; a < n; a++) {
                for(int b = 0; b < m; b++) {
                    if(x == y and a == b) continue;
                    if(g[x][y] == 'B' and g[a][b] == 'B') {
                        if(!check(x, y, a, b)) {
                            cout << "NO" << '\n';
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "YES" << '\n';

    return 0;
}