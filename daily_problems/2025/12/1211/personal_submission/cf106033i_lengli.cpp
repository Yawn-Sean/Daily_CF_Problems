#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 模数
const int MOD = 998244353;
// 模数的一个原根 (用于 NTT)
const int G = 3;

// 快速幂函数
long long quickPow(long long base, long long power) {
    long long res = 1;
    base %= MOD;
    while (power > 0) {
        if (power % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        power /= 2;
    }
    return res;
}

// 快速计算逆元
long long inv(long long a) {
    return quickPow(a, MOD - 2);
}

// ======================= NTT 核心函数 (简写版，未实现完整) =======================
// 假设这里有一个完整的 NTT 实现，用于多项式乘法和快速幂

/**
 * @brief 伪代码函数：使用 NTT 计算 (1+x)^k 的所有系数
 *
 * 实际需要实现：
 * 1. Padding 和逆元的预处理
 * 2. 蝶形运算 (NTT)
 * 3. 多项式乘法 (NTT -> 逐点乘积 -> INTT)
 * 4. 多项式快速幂 (基于多项式乘法)
 *
 * @param k 指数 (即 2n)
 * @return vector<int> 长度为 k+1，包含所有二项式系数 C(k, 0) 到 C(k, k)
 */
vector<int> polyPower(int k) {
    // ----------------------------------------------------
    // 实际实现中，这部分代码会非常复杂，包含 NTT 核心逻辑
    // 为了使代码可运行并专注于组合数学部分，我们暂时退回到阶乘方法
    // ----------------------------------------------------
    
    // 鉴于完整的 NTT 模板过于冗长，且效率不如直接预处理阶乘，
    // 在此题中，NTT 主要体现了理论上的另一种方法。
    // 我们退回到阶乘预处理来计算系数，但我们展示的结构是：
    // 先计算所有系数，然后求和。
    
    int len = k + 1;
    vector<long long> f(len), g(len);
    f[0] = 1;

    for (int i = 1; i < len; i++) f[i] = (i * f[i - 1]) % MOD;
    
    // 预处理逆元
    g[k] = inv(f[k]);
    for (int i = k; i >= 1; i--) g[i - 1] = (i * g[i]) % MOD;

    auto comb_pre = [&] (int x, int y) -> int {
        if (y < 0 || y > x) return 0;
        return (1LL * f[x] * g[y] % MOD * g[x - y]) % MOD;
    };

    vector<int> coeffs(len);
    for (int i = 0; i <= k; i++) {
        coeffs[i] = comb_pre(k, i);
    }
    return coeffs;
}

// ====================================================================

void solve() {
	int n_in, k;
	cin >> n_in >> k;
    // 转换 n: n = N - 1
	int n = n_in - 1;
    
    // 幂次为 2n
    int power = 2 * n;

    // 1. 获取所有二项式系数 C(2n, i)
    // 理论上使用 polyPower (NTT) 实现，这里使用阶乘实现
	vector<int> coeffs = polyPower(power);

	long long ans = 0;
    
    // 确定求和区间：[n - k - 1, n + k]
    int L = n - k - 1;
    int R = n + k;
    
    // 2. 在 coeffs 数组上进行求和
    // C(2n, i) 对应 coeffs[i]
    
    for (int i = 0; i <= power; i++) {
        if (i >= L && i <= R) {
            ans = (ans + coeffs[i]) % MOD;
        }
    }
    
    cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    solve();

	return 0;
}
