#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    string s;;
    cin >> s;
    int n = s.size();
    int cnt = 1, ans = 0;  // cnt至少为1
    string double_s = s + s;
    // 视为一个环型字符串，相当于在分隔处截断，再考虑首尾拼接的字符串，在翻转某一个位置时，不会影响其他已形成的子串
    for (int i = 0; i < 2 * n - 1; i++) {
        if (double_s[i] != double_s[i+1]) {
            cnt++;
        } else {
            cnt = 1;
        }
        ans = max(cnt, ans);  // 考虑每一个位置翻转时，能够得到的最大的结果
    }
    ans = min(ans, n);  // 不能超过输入字符串的长度
    cout << ans << endl;
    return 0;
}