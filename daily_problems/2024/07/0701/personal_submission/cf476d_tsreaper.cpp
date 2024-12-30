#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K; scanf("%d%d", &n, &K);
    int t = (n - 1) * 6 + 5;
    printf("%d\n", t * K);
    for (int i = 1, l = 1; i <= n; i++, l += 6) {
        vector<int> vec = {l, l + 1, l + 2, l + 4};
        for (int i = 0; i < 4; i++) for (int j = i + 1; j < 4; j++) assert(gcd(vec[i], vec[j]) == 1);
        for (int x : vec) printf("%d ", x * K);
        printf("\n");
    }
    return 0;
}
