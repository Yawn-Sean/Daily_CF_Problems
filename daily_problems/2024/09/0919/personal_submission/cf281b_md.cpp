// 0919
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // min(abs(x / y - a / b))
    int x, y, n;
    std::cin >> x >> y >> n;

    i64 diff_nu = x, diff_de = y;
    i64 nu = 0, de = 1;
    for (int b = 1; b <= n; ++b) {
        i64 a = 1ll * x * b / y;
        for (i64 v = a; v <= a + 1; ++v) {
            i64 ndiff_nu = abs(1ll * x * b - 1ll * y * v);
            i64 ndiff_de = 1ll * y * b;
            if (ndiff_nu * diff_de < diff_nu * ndiff_de) {
                diff_nu = ndiff_nu;
                diff_de = ndiff_de;
                nu = v;
                de = b;
            }
        }
    }

    std::cout << nu << '/' << de << '\n';
    return 0;
}