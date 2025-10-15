/*
有 n - 1 个切割点，每个切割点可以切也可以不切
需要恰好选 3 个切割点，使得切出来差距尽可能小
只需要输出最小的差即可，无需输出具体方案
能否先确定最小的差，然后看能否取出呢
或者我指定最小的一段的长度，后边只能取 >= 这个长度的
我们不妨枚举第一段是多长，也就是第一个切割点在哪里选的
那么第三个切割点需要找最接近第一段长度的位置
可以二分/用一个指针维护这个位置
但是目前有两个问题：
1. 选最接近第一段的是否真的最优？
2. 如果是最优，那么当有两个一样优的切割点时，选哪个？

我们思考了一下，发现似乎可以有另一种枚举方式
我们枚举第二个切割点的位置，这样就分成了左右两段
每段再选一个切割点进行切分
左右两边是否取最接近中点的那（1或2）个点呢？
不妨考虑左半段长度 <= 右半段长度
假如不按中点分，则左边的较短的那段肯定更短了，右边更长的段也更长了，不优
考虑找中点的具体做法
枚举第二个分割点为 i，则左半段我们希望找 >= x[i] / 2 的第一个分割点
并把它左边那个分割点也考虑一下
右半段的长度为 L - x[i]，我们希望找 >= x[i] + (L - x[i]) / 2 的第一个分割点
并把它左边那个分割点也考虑一下
注意，点别重复了
对拍了一下，应该是正确的做法
*/ 

LL n, L, x[N];

LL calc(LL p1, LL p2, LL p3) {
    assert(p1 < p2 && p2 < p3 && p1 > 0 && p2 < n);
    
    vector<LL> len;
    len.push_back(x[p1]);
    len.push_back(x[p2] - x[p1]);
    len.push_back(x[p3] - x[p2]);
    len.push_back(L - x[p3]);
    sort(len.begin(), len.end());
    return len.back() - len[0];
}

void meibao() {
    cin >> n >> L;
    for (int i = 1; i < n; i++) {
        cin >> x[i];
    }
    
    LL res = 1e16;
    for (int i = 2; i < n - 1; i++) {
        int p1 = lower_bound(x + 1, x + n, x[i] / 2) - x;
        int p2 = 0;
        if (p1 == i) {
            p1--;
            p2 = p1;
        } else {
            p2 = p1 - 1;
            if (p2 == 0) {
                p2++;
            }
        }
        
        int p3 = lower_bound(x + 1, x + n, x[i] + (L - x[i]) / 2) - x;
        int p4 = 0;
        if (p3 == n) {
            p3--;
            p4 = p3;
        } else {
            p4 = p3 - 1;
            if (p4 == i) {
                p4++;
            }
        }
        
        res = min(res, calc(p1, i, p3));
        res = min(res, calc(p1, i, p4));
        res = min(res, calc(p2, i, p3));
        res = min(res, calc(p2, i, p4));
    }
    cout << res << endl;
}   
