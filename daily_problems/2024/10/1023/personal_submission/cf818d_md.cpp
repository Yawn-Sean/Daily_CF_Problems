// 1023
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, A;
    std::cin >> n >> A;
    std::vector<std::vector<int>> numIdx(1e6 + 1);
    
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        numIdx[x].push_back(i);
    }

    if (size(numIdx[A]) == 0) {
        if (A == 1) {
            std::cout << 2;
        } else {
            std::cout << 1;
        }
        return 0;
    }
        
    for (int val = 0; val <= 1e6; ++val) {
        if (val == A || size(numIdx[val]) < size(numIdx[A])) {
            continue;
        }
 
        auto check = [&]() {
            for (int idx = 0; idx < size(numIdx[A]); ++idx) {
                if (numIdx[val][idx] > numIdx[A][idx]) {
                    return false;
                }
            }
            return true;
        };

        if (check()) {
            std::cout << val << '\n';
            return 0;
        }
    }
    std::cout << -1;


    return 0;
}