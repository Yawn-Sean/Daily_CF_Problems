#include <bits/stdc++.h>

using namespace std;
constexpr int N = 200'000;
char s[N + 1];

int main() {
    int n;
    scanf("%d%s", &n, s);
    vector<int> ppos, apos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') apos.push_back(i);
        else if (s[i] == 'P') ppos.push_back(i);
    }
    auto check = [&] (int t) {
        int j = 0;
        for (auto& x : ppos) {
            int l = min(x, apos[j]), r = max(x, apos[j]);
            while (r - l + min(x - l, r - x) <= t) {
                if (++j == apos.size()) return true;
                l = min(l, apos[j]);
                r = max(r, apos[j]);
            }
        }
        return false;
    };
    int lo = 0, hi = n << 1;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        if (check(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", lo);
    return 0;
}

