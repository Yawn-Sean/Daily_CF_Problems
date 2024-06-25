using pli = pair<ll, int>;
int n, k;
ll x;

void solve() {
    // 看能否负数
    cin >> n >> k >> x;
    vector<ll> a(n);
    cin >> a;
    
    int neg = 0, zero = 0, act = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] < 0ll) neg ++;
        else if (a[i] == 0ll) zero ++;
        else act ++;
    }
    
    // 如果是非负, 看看能否先变成负, 找绝对值最小的数
    if (zero > 0 or neg % 2 == 0) {
        // 尝试先变为负数 先干掉所有的0
        if (zero > k) {
            // 只能是0
            cout << a << endl;
            return;
        }
        // 如果负数为奇数个, 0全变正数, 不然1个变负数
        for (int i = 0; i < n; i ++) {
            if (a[i] == 0) {
                if (neg % 2) {
                    act ++;
                    a[i] = x;
                }
                else {
                    neg ++;
                    a[i] = -x;
                }
                zero --;
                k --;
            }
        }
        
        // 如果仍然为正数 说明就没有0
        // 绝对值最小的变化一下
        if (neg % 2 == 0) {
            int idx = 0;
            for (int i = 1; i < n; i ++) {
                if (abs(a[i]) < abs(a[idx])) idx = i;
            }
            if (abs(a[idx]) >= x * k) {
                if (a[idx] > 0) a[idx] -= x * k;
                else a[idx] += x * k;
                cout << a << endl;
                return; 
            }
            // 可变为负数
            int need = abs(a[idx]) / x + 1;
            if (a[idx] >= 0) a[idx] -= (ll)need * x;
            else a[idx] += (ll)need * x;
            k -= need;
        }
    }

    // 每次贪心给最小的数
    priority_queue<pli, vector<pli>, greater<pli>> q;
    for (int i = 0; i < n; i ++) {
        q.emplace(abs(a[i]), i);
    }
    
    while (k > 0) {
        int idx = q.top().se;
        q.pop();
        
        if (a[idx] > 0) a[idx] += x;
        else a[idx] -= x;
        k --;
        q.emplace(abs(a[idx]), idx);
    }
    cout << a << endl;
}