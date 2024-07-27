/*
假设没有 0，怎么判断是否能通过题目的操作得到？
题目保证给的 a[i] <= q
一定得存在最大值 q
某个数 val 最左和最右位置为 l, r，[l, r] 之间不能有 < val 的数
*/

int T;
int n, q, a[N], l[N], r[N];
ST st;

void solve1() {
    cin >> n >> q;
    int mx = 0, zero_cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        if (a[i] == 0) {
            zero_cnt++;
        }
    }
    if (mx != q) {
        if (zero_cnt == 0) {
            cout << "NO\n";
            return;
        }
        
        zero_cnt--;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                a[i] = q;
                break;
            }
        }
    }
    int val = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            a[i] = val;
        } else {
            val = a[i];
        }
    }
    
    
    st.init_st(a, n);
    for (int i = 1; i <= n; i++) {
        if (l[a[i]] == 0) {
            l[a[i]] = i;
        }
        r[a[i]] = i;
    }
    for (int i = 1; i <= q; i++) {
        if (l[i] != 0) {
            int val = st.query(l[i], r[i]);
            if (val < i) {
                cout << "NO\n";
                return;
            }
        }
    }
    
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}                                                                                                                  
