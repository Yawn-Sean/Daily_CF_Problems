/*
点燃爆炸时间最短的一批鞭炮
假设点燃 cnt 个，则至少有 cnt 个时间不能动，其他的都是尽可能尝试远离
假如点燃前 cnt 个比较快的鞭炮，则肯定是先扔需要时间长的，再扔需要时间短的
假如我离警察 len 的距离，则说明我至多能扔 len - 1 个鞭炮
直接考虑扔最短的 min(m, len - 1) 个就好了
但是，扔了的一定能爆炸吗？并不一定可以，所以还是要二分到底能扔前几个，然后模拟一下
*/

int n, m, a, b, s[N];
 
void meibao() {
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
    }
    sort(s + 1, s + m + 1);
    int len = (a > b ? (a - b) : (b - a));
    int max_cnt = min(len - 1, m);
    int alive_cnt = (a > b ? (n - b) : (b - 1));
    

    int l = 0, r = max_cnt, mid;
    
    auto check = [&] (int ans) -> bool {
        for (int i = ans; i > 0; i--) {
            int st = ans - i;
            if (st + s[i] >= alive_cnt) {
                return false;
            }
        }
        return true;
    };
    
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (check(r)) {
        cout << r << "\n";
    } else {
        cout << l << "\n";
    }
}   
