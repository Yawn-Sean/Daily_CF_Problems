// 0713
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> ret;    
    auto f = [&](auto self, int n, int t) -> void {
        if (n <= 3) {
            for (int i = 0; i < n - 1; ++i) {
                ret.push_back(t); 
            }
            ret.push_back(n * t);
            return;
        }

        for (int i = 0; i < n - n / 2; ++i) {
            ret.push_back(t);
        }
        self(self, n / 2, t * 2);
    };

    f(f, n, 1);
    for (auto x : ret) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
 
    return 0;
}