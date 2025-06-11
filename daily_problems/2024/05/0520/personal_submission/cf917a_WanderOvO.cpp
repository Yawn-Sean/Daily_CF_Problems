int T;
string s;

void solve1() {
    cin >> s;
    int n = s.size();
    s = " " + s;
    LL res = 0;
    for (int l = 1; l <= n; l++) {
        int sum = 0, cnt_question = 0;
        for (int r = l; r <= n; r++) {
            if (s[r] == '(') {
                sum++;
            } else if (s[r] == ')') {
                sum--;
            } else {
                cnt_question++;
                sum--;
            }
            if (sum < 0) {
                if (cnt_question == 0) {
                    break;
                }
                cnt_question--;
                sum += 2;
            }
            if (sum == 0) {
                res++;
            }
        }
    }
    cout << res << "\n";
}                                                                                                                  
