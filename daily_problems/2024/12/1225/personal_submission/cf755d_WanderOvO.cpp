/*
条件为什么保证 gcd(n, k) = 1？假设从 0 开始走，则走到的位置为 cnt * k % n
设 r = cnt * k % n, 则 cnt * k + c * n = r
gcd(n, k) | r 时才有整数解，由于 gcd(n, k) = 1，故所有位置均可达，并且一定是最后回到 1
如果走到一个之前走过的点，就不会有新的线了，后边的区域数也不变了
每画一条新的线会和多少条老的线相交，和 cnt 个线相交，会增加 cnt + 1 个区域
如何刻画相交？假设现在在 cur 点，走到 ne 点
有没有可能有线段被完全包含在 (cur, ne) 里面了？k 超过一半时可能
我们关心 (cur, ne) 中总共往外连了多少条线，并且会单点更新
*/

LL n, k;
BIT t;

void meibao() {
    cin >> n >> k;
    k = min(k, n - k);
    t.init(n);
    int cur = 1;
    LL last_res = 1;
    for (int i = 1; i <= n; i++) {
        int ne = cur + k;
        if (ne > n) {
            ne = cur + k - n;
        }
        if (cur < ne) {
            if (cur + 1 <= ne - 1) {
                last_res += t.query(ne - 1) - t.query(cur);
            } 
        } else {
            last_res += t.query(n) - t.query(cur);
            if (ne - 1 > 0) {
                last_res += t.query(ne - 1);
            }
        }
        last_res++;
        cout << last_res << " ";
        t.add(cur, 1);
        t.add(ne, 1);
        cur = ne;
    }
}
