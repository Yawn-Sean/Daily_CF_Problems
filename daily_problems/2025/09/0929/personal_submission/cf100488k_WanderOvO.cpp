/*
我先手
如果有奇数个，则最后一个必然是我的
如果有偶数个，则最后两个里面必然有一个是我的
前一半里面，我至多只能拿一半的一半
对于每个前缀，我都至多只能拿这个前缀的一半上取整个
假如我确定了我要拿哪些，那么从前往后拿是最可能实现这一点的
不妨我就先能拿则拿，然后和前面的哪些换一下，有点像反悔贪心
只考虑前 i 个物品，看我至多能拿多少钱的
从左往右遍历，用堆维护自己拿了哪些
如果能多拿一个了，就直接无脑拿
否则，考虑选一个最小的，能不能和当前的换一下
*/

LL n, a[N];

void meibao() {
    cin >> n;
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    priority_queue<LL, vector<LL>, greater<LL>> pq;
    for (int i = 1; i <= n; i++) {
        int sz = pq.size();
        if ((i + 1) / 2 > sz) {
            pq.push(a[i]);
        } else {
            int tp = pq.top();
            pq.pop();
            if (tp <= a[i]) {
                pq.push(a[i]);
            } else {
                pq.push(tp);
            }
        }
    }

    LL res = 0;
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    cout << res << " " << sum - res << "\n";
}   
