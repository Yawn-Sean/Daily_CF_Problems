/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-06-28 21:36 */
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

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << gcd(n - 1, m - 1) + 1 << endl;
    return 0;
}

/*

*/
