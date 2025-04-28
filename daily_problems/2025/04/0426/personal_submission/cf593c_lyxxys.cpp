void solve(){
    int n;
    cin >> n;
    vector <int> xs(n), ys(n);
    for (int i = 0, r; i < n; ++ i){
        cin >> xs[i] >> ys[i] >> r;
    }

    auto work = [&](vector <int> vec)->void{
        cout << string(n-1, '(');
        for (int i = 0; i < n; ++ i){
            if (i) cout << "+";
            cout << "(" << vec[i]/2;
            cout << "*((1-abs((t-" << i << ")))";
            cout << "+abs((1-abs((t-" << i << "))))))";
            if (i) cout << ")";
        }
        cout << "\n";
    };

    work(xs);
    work(ys);
}
