// 0817
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<int, 4> xs, ys;
    auto cin_sort = [&]() {
        for (int i = 0; i < 4; ++i) {
            std::cin >> xs[i] >> ys[i];
            xs[i] += 100;
            ys[i] += 100;
        }
        std::sort(begin(xs), end(xs));
        std::sort(begin(ys), end(ys));
    };

    cin_sort();
    std::vector<std::vector<int>> grid(201, std::vector<int>(201, 0));
    for (int i = xs[0]; i <= xs[2]; ++i) {
        for (int j = ys[0]; j <= ys[2]; ++j) {
            grid[i][j] = 1;
        } 
    }

    cin_sort();
    auto check = [&](int ymin, int ymax, int xmin, int xmax, int inc) {
        int left = xmin;
        int right = xmax;
        for (int y = ymin; y != ymax; y += inc) {
            if (left > right) {
                break;
            }
            for (int x = left; x <= right; ++x) {
                if (grid[x][y] == 1) {
                    return true;
                }
            }
            left++;
            right--;
        }
        return false;
    };

    if (check(ys[2], ys[3] + 1, xs[0], xs[3], 1) || check(ys[1], ys[0] - 1, xs[0], xs[3], -1)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }


    return 0;
} 