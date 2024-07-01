/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-01 18:24 */
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

const int N = 512345;

int pr[N], psum, minp[N];
bool st[N], st2[N];
int now_set, now_loc;
vector<int> ans[N];

int main() {
    int n, k;
    cin >> n >> k;
    cout << (5 + (6 * (n - 1))) * k << endl;
    for (int i = 1; i <= n; i ++) {
        cout << (1 + (6 * (i - 1))) * k << ' ' << ((3 + (6 * (i - 1)))) * k << ' ' << ((5 + (6 * (i - 1)) - 1)) * k << ' ' << (5 + (6 * (i - 1))) * k << endl;
    }
    return 0;
}

/*

*/
