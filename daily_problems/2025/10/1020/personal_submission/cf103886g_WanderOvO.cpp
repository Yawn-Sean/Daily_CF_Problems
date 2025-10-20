/*
等差的三个数，下标不能再等差了
能否打表先看看？只看字典序最小的可能不够
符合题意的排列的密度大吗？n 比较小的时候密度确实还可以，直接随机的机会很大

羊的提示：将问题拆解为更小规模的问题
奇数放前一半，偶数放后一半，则成等差数列的三元组一定是左边或右边内部的，不可能跨段
然后就可以继续递归，按照第二位是 0 还是 1 去递归分段
*/ 

int n;
int res[M];

void dfs(int bit, int l, int r, vector<int> a) {
    if (l == r) {
        res[l] = a[0];
        return;
    }
    
    vector<int> b, c;
    for (auto val : a) {
        if ((val >> bit) & 1) {
            c.push_back(val);
        } else {
            b.push_back(val);
        }
    }

    int mid = b.size() + l - 1;
    dfs(bit + 1, l, mid, b);
    dfs(bit + 1, mid + 1, r, c);
}

void meibao() {
    cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    dfs(0, 1, n, a);
    // for (int i = 1; i <= n; i++) {
    //     for (int d = 1; i + 2 * d <= n; d++) {
    //         int j = i + d, k = i + 2 * d;
    //         if (res[k] - res[j] == res[j] - res[i]) {
    //             cout << "fuck\n";
    //             return;
    //         }
    //     }
    // }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}  
