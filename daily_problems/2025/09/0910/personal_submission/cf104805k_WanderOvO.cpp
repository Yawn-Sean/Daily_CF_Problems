/*
对于一个集合 y，其值为枚举 y 的所有子集 s，对 s 中的所有数求乘积，然后再把所有 s 计算出的乘积加起来
假如已经知道集合 y 了，如何快速算这个值？
直接暴力硬算的话，又要枚举一次集合

x >= 2，L <= 1e12，2^40 = 1e12，所以还是得枚举所有的集合
3^26 > 1e12
4^20 > 1e12
15^20 很大了
如果 x[i] 稍微大一点，枚举量就能下来很多

能否 dfs 时动态维护一个集合里的值？
假设现在正在枚举集合 y，枚举到中间某步了，现在的乘积的和是 sum，想新加一个 val
则新的 sum = sum + val * (sum + 1)
但是枚举新加数时，这个数可能是当前数，也可能是下一个数，这又很难评
先写一个暴搜试试看吧，说不定跑得很快呢？

我们好像只关心有多少个计算出来的结果，这似乎意味着可以先给原数组去个重，并不影响结果
另外可以记录一下搜过的状态，保证不再搜了，说不定能跑过去
*/

LL n, m, a[N], L;
set<LL> st;
set<PLL> vis;

void dfs(int u, LL sum) {
    if (sum <= L && sum != 0) {
        st.insert(sum);
    }
    
    if (u > m) {
        return;
    }

    if (sum > L) {
        return;
    }

    if (vis.count({u, sum})) {
        return;
    }

    if (sum <= L && sum != 0) {
        st.insert(sum);
        vis.insert({u, sum});
    }
    
    dfs(u + 1, sum);
    dfs(u, sum + (1 + sum) * a[u]);
    dfs(u + 1, sum + (1 + sum) * a[u]);
}

void meibao() {
    cin >> n >> L;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    m = unique(a + 1, a + n + 1) - a - 1;
    for (int i = 1; i <= m; i++) {
        int j = m + 1 - i;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    dfs(1, 0);

    cout << st.size() << "\n";
}   
