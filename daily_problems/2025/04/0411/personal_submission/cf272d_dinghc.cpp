#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        freq[x] += 1;
        a[i] = x;
    }
    int denum = 0;
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        freq[x] += 1;
        if (x == a[i]) denum += 1;
    }
    int m;
    scanf("%d", &m);
    int ans = 1;
    for (auto& [x, k] : freq) {
        for (int i = 2; i <= k; i++) {
            int q = i;
            while (q % 2 == 0 && denum) {
                q /= 2;
                denum -= 1;
            }
            ans = 1LL * ans * q % m;
        }
    }
    printf("%d\n", ans);
    return 0;
}

