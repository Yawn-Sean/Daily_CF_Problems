void solve(){
    string s, t;
    cin >> s >> t;
    
    string ans = s;
    int n = s.size();

    for (int i = n-1, cur = 1; i >= 0; -- i){
        int c = ans[i]-'a';
        if (c + cur == 26) ans[i] = 'a';
        else {
            ans[i] = char('a'+c+1);
            cur = 0;
            break;
        }
    }
    if (ans == t) cout << "No such string\n";
    else cout << ans << "\n";
}
