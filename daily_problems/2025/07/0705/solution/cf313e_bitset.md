不会贪心，来个简单暴力的 `bitset` 解法。

为了让答案的字典序尽可能大，我们先想办法凑出尽量多的 $(m - 1)$。令 $a_i$ 表示第一个序列里的 $i$ 还剩几个，$b_i$ 表示第二个序列里的 $i$ 还剩几个。想象两个链表，第一个链表装的是 $a_0 \to a_1 \to \cdots \to a_{m - 1}$，第二个链表装的是 $b_{m - 1} \to b_{m - 2} \to \cdots \to b_0$，那么只要两个链表的第 $i$ 个节点都非 $0$，我们就能把对应的元素匹配上，凑出若干个 $(m - 1)$。

$(m - 1)$ 凑完了，接下来尝试凑 $(m - 2)$。想象把第二个链表左移一位，变成 $b_{m - 2} \to b_{m - 3} \to \cdots \to b_0 \to b_{m - 1}$，我们又能将节点一一对应了。之后每一轮我们都把第二个链表左移一位即可。

需要注意的是，如果我们每轮都枚举链表的每个节点，复杂度是 $\mathcal{O}(m^2)$ 的，所以我们每轮只能枚举两个链表均非 $0$ 的下标。怎么快速找出这些下标呢？用两个 `bitset` 维护两个链表哪些下标非 $0$，两者 `&` 起来，就能找到哪些下标同时非 $0$ 了。标准库里的 `bitset` 不支持快速找到第一个 $1$ 在哪，所以我们得手写 `bitset`。

由于每次枚举一对非 $0$ 的节点，都能匹配至少一对数，所以至多匹配 $n$ 次，复杂度 $\mathcal{O}(\frac{(n + m)m}{w})$，其中 $w = 64$ 是计算机字长。

```c++
#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, A[2][MAXN + 5];

// 手写 bitset
struct Bitset {
    const int W = 64;
    int len;
    typedef unsigned long long ull;
    vector<ull> vec;

    Bitset(int len): len(len) {
        vec.resize((len + W - 1) / W, 0);
    }

    void set(int pos) {
        vec[pos / W] |= 1ULL << (pos & (W - 1));
    }

    void unset(int pos) {
        vec[pos / W] &= ~(1ULL << (pos & (W - 1)));
    }

    // bitset 左移一位
    void shift() {
        int b = vec[0] & 1;
        for (int i = 0; i < vec.size(); i++) {
            int t = vec[i] & 1;
            vec[i] >>= 1;
            if (t && i > 0) vec[i - 1] |= 1ULL << (W - 1);
        }
        if (b) vec[vec.size() - 1] |= 1ULL << ((len - 1) & (W - 1));
    }

    // 两个 bitset & 起来
    void join(Bitset &o) {
        assert(len == o.len);
        for (int i = 0; i < vec.size(); i++) vec[i] &= o.vec[i];
    }

    // 找到第 bgn 位右边最近的 1
    int findFirst(int bgn) {
        int bias = bgn & (W - 1);
        for (int i = bgn / W; i < vec.size(); i++) {
            ull x = vec[i] >> bias;
            x &= -x;
            if (x) return i * W + __lg(x) + bias;
            bias = 0;
        }
        return -1;
    }
};

int main() {
    scanf("%d%d", &n, &m);
    for (int k = 0; k < 2; k++) for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        A[k][x]++;
    }

    Bitset X(m), Y(m);
    // 第一个链表从 0 到 m - 1
    for (int i = 0; i < m; i++) if (A[0][i]) X.set(i);
    // 第二个链表从 m - 1 到 0
    for (int i = 0; i < m; i++) if (A[1][i]) Y.set(m - 1 - i);

    // 从 m - 1 开始凑
    for (int v = m - 1; v >= 0; v--) {
        Bitset Z = X;
        Z.join(Y);
        int idx = 0;
        while (true) {
            // 每次只访问两个链表同时非 0 的节点
            idx = Z.findFirst(idx);
            if (idx < 0) break;
            int iidx = (v - idx + m) % m;
            int t = min(A[0][idx], A[1][iidx]);
            for (int i = 1; i <= t; i++) printf("%d ", v);
            if ((A[0][idx] -= t) == 0) X.unset(idx);
            if ((A[1][iidx] -= t) == 0) Y.unset(idx);
            idx++;
        }
        // 每轮把第二个链表左移一位
        Y.shift();
    }
    printf("\n");
    return 0;
}
```
