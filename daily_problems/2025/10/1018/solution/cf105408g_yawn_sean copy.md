**提示 1：** 两两的 GCD 既然相同，先求一下。

**提示 2：** 都除以 GCD 后就得互质了。怎么判是否两两互质？

首先我们先假设题设成立，先求两两的 GCD 。只需取一对数就行。

接下来所有数除以这个 GCD，如果除不尽直接返回不成立。

剩余的数两两互质，也就不能有相同质因子，因此直接质因数分解，记录当前出现过的质因子即可。一旦某个质因子在多个数字中出现，返回不成立。

时间复杂度为 $\mathcal{O}(n\log M+M)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main(): 
    n = II()
    nums = LII()
    g = math.gcd(*nums)
    
    for i in range(n):
        nums[i] //= g
    
    M = max(nums)
    prime_factor = list(range(M + 1))
    
    for i in range(2, M + 1):
        if prime_factor[i] == i:
            for j in range(i, M + 1, i):
                prime_factor[j] = i
    
    vis = [0] * (M + 1)
    
    for x in nums:
        while x > 1:
            p = prime_factor[x]
            if vis[p]: exit(print('NO'))
            vis[p] = 1
            while x % p == 0:
                x //= p
    
    print('YES')
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
	int g = 0;
	for (auto &x: nums) {
		cin >> x;
		g = gcd(x, g);
	}

	for (auto &x: nums)
		x /= g;
	
	int M = *max_element(nums.begin(), nums.end());
	vector<int> pr(M + 1);
	iota(pr.begin(), pr.end(), 0);

	for (int i = 2; i <= M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j <= M; j += i) {
				pr[j] = i;
			}
		}
	}

	vector<int> vis(M + 1, 0);

	for (auto &x: nums) {
		while (x > 1) {
			int p = pr[x];
			if (vis[p]) return cout << "NO", 0;
			vis[p] = 1;
			while (x % p == 0) x /= p;
		}
	}

	cout << "YES";

	return 0;
}
```