#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5'000;
char c[N], a[N];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", c);
    scanf("%s", a);
    vector<int> msk(n);
    array<int, 4> b{};
    for (int i = 0; i < n; i++) {
        msk[i] = (a[i] - '0') | ((c[i] - '0') << 1);
        b[msk[i]]++;
    }
    // x[0] + x[1] + x[2] + x[3] = n / 2
    // x[2] + x[3] = b[1] - x[1] + b[3] - x[3]
    for (int x0 = 0; x0 <= b[0]; x0++) {
        for (int x1 = 0; x1 <= b[1]; x1++) {
            int x3 = (b[1] - x1 + b[3]) - (n / 2 - x0 - x1);
            int x2 = n / 2 - x0 - x1 - x3;
            if (x2 >= 0 && x2 <= b[2] && x3 >= 0 && x3 <= b[3]) {
                b = {x0, x1, x2, x3};
                for (int i = 0; i < n; i++) {
                    if (b[msk[i]] > 0) {
                        b[msk[i]]--;
                        printf("%d ", i + 1);
                    }
                }
                printf("\n");
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}

