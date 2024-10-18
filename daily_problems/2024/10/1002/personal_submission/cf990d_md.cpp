// 1002
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, a, b; 
    std::cin >> n >> a >> b;

    std::vector<std::string> graph(n, std::string(n, '0'));

    if (a == 1) {
        if (b == 1) { // a == 1 && b == 1
            if (n == 2 || n == 3) {
                std::cout << "NO\n";
                return 0;
            }

            for (int i = 1; i < n; ++i) {
                graph[i][i - 1] = '1';
                graph[i - 1][i] = '1';
            }

        } else { // a == 1 && b > 1
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j) {
                        graph[i][j] = '1';
                    }
                }
            }

            for (int i = 0; i <= n - b; i ++) {
                for (int j = 0; j <= n - b; j ++) {
                    if (i != j) graph[i][j] = '0';
                }
            }
        }
    } else { // a > 1
        if (b == 1) { // a > 1 && b == 1
            for (int i = 0; i <= n - a; ++i) {
                for (int j = 0; j <= n - a; ++j) {
                    if (i != j) {
                        graph[i][j] = '1';
                    }
                }
            }
        } else { // a > 1 && b > 1
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        std::cout << graph[i] << '\n';
    }

    return 0;
}