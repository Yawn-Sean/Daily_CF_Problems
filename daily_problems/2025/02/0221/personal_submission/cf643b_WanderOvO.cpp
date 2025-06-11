
/*
先连一条从 a 开始，经过所有点最终走到 b 的链，其中 c 和 d 不相邻
然后 c 走到 a，a 走到 c 的下一个，一直走，然后走 b，b 再到 d
*/

int n, k, a, b, c, d;

void meibao() {
    cin >> n >> k >> a >> b >> c >> d;
    if (k < n + 1 || n == 4) {
        cout << "-1\n";
        return;
    }
    vector<int> path;
    cout << a << " " << c << " ";
    path.push_back(a);
    path.push_back(c);
    for (int i = 1; i <= n; i++) {
        if (i != a && i != b && i != c && i != d) {
            cout << i << " ";
            path.push_back(i);
        }
    }
    cout << d << " " << b << "\n";
    path.push_back(d);
    path.push_back(b);
    
    cout << c << " " << a << " ";
    for (int i = 2; i < n && path[i] != d; i++) {
        cout << path[i] << " ";
    }
    for (int i = n - 1; i >= 0 && path[i] != d; i--) {
        cout << path[i] << " ";
    }
    cout << d << "\n";
}

}
