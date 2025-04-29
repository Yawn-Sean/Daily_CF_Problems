void solve(){
    int n;
    cin >> n;
    vector<array<int,2>> events;

    for (int i = 0,type,x; i < n; ++ i){
        cin >> type;
        x = -1;
        if (type == 1 || type == 3) cin >> x;
        events.push_back({type, x});
    }

    int res = 0;
    bool jug = 0;
    for (int i = n-1; i >= 0; -- i){
        auto [type, x] = events[i];
        if (type%2 == 0){
            if (type == 2) jug = 1;
            else if (type == 4) jug = 0;
            else res += jug;
        }
    }


    vector <int> stk;
    int speed = 0;
    for (int i = 0; i < n; ++ i){
        auto [type, x] = events[i];
        if (type%2 == 1){
            if (type == 1){
                speed = x;
                
                while (!stk.empty() && stk.back() < speed){
                    stk.pop_back();
                    res += 1;
                }
                
            } else if (type == 3){
                if (x >= speed){
                    stk.push_back(x);
                } else {
                    res += 1;
                }
            } else {
                stk.clear();
            }
        }
    }

    cout << res << "\n";
}
