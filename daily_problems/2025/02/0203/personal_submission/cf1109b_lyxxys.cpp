
void solve(){
    auto impo = [&]()->void{
        cout << "Impossible\n";
    };

    string s;
    cin >> s;
    int n = s.size();
    set <char> st;

    if (n%2 == 0){
        for (int i = 0; i < n; ++ i){
            st.insert(s[i]);
        }
        
        if (st.size() == 1) return impo();

        while (s.size()%2 == 0){
            string t1 = s.substr(0, s.size()/2), t2 = t1;
            reverse(t2.begin(), t2.end());
            if (t1 != t2) return cout << 1 << "\n", void();
            s = t1;
        }
        cout << 2 << "\n";
    } else {
        for (int i = 0; i < n; ++ i){
            if (i == n/2) continue;
            st.insert(s[i]);
        }
        if (st.size() > 1) cout << 2 << "\n";
        else impo();
    }
}

