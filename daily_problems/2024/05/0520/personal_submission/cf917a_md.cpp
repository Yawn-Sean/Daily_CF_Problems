// 0520
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string input;
    std::cin >> input;

    int n = size(input);
    int ret = 0;
    for (int start = 0; start < n; ++start) {
        int sum = 0;
        int r_cnt = 0;
        for (int end = start; end < n; ++end) {
            if (input[end] == '?') {
                --sum;
                ++r_cnt;
            } else {
                sum += (input[end] == '(') ? 1 : -1;
            }

            if (sum < 0) {
                if (r_cnt > 0) {
                    --r_cnt;
                    sum += 2;
                } else {
                    break;
                }
            }

            if (sum == 0) {
                ++ret;
            }
        }
    }

    cout << ret << endl;

    return 0;
}