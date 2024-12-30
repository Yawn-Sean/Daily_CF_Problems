#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n;
char s1[MAXN + 10], s2[MAXN + 10];

int main() {
    scanf("%d%s%s", &n, s1 + 1, s2 + 1);

    int goal = 0;
    vector<int> vec[3];
    for (int i = 1; i <= n; i++) {
        if (s1[i] == '1') goal++;
        int t = (s1[i] - '0') + (s2[i] - '0');
        vec[t].push_back(i);
    }

    for (int x = 0; x <= vec[0].size(); x++) {
        int z = goal - n / 2 + x, y = goal - z * 2;
        if (y < 0 || y > vec[1].size() || z < 0 || z > vec[2].size()) continue;

        vector<int> ans;
        int K[3] = {x, y, z};
        for (int k = 0; k < 3; k++) {
            while (vec[k].size() > K[k]) {
                ans.push_back(vec[k].back());
                vec[k].pop_back();
            }
        }
        for (int x : ans) printf("%d ", x);
        printf("\n");
        return 0;
    }
    printf("-1\n");
    return 0;
}
