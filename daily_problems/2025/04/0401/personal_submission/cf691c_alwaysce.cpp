#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;


    int n = s.size();
    int i = 0;

    vector<char> int_part, frac_part;
    while (i < n && s[i] == '0') {
        i++;
    }
    
    while (i < n && s[i] != '.') {
        int_part.push_back(s[i]);
        i++;
    }
    
    bool flag = false;
    if (i < n && s[i] == '.') {
        flag = true;// 存在小数部分

        int j = i + 1;
        bool has_non_zero = false;
        while (j < n) {
            if (s[j] != '0') {
                has_non_zero = true;

            }
            j++;
        }

        if (!has_non_zero) {
            flag = false; // 小数部分全是0
        } else {
            j = i + 1;
            while (j < n) {
                frac_part.push_back(s[j]);
                j++;
            }
            // 去掉小数部分末尾的0
            while (frac_part.size() > 0 && frac_part.back() == '0') {
                frac_part.pop_back();
            }
        }
    }

    int exp = 0;
    if (int_part.size() > 0) {
        exp = int_part.size() - 1;
        cout << int_part[0];
        
        // 存在笑鼠部分
        if (flag) {
            cout << '.';
            for (int j = 1; j < int_part.size(); j++) {
                cout << int_part[j];
            }

            for (int j = 0; j < frac_part.size(); j++) {
                cout << frac_part[j];
            }    
        } else {
            // 没有小数部分
            while (int_part.size() > 0 && int_part.back() == '0') {
                int_part.pop_back();
            }

            // 去0之后还有数字
            if (int_part.size() > 1) {
                cout << '.';
            }
            for (int j = 1; j < int_part.size(); j++) {
                cout << int_part[j];
            }
        }

        if (exp > 0) {
            cout << "E" << exp;
        }
        cout << "\n";
    } else if (flag && frac_part.size() > 0) {
        // .000001345566
        // 0.1234 -> 1.234E-1
        int j = 0;
        while (j < frac_part.size() && frac_part[j] == '0') {
            j++;
            exp--;
        }
        
        if (j < frac_part.size()) {
            cout << frac_part[j];
            j++;
            exp--;
            if (j < frac_part.size()) {
                cout << '.';
            }
            while (j < frac_part.size()) {
                cout << frac_part[j];
                j++;
            }
            cout << "E" << exp;
        }
        cout << "\n";
    } else {
        cout << "0\n";
        return 0;
    }
    
    return 0;
}
