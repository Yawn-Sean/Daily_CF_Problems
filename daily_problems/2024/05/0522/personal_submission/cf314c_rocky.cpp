#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

// 树状数组模板
class FenwickTree {
public :
    FenwickTree(int size) : n(size), c(n + 1) {}
    void add(int i, int x) {
        while (i <= n) {
            c[i] = (c[i] + x) % MOD;
            i += lowbit(i);  // 将低位左移
        }
    }

    int query(int x) {
        int sum = 0;
        while (x) {
            sum = (sum + c[x]) % MOD;
            x &= (x - 1);  // 将低位置 0
        }
        return sum;
    }

private:
    int n; // 下标上限
    vector<int> c;  // c[i] 的含义是: s[i] 往前（包括s[i]）, k（k为 i 的最低位的值）个元素之和

    int lowbit(int x) {
        return x & (-x);
    }
};

int pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % MOD;
        y /= 2;
        x = 1ll * x * x % MOD;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> nums(n), rk(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    vector<int> sorted(nums.begin(), nums.end());
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    for (int i = 0; i < n; ++i) {
        int k = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
        rk[i] = k + 1;
    }

    int m = sorted.size();
    FenwickTree ft(m);  // 以排名为 rk[i] 的元素结尾的序列的贡献
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int pre = ft.query(rk[i]);
        int cur = 1ll * (pre + 1) * nums[i] % MOD;
        int raw = (pre - ft.query(rk[i] - 1) + MOD) % MOD;  // 原来计算的答案
        int increment = (cur - raw + MOD) % MOD;  // 计算增量，替换为现有答案
        ft.add(rk[i], increment);
    }

    cout << ft.query(m) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}