**提示 1：** 很典型的问题。区间赋值取最大。

**提示 2：** 最后提取答案怎么办。

我们先确定对于每一个横坐标，竖着是多少。这是典型的区间复制，最后提取最大值的问题。

有很多种方式——

- 染色——从大数往小数染色。染过色的位置进行删除。这样只要快速得到没被染色过的区间就行，可以使用有序结构维护，或者用类似并查集定向往右合并，找到下一个还没合并的位置。

- 扫描线——从左到右，用有序集合维护到某个位置为止还有的高度的数据。这个数据集的最大值就是对应高度。

- 懒更新线段树——区间赋值，很典型。

最后输出答案的时候，只需看当前的高度跟之前的高度有无差别，如果有差别，就会多两个拐点，把它们加入答案即可。

时间复杂度为 $\mathcal{O}(n\log n)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    delta = random.getrandbits(30)

    infile = open('input.txt', 'r')
    input = lambda: infile.readline().strip()
    outfile = open('output.txt', 'w')
    print = lambda x: outfile.write(str(x) + '\n')

    n = II()

    ls = []
    rs = []
    hs = []

    for _ in range(n):
        h, l, r = MII()
        l += delta
        r += delta
        ls.append(l)
        rs.append(r)
        hs.append(h)

    seps = sorted(set(ls + rs))
    k = len(seps)
    d = {v: i for i, v in enumerate(seps)}

    vals = [0] * k
    dsu = UnionFind(k)

    for i in sorted(range(n), key=lambda x: -hs[x]):
        pl = d[ls[i]]
        pr = d[rs[i]]
        h = hs[i]
        while dsu.find(pl) < pr:
            pl = dsu.find(pl)
            vals[pl] = h
            dsu.merge_to(pl, pl + 1)

    pts = []
    cur_h = 0

    for i in range(k):
        if vals[i] != cur_h:
            pts.append(f'{seps[i] - delta} {cur_h}')
            pts.append(f'{seps[i] - delta} {vals[i]}')
            cur_h = vals[i]

    print(len(pts))
    print('\n'.join(pts))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    map<int, vector<int>> diff;
    while (n --) {
        int h, l, r;
        fin >> h >> l >> r;
        diff[l].emplace_back(h);
        diff[r].emplace_back(-h);
    }

    int cur_h = 0;
    multiset<int> vals;
    vals.insert(0);

    vector<pair<int, int>> pts;

    for (auto &[k, v]: diff) {
        for (auto &x: v) {
            if (x > 0) vals.insert(x);
            else vals.erase(vals.find(-x));
        }
        int new_h = *vals.rbegin();
        if (cur_h != new_h) {
            pts.emplace_back(k, cur_h);
            pts.emplace_back(k, new_h);
            cur_h = new_h;
        }
    }

    fout << pts.size() << '\n';
    for (auto &[x, y]: pts) fout << x << ' ' << y << '\n';

    return 0;
}
```