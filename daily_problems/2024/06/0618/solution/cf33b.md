**提示 1：** 可以发现每个位置是相互独立的，因此每个位置单独处理即可。

**提示 2：** 依次考虑每个位置，最小成本如何计算？

首先，根据提示 1，我们只需对每个位置求出最小成本，最后进行加总即可。

接下来我们考虑某一个位置，假设初始字符分别是 $c_1,c_2$ ，最后变成了 $c_0$ ，那么总成本为 $c_1$ 变为 $c_0$ 的最小成本加上 $c_2$ 变成 $c_0$ 的最小成本。

于是，不难想到，我们预处理每一个字符变成另一个字符的最小成本。而这是一个经典的图论问题，本题给出的变化过程相当于在两个字符之间加了一条边，我们要求得两点之间的最短路。由于我们要查询多次，我们直接使用 Floyd 算法预处理，得到任意两点之间的最短路。

接下来，我们对任何一对 $c_1, c_2$ 只需枚举 $c_0$ 找到总变化成本的最小值即可。

而由于 $c_1,c_2$ 的组合相当有限，我们直接预处理任意一对字符变相同的最小成本即可，后续考虑每一个位置只需要查询前面预处理的结果即可。

另外，注意处理题目中的特殊情况，即给出的两个字符串长度不同，直接输出 `-1` 即可。

时间复杂度为 $\mathcal{O}(n+|Σ|^3)$ ，来源于寻找字符串最后的对应以及最短路找到成本最低的匹配方法。

#### 具体代码如下（只包含中间处理部分）——

Python 做法如下——

```Python []
def main():
    s1 = [ord(c) - ord('a') for c in I()]
    s2 = [ord(c) - ord('a') for c in I()]

    n = II()

    inf = 10 ** 9
    dist = [[inf] * 26 for _ in range(26)]

    for i in range(26):
        dist[i][i] = 0

    for _ in range(n):
        c1, c2, d = LI()
        c1 = ord(c1) - ord('a')
        c2 = ord(c2) - ord('a')
        d = int(d)
        if d < dist[c1][c2]:
            dist[c1][c2] = d

    for i in range(26):
        for j in range(26):
            for k in range(26):
                if dist[j][i] + dist[i][k] < dist[j][k]:
                    dist[j][k] = dist[j][i] + dist[i][k]

    ans = [[inf] * 26 for _ in range(26)]
    chosen = [[-1] * 26 for _ in range(26)]
    for i in range(26):
        for j in range(26):
            for k in range(26):
                if dist[i][k] + dist[j][k] < ans[i][j]:
                    ans[i][j] = dist[i][k] + dist[j][k] 
                    chosen[i][j] = k

    if len(s1) != len(s2):
        print(-1)
        exit()

    k = len(s1)
    tot = 0
    res = []

    for i in range(k):
        if chosen[s1[i]][s2[i]] != -1:
            tot += ans[s1[i]][s2[i]]
            res.append(chosen[s1[i]][s2[i]])
        else:
            print(-1)
            exit()

    print(tot)
    print(''.join(chr(ord('a') + c) for c in res))
```

C++ 做法如下——

```cpp []
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() != s2.size()) {
        cout << "-1\n";
        return 0;
    }

    int inf = 1e8;
    vector<vector<int>> dist(26, vector<int>(26, inf));

    for (int i = 0; i < 26; i ++) dist[i][i] = 0;
    
    int n;
    cin >> n;

    while (n --) {
        char c1, c2;
        int d;
        cin >> c1 >> c2 >> d;
        int x1 = c1 - 'a', x2 = c2 - 'a';
        dist[x1][x2] = min(dist[x1][x2], d);
    }

    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < 26; j ++)
            for (int k = 0; k < 26; k ++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    
    vector<vector<int>> ans(26, vector<int>(26, inf));
    vector<vector<int>> chars(26, vector<int>(26, -1));

    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < 26; j ++)
            for (int k = 0; k < 26; k ++)
                if (dist[i][k] + dist[j][k] < ans[i][j])
                    ans[i][j] = dist[i][k] + dist[j][k], chars[i][j] = k;
    
    int len = s1.size();
    int res = 0;
    string final_str(len, 'a');

    for (int i = 0; i < len; i ++) {
        int x = s1[i] - 'a', y = s2[i] - 'a';
        if (chars[x][y] == -1) {
            cout << "-1\n";
            return 0;
        }
        res += ans[x][y], final_str[i] += chars[x][y];
    }
    cout << res << '\n' << final_str << '\n';

    return 0;
}
```
