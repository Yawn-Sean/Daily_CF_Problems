#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), t(n), idx(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    long long ans = 0, sum = 0;
    std::priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            int d = std::min((int)pq.size(), a[idx[i]] - a[idx[i-1]]);
            while (d--) {
                sum -= pq.top();
                pq.pop();
                ans += sum;
            }
        }
        sum += t[idx[i]];
        pq.push(t[idx[i]]);
    }
    
    while (!pq.empty()) {
        sum -= pq.top();
        pq.pop();
        ans += sum;
    }
    std::cout << ans << std::endl;
}
