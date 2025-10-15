#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);

    vector<int> ans;
    for (int i = 2; i <= n; i += 2) ans.push_back(i);
    for (int i = 1; i <= n; i += 2) ans.push_back(i);
    for (int i = 2; i <= n; i += 2) ans.push_back(i);

    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
