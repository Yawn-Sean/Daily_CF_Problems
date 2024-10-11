/*
 *   题意：定义两个长度相同的串 s,t 为一对“神奇串”当且仅当 s 重新排列后可以变成 t。
 *   若能递归的处理s、t使其子串 s1、t1为 “神奇串" 且s = s1 + s2 + …… + sk,
 *   t = t1 + t2 + …… + tk
 *   问对于s的子串 是否存在一个重排序的串t使他们不能递归处理构成长度大于等于2的神奇串
 *
 *   存在以下条件则输出 Yes
 *   1、l == r 长度等于 1(不能构成大于等于2的)
 *   2、第一个字符和最后一个字符不同（满足条件的方案：对于t把s的第一个和最后一个字符都放开始）
 *   3、第一个字符和最后一个字符相同的情况下 至少包含三个不同的字符 （
 *      将第一个字符不同的最后一个字符全放前 再把所有的第一个字符（包含最后一个字符）放其后）
 *
 *      为什么是 >= 3， 2个不同字符不行吗？
 *      假设字符串s中仅有两个字符a、b, 则 s的形式为; a……b……a(首尾相同)
 *      则t要是其神奇串 且不是超级神奇串 t仅能以b开头，若以a开头则至少可以分为a和其余的串
 *      则构成超级神奇串.所以t以b开头 但s、t串应该长度是相同的且包含的a、b数量应该相同
 *
 * */
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e5 + 10;
int sum[N][26];
char str[N];

void solve() {
    cin >> (str+1);
    int q;
    cin >> q;
    int n = strlen(str+1);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j];
        }
        sum[i][str[i] - 'a']++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "Yes" << endl; //1、仅一个字符

        } else if (str[l] != str[r]) {
            cout << "Yes" << endl; //2、首末字符不同

        } else {
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                cnt += (sum[r][i] - sum[l - 1][i] > 0);
            }
            if (cnt >= 3) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //  cin >> T;
    while (T--)
        solve();
    return 0;
}
