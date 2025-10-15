#include <bits/stdc++.h>
using namespace std;

long long ans;

void gao(int x) {
    vector<int> vec;
    for (int y = x; y; y /= 10) vec.push_back(9 - y % 10);
    long long r = 0;
    while (!vec.empty()) r = r * 10 + vec.back(), vec.pop_back();
    ans = max(ans, x * r);
}

int main() {
    int l, r; scanf("%d%d", &l, &r);
    for (int p = 1; p < 1e9; p *= 10) {
        int w = p * 5;
        if (l <= w && w <= r) gao(w);
    }
    gao(l); gao(r);
    printf("%lld\n", ans);
    return 0;
}
