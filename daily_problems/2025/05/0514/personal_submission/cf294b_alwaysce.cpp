#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int inf= 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        dp[i]: 厚度和=i的时候能够得到的最大宽度(给第二层书用)

        i >= tot - dp[i] 把厚度吃了
    */
    int n;
    cin >> n;
    
    vector<int> dp(201, -inf);
    dp[0] = 0;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int t, w;
        cin >> t >> w;
        tot += w;
        for (int i = 200; i >= t; i--) {
            dp[i] = max(dp[i], dp[i - t] + w);
        }
    }

    for (int i = 1; i <= 200; i++) {
        if (tot - dp[i] <= i) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
