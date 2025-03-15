void solve(){
    int n;
    cin >> n;

    int res = 0;
    vector <int> chose;
    map <array<int,2>, array<int,2>> mps;
    vector <int> stone(3);
    auto chge = [&](int x, int y, int d, int id)->void{
        if (!mps.count({x,y}) || mps[{x,y}][0] < d){
            mps[{x,y}] = {d, id};
        }
    };
    for (int i = 0; i < n; ++ i){
        for (auto &x : stone){
            cin >> x;
        }
        sort(stone.begin(), stone.end());
        if (mps.count({stone[0], stone[1]})){
            auto [d, id] = mps[{stone[0], stone[1]}];
            int mi = min({stone[0], stone[1], d+stone[2]});
            if (mi > res){
                res = mi;
                chose = {id, i+1};
            }
        }
        if (mps.count({stone[0], stone[2]})){
            auto [d, id] = mps[{stone[0], stone[2]}];
            int mi = min({stone[0], stone[2], d+stone[1]});
            if (mi > res){
                res = mi;
                chose = {id, i+1};
            }
        }
        if (mps.count({stone[1], stone[2]})){
            auto [d, id] = mps[{stone[1], stone[2]}];
            int mi = min({stone[1], stone[2], d+stone[0]});
            if (mi > res){
                res = mi;
                chose = {id, i+1};
            }
        }
        if (min({stone[0], stone[1], stone[2]}) > res){
            res = stone[0], stone[1], stone[2];
            chose = {i+1};
        }
        chge(stone[0], stone[1], stone[2], i+1);
        chge(stone[0], stone[2], stone[1], i+1);
        chge(stone[1], stone[2], stone[0], i+1);
    }

    cout << chose.size() << "\n";
    print(chose);
}
