void solve(){
    int m;
    cin >> m;
    auto Val = [&](vector<int>& s)->int{
        int ma = 0;
        vector <int> cnts(52);
        for (auto &x : s){
            cnts[x] += 1;
        }
        for (int i = 0; i < 52; ++ i){
            fmax(ma, cnts[i]);
        }
        int n = s.size();
        int res = min(n, ma+m);
        if (ma == n && m == 1) res = max(1, res-1);
        return res;
    };
    auto turn = [&](vector <int> &A, string s)->void{
        for (auto &ch : s){
            if (islower(ch)) A.push_back(ch-'a');
            else A.push_back(ch-'A'+26);
        }
    };

    vector <int> A, B, C;
    string a, b, c;
    cin >> a >> b >> c;
    turn(A, a), turn(B, b), turn(C, c);

    const vector<string> nm = {"Kuro", "Shiro", "Katie"};
    vector<int> mas = {Val(A), Val(B), Val(C)};
    int x = *max_element(mas.begin(), mas.end()), cnt = 0;
    for (auto &y : mas){
        if (y == x){
            cnt += 1;
        }
    }
    if (cnt > 1){
        cout << "Draw\n";
    } else {
        for (int i = 0; i < 3; ++ i){
            if (mas[i] == x){
                cout << nm[i] << "\n";
            }
        }
    }
}
