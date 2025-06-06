#include <bits/stdc++.h>

using namespace std;
constexpr int B = 7;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int k1 = 0, k2 = 0;
    int q = n - 1;
    while (q) {
        q /= B;
        k1 += 1;
    }
    k1 = max(k1, 1);
    q = m - 1;
    while (q) {
        q /= B;
        k2 += 1;
    }
    k2 = max(k2, 1);
    if (k1 + k2 > B) {
        printf("0\n");
        return 0;
    }
    auto check = [] (set<int>& s, int a, int k) -> bool {
        int q = a;
        for (int i = 0; i < k; i++) {
            if (s.contains(q % B)) return false;
            s.insert(q % B);
            q /= B;
        }
        return true;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        set<int> s1;
        if (check(s1, i, k1)) {
            for (int j = 0; j < m; j++) {
                set<int> s2 = s1;
                if (check(s2, j, k2)) {
                    ans += 1;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}


