#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1000;
array<int, 5> pt[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0, a, b, c, d, e; i < n; i++) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        pt[i] = array<int, 5>{a, b, c, d, e};
    }
    if (n > 33) {
        printf("0\n");
    } else {
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool is_bad = false;
            auto&[a, b, c, d, e] = pt[i];
            for (int j = 0; j < n && !is_bad; j++) {
                if (j == i) continue;
                int x1 = pt[j][0] - a;
                int x2 = pt[j][1] - b;
                int x3 = pt[j][2] - c;
                int x4 = pt[j][3] - d;
                int x5 = pt[j][4] - e;
                for (int k = j + 1; k < n; k++) {
                    if (k == i) continue;
                    int y1 = pt[k][0] - a;
                    int y2 = pt[k][1] - b;
                    int y3 = pt[k][2] - c;
                    int y4 = pt[k][3] - d;
                    int y5 = pt[k][4] - e;
                    if (x1 * y1 + x2 * y2 + x3 * y3 + x4 * y4 + x5 * y5 > 0) {
                        is_bad = true;
                        break;
                    }
                }
            }
            if (!is_bad) ans.push_back(i);
        }
        printf("%d\n", ans.size());
        for (auto& i : ans) {
            printf("%d\n", i + 1);
        }
    }
    return 0;
}

