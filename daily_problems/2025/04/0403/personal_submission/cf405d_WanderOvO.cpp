/*
x 都知道，先求出来 sum(x - 1)
剩下所有的 y 改成 s - y
相当于求类似背包的东西，但是值域很大，但是物品的价值很有规则
羊神提示：配对
如果有 x - 1 = s - y，则应该有 x + y = s + 1，满足这个条件的 x, y 我们给配个对
其实就是 x = 1, y = s, x = 2, y = s - 1...
如果 x 在 X 中，但 y 不在 X 中，则可以用 y 去抵消 x
如果 x 和 y 都在 X 中，则找一对不在 X 里面的
因此，先枚举 x，尝试用其配对消掉
对于消不掉的，一定是一堆对子，我们在 y 中找一些对子搞掉即可
y 中的对子会不会不够用？不会的，最差的情况都是刚好够
*/

int n, x[N], in_x[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        in_x[x[i]] = 1;
    }

    vector<int> left_x;
    int s = 1e6;
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        int y = s - x[i] + 1;
        if (!in_x[y]) {
            res.push_back(y);
        } else {
            left_x.push_back(x[i]);
        }
    }
    assert(left_x.size() % 2 == 0);
    int pair_cnt = left_x.size() / 2;
    for (int i = 1; i <= s && pair_cnt > 0; i++) {
        if (!in_x[i] && !in_x[s - i + 1]) {
            res.push_back(i);
            res.push_back(s - i + 1);
            pair_cnt--;
        }
    }
    assert(pair_cnt == 0);
    cout << res.size() << "\n";
    for (auto val : res) {
        cout << val << " ";
    }
}
