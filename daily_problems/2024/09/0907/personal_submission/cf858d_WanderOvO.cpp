/*
每个串总共可能有 55 种子字符串
我们考虑直接枚举所有串的所有子串，看这些子串在哪些字符串里面出现过
统计子串的出现次数，并记录子串出现在了哪个字符串中（只需要记录一个）
最后枚举所有子串，看该子串是否只出现在一个字符串中，是的话则更新一下答案
*/

int T;
int n;
string s[N], res[N];
map<string, int> cnt;
map<string, int> from;

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        unordered_set<string> substrs;
        for (int l = 0; l < 9; l++) {
            for (int r = l; r < 9; r++) {
                string substr = s[i].substr(l, r - l + 1);
                substrs.insert(substr);
            }
        }
        for (auto &str : substrs) {
            if (cnt.count(str)) {
                cnt[str]++;
            } else {
                cnt[str] = 1;
                from[str] = i;
            }
        }
    }
    for (auto &it : cnt) {
        if (it.y == 1) {
            int id = from[it.x];
            if (res[id].size() == 0) {
                res[id] = it.x;
            } else if (res[id].size() > it.x.size()) {
                res[id] = it.x;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << "\n";
    }
}    
