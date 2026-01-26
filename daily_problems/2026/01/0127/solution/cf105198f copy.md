**提示 1：** 可以简单打下小一点的数的表。

**提示 2：** 足够大的数怎么办？

我们先暴力枚举不大的数，计算其需要点亮的条的数量。

对于足够大的数，前面的自由度比较高，我们要用掉尽可能多的亮条，直觉上来看应该在最后填入 $8$ 。

证明也可以考虑某一组连续 $7$ 个 $n$ 对应的答案是递增的情况下，新增一项，枚举最后一个数码，一定是在第一个数的末尾填入 $8$ 时结果最小，此时最后 $7$ 项仍然递增，因此数学归纳法可证。

预处理后复杂度是 $\mathcal{O}(n)$ 的。因为你如果不细致处理开头的部分就会出问题，所以难度分稍微给高一点。你至少需要处理到最后有一长段递增序列的情况下才能停下。


### 具体代码如下——

Python 做法如下——

```Python []
def main(): 
    digits = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
    ans = [1000] * 22
    
    for i in range(10):
        ans[digits[i]] = fmin(ans[digits[i]], i)
    
    for i in range(1, 10):
        for j in range(10):
            d = digits[i] + digits[j]
            ans[d] = fmin(ans[d], i * 10 + j)
    
    for i in range(1, 10):
        for j in range(10):
            for k in range(10):
                d = digits[i] + digits[j] + digits[k]
                ans[d] = fmin(ans[d], i * 100 + j * 10 + k)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        if n <= 21: outs.append(str(ans[n]))
        else:
            v = (n - 15) % 7 + 15
            outs.append(str(ans[v]) + (n - v) // 7 * '8') 
    
    print('\n'.join(outs))
```

C++ 做法如下——

```cpp []
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> digits = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	vector<int> ans(22, 1000);

	for (int i = 0; i < 10; i ++) ans[digits[i]] = min(ans[digits[i]], i);

	for (int i = 1; i < 10; i ++) {
		for (int j = 0; j < 10; j ++) {
			int d = digits[i] + digits[j];
			ans[d] = min(ans[d], i * 10 + j);
		}
	}

	for (int i = 1; i < 10; i ++) {
		for (int j = 0; j < 10; j ++) {
			for (int k = 0; k < 10; k ++) {
				int d = digits[i] + digits[j] + digits[k];
				ans[d] = min(ans[d], i * 100 + j * 10 + k);
			}
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		if (n <= 21) cout << ans[n] << '\n';
		else {
			int v = (n - 15) % 7 + 15;
			cout << ans[v] << string((n - v) / 7, '8') << '\n';
		}
	}

	return 0;
}
```
