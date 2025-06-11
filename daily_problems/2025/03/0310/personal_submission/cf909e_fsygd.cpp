#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int n, m, ans, res;
int degree[100010], e[100010];
int t1, q1[100010], t2, q2[100010];
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &e[i]);
        if (e[i] == 1) ++res;
    }
    vector<vector<int>> links(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        ++degree[t1];
        links[t2].push_back(t1);
    }
    for (int i = 0; i < n; ++i)
        if (degree[i] == 0) {
            if (e[i] == 0)
                q1[++t1] = i;
            else
                q2[++t2] = i;
        }
    while (res > 0) {
        for (int i = 1; i <= t1; ++i) {
            for (auto x: links[q1[i]]) {
                if (--degree[x] == 0) {
                    if (e[x] == 0) q1[++t1] = x; else q2[++t2] = x;
                }
            }
        }
        t1 = 0;
        ++ans;
        for (int i = 1; i <= t2; ++i) {
            --res;
            for (auto x: links[q2[i]]) {
                if (--degree[x] == 0) {
                    if (e[x] == 0) q1[++t1] = x; else q2[++t2] = x;
                }
            }
        }
        t2 = 0;
    }
    printf("%d\n", ans);
    return 0;
}