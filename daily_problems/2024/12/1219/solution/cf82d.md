**提示 1：** 每次操作相当于删掉前缀中的某两个数值，实际上剩余的位置排列种类数量并不多。

**提示 2：** 用一个变量表示剩余的人所在的位置情况。再进行动态规划。

这题很有特点，每次删掉剩余的人中下标最小的 $3$ 中之 $2$ 。

表面上看，剩余的人可能有很多种可能，但由于上面的操作限制很强（取的是下标最小的三个），因此剩余的人的位置满足一定的性质。

这里可以自己尝试一下。

我们发现，剩余的人一定是一个单人，配上一个后缀。具体证明可以使用数学归纳法。

因此，假设我们处理了 $2k$ 个人后，最后 $n-2k-1$ 个人一定未被处理，而前缀的 $2k+1$ 个人中，恰好有一个被处理了。（感觉有点黑暗）

于是使用这里的 $k$ 和未被处理的人的下标 $idx$ 作为状态变量进行动态规划。每次枚举三人组中处理哪两个人即可。由于需要输出方案，请记得记录你的转移方式。

这里的动态规划只做了 $2$ 人组的部分，最后可能剩下一个人，那么我们只需看 $k=\lfloor n/2\rfloor$ 时，每一个剩下的 $idx$ 对应的最小成本，再加上处理 $nums[idx]$ 本身的成本即可。

如果 $n$ 是偶数，可以强行在数组末端补上一个哨兵元素 $0$ ，方便跟奇数一起处理。此时注意输出时，不要输出你的哨兵。

时间复杂度为 $\mathcal{O}(n^2)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    nums = LII()

    inf = 10 ** 9

    vn = n
    if n % 2 == 0:
        vn += 1
        nums.append(0)

    dp = [[inf] * vn for _ in range(n // 2 + 1)]
    pre = [[-1] * vn for _ in range(n // 2 + 1)]

    dp[0][0] = 0

    for i in range(n // 2):
        for j in range(2 * i + 1):
            v = fmax(nums[j], nums[2 * i + 1]) + dp[i][j]
            if v < dp[i + 1][2 * i + 2]:
                dp[i + 1][2 * i + 2] = v
                pre[i + 1][2 * i + 2] = j
            
            v = fmax(nums[j], nums[2 * i + 2]) + dp[i][j]
            if v < dp[i + 1][2 * i + 1]:
                dp[i + 1][2 * i + 1] = v
                pre[i + 1][2 * i + 1] = j
            
            v = fmax(nums[2 * i + 1], nums[2 * i + 2]) + dp[i][j]
            if v < dp[i + 1][j]:
                dp[i + 1][j] = v
                pre[i + 1][j] = j

    ans, idx = inf, -1
    for i in range(vn):
        if dp[n // 2][i] + nums[i] < ans:
            ans = dp[n // 2][i] + nums[i]
            idx = i

    print(ans)

    outs = []
    if idx < n: outs.append(str(idx + 1))

    for i in range(n // 2, 0, -1):
        nidx = pre[i][idx]
        if idx == 2 * i - 1: pair = (nidx, 2 * i)
        elif idx == 2 * i: pair = (nidx, 2 * i - 1)
        else: pair = (2 * i - 1, 2 * i)
        outs.append(' '.join(str(x + 1) for x in pair if x < n))
        idx = nidx

    print('\n'.join(reversed(outs)))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;
    
    int inf = 1e9, vn = n;

    if ((vn & 1) == 0)
        vn ++, nums.emplace_back(0);
    
    vector<vector<int>> dp(n / 2 + 1, vector<int>(vn, inf)), pre(n / 2 + 1, vector<int>(vn, -1));

    dp[0][0] = 0;
    for (int i = 0; i < n / 2; i ++) {
        for (int j = 0; j <= 2 * i; j ++) {
            int v;
            v = max(nums[j], nums[2 * i + 1]) + dp[i][j];
            if (v < dp[i + 1][2 * i + 2]) {
                dp[i + 1][2 * i + 2] = v;
                pre[i + 1][2 * i + 2] = j;
            }
            v = max(nums[j], nums[2 * i + 2]) + dp[i][j];
            if (v < dp[i + 1][2 * i + 1]) {
                dp[i + 1][2 * i + 1] = v;
                pre[i + 1][2 * i + 1] = j;
            }
            v = max(nums[2 * i + 1], nums[2 * i + 2]) + dp[i][j];
            if (v < dp[i + 1][j]) {
                dp[i + 1][j] = v;
                pre[i + 1][j] = j;
            }
        }
    }

    int ans = inf, idx = -1;
    for (int i = 0; i < vn; i ++) {
        if (dp[n / 2][i] + nums[i] < ans) {
            ans = dp[n / 2][i] + nums[i];
            idx = i;
        }
    }
    cout << ans << '\n';

    vector<pair<int, int>> chosen;
    chosen.emplace_back(idx, n);

    for (int i = n / 2; i > 0; i --) {
        int nidx = pre[i][idx];
        if (idx == 2 * i - 1) chosen.emplace_back(nidx, 2 * i);
        else if (idx == 2 * i) chosen.emplace_back(nidx, 2 * i - 1);
        else chosen.emplace_back(2 * i - 1, 2 * i);
        idx = nidx;
    }

    reverse(chosen.begin(), chosen.end());

    for (auto &[x, y]: chosen) {
        if (x < n) cout << x + 1 << ' ';
        if (y < n) cout << y + 1 << ' ';
        cout << '\n';
    }

    return 0;
}
```
