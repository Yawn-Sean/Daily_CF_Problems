int a[N];
int cnt[31][2];
int bad_bits = 0; 

int get_highest_bit(int u, int v) {
    if (u == v) return -1;
    int diff = u ^ v;
    return 31 - __builtin_clz(diff);
}

void update(int u, int v, int delta) {
    int k = get_highest_bit(u, v);
    if (k == -1) 
        return;

    int type = (u >> k & 1); 
    
    if (cnt[k][0] > 0 && cnt[k][1] > 0) 
        bad_bits--;

    cnt[k][type] += delta;


    if (cnt[k][0] > 0 && cnt[k][1] > 0) 
        bad_bits++;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    LL res = 0;
    int l = 1;
    for (int r = 1; r <= n; r++) {
        if (r > 1) {
            update(a[r - 1], a[r], 1);
        }

        while (bad_bits > 0) {
            update(a[l], a[l + 1], -1);
            l++;
        }

        res += (r - l + 1);
    }

    cout << res << "\n";
}
