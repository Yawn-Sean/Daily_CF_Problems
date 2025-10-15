#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (n % gcd(a, b) != 0) {
        printf("-1\n");
        return 0;
    }
    for (int r = n; r >= 0; r -= a) {
        if (r % b == 0) {
            vector<int> p(n + 1);
            int s = 1;
            for (int k = 0; k < r / b; k++) {
                for (int i = s; i < s + b - 1; i++) {
                    p[i] = i + 1;
                }
                p[s + b - 1] = s;
                s += b;
            }
            for (int k = 0; k < (n - r) / a; k++) {
                for (int i = s; i < s + a - 1; i++) {
                    p[i] = i + 1;
                }
                p[s + a - 1] = s;
                s += a;
            }
            for (int i = 1; i <= n; i++) printf("%d ", p[i]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

