// https://codeforces.com/problemset/submission/1340/309189007
// 记忆化回溯
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, k;
int a[2002];
int dp[2002][2002];
int digits[10];

void init() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i] = stoi(s, nullptr, 2);
    }
}

int popcount(int n) {
    return n == 0 ? 0 : 1 + popcount(n & n - 1);
}

string dpdfs(int i, int r) {
    if (i == n) 
        return r == 0 ? "" : "-1";
    else if (dp[i][r] == -1) return "-1";

    int y = a[i];
    for (int j = 9; j >= 0; --j) {
        int x = digits[j];
        if ((x | y) == x) {
            int c = popcount(x ^ y);
            if (c <= r) {
                string ans = dpdfs(i + 1, r - c);
                if (ans != "-1") {
                    dp[i][r] = j;
                    ans = "" + to_string(j) + ans;
                    return ans;
                }
            }
        }
    }
    dp[i][r] = -1;
    return "-1";
};

string solve() {
    int d[] = {
        stoi("1110111", nullptr, 2),
        stoi("0010010", nullptr, 2),
        stoi("1011101", nullptr, 2),
        stoi("1011011", nullptr, 2),
        stoi("0111010", nullptr, 2),
        stoi("1101011", nullptr, 2),
        stoi("1101111", nullptr, 2),
        stoi("1010010", nullptr, 2),
        stoi("1111111", nullptr, 2),
        stoi("1111011", nullptr, 2)
    };
    for (int i = 0; i < 10; ++i) digits[i] = d[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            dp[i][j] = -2;

    string ans = dpdfs(0, k);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    string ans = solve();
    cout << ans << "\n";
    return 0;
}