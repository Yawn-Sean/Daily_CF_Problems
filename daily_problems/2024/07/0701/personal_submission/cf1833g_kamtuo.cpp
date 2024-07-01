/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-01 17:32 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <stack>

#define endl "\n"
typedef long long LL;

using std::cin;
using std::cout;
using std::getline;

using std::max;
using std::min;
using std::sort;

using std::vector;
using std::string;
using std::stringstream;
using std::queue;
using std::priority_queue;
using std::map;
using std::stack;

const int N = 412345;

int ne[N], idx = 1, h[N], d[N], e[N];
int n;
int sz[N];
bool ok;
vector<int> ans;

void add(int u, int v, int i) {
    ne[idx] = h[u];
    d[idx] = v;
    e[idx] = i;
    h[u] = idx ++;
}

void dfs(int now, int fa) {
    sz[now] = 1;
    for (int i = h[now]; i; i = ne[i]) {
        int j = d[i];
        if (j == fa) continue;
        dfs(j, now);
        if (sz[j] == 3) {
            ans.push_back(e[i]);
        } else {
            sz[now] += sz[j];
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        ans.clear();
        idx = 1;
        ok = true;
        for (int i = 1; i <=n; i ++) {
            h[i] = 0;
            sz[i] = 0;
        }
        for (int i = 1; i < n; i ++) {
            int u, v;
            cin >> u >> v;
            add(u, v, i);
            add(v, u, i);
        }
        dfs(1, -1);
        if (sz[1] != 3) ok = false;
        if (ok) {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i ++) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    } 
    return 0;
}

/*

*/
