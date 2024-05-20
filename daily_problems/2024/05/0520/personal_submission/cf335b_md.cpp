// 0520
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string input;
    cin >> input;

    int len = size(input);
    map<char, int> freq;
    for (auto ch : input) {
        ++freq[ch];
    }

    for (auto& [ch, cnt] : freq) {
        if (cnt >= 100) {
            cout << string(100, ch) << endl;
            return 0;
        }
    }

    vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
    for (int j = 1; j <= len ; ++j) {
        dp[j][j] = 1;
        for (int i = j - 1; i >= 1; --i) {
            if (input[i - 1] == input[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    int left = 1;
    int right = len;
    string half{};
    while (left < right) {
        if (input[left - 1] == input[right - 1]) {
            half += input[left - 1];
            ++left;
            --right;
        } else {
            if (dp[left][right] == dp[left + 1][right]) {
                ++left;
            } else {
                --right;
            }
        }
    }

    if (size(half) >= 50) {
        half.resize(50);
        string reversed_half = half;
        reverse(begin(reversed_half), end(reversed_half));
        cout << half << reversed_half << endl;
        return 0;
    } else {
        cout << half;
        if (left == right) {
            cout << input[left - 1];
        }
        string reversed_half = half;
        reverse(begin(reversed_half), end(reversed_half));
        cout << reversed_half << endl;
    }

    return 0;
}