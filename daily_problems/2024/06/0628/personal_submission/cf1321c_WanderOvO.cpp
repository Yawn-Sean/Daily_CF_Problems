/*
删除顺序是有影响的
a 没有前驱，所以 a 肯定删除不了
从 z 开始删？
z 现在删除不了，则后面还有删的可能性吗？
z...y，需要把 ... 删完，但显然删不完，所以没有希望被删除了
所以只需要从 z 开始删即可
*/

int T;
int n;
string s, next_s;

void solve1() {
    cin >> n >> s;
    int cnt = n;
    for (char ch = 'y'; ch >= 'a'; ch--) {
        set<int> deleted;
        for (int i = 0; i < cnt; i++) {
            if (s[i] == ch) {
                for (int j = i - 1; j >= 0; j--) {
                    if (s[j] == ch + 1) {
                        deleted.insert(j);
                    } else {
                        break;
                    }
                }
                for (int j = i + 1; j < cnt; j++) {
                    if (s[j] == ch + 1) {
                        deleted.insert(j);
                    } else {
                        break;
                    }
                }
            }
        }
        next_s = "";
        for (int i = 0; i < cnt; i++) {
            if (!deleted.count(i)) {
                next_s += s[i];
            }
        }
        s = next_s;
        cnt = s.size();
        // cout << s << "\n";
    }
    cout << n - next_s.size() << "\n";
}                                                                                                                  