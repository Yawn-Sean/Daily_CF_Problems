void solve(){
    vector <int> cnts(26);
    deque <int> dq1, dq2;
    string s;

    cin >> s;
    for (auto &ch : s){
        cnts[ch-'a'] += 1;
    }
    for (int i = 25; i >= 0; -- i){
        while (cnts[i]){
            dq1.push_back(i);
            cnts[i] -= 1;
        }
    }

    cin >> s;
    for (auto &ch : s){
        cnts[ch-'a'] += 1;
    }
    for (int i = 0; i < 26; ++ i){
        while (cnts[i]){
            dq2.push_back(i);
            cnts[i] -= 1;
        }
    }

    int n = s.size();
    string ans(n, '?');

    int i = 0, j = n-1, turn = 1;
    while (dq1.size() != (n+1)/2){
        dq1.pop_front();
    }
    while (dq2.size() != n/2){
        dq2.pop_front();
    }

    while (i <= j){
        deque<int> &Q = (turn ? dq1 : dq2);
        if (dq1.back() < dq2.back()){
            ans[i] = char(Q.back()+'a');
            Q.pop_back();
            i += 1;
        } else {
            ans[j] = char(Q.front()+'a');
            Q.pop_front();
            j -= 1;
        }
        turn = !turn;
    }

    cout << ans << "\n";
}
