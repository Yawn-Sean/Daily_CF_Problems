/*
我们其实关心的是，连续一段 ? 中，我们能猜出来多少地方

A?A，完全确定不了，猜不对
A?B，只能是 C，能猜对 1 个

A??A
 BC
 CB
最差能猜对 1 个
A??B
 BA
 BC
 CA
如果我填 BA，就至少能对一个

A???A
 BAB
 BAC
 BCB
 CAB
 CAC
 CBC
如果填 BAC 的话，至少能对一个
A???B
 BAC
 BCA
 CAC
 CBA
 CBC
至少有一个 C，所以都猜 C 就好了

A????A
 BABC
 BACB
 BCAB
 BCAC
 CABC
 CACB
 CBAB
 CBAC
 CBCB
全猜 C


A????B
 BABA
 BABC
 BACA
 BCAC
 BCBA
 BCBC
 CABA
 CABC
 CACA
 CBAC
 CBCA
也是至少能猜对 1 个，比如 BAAA

至此，我们似乎可以猜结论了
对于连续的 >= 2 个 ?，至少能猜对 1 个
如果只有一个 ?，则两边不同时能确定，否则确定不了
但还有两种情况悬而未决
只有一边有限制，另一边顶到头时，会怎样，以及两边都顶到头了会怎样
??
AB
AC
BA
BC
CA
CB

???
ABA
ABC
ACA
ACB
BAB
BAC
BCA
BCB
CAB
CAC
CBA
CBC
好像也是确定不了
只有一边顶到头时
A?，确定不了
A??
BA
BC
CA
CB
也确定不了
*/

int n;
string s;

void solve() {
    cin >> n >> s;
    s = " " + s;
    bool all_question = true;
    for (int i = 1; i <= n; i++) {
        if (s[i] != '?') {
            all_question = false;
        }
    }
    if (all_question) {
        cout << "0\n";
        return;
    }
    
    int res = 0;
    for (int i = 1; i <= n; ) {
        if (s[i] == '?') {
            int j = i;
            while (j <= n && s[j] == '?') {
                j++;
            }
            if (j <= n) {
                int len = j - i;
                if (len == 1) {
                    if (i - 1 != 0) {
                        if (s[i - 1] != s[j]) {
                            res++;
                        }
                    }
                } else {
                    if (i - 1 != 0) {
                        res++;
                    }
                }
            }
            i = j;
        } else {
            res++;
            i++;
        }
    }
    cout << res << "\n";
}
