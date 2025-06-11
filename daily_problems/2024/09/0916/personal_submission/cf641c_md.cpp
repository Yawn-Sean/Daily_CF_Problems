// 0916
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    
    bool swap = false;
    int odd_offset = 0;
    int even_offset = 0;
    for (int i = 0; i < q; ++i) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x;
            std::cin >> x;
            odd_offset = (odd_offset + n + x) % n;
            even_offset = (even_offset + n + x) % n;
            swap ^= (x & 1);
        } else {
            if (swap > 0) {
                even_offset = (even_offset + 1 + n) % n;
                odd_offset = (odd_offset - 1 + n) % n;
            } else {
                even_offset = (even_offset - 1 + n) % n;
                odd_offset = (odd_offset + 1 + n) % n;
            }
            swap ^= 1;
        }
    }

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            nums[(i + odd_offset) % n] = i;
        } else {
            nums[(i + even_offset) % n] = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << nums[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}