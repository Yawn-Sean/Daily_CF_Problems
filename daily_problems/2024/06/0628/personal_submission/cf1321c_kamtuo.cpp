/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-06-28 21:27 */
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

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (char i = 'z'; i >= 'a'; i --) {
        for (int j = 0; j < s.size(); j ++) {
            if (s[j] == i) {
                bool ok = false;
                if (j - 1 >= 0) if (s[j - 1] == s[j] - 1) ok = true;
                if (j + 1 < s.size()) if (s[j + 1] == s[j] - 1) ok = true;
                if (ok) ans ++, s.erase(j, 1), j --;
            }
        }
        if (s.size())
        for (int j = s.size() - 1; j >= 0; j --) {
            if (s[j] == i) {
                bool ok = false;
                if (j - 1 >= 0) if (s[j - 1] == s[j] - 1) ok = true;
                if (j + 1 < s.size()) if (s[j + 1] == s[j] - 1) ok = true;
                if (ok) ans ++, s.erase(j, 1), j ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*

*/
