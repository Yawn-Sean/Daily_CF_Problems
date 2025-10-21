/*
感觉总体思路是从前往后确定每个数是谁
首先需要复习一下康托展开咋算的排名，现在复习好了
假设当前的排列的排名是 rk，则我们相当于要求排名是 rk + n! / 2 的排列是谁
rk 可以用康托展开去求，其表达式为
rk = sum((k[i] - 1) * (n - i)!) + 1
其中，k[i] 表示 a[i] 在 a[i...n] 中的排名是多少
现在相当于求第 sum((k[i] - 1) * (n - i)!) + 1 + n! / 2 的排列是谁
羊神的做法是，把 n! / 2 合并到前面的式子里，具体来说
(k[2] - 1) * (n - 2)! 这一项和 n! / 2 合并，变成
(k[2] - 1 + n * (n - 1) / 2) * (n - 2)!
其他项完全不变
k[2] - 1 + n * (n - 1) / 2 这个东西会超过 n - 1，对于超过的部分，我们直接将其加到第一位上
即，k[2] - 1 + n * (n - 1) / 2 需要对 n - 1 取模，用来表示这一位已经有多少位的全排列已经搞过了
k[2] - 1 + n * (n - 1) / 2 除以 n - 1 的，贡献到第一位，这个可能也会爆，所以第一位要对 n 取模
时限很严格，需要写真正的树状数组二分
*/ 

LL n, a[N], tr[N], k[N];

LL lowbit(LL x) {
    return x & -x;
}

void modify(LL pos, LL val) {
    while (pos <= n) {
        tr[pos] += val;
        pos += lowbit(pos);
    }
}

LL query(LL pos) {
    LL res = 0;
    while (pos > 0) {
        res += tr[pos];
        pos -= lowbit(pos);
    }
    return res;
}

LL find_kth(LL rk) {
    LL pos = 0, sum = 0;
    for (int i = log2(n); i >= 0; i--) {
        if (pos + (1 << i) <= n) {
            int new_pos = pos + (1 << i);
            if (sum + tr[new_pos] < rk) {
                pos = new_pos;
                sum += tr[new_pos];
            }
        }
    }
    return pos + 1;
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i > 0; i--) {
        k[i] = query(a[i] - 1);
        modify(a[i], 1);
    }

    k[2] += n * (n - 1) / 2;
    k[1] += k[2] / (n - 1);
    k[2] %= (n - 1);
    k[1] %= n;

    for (int i = 0; i < N; i++) {
        tr[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        modify(i, 1);
    }

    for (int i = 1; i <= n; i++) {
        int res = find_kth(k[i] + 1);
        cout << res << " ";
        modify(res, -1);
    }
}   
