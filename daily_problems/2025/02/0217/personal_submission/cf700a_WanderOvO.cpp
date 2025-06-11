/*
二分最早到的时间
可以计算出每个人需要被公交车载多久才能在规定时间内到达
看是否每个人都可以被载至少这么久
*/

LL n, k, l;
long double v1, v2;

// 计算每个人需要被 bus 载多久才能在规定时间内恰好到达
long double get_bus_time(long double ans) {
    long double left = 0, right = ans, mid;
    for (int rd = 0; rd <= 70; rd++) {
        mid = (left + right) / 2;
        if (mid * v2 + (ans - mid) * v1 < l) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

bool check(long double ans) {
    long double time_without_bus = (1.0 * l) / v1;
    if (time_without_bus < ans || (fabs(time_without_bus - ans) < eps)) {
        return true;
    }

    long double bus_time = get_bus_time(ans);
    if (fabs(bus_time - ans) < eps && bus_time * v2 < l) {
        return false;
    }
    long double used_time = 0, c = 0;
    for (int i = 1; i <= n; i += k) {
        long double left_dist = l - used_time * v1;
        long double need_to_go = bus_time * v2;
        if (need_to_go <= left_dist) {
            long double y = bus_time - c; 
            long double z = used_time + y; 
            c = (z - used_time) - y; 
            used_time = z;
            
            y = (bus_time * (v2 - v1)) / (v2 + v1) - c; 
            z = used_time + y; 
            c = (z - used_time) - y; 
            used_time = z; 
        } else {
            return false;
        }
    }
    return true;
}

void meibao() {
    cin >> n >> l >> v1 >> v2 >> k;
    long double l = 0, r = 2e9, mid;
    for (int rd = 0; rd <= 70; rd++) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << setprecision(15) << l << "\n";
}
