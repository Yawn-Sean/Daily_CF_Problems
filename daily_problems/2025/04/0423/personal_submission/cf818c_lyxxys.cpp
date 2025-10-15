void solve(){
    int d, n, m;
    int cl, cr, ct, cb;

    cin >> d >> n >> m;

    vector<array<int,4>> A(d);

    vector <int> pr1(n+2), pr2(n+2), pr3(m+2), pr4(m+2);
    for (auto &i : A){
        cin >> i[0] >> i[1] >> i[2] >> i[3];
        pr1[min(i[0], i[2])] += 1;
        pr2[max(i[0], i[2])] += 1;
        pr3[min(i[1], i[3])] += 1;
        pr4[max(i[1], i[3])] += 1;
    }
    cin >> cl >> cr >> ct >> cb;

    for (int i = 1; i <= n; ++ i){
        pr1[i] += pr1[i-1];
    }
    for (int i = n; i >= 1; -- i){
        pr2[i] += pr2[i+1];
    }
    for (int i = 1; i <= m; ++ i){
        pr3[i] += pr3[i-1];
    }
    for (int i = m; i >= 1; -- i){
        pr4[i] += pr4[i+1];    
    }

    int chose = -2;
    for (int i = 0; i < d; ++ i){
        auto [x1, y1, x2, y2] = A[i];
        int cnt = 0;

        int c1 = max(x1, x2), c2 = min(x1, x2), c3 = max(y1, y2), c4 = min(y1, y2);
        if (pr1[c1-1]-(c1!=c2) == cl) cnt += 1;
        if (pr2[c2+1]-(c1!=c2) == cr) cnt += 1;
        if (pr3[c3-1]-(c3!=c4) == ct) cnt += 1;
        if (pr4[c4+1]-(c3!=c4) == cb) cnt += 1;

        if (cnt == 4){
            chose = i;
            break;
        }
    }


    cout << chose+1 << "\n";
}
