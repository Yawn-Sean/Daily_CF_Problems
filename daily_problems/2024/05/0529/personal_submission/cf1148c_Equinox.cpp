#include <bits/stdc++.h>
using PII = std::pair<int, int>;
const int N = 3e5 + 10;
int p[N], a[N], n, s;
std::vector<PII> path;

void swap(int x, int y) {
    std::swap(p[a[x]], p[a[y]]);
    std::swap(a[x], a[y]);
    path.emplace_back(x, y);
}

int main () {
    std::cin >> n;
    path.reserve(5 * n);
    for (int i = 1; i <= n; i ++ ) std::cin >> a[i], p[a[i]] = i;
    for (int i = 1; i <= n / 2; i ++ ) {
        if (p[i] != i) {
            if (p[i] <= n / 2) {
                swap(p[i], n);
                swap(i, n);
            }
            else {
                swap(1, p[i]);
                swap(1, n);
                swap(i, n);
            }
        }
    }
    for (int i = n / 2 + 1; i <= n; i ++ ) {
        if (p[i] != i) {
            if (p[i] > n / 2) {
                swap(1, p[i]);
                swap(1, i);
            }
            else {
                swap(p[i], n);
                swap(1, n);
                swap(1, i);
            }
        }
    }
    if (a[1] != 1) swap(1, n);
    std::cout << path.size() << '\n';
    for (auto [x, y] : path) 
        std::cout << x << " " << y << '\n';
    return 0;
}