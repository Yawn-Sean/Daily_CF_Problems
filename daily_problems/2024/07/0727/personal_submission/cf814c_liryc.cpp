/**
 * https://codeforces.com/contest/814/submission/272915897
 * 814 C
 * 2024/7/27 Y1
 * 滑动窗口，同样算法cpp能过，python超时！
 */

#include <iostream>
#include <string>
using namespace std;

int longestOnes(string &garland, const char &target, int k) {
    int n = garland.size(), i = 0, maxlen = 0;
    for (int j = 0; j < n; ++j) {
        char &x = garland[j];
        if (x != target) {
            --k;
            while (i < n && k < 0) {
                if (garland[i] != target) ++k;
                ++i;
            }
        }
        int le = j - i + 1;
        if (le > maxlen) maxlen = le;
    }
    return maxlen;
}

int dp[26][1501];

int main() {
    int n; cin >> n;
    string garland; cin >> garland;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = longestOnes(garland, (char)(i + 97), j);
    int m; cin >> m;
    while (m--) {
        int mi; char ci; cin >> mi >> ci;
        cout << dp[ci - 'a'][mi] << endl;
    }
    return 0;
}

/* PyPy3 - TLE
# from LC 1004
def longestOnes(garland: str, target: str, k: int) -> int:
    n, i, maxlen = len(garland), 0, 0
    for j, x in enumerate(garland):
        if x != target:
            k -= 1
            while i < n and k < 0:
                if garland[i] != target:
                    k += 1
                i += 1
        maxlen = max(maxlen, j - i + 1)
    return maxlen

if __name__ == '__main__':
    n = int(input())
    garland = input()
    dp = [[0] * (n + 1) for _ in range(26)]
    for i in range(26):
        for j in range(n + 1):
            dp[i][j] = longestOnes(garland, chr(i + 97), j)
    m = int(input())
    for _ in range(m):
        q1, q2 = input().split()
        mi, ci = int(q1), ord(q2) - 97
        print(dp[ci][mi])
*/