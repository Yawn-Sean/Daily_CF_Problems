#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, K, A[MAXN + 5];
vector<int> ans;

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = n; i > 0; i--) {
        vector<int> tmp;
        int now = 0;
        bool flag = false;
        for (int x : ans) {
            if (now == A[i] && !flag) tmp.push_back(i), flag = true;
            tmp.push_back(x);
            if (x >= i + K) now++;
        }
        if (!flag) tmp.push_back(i);
        ans = tmp;
    }
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
