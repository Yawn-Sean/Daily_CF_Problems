/*
假如碰到不喜欢的歌，则会把之前听过的喜欢的歌都再听一遍
假设听的顺序已经确定了，则如何计算期望秒数？
从左到右看每首歌：
- 假如喜欢这首歌，则先听 1 次，再看右边有几首不喜欢的歌，就还得再听几次
  需要计算一下右边不喜欢的歌的期望首数，似乎就是把不喜欢概率加起来？
  (概率和 + 1) * 这首歌的秒数 * 喜欢这首歌的概率
- 假如不喜欢这首歌，则只需听 1 次，这首歌的描述 * 不喜欢这首歌的概率

所以最大的听的顺序是什么呢？似乎得推一下式子，考虑邻项交换
*/

struct Song {
    LL l, p;

    bool operator<(const Song &o) const {
        return p * l * (100 - o.p) > o.p * o.l * (100 - p);
    }
};

LL n;
Song a[N];
LL dislike_p[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].p;
    }
    double res = 0;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        dislike_p[i] = dislike_p[i - 1] + (100 - a[i].p);
    }
    for (int i = 1; i <= n; i++) {
        LL dislike = dislike_p[n] - dislike_p[i];
        res += (100 - a[i].p) * a[i].l / 100.0;
        res += (a[i].p / 100.0) * a[i].l * (dislike / 100.0 + 1);
    }
    cout << setprecision(15) << res << "\n";
}  
