/*
首先，要排除最后长度不合法的问题
如果确定长度范围下有合法的分割，之后怎么搞呢？
我们考虑第一段，所有段的 gcd 一定是第一段的约数

感觉没有找对突破口

羊的提示：考虑最后分成的段长度分别为 v1, ... vm
则由于 C(t, v1) = t! / (v1!) / (t - v1)! = (t - v1 + 1) * ... * t / (v1!)
这个东西说明了 (t - v1 + 1) * ... * t 是 v1! 的倍数
不妨 v1 <= v2 <= .... vm，则由于 v1! | v2! | ... | vm!
所以 v1! 就是最小的答案了，我们要尽量让 v1 小
如何做到？好像还是不会

m 是自己定的，我们肯定希望分组分多一些
分 m 组，则 [mL, mR] 应该包含 n
m 最大是多少呢？理论上应该是 n / L
具体怎么搞？
假设当前在搞第 i 段，则后边还有 cnt - i 段
sum + cur_len + (cnt - i) * R >= n
cur_len >= n - sum - (cnt - i) * R
*/ 


void solve() {
    const int mod = 998244353;
    LL n, L, R;
    cin >> n >> L >> R;
    
    LL cnt = n / L;
    if (cnt * R < n) {
        cout << "-1\n";
        return;
    }
    
    vector<LL> len;
    LL sum = 0;
    for (int i = 1; i <= cnt; i++) {
        LL cur_len = max(L, n - sum - (cnt - i) * R);
        sum += cur_len;
        len.push_back(cur_len);
    }
    
    LL res = 1;
    for (int i = 1; i <= len[0]; i++) {
        res *= i;
        res %= mod;
    }
    cout << len.size() << " ";
    cout << res << "\n";
    
    LL pt = 1;
    for (auto l : len) {
        cout << pt << " " << pt + l - 1 << "\n";
        pt += l;
    }
}
