int query(int pos, int n) {
    printf("? %d\n", pos);
    fflush(stdout);
    int val1, val2;
    scanf("%d", &val1);
    printf("? %d\n", pos + (n / 2));
    fflush(stdout);
    scanf("%d", &val2);
    return val1 - val2;
}
 
void solve() {
    int n;
    scanf("%d", &n);
    if (n % 4 != 0) {
        printf("! -1\n");
        fflush(stdout);
        return;
    }
    int g1 = query(1, n);
    if (g1 == 0) {
        printf("! 1\n");
        fflush(stdout);
        return;
    }
    int lo = 1, hi = n / 2;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int val = query(mid, n);
        if (val == 0) {
            printf("! %d\n", mid);
            fflush(stdout);
            return;
        }
        if (val * g1 < 0) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
}
