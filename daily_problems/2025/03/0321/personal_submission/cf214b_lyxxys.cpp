
void solve(){
    int n;
    cin >> n;
    vector <int> cnts(10);
    int tot = 0;
    for (int i = 0; i < n; ++ i){
        int x;
        cin >> x;
        cnts[x] += 1;
        tot += x;
    }

    auto fout = [&]()->void{
        string ans;
        for (int i = 9; i >= 0; -- i){
            int cnt = cnts[i];
            while (cnt--) ans += char(i+'0');
        }
        if (ans[0] == '0') cout << 0 << "\n";
        else cout << ans << "\n";
    };
    
    if (cnts[0] == 0){
        cout << -1 << "\n";
    } else if (tot%3 == 0){
        fout();
    } else {
        for (int i = 1; i < 10; ++ i){
            if (!cnts[i]) continue;
            if ((tot-i)%3 == 0){
                cnts[i] -= 1;
                fout();
                return;
            }
        }
        for (int i = 1; i < 10; ++ i){
            if (!cnts[i]) continue;
            if (i == 0 && cnts[i] == 1) continue;
            cnts[i] -= 1;
            for (int j = 1; j <= i; ++ j){
                if (cnts[j] && (tot-i-j)%3 == 0){
                    if (j == 0 && cnts[j] == 1) continue;
                    cnts[j] -= 1;
                    fout();
                    return;
                }
            }
            cnts[i] += 1;
        }
    }
}
