#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> e1, e2;
    for (int i = 1, a, b; i <= m; i++) {
        scanf("%d%d", &a, &b);
        if (a < b) e1.push_back(i);
        else e2.push_back(i);
    }
    if (e1.size() < e2.size()) {
        e1.swap(e2);
    }
    printf("YES\n%d\n", e1.size());
    for (auto& x : e1) {
        printf("%d ", x);
    }
    return 0;
}
