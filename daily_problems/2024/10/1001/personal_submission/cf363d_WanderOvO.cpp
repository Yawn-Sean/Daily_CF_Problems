/*
显然有便宜的车肯定先租便宜的车更好，最后租的车是前 r 便宜的肯定是一种最优解
假如一个自带钱多的人最后都租不到车，那么自带钱少的人更租不到车了，所以可以断定一定是租金前 r 多的人租到了车
升序排序车子，降序排序人，二分 r
对于某个确定的 r，如何检查？
分类讨论画画线段，发现钱多的买贵的，钱少的买便宜的最好
这样可以求出最大的 r，进一步如何求最小的 s？
由于买这 r 个车总钱数确定，所以要多花公共的钱才能让 s 变小，其实就是最极限把 a 都花光
所以直接总代价 - a，和 0 取最大值就是最少花费的个人财产
*/

int n, m, a, b[N], p[N];

bool check(int ans) {
    int left_a = a;
    for (int i = 1; i <= ans; i++) {
        left_a -= max(0, p[ans - i + 1] - b[i]);
        if (left_a < 0) {
            break;
        }    
    }
    return left_a >= 0;
}

void solve1() {
    cin >> n >> m >> a;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    sort(b + 1, b + n + 1);
    sort(p + 1, p + m + 1);
    reverse(b + 1, b + n + 1);
    int l = 0, r = min(n, m), mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int res = check(r) ? r : l;
    cout << res << " ";
    LL tot_rent = 0;
    for (int i = 1; i <= res; i++) {
        tot_rent += p[i];
    }
    tot_rent -= a;
    cout << max(0LL, tot_rent) << " ";
}                                                                                                                  
