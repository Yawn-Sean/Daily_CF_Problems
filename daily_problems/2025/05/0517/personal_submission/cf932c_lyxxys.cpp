void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    int n1 = -1, n2 = -1;
    for (int i = 0; i*x <= n; ++ i){
        if ((n-i*x)%y == 0){
            n1 = i, n2 = (n-i*x) / y;
            break;
        }
    }
    if (n1 == -1) return void(cout << -1 << "\n");

    int p = 0;
    vector <int> ans;
    while (n1--){
        ans.push_back(p+x-1);
        for (int i = p; i < p+x-1; ++ i){
            ans.push_back(i);
        }
        p += x;
    }
    while (n2--){
        ans.push_back(p+y-1);
        for (int i = p; i < p+y-1; ++ i){
            ans.push_back(i);
        }
        p += y;
    }

    print(ans, 1);
}
