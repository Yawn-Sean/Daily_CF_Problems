/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-06-27 19:07 */
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

const int N = 1234, M = 6123;

int ne[M], idx = 1, h[M], d[M], l[M], r[M];
int n, m;
bool st[N];
int ans;
vector<int> nums;

void add(int u, int v, int sl, int sr) {
    ne[idx] = h[u];
    d[idx] = v;
    l[idx] = sl;
    r[idx] = sr;
    h[u] = idx ++;
}

void dfs(int now, int sl, int sr) {
    st[now] = true;
    for (int i = h[now]; i; i = ne[i]) {
        int j = d[i];
        if (st[j] == false) {
            if (sl < l[i] || sr > r[i]) continue;
            dfs(j, sl, sr);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v, sl, sr;
        cin >> u >> v >> sl >> sr;
        add(u, v, sl, sr);
        add(v, u, sl, sr);
        nums.push_back(sl);
        nums.push_back(sr);
    }
    sort(nums.begin(), nums.end());
    int len = unique(nums.begin(), nums.end()) - nums.begin();
    for (int i = 0; i < len; i ++) {
        int ssl = i, ssr = len - 1;
        while (ssl < ssr) {
            int mid = ssl + ssr + 1 >> 1;
            for (int j = 1; j <= n; j ++) st[j] = false;
            dfs(1, nums[i], nums[mid]);
            if (st[n]) ssl = mid;
            else ssr = mid - 1;
        }
        for (int j = 1; j <= n; j ++) st[j] = false;
        dfs(1, nums[i], nums[ssl]);
        if (st[n]) ans = max(nums[ssl] - nums[i] + 1, ans);
    }
    if (ans) cout << ans << endl;
    else cout << "Nice work, Dima!" << endl;
    return 0;
}

/*

*/
