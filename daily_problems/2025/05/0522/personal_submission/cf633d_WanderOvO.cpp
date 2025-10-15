/*
枚举前两个数字，则后面的也就确定了，但是需要 O(n^3)
真的是 O(n^3) 吗？给的数字范围在 [-1e9, 1e9]，如果加爆了就可以 break 了
如果选的是两个正数或者两个负数，那么复杂度是有保证的
如果选的是一正一负：
- 绝对值相等，则第三个数是 0，后边就是单调的
- 绝对值不等，不妨假设正数绝对值更大
  - f0 为负，f1 为正，则后边都是正数
  - f0 为正，f1 为负，虽然 f2 为正，但后面可能会发生震荡
0 也会影响复杂度，怎么处理呢？

羊神提示：前两项不都为 0 时，可以求出通项公式，通过分析可以发现这个时候一定是会快速爆范围的
前两项都为 0 时，其实就是全 0，单独考虑
*/

LL a[N], n;
 
void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    int res = 0;
    map<int, int> st;
    for (int i = 1; i <= n; i++) {
        st[a[i]]++;
        if (a[i] == 0) {
            res++;
        }
    }
    for (int i = 1; i <= n && res < n; i++) {
        for (int j = 1; j <= n && res < n; j++) {
            if (i != j && !(a[i] == 0 && a[j] == 0)) {
                LL f0 = a[i], f1 = a[j];
                int len = 2;
                vector<int> deleted;
                st[f0]--;
                st[f1]--;
                deleted.push_back(f0);
                deleted.push_back(f1);
                while (true) {
                    LL f2 = f0 + f1;
                    if (st.count(f2) && st[f2] != 0) {
                        st[f2]--;
                        deleted.push_back(f2);
                        f0 = f1;
                        f1 = f2;
                        len++;
                    } else {
                        break;
                    }
                }
                for (auto val : deleted) {
                    st[val]++;
                }
                res = max(res, len);
            }
        }
    }
    cout << res << "\n";
}   
