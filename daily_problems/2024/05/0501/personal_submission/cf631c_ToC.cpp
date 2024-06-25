// https://codeforces.com/contest/631/submission/259021770
void sol()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxr = -1, start = -1;
    for (int i = 1; i <= m; i++) {
        cin >> op[i].ff >> op[i].ss;
        // take the last appearance of maxr
        if (maxr <= op[i].ss) {
            start = i;
            maxr = op[i].ss;
        }
    }
    // 只执行stk中的有效排序
    vector<int> stk;
    stk.push_back(start);
    for (int i = start + 1; i <= m; i++) {
        int tmp = op[i].ss;
        while (!stk.empty() && (tmp >= op[stk.back()].ss)) {
            stk.pop_back();
        }
        stk.push_back(i);
    }
    int head = 1, tail = maxr;
    sort(a + 1, a + maxr + 1);  // 非降序排列
    vector<int> res(n + 1);
    for (int i = maxr + 1; i <= n; i++) 
        res[i] = a[i];

    int wr = op[stk[0]].ss, wl = -1;  // 填写答案[wl, wr]
    for (int i = 0; i < stk.size() - 1; i++) {
        // op[stk[i]]是降序 等价于 left_flag == true
        bool left_flag = op[stk[i]].ff == 2;
        wl = op[stk[i + 1]].ss + 1;
        if (wl > wr) break; //保证O(n)
        // printf("wl: %d, wr: %d\n", wl, wr);
        if (left_flag) {
            // 填写非降序序列中左侧子数组
            for (int i = wr; i >= wl; i--) 
                res[i] = a[head++];
        } else {
            // 填写非降序序列中右侧子数组
            for (int i = wr; i >= wl; i--) 
                res[i] = a[tail--];
        }
        wr = wl - 1;
    }
    wl = 1;
    // 填写最后一次的排序内容[1, wr]
    if (op[stk.back()].ff == 2) {
        for (int i = wr; i >= wl; i--) 
            res[i] = a[head++];
    } else {
        for (int i = wr; i >= wl; i--) 
            res[i] = a[tail--];
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';
}
