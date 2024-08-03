// https://codeforces.com/contest/1019/submission/260262188
vector<int> p2v[MAXN];
// 单调性: 1党最终mid票的花费 <= 最终mid + 1票的花费
LL check(int mid) {
    vector<int> left;   //剩余元素
    LL tot = 0;
    int cnt = p2v[1].size();
    for (int i = 2; i <= m; i++) {
        int siz = p2v[i].size(), idx = 0;
        // 假设最终1党有mid票
        // 所有大于等于mid的其他党都要减少到mid - 1
        while (siz >= mid) {
            tot += p2v[i][idx];
            idx++;
            siz--;
            cnt++;
        }
        // 把剩余的票合并在一起
        while (idx < p2v[i].size()) {
            left.push_back(p2v[i][idx]);
            idx++;
        }
    }
    // 剩余票排序
    sort(left.begin(),left.end());

    // 如果1党票数 > mid，非法值
    if (cnt > mid) return LNF;
    if (cnt == mid) return tot;
    // 如果1党票数 < mid，则继续补充
    for (int i = 0; i < left.size(); i++) {
        if (cnt == mid) {
            break;
        }
        cnt++;
        tot += left[i];
    }
    return tot;
}
void sol()
{
    cin >> n >> m;
    int pa, pr;
    for (int i = 1; i <= n; i++) {
        cin >> pa >> pr;
        p2v[pa].push_back(pr);
    }
    //  选择本来支持1党的代价为0
    for (int i = 0; i < p2v[1].size(); i++)
        p2v[1][i] = 0;
    for (int i = 1; i <= m; i++) {
        sort(p2v[i].begin(), p2v[i].end());
    }
    int head = max(1, (int)p2v[1].size()), tail = n;
    LL res = LNF;
    for (int i = head; i <= tail; i++) {
        res = min(res, check(i));
    }
    cout << res << '\n';
}
