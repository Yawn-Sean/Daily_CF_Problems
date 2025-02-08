#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int q = static_cast<int>(sqrt(n));
    int start = n;
    while (start >= 1) {
        for (int i = max(start - q + 1, 1); i <= start; i++) {
            printf("%d ", i);
        }
        start -= q;
    }
    return 0;
}

