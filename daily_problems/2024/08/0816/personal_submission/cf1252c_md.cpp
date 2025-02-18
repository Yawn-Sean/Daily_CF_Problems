// 0816
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> r(n), c(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(r));
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(c));

    std::transform(begin(r), end(r), begin(r), [](int x) { return x % 2; });
    std::transform(begin(c), end(c), begin(c), [](int x) { return x % 2; });

    std::vector<int> ids_r(n), ids_c(n);
    std::iota(begin(ids_r), end(ids_r), 0);
    std::iota(begin(ids_c), end(ids_c), 0);

    for (int i = 1; i < n; ++i) {
        if (r[i] == r[i - 1]) {
            ids_r[i] = ids_r[i - 1];
        }

        if (c[i] == c[i - 1]) {
            ids_c[i] = ids_c[i - 1];
        }
    }

    for (int i = 0; i < q; ++i) {
        int ra, ca, rb, cb;
        std::cin >> ra >> ca >> rb >> cb;
        --ra; --ca; --rb; --cb;
        
        if (ids_r[ra] == ids_r[rb] && ids_c[ca] == ids_c[cb]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }


    return 0;
}