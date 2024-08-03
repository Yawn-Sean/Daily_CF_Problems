#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b; scanf("%lld%lld", &a, &b);
    int n = (sqrt(8 * (a + b) + 1) - 1) / 2;
    vector<int> ans1, ans2;
    for (int i = n; i >= 1; i--) {
        if (a >= i) ans1.push_back(i), a -= i;
        else ans2.push_back(i);
    }
    for (auto &vec : {ans1, ans2}) {
        printf("%d\n", vec.size());
        for (int x : vec) printf("%d ", x);
        printf("\n");
    }
    return 0;
}
