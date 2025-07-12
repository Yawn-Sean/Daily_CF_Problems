#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<int, int> freq;
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        freq[x] += 1;
    }
    int mx = 0, cnt = 0;
    while (!freq.empty()) {
        auto [x, k] = *freq.begin();
        freq.erase(freq.begin());
        if (k > 1) freq[x + 1] += k / 2;
        cnt += k & 1;
        mx = max(mx, x);
    }
    printf("%d\n", mx - cnt + 1);
    return 0;
}

