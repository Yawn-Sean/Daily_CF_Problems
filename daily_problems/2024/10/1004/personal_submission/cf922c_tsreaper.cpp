#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, K; scanf("%lld%lld", &n, &K);
    for (long long i = 1; i <= K; i++) if (n % i != i - 1) { printf("No\n"); return 0; }
    printf("Yes\n"); return 0;
}
