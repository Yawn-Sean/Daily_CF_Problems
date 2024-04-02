#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<array<int, 3>> A, B;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        if (x < y) A.push_back({x, y, i});
        else B.push_back({x, y, i});
    }
    if (A.size() > B.size()) {
        sort(A.begin(), A.end());
        printf("%d\n", A.size());
        for (int i = (int) A.size() - 1; i >= 0; i--) printf("%d%c", A[i][2], "\n "[i > 0]);
    } else {
        sort(B.begin(), B.end());
        printf("%d\n", B.size());
        for (int i = 0; i < B.size(); i++) printf("%d%c", B[i][2], "\n "[i + 1 < B.size()]);
    }
    return 0;
}
