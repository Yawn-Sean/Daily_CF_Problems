#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> vec[3];
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vec[x % 3].push_back(x);
    }
    for (int i = 0; i < 3; i++) sort(vec[i].begin(), vec[i].end(), greater<int>());

    int sm = 0;
    for (int i = 0; i < 3; i++) sm += i * vec[i].size();
    sm %= 3;
    if (sm) {
        if (vec[sm].size() > 0) vec[sm].pop_back();
        else for (int i = 0; i < 2; i++) vec[3 - sm].pop_back();
    }

    int m = 0;
    for (int i = 0; i < 3; i++) m += vec[i].size();
    if (vec[0].empty() || vec[0].back() != 0) { printf("-1\n"); return 0; }
    if (vec[0].size() == m && vec[0][0] == 0) { printf("0\n"); return 0; }

    vector<int> ans;
    for (int i = 0; i < 3; i++) for (int x : vec[i]) ans.push_back(x);
    sort(ans.begin(), ans.end(), greater<int>());
    for (int x : ans) printf("%d", x);
    printf("\n");
    return 0;
}
