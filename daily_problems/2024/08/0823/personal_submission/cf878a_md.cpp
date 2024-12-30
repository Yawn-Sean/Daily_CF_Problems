// 0823
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::bitset<10> mask;
    std::bitset<10> dep(1023);
    for (int i = 0; i < n; ++i) {
        char op;
        int num;
        std::cin >> op >> num;
        for (int bit = 0; bit < 10; ++bit) {
            if (op == '|') {
                if ((num >> bit) & 1) {
                    mask.set(bit);
                    dep.reset(bit);
                }
            } else if (op == '&') {
                if (!((num >> bit) & 1)) {
                    mask.reset(bit);
                    dep.reset(bit);
                }
            } else {
                if ((num >> bit) & 1) {
                    mask.flip(bit);
                }
            }
        }
    }

    int and_ops = 0, or_ops = 0, xor_ops = 0;
    for (int i = 0; i < 10; ++i) {
        if (dep[i]) {
            if (mask[i]) {
                xor_ops |= 1 << i;
            }
        } else {
            if (mask[i]) {
                or_ops |= 1 << i;
            } else {
                and_ops |= 1 << i;
            }
        }
    }

    std::cout << "3\n";
    std::cout << "& " << (1023 ^ and_ops) << '\n';
    std::cout << "| " << or_ops << '\n';
    std::cout << "^ " << xor_ops << '\n';
    return 0;
}