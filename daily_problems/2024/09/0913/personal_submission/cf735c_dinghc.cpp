#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    long long f1 = 2, f2 = 3;
    int i = 1;
    for (; f2 <= n; i++) {
        long long nf2 = f2;
        f2 = f1 + f2;
        f1 = nf2;
    }
    printf("%d\n", i);
    return 0;
}

