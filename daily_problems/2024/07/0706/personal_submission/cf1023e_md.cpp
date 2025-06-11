// 0706
#include <bits/stdc++.h>

//#define DEBUG 42

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

#ifdef DEBUG
    std::vector<std::string> board(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> board[i];
    }
#endif

    auto ask = [&](int x1, int y1, int x2, int y2) -> bool {
        std::cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << std::endl;
#ifdef DEBUG
        --x1;--x2;--y1;--y2;
        auto ret = [&]() -> bool {
            if (board[x1][y1] == '#') {
                return false;
            }
            std::vector<std::pair<int, int>> dirs = {{1, 0}, {0, 1}};
            std::queue<std::pair<int, int>> q;
            q.push({x1, y1});
            std::vector<std::vector<bool>> vis(n, std::vector<bool>(n, false));
            vis[x1][y1] = true;

            while (!empty(q)) {
                auto [x, y] = q.front();
                q.pop();
                if (x == x2 && y == y2) {
                    return true;
                }

                for (auto[dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx <= x2 && ny < y2 && !vis[nx][ny] && board[nx][ny] == '.') {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            return false;
        } ();
        std::cout << (ret ? "YES" : "NO") << std::endl; 
        return ret;
#else
        std::string res;
        std::cin >> res;
        return res == "YES";
#endif
    };
    
    int x1 = 1;
    int y1 = 1;
    std::string ret;
    for (int i = 0; i < n - 1; ++i) {
        if (ask(x1, y1 + 1, n, n)) {
            ret.push_back('R');
            ++y1;
        } else {
            ret.push_back('D');
            ++x1;
        }
    }
    
    x1 = n;
    y1 = n;
    std::string ret2;
    for (int i = 0; i < n - 1; ++i) {
        if (ask(1, 1, x1 - 1, y1)) {
            ret2.push_back('D');
            --x1;
        } else {
            ret2.push_back('R');
            --y1;
        }
    }

    std::reverse(begin(ret2), end(ret2));
    std::cout << "! " << ret + ret2 << std::endl;

    return 0;
}