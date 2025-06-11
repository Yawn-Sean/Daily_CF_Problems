// 0612
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string input;
    std::cin >> input;

    if (n < 2 || input[0] == ')' || input.back() == '(') {
        std::cout << ":(\n";
        return 0;
    }

    input[0] = '(';
    input.back() = ')';

    int sum {0};
    std::vector<int> r_pos;
    for (int i = 1; i < n - 1; ++i) {
        if (input[i] == '?') {
            sum--;
            input[i] = ')';
            r_pos.push_back(i);
        } else {
            sum += input[i] == '(' ? 1 : -1;
        }

        if (sum < 0) {
            if (size(r_pos) > 0) {
                input[r_pos.back()] = '(';
                r_pos.pop_back();
                sum += 2;
            } else {
                std::cout << ":(\n";
                return 0;
            }
        }
    }

    if (sum != 0) {
        std::cout << ":(\n";
    } else {
        std::cout << input << '\n';
    }

    return 0;
}