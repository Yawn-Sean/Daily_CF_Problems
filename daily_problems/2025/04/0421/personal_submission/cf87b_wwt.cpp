#include <iostream>
#include <map>
#include <string>

using namespace std;

// 解析变量类型并计算偏移量，同时获取原始类型
pair<int, string> parseType(const string& t) {
    int l = 0, r = t.size() - 1;
    int offset = 0;

    while (l < t.size() && t[l] == '&') {
        ++l;
        --offset;
    }

    while (r >= 0 && t[r] == '*') {
        --r;
        ++offset;
    }

    string orig = t.substr(l, r - l + 1);
    return { offset, orig };
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    map<string, int> typeMap;
    typeMap["void"] = 0;
    typeMap["errtype"] = -100000;

    for (int i = 0; i < n; ++i) {
        string op;
        cin >> op;

        if (op[4] == 'd') {
            string t1, t2;
            cin >> t1 >> t2;
            pair<int, string> result = parseType(t1);
            int offset = result.first;
            string orig = result.second;
            if (typeMap.find(orig) == typeMap.end()) {
                typeMap[orig] = -100000;
            }
            int newVal = typeMap[orig] + offset;
            typeMap[t2] = (newVal >= 0 ? newVal : -100000);
        }
        else {
            string t;
            cin >> t;
            pair<int, string> result = parseType(t);
            int offset = result.first;
            string orig = result.second;
            auto it = typeMap.find(orig);
            if (it == typeMap.end() || it->second + offset < 0) {
                cout << "errtype" << endl;
            }
            else {
                cout << "void" << string(it->second + offset, '*') << endl;
            }
        }
    }

    return 0;
}
