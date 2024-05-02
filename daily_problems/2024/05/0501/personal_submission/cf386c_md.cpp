// 0501
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string input;
    cin >> input;
    map<int, int> dict;
    for (auto ch : input) {
        dict[ch]++;
    }
    int d = size(dict);
    cout << d << endl;

    vector<i64> ret(d + 1, 0);
    
    auto atMostK = [&input](int k) -> i64 {
        array<int, 26> freq{};
        int start = 0;
        int n = size(input);
        int diff_num = 0;
        i64 ret = 0;
        for (int end = 0; end < n; ++end) {
            if (freq[input[end] - 'a'] == 0) {
                ++diff_num;
            }
            ++freq[input[end] - 'a'];

            while (diff_num > k) {
                if (freq[input[start] - 'a'] == 1) {
                    --diff_num;
                }
                freq[input[start++] - 'a']--;
            }

            ret += 1ll + end - start;
        }
        return ret;
    };

    for (int i = 1; i <= d; ++i) {
        ret[i] = atMostK(i) - atMostK(i - 1);
    }

    for (int i = 1; i <= d; ++i) {
        cout << ret[i] << "\n";
    }
    return 0;
}