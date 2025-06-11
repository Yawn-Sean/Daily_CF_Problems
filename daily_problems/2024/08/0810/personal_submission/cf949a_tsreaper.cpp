#include <bits/stdc++.h>
#define MAXS ((int) 2e5)
using namespace std;

int n;
char s[MAXS + 10];
vector<vector<int>> ans;

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);

    vector<int> vec[2];
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            if (vec[1].size() > 0) {
                ans[vec[1].back()].push_back(i);
                vec[0].push_back(vec[1].back());
                vec[1].pop_back();
            } else {
                vec[0].push_back(ans.size());
                ans.push_back({i});
            }
        } else {
            if (vec[0].size() > 0) {
                ans[vec[0].back()].push_back(i);
                vec[1].push_back(vec[0].back());
                vec[0].pop_back();
            } else {
                printf("-1\n");
                return 0;
            }
        }
    }

    if (vec[1].size() > 0) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", ans.size());
    for (auto &vec : ans) {
        printf("%d", vec.size());
        for (int x : vec) printf(" %d", x);
        printf("\n");
    }
    return 0;
}
