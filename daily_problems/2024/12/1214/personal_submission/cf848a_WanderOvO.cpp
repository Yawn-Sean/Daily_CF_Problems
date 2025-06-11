/*
假如已知了字符集，怎样合并代价最小？
每次合并的代价是两个 26 维向量做内积，合并结果是两个向量的和
真的需要把 26 个字母都用到吗？
k = 1，a a
k = 2，a b a b
k = 3，a a a
a a a a a:
1 + 2 + 3 + 4 = 10
1 + 1 + 4 + 4 = 10
1 + 2 + 1 + 6 = 10
有了一些智慧发现：
1. 所有字符一样，怎样合并代价最小？手玩之后感觉怎么合并代价都一样
2. 每个字符的代价可以分开算，假设某个字符出现 cnt 次，代价之和为 cnt * (cnt - 1) / 2
1 3 6 10 15 21 28 36 45 55 66 78 91 105 120 136 153 171 190
能否通过 26 个这个数列中的数拼出来想要的数？考虑贪心拼凑一下，最后实在不行用 1
*/

int k, c[M];

void meibao() {
    cin >> k;
    
    for (int i = 1; i < M; i++) {
        c[i] = i * (i - 1) / 2;
    }

    if (k == 0) {
        cout << "a\n";
        return;
    }

    vector<int> res;
    while (k > 0) {
        int pos = upper_bound(c + 1, c + M, k) - c;
        pos--;
        res.push_back(pos);
        k -= c[pos];
    }
    assert(k == 0);
    for (int i = 0; i < res.size(); i++) {
        char ch = 'a' + i;
        for (int j = 0; j < res[i]; j++) {
            cout << ch;
        }
    }
}
