// 1119
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    i64 A = 0, Bx = 0, By = 0, C = 0;
    for (int i = 2; i <= 4 * n; i += 4) {
        for (int j = 2; j <= 4 * m; j += 4) {
            i64 x = 0;
            std::cin >> x;
            A += x;
            Bx += 2 * x * i;
            By += 2 * x * j;
            C += x * (i * i + j * j);
        }
    }

    auto find = [&](i64 a, i64 b) -> i64 {
        if (a == 0) {
            return 0;
        }

        i64 x0 = b / 2 / a;
        x0 /= 4;
        i64 x1 = x0 + 1;

        // min dist from b/2a to x0 => |x0 - b/2a| = |8 a x0' - b|
        if (abs(8 * a * x0 - b) <= abs(8 * a * x1 - b)) {
            return x0;
        } else {
            return x1;
        }
    };

    auto x = find(A, Bx) * 4;
    auto y = find(A, By) * 4;

    std::cout << A * (x * x + y * y) - Bx * x - By * y + C << std::endl;
    std::cout << x / 4 << " " << y / 4 << std::endl;
    return 0;
}