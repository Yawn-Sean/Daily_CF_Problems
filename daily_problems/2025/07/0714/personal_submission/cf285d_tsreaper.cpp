#include <bits/stdc++.h>
#define MOD ((int) 1e9 + 7)
using namespace std;

long long ans[] = {0, 1, 0, 3, 0, 15, 0, 133, 0, 2025, 0, 37851, 0, 1030367, 0, 36362925, 0};

int main() {
    int n; scanf("%d", &n);
    long long t = ans[n];
    for (int i = 1; i <= n; i++) t = t * i % MOD;
    printf("%lld\n", t);
    return 0;
}
