/*
两个圆环不同心，意味着不会出现边界完全贴合的情况
r[i] < R[i] 严格成立
答案至多是 4
某个圆能贡献，需要满足什么条件？
1. 其在对方两个圆外面，可以是自己包含对方两个圆，或者 out
2. 其在对方两个圆里面
*/

int d, x[3], y[3], r[3], R[3]; 

bool is_join(int r1, int r2) {
    return (d < (r1 + r2) * (r1 + r2) && d > (r1 - r2) * (r1 - r2));
}

bool is_out(int r1, int r2) {
    return d >= (r1 + r2) * (r1 + r2);
}

bool is_in(int r1, int r2) {
    return d <= (r1 - r2) * (r1 - r2) && (r1 <= r2);
}

void meibao() {
    for (int i = 1; i <= 2; i++) {
        cin >> x[i] >> y[i] >> r[i] >> R[i];
    }
    d = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
    
    auto check = [&] (int r1, int r2, int r3) -> int {
        if (is_in(r1, r2) && is_in(r1, r3)) {
            return 1;
        }
        if (is_in(r2, r1) && is_in(r3, r1)) {
            return 1;
        }
        if (is_out(r1, r2) && is_out(r1, r3)) {
            return 1;
        }
        return 0;
    };
    cout << check(r[1], r[2], R[2]) + check(R[1], r[2], R[2]) + check(r[2], r[1], R[1]) + check(R[2], r[1], R[1]) << "\n";
}
