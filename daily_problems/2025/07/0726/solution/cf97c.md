**提示 1：** 长期来看 $a_i$ 的均值如何？

**提示 2：** 将 $a_i,p_i$ 作到一个二维平面上。

长期来看 $\frac{a_i}{n}$ 均值不应该超过 $0.5$ ，因为前 $n$ 轮中，第二次参赛的一定不超过第一次参赛的人次。因此 $a_i$ 均值不超过 $\frac{n}{2}$ 。

考虑 $i$ 人参赛选取了 $\lambda_i$ 次，那么考虑 $(a_i,p_i)$ 形成的平面，最后求出来的均值就是这几个点的关于权重 $\{\lambda_i\}$ 的加权平均！

而平面上几个点的加权平均的可行域，就是这几个点形成的凸包。而在总次数充分大的情况下，这些 $\frac{\lambda_i}{\sum\lambda_i}$ 可以充分逼近任意一组和为 $1$ 的权值组。

因此凸包内的任何一点都可以被充分逼近。

而同时 $a_i$ 的均值不能超过 $\frac{n}{2}$ ，所以就只需求这个凸包在 $\frac{n}{2}$ 左侧的最高点。而因为所有点都是单调递增的，所以只需求 $\frac{n}{2}$ 对应的交点位置即可。

真有趣，一个概率题最后转化后变成了个几何题。

时间复杂度为 $\mathcal{O}(n^2)$ ，如果枚举两个点看是否取最大值。也可以通过求凸包，再求和直线的交点进一步优化到 $\mathcal{O}(n\log n)$ ，但这不是必要的。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    nums = LFI()
    
    ans = nums[n // 2]
    
    for i in range(n + 1):
        wi = 2 * i - n
        for j in range(n + 1):
            wj = 2 * j - n
            
            if wi < 0 and wj > 0:
                ans = fmax(ans, (wj * nums[i] - wi * nums[j]) / (wj - wi))
    
    print(ans)
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long double> nums(n + 1);
    for (auto &v: nums) cin >> v;

    long double ans = nums[n / 2];

    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= n; j ++) {
            int wi = 2 * i - n, wj = 2 * j - n;
            if (wi < 0 && wj > 0) {
                ans = max(ans, (wj * nums[i] - wi * nums[j]) / (wj - wi));
            }
        }
    }

    cout << fixed << setprecision(15) << ans;

    return 0;
}
```