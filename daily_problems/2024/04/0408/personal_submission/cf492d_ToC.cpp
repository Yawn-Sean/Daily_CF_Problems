/*
    0、攻击是群攻，所有血量 > 0的 怪物都受到伤害，血量减少1
    1、调整时间单位，使得攻击的时间间隔变成整数
        新的单位t，定义为：1秒 = x*y t
        所以，Vanya每y t 攻击一次，Vova 每 x t攻击一次
    2、最多血量 * 最慢攻击 / 2 = 1e9 * 1e6 / 2= 1e15 / 2 t，才能把怪物杀死
    3、对于每个怪物，二分找出它血量为0，需要z t
    4、如果z是y的倍数，则Vanya拿到最后一滴血；如果z是x的倍数，则Vova拿到最后一滴血
*/
int n, t, m, x, y;
void sol()
{
    cin >> n >> x >> y;
    LL b, l, r;
    for (int i = 0; i < n; i++) {
        cin >> b;
        l = 1, r = 1e15;
        while (l < r) {
            LL mid = l + r >> 1;
            if (mid / x + mid / y >= b) r = mid;
            else l = mid + 1; 
        }
        if (r % y == 0 && r % x == 0) cout << "Both\n";
        else if (r % y == 0) cout << "Vanya\n";
        else if (r % x == 0) cout << "Vova\n";

    }
}
