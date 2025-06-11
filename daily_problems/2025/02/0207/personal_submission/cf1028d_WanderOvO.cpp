/*
n <= 4e5
- 向 A 或者 B 集合插入一个元素
- 删除元素 x，x 必须是当前 A 的最大值或者 B 的最小值
求方案数

羊神提示：只有插入操作时，对所有元素升序排序，一定是前缀是 A 中的，后缀是 B 中的，所以一共有 n + 1 种方案
考虑有成交操作的情况，在遇到第一个成交操作时，假设元素是 val，这个可能是 A 中最大的，也可能是 B 中最小的
但可以确定的是，所有 < val 的都在 A 中，所有 > val 的都在 B 中，因此只有 val 的位置不确定，2 种情况
找 > val 的最小的数 mn，< val 的最大的数 mx，就确定了界，所有 > mn 的一定在 B 中，< mx 的一定在 A 中
之后还会插入元素以及成交（删除）
如果插入的元素是确定了在哪个集合范围内的，则不会增加情况数
如果插入的元素是在 (mx, mn) 之间的，则只有在下一次删除时才知道分组情况
考虑第二次删除的元素是 val2，显然 mx <= val2 <= mn，否则寄了
如果没寄，则继续确定 > val2 的最小值以及 < val2 的最大值，得到新的 mn 和 mx
这一步中，假如是删除的端点值，则由于端点值的归属是确定的，因此不会增加方案数
如果删除的是内点，则方案数 * 2
一直这样下去，最后考虑还在 (mx, mn) 中的数有多少，有 cnt 个，则有 cnt + 1 种划分方法
*/

LL n;

void meibao() {
    string op;
    set<LL> s;
    s.insert(INFLL);
    s.insert(-INFLL);
    LL val;
    LL res = 1, mx = -INFLL, mn = INFLL, to_check = 0;
    cin >> n;
    int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        cin >> op >> val;
        if (op[1] == 'D') {
            s.insert(val);
            if (val > mx && val < mn) {
                to_check++;
            }
        } else {
            if (val < mx || val > mn) {
                res = 0;
            } else {
                if (val != mx && val != mn) {
                    res *= 2;
                    res %= mod;
                } 
                mn = *s.upper_bound(val);
                mx = *prev(s.lower_bound(val));
                s.erase(val);
                to_check = 0;
            }
        }
    }
    res *= (to_check + 1);
    res %= mod;
    cout << res << "\n";
}
