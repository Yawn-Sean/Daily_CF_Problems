/*
由于 x 和 y 都是 distinct，所以 x 最差是 y
设最大值不超过 mx，则似乎是可以二分的？
对于所有 > mx 的数，右移直到 <= mx
然后往集合里面塞，只要不相等就右移即可
*/

int T;
int n, a[N];

bool check(int mx) {
    set<int> s;
    for (int i = 1; i <= n; i++) {
        int val = a[i];
        if (val > mx) {
            while (val > mx) {
                val >>= 1;
            }
        } 
        while (val > 0 && s.count(val)) {
            val >>= 1;
        }
        if (val != 0 && !s.count(val)) {
            s.insert(val);
        } else {
            return false;
        }
    }
    return true;
}

void solve1() {
    cin >> n;
    int mxval = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mxval = max(mxval, a[i]);
    }
    int l = 1, r = mxval, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    int mx = 0;
    if (check(l)) {
        mx = l;
    } else {
        assert(check(r));
        mx = r;
    } 
    set<int> s;
    for (int i = 1; i <= n; i++) {
        int val = a[i];
        if (val > mx) {
            while (val > mx) {
                val >>= 1;
            }
        } 
        while (val > 0 && s.count(val)) {
            val >>= 1;
        }
        assert (val != 0 && !s.count(val));
        s.insert(val);
    }
    for (auto val : s) {
        cout << val << " ";
    }
}      
