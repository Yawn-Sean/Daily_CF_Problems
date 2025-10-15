#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    if (n == 0) { printf("a\n"); return 0; }
    vector<int> vec = {0};
    for (int i = 1; vec.back() < n; i++) vec.push_back(vec.back() + i);
    for (int i = vec.size() - 1, j = 0; i > 0; i--) while (vec[i] <= n) {
        n -= vec[i];
        for (int k = 1; k <= i + 1; k++) printf("%c", j + 'a');
        j++;
    }
    printf("\n");
    return 0;
}
