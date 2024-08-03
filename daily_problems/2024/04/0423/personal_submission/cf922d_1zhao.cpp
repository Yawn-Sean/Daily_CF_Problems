long long h(string &s) {
    int m = s.size();
    vector<int> S(m+1);

    for(int i=0; i<m; i++) {
        S[i+1] = S[i] + (s[i] == 's');
    }

    long long res = 0;
    for(int i=0; i<m; i++) {
        if(s[i] == 'h') {
            res += S[i];
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<string> vc(n);
    for(int i=0; i<n; i++) cin >> vc[i];

    sort(vc.begin(), vc.end(), [](string &a, string &b)->bool{
        string s1 = a+b;
        string s2 = b+a;
        return h(s1) > h(s2);
    });

    string s = "";
    for(string &a: vc) s+=a;

    cout << h(s) << endl;
}
