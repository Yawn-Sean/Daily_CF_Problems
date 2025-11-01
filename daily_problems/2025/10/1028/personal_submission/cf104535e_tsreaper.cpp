#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n); n--;
    printf("0 0\n%d 1\n%d 2\n%d 2\n0 1\n-1 0\n", n, n + 1, n);
    return 0;
}
