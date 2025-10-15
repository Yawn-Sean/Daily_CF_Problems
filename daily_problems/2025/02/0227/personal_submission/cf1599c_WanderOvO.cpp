/*
每轮游戏开始前，先从 n 个地图里选 3 个，然后对方和自己分别选择一个地图来丢弃（选择可能相同）
在这 3 个里面剩下的随机选一个作为本轮使用的地图
假设自己学了 cnt 张地图，概率是多少？
只要选到了 >= 2 张自己学过的地图，就一定押题成功，所以只需要算抽到 1 个以及没抽到的情况
- 抽到了 0 张自己学过的地图，有 C(n - cnt, 3) / C(n, 3) 的概率，之后不管怎么选都无所谓，一定没押中
- 抽到了 1 张自己学过的地图，有 C(n - cnt, 2) * cnt / C(n, 3) 的概率
  进一步考虑这种情况的概率，自己肯定是没学过的 2 选 1，对方是 3 选 1，算一下概率 1 / 12 + 1 / 12 + 1 / 6 + 1 / 6 = 1 / 2
- 抽到了 2 张自己学过的地图，有 C(n - cnt, 1) * C(cnt, 2) / C(n, 3)
- 抽到了 3 张自己学过的地图，有 C(cnt, 3) / C(n, 3)
*/

LL n;
double p;

double C(LL a, LL b) {
    double res = 1;
    if (a < b) return 0;
    for (int i = a - b + 1; i <= a; i++) {
        res *= i;
    }
    for (int i = 2; i <= b; i++) {
        res /= i;
    }
    return res;
}

void meibao() {
    cin >> n >> p;

    for (LL cnt = 0; cnt <= n; cnt++) {
        double prob = C(n - cnt, 2) * cnt / 2 + C(n - cnt, 1) * C(cnt, 2) + C(cnt, 3);
        prob /= C(n, 3);
        // cout << prob << "\n";
        if (prob >= p) {
            cout << cnt << "\n";
            return;
        }
    }
}   
