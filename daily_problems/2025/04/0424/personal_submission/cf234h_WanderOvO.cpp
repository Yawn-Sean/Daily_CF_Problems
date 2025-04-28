/*
第一堆牌按照正反面分段，能分成 cnt1 段，第二堆牌分成 cnt2 段
则合并之后段数不会小于 max(cnt1, cnt2)
合并完之后，反而很好说了，其实就是合并之后的段数或者段数 - 1，减或者不减取决于最后一段是否本来就是朝下的
不妨 cnt1 >= cnt2
cnt1 > cnt2 时，第二堆合并到第一堆里面能使得段数最少，但是最后一段可能是 1
假如 cnt2 最后一段是 0，但 cnt1 最后一段是 1，似乎没有办法在保证段数还是这些的情况下让最后一段是 0
cnt1 = cnt2，要么都是 0101，要么都是 1010，要么一个 0101 一个 1010
前两种情况没什么好说的，只有一种合并办法；第三种怎样合并都会多出来一段，我们选是 0 结尾的
*/

int n, m, a[N], b[N], c[N];

void merge1() {
    int i = 1, j = 1, idx = 0;
    for ( ; i <= n && j <= m; ) {
        c[++idx] = i;
        int new_i = i + 1;
        for ( ; new_i <= n && a[i] == a[new_i]; new_i++) {
            c[++idx] = new_i;
        }
        
        if (b[j] == a[i]) {
            c[++idx] = j + n;
            int new_j = j + 1;
            for ( ; new_j <= m && b[new_j] == b[j]; new_j++) {
                c[++idx] = new_j + n;
            }    
            j = new_j;
        }
        i = new_i;
    }

    while (i <= n) {
        c[++idx] = i;
        i++;
    }

    while (j <= m) {
        c[++idx] = j + n;
        j++;
    }
}

void merge2() {
    int i = 1, j = 1, idx = 0;
    for ( ; i <= n && j <= m; ) {
        c[++idx] = j + n;
        int new_j = j + 1;
        for ( ; new_j <= m && b[j] == b[new_j]; new_j++) {
            c[++idx] = new_j + n;
        }
        
        if (b[j] == a[i]) {
            c[++idx] = i;
            int new_i = i + 1;
            for ( ; new_i <= n && a[new_i] == a[i]; new_i++) {
                c[++idx] = new_i;
            }    
            i = new_i;
        }
        j = new_j;
    }

    while (i <= n) {
        c[++idx] = i;
        i++;
    }

    while (j <= m) {
        c[++idx] = j + n;
        j++;
    }
}
 
void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    int cnt1 = 1, cnt2 = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i + 1]) {
            cnt1++;
        }
    }
    for (int i = 1; i < m; i++) {
        if (b[i] != b[i + 1]) {
            cnt2++;
        }
    }

    if (cnt1 > cnt2) {
        merge1();
    } else if (cnt1 == cnt2) {
        if (a[n] == 0) {
            merge2();
        } else if (b[m] == 0) {
            merge1();
        } else {
            merge1();
        }
    } else {
        merge2();
    }

    for (int i = 1; i <= n + m; i++) {
        cout << c[i] << " ";
    }
    cout << "\n";

    int cnt = 0;
    for (int i = 1; i <= n + m; i++) {
        c[i] = (c[i] <= n ? a[c[i]] : b[c[i] - n]);
    }

    vector<int> res;
    for (int i = 1; i < n + m; i++) {
        if (c[i] != c[i + 1]) {
            res.push_back(i);
        }
    }
    if (c[n + m] != 0) {
        res.push_back(n + m);
    }
    cout << res.size() << "\n";
    for (auto pos : res) {
        cout << pos << " ";
    }
}   
