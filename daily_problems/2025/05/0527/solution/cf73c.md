**提示 1：** 假设我们考虑到了第 $i$ 个字符，哪些状态是重要的？

**提示 2：** 写清楚 DP 。

典型的 DP。

假设我们当前解决了长度为 $i$ 的前缀的问题，接下来要尝试解决长度为 $i+1$ 的前缀。

新考虑了一个字符，哪些状态是重要的呢？

首先，这个字符可以跟前面的一个字符形成一个需要考虑成本的对。因此前缀中最后一个字符是需要记录的状态。

同时，新来的字符需要考虑是否修改了，我们要求总修改次数不超过 $k$ ，因此我们也需要记录当前修改次数。

于是，设 $dp[i][j][k]$ 表示到第 $i$ 个字符时，最后一个字符为 $j$ 且修改了 $k$ 次字符串时的最大权值。

只需枚举新的一位是什么字符就行了。

注意 $dp$ 的起点是第一个字符对应的前缀。注意 $k=0$ 的愚蠢情况。

时间复杂度为 $\mathcal{O}(|s|k|\Sigma|^2)$ ，其中 $|s|$ 表示字符串长度， $|\Sigma|$ 表示字符集大小。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    s, k = LI()

    s = [ord(c) - ord('a') for c in s]
    k = int(k)

    grid = [[0] * 26 for _ in range(26)]

    n = II()
    for _ in range(n):
        c1, c2, v = LI()
        grid[ord(c1) - ord('a')][ord(c2) - ord('a')] = int(v)

    inf = 10 ** 9
    dp = [[-inf] * 26 for _ in range(k + 1)]
    ndp = [[-inf] * 26 for _ in range(k + 1)]

    for i in range(26):
        if s[0] == i: dp[0][i] = 0
        elif k: dp[1][i] = 0

    for i in range(1, len(s)):
        for x in range(k + 1):
            for y in range(26):
                for ny in range(26):
                    nx = x + 1 if ny != s[i] else x
                    if nx <= k:
                        ndp[nx][ny] = fmax(ndp[nx][ny], dp[x][y] + grid[y][ny])
        
        for x in range(k + 1):
            for y in range(26):
                dp[x][y] = ndp[x][y]
                ndp[x][y] = -inf

    print(max(max(v) for v in dp))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int k;

    cin >> s >> k;

    vector<vector<int>> grid(26, vector<int>(26, 0));

    int n;
    cin >> n;

    while (n --) {
        char c1, c2;
        int v;
        cin >> c1 >> c2 >> v;
        grid[c1 - 'a'][c2 - 'a'] = v;
    }

    int inf = 1e9;
    vector<vector<int>> dp(k + 1, vector<int>(26, -inf));
    vector<vector<int>> ndp(k + 1, vector<int>(26, -inf));

    for (int i = 0; i < 26; i ++) {
        if (s[0] - 'a' == i) dp[0][i] = 0;
        else if (k) dp[1][i] = 0;
    }

    for (int i = 1; i < s.size(); i ++) {
        for (int x = 0; x <= k; x ++) {
            for (int y = 0; y < 26; y ++) {
                for (int ny = 0; ny < 26; ny ++) {
                    int nx = (s[i] - 'a' == ny ? x : x + 1);
                    if (nx <= k)
                        ndp[nx][ny] = max(ndp[nx][ny], dp[x][y] + grid[y][ny]);
                }
            }
        }
        for (int x = 0; x <= k; x ++) {
            for (int y = 0; y < 26; y ++) {
                dp[x][y] = ndp[x][y];
                ndp[x][y] = -inf;
            }
        }
    }

    int ans = -inf;
    for (int i = 0; i <= k; i ++)
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    
    cout << ans;

    return 0;
}
```