/*
一定存在某个 x，使得 b 符合题意
如何判断某个 x 是否符合题意？
对于比较小的数，优先让它属于 x 组
对于比较小的数 val，选择最小的比 val 大，且没出现在 b 中的
对于比较大的数 val，选择最大的比 val 小，且没出现在 b 中的
关于 x 是否有单调性？非也，样例 2 告诉我们没有
是否一定是连续的 x？不知道
理论上最小和最大的 x 能否求出来？
最大的 x：对于 val in b，贪心地让它和比它大且最小的没出现在 b 中的数配对
最小的 x：对于 val in b，贪心地让它和比它小且最大的没出现在 b 中的数配对
*/

int n;

void meibao() {
    cin >> n;
    set<int> a, b;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        b.insert(val);
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (!b.count(i)) {
            a.insert(i);
        }
    }

    set<int> disappear, appear;
    for (auto val : a) {
        disappear.insert(val);
    }
    for (auto val : b) {
        appear.insert(val);
    }
    int maxx = 0, minx = 0;
    for (auto val : appear) {
        auto pos = disappear.upper_bound(val);
        if (pos != disappear.end()) {
            maxx++;
            disappear.erase(pos);
        } else {
            break;
        }
    }
    disappear.clear();
    appear.clear();
    for (auto val : a) {
        disappear.insert(val);
    }
    for (auto val : b) {
        appear.insert(val);
    }
    for (auto val : appear) {
        auto pos = disappear.lower_bound(val);
        if (pos != disappear.begin()) {
            pos = prev(pos);
            disappear.erase(pos);
            minx++;
        } 
    }
    minx = n - minx;
    cout << maxx - minx + 1 << "\n";
}
