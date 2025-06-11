void solve(){
    string s;
    getline(cin, s);
    stringstream ssin(s);

    int a = 1, b = 0, cnt = 0;
    int n = 0;
    vector <int> who = {1};{
        bool jg = 0;
        char x;
        while (ssin >> x){
            if (jg){
                n = n*10 + (x - '0');
            } else {
                if (x == '?'){
                    cnt += 1;
                } else if (x == '+'){
                    a += 1;
                    who.push_back(1);
                }
                else if (x == '-'){
                    b += 1;
                    who.push_back(-1);
                } else jg = 1;
            }
        }
    }

    assert(a+b == cnt);

    if (n*(a-1) >= b && n*(1+b) >= a){
        vector <int> ans(cnt);
        for (int i = 0; i < cnt; ++ i){
            if (who[i] == 1) ans[i] = n;
            else ans[i] = 1;
        }
        int rare = a*n-b - n;
        for (int i = 0; i < cnt; ++ i){
            if (rare > n-1){
                rare -= n-1;
                ans[i] -= who[i] * (n-1);
            } else {
                ans[i] -= who[i] * rare;
                rare = 0;
            }
            if (rare == 0) break;
        }
        assert(rare == 0);

        cout << "Possible\n";
        for (int i = 0; i < cnt; ++ i){
            if (i > 0){
                cout << (who[i] > 0 ? " + " : " - ");
            }
            cout << ans[i];
        }
        cout << " = " << n << "\n";
    } else {
        cout << "Impossible\n";
    }
}
