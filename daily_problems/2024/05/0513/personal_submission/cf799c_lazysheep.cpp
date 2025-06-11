#include <vector>
#include <ranges>
#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int n, c, d;
    std::cin >> n >> c >> d;
    std::vector<std::vector<int>> C, D;
    for (int i = 0; i < n; i++) {
        int b, p; char c;
        std::cin >> b >> p >> c;
        if (c == 'C') {
            C.push_back({p, b});
        } else {
            D.push_back({p, b});
        }
    }
    std::ranges::sort(C);
    std::ranges::sort(D);
    int lenc = C.size(), lend = D.size();
    std::vector<int> prec(lenc), pred(lend);
    int mx = 0;
    for (int i = 0; i < lenc; i++) {
        mx = std::max(mx, C[i][1]);
        prec[i] = mx;
    }
    mx = 0;
    for (int i = 0; i < lend; i++) {
        mx = std::max(mx, D[i][1]);
        pred[i] = mx;
    }

    int it1 = std::upper_bound(C.begin(), C.end(), std::vector<int>{c, 0}, 
    [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
        return lhs[0] < rhs[0];
    }) - C.begin();
    it1--;
    int it2 = std::upper_bound(D.begin(), D.end(), std::vector<int>{d, 0}, 
    [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
        return lhs[0] < rhs[0];
    }) - D.begin();
    it2--;
    int ans = 0;
    if (it1 >= 0 && it2 >= 0) {
        ans = std::max(ans, prec[it1] + pred[it2]);
    }

    for (int i = lenc - 1; i > 0; i--) {
        if (C[i][0] > c)    continue;
        int it = std::upper_bound(C.begin(), C.end(), std::vector<int>{c - C[i][0], 0}, 
        [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
            return lhs[0] < rhs[0];
        }) - C.begin();
        it--;
        if (it >= i) it = i - 1;
        if (it >= 0)
            ans = std::max(ans, C[i][1] + prec[it]);
    }
    for (int i = lend - 1; i > 0; i--) {
        if (D[i][0] > d)    continue;
        int it = std::upper_bound(D.begin(), D.end(), std::vector<int>{d - D[i][0], 0}, 
        [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
            return lhs[0] < rhs[0];
        }) - D.begin();
        it--;
        if (it >= i) it = i - 1;
        if (it >= 0)
            ans = std::max(ans, D[i][1] + pred[it]);
    }

    std::cout << ans << '\n';
    
    return 0;
}
