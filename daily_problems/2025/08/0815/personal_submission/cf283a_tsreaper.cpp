#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> A = {0}, det = {0};
    long long tot = 0;

    int q; scanf("%d", &q);
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int x, y; scanf("%d%d", &x, &y);
            det[x - 1] += y;
            tot += 1LL * x * y;
        } else if (op == 2) {
            int x; scanf("%d", &x);
            A.push_back(x);
            det.push_back(0);
            tot += x;
        } else {
            int sz = A.size();
            tot -= A.back() + det.back();
            A.pop_back();
            det[sz - 2] += det[sz - 1];
            det.pop_back();
        }
        printf("%.12f\n", 1.0 * tot / A.size());
    }
    return 0;
}
