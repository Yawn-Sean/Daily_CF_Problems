#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <complex>
#include <functional>
#define ff first
#define ss second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9+250;
LL mod=1e9+7;
const int N=1e5 + 10;
int n, fa, root;
int s[N], a[N], par[N];
vector<int> g[N];
int h[N];
bool flag;

void dfs(int cur, int dep, int sum) {
    h[cur] = dep;
    if (s[cur] != -1 && s[cur] < sum) {
        flag = false;
        return ;
    } 
    for (auto &chd : g[cur]) {
        if (s[chd] != -1) 
            dfs(chd, dep + 1, max(s[chd], sum));
        else 
            dfs(chd, dep + 1, sum);
        if (!flag) return;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> fa;
        par[i] = fa;
        g[fa].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    flag = true;
    root = 1;
    a[1] = s[1];
    dfs(root, 1, s[1]);  
    if (!flag) {
        printf("-1\n");
    } else {
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            auto x = q.front(); //x在奇数层
            q.pop();

            for (auto &chd : g[x]) {    //chd在偶数层
                int minv = INF;
                for (auto &gchd : g[chd]) {     //gchd在奇数层
                    minv = min(minv, s[gchd]);
                }

                if (minv == INF) {  //chd是叶子
                    a[chd] = 0;
                } else {    //chd不是叶子
                    a[chd] = minv - s[x];
                    s[chd] = s[x] + a[chd];
                    for (auto &gchd : g[chd]) {
                        a[gchd] = s[gchd] - s[chd];
                        q.push(gchd);
                    }
                }
            }
        }
        LL res = 0;
        for (int i = 1; i <= n; i++) res += a[i];
        printf("%lld\n", res);
    }
    return 0;
}
