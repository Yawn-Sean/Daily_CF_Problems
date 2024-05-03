/*
最终其实就是每个数被加了一定的次数，而操作次数我们只需要看被操作最多的那个即可
我们可以二分答案，设每个数被操作不超过 ans 次，
*/

int T;
int n, m, a[N], b[N];

bool check(int ans) {
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if (b[i] < b[i - 1]) {
            if (b[i - 1] - b[i] > ans) {
                return false;
            }
            b[i] = b[i - 1];
        } else if (b[i] > b[i - 1]) {
            if (b[i - 1] + m - b[i] <= ans) {
                b[i] = b[i - 1];
            }
        }
    }
    return true;
}

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }    
    
    int l = 0, r = 2 * m, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) {
        cout << l << "\n";
    } else {
        cout << r << "\n";
    }
}            