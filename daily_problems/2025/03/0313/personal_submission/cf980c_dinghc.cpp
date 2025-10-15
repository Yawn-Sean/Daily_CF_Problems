#include <bits/stdc++.h>

using namespace std;
constexpr int A = 256;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> colortbl(A, -1);
    set<int> s;
    s.insert(-1);
    s.insert(A);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        if (colortbl[x] == -1) {
            auto it = s.upper_bound(x);
            int pre = *--it;
            if (pre >= 0 && x - colortbl[pre] < k) {
                for (int i = pre + 1; i <= x; i++) colortbl[i] = colortbl[pre];
                s.insert(x);
            } else {
                int beg = max(pre + 1, x - k + 1);
                for (int i = beg; i <= x; i++) colortbl[i] = beg;
                s.insert(beg);
                s.insert(x);
            }
        }
        printf("%d ", colortbl[x]);
    }
    return 0;
}

