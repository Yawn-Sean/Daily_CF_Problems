// 0521
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    string S, T;
    cin >> S;
    cin >> T;

    if (S == T) {
        cout << n + 1;
        return 0;
    }

    int start = n;
    int end = 0;
    for (int i = 0; i < n; ++i) {
        if (S[i] != T[i]) {
            start = min(start, i);
            end = max(end, i);
        }
    }

    auto len = end - start;
    int prev = S.substr(start + 1, len) == T.substr(start, len);
    int post = S.substr(start, len) == T.substr(start + 1, len);

    cout << prev + post << endl;

    return 0;
}