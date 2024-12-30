// 0515
#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using pii = std::pair<int, int>;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n;
    std::cin >> n;
    string last = "";
    vector<string> outputs;
    for (int i = 0; i < n; ++i) {
        string num;
        cin >> num;
        const int siz_num = ssize(num);
        const int siz_last = ssize(last);
        if (siz_num < siz_last) {
            std::cout << "NO" << endl;
            return 0;
        } else if (siz_num == siz_last) {
            bool larger = false;
            int start_idx = siz_num;
            for (int d = 0; d < siz_num; ++d) {
                if (num[d] == '?' || num[d] == last[d]) {
                    continue;
                }
 
                larger = num[d] > last[d];
                start_idx = d;
                break;
            }

            for (int d = start_idx + 1; d < siz_num; ++d) {
                if (num[d] == '?') {
                    num[d] = '0';
                }
            }
 
            for (int d = start_idx - 1; d >= 0; --d) {
                if (num[d] != '?') {
                    continue;
                }
 
                if (larger) {
                    num[d] = last[d];
                } else {
                    if (last[d] == '9') {
                        num[d] = '0';
                    } else {
                        num[d] = last[d] + 1;
                        larger = true;
                    }
                }
            }
            
            if (!larger) {
                std::cout << "NO" << endl;
                return 0;
            }
        } else {
            for (int d = 0; d < siz_num; ++d) {
                if (num[d] == '?') {
                    num[d] = ((d == 0) ? '1' : '0');
                }
            }
        }
        last = num;
        outputs.emplace_back(std::move(num));
    }
 
    std::cout << "YES\n";
    for (const auto& num : outputs) {
        std::cout << num << endl;
    }
 
    return 0;
}