// 0921
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string input;
    std::cin >> input;

    std::vector<int> leftg(n, 0), rightg(n, 0);
    int Gcnt = 0;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (input[i] == 'G') {
            ++Gcnt;
            leftg[i] = (i - 1 >= 0) ? leftg[i - 1] + 1 : 1;
            ret = std::max(ret, leftg[i]);
        } else {
            leftg[i] = 0;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (input[i] == 'G') {
            rightg[i] = (i + 1 < n) ? rightg[i + 1] + 1 : 1;
        } else {
            rightg[i] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (input[i] == 'S') {
            int left = (i - 1 >= 0) ? leftg[i - 1] : 0;
            int right = (i + 1 < n) ? rightg[i + 1] : 0;
            ret = std::max(ret, left + right + (left + right < Gcnt));
        }
    }

    std::cout << ret << '\n';

    return 0;
}