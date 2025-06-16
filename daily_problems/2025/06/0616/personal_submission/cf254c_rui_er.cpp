ifstream fin("input.txt");
ofstream fout("output.txt");

#define cin fin
#define cout fout

const int N = 1e5 + 5;

string s, t;
int cntS[26], cntT[26], n;
stack<int> stk;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> t;
    n = s.size();
    for(char c: s) ++cntS[c - 'A'];
    for(char c: t) ++cntT[c - 'A'];
    per(i, 25, 0) rep(j, cntS[i] + 1, cntT[i]) stk.push(i);
    cout << stk.size() << endl;
    rep(i, 0, n - 1) {
        int k = s[i] - 'A';
        if(cntS[k] > cntT[k] && (stk.top() < k || !cntT[k])) {
            cout << char(stk.top() + 'A');
            --cntS[k];
            --cntT[stk.top()];
            stk.pop();
        }
        else {
            cout << s[i];
            --cntS[k];
            --cntT[k];
        }
    }
    cout << endl;
    return 0;
}
