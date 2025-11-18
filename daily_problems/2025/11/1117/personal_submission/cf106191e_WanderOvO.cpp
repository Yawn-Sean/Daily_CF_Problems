/*
我先问 [1, n] 和 [1, n]
这样相当于知道了所有边的数量
然后枚举左右两边去掉一个点，比如去掉 n
则 [1, n - 1] 和 [1, n - 1] 能询问出边数
两个相减，就是和 n 相连的边数
*/

void query(vector<int> &a, vector<int> &b) {
    cout << "?";
    cout << " " << a.size();
    for (auto v : a) {
        cout << " " << v;
    }
    cout << " " << b.size();
    for (auto v : b) {
        cout << " " << v;
    }
    cout << endl;
}

void answer(int ans) {
    cout << "! " << ans << endl;
}

void solve() {   
    int n;
    int total = 0;
    cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
        b.push_back(i);
    }
    
    query(a, b);
    cin >> total;
    int s = 0;
    for (int i = 1; i < n; i++) {
        a.clear();
        b.clear();
        for (int j = 1; j <= n; j++) {
            if (j != i) {
                a.push_back(j);
                b.push_back(j);
            }
        }
        
        query(a, b);
        int cnt;
        cin >> cnt;
        if (total - cnt == 1) {
            answer(i);
            return;
        }
        s += total - cnt;
        
    }
    
    if (2 * total - s == 1) {
        answer(n);
    } else {
        answer(-1);
    }
}
