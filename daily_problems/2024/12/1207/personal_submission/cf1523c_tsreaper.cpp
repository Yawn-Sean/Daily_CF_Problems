#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; scanf("%d", &n);
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x == 1) vec.push_back(1);
        else {
            while (vec.back() + 1 != x) vec.pop_back();
            vec.pop_back();
            vec.push_back(x);
        }
        for (int j = 0; j < vec.size(); j++) {
            if (j) printf(".");
            printf("%d", vec[j]);
        }
        printf("\n");
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
