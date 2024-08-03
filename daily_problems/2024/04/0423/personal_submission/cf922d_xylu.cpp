#include <bits/stdc++.h>

int main() {
    int n, cnths = 0;
    long long ans = 0;
    std::cin >> n;
    std::vector<std::string> ss(n);
    std::vector<int> cnth(n, 0), idx(n, 0);
    iota(idx.begin(), idx.end(), 0);
    for (int i = 0; i < n; i++) {
        auto &s = ss[i];
        std::cin >> s;
        cnth[i] = accumulate(s.begin(), s.end(), 0, [](int x, char ch) {
            return x + (ch == 'h');
        });
        cnths += cnth[i];
        int cnthi = cnth[i];
        for (auto &&ch : s) {
            if (ch == 's') ans += cnthi;
            else cnthi--;
        }
    }

    sort(idx.begin(), idx.end(), [&](const int i, const int j) {
        return (ss[i].size() - cnth[i]) * cnth[j] > (ss[j].size() - cnth[j]) * cnth[i];
    });
    for (int i = 0; i < n; i++) {
        cnths -= cnth[idx[i]];
        ans += (ss[idx[i]].size() - cnth[idx[i]]) * cnths;
    }
    std::cout << ans << '\n';
    return 0;
}
