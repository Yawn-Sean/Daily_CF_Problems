/*
n = 1, a
n = 2, ab
n = 3, aba
n = 4, abac
n = 5, abaca
n = 6, abacab
n = 7, abacaba
n = 8, abacabad
abacabadabacabae
长度为 n 的符合题意的串，其前 n - 1 个字符组成的串一定也符合题意
由于字典序贪心的性质，所以长度为 n 的字典序最小的串，其前 n - 1 个字符一定也得是字典序最小的串
似乎可以类似倍增的方式
初始化为 a，假设当前长度为 n，则复制一遍 n - 1 长度的串，然后加一个新的从来没出现过的字符
2^25 > 4e6，完全够了
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> res = {0};
    int length = 1;
    int idx = 1;
    
    while (length * 2 <= n) {
        int current_size = res.size();
        for (int i = 0; i < current_size - 1; ++i) {
            res.push_back(res[i]);
        }
        res.push_back(idx);
        idx++;
        length *= 2;
    }
    
    if (length < n) {
        for (int i = 0; i < length; ++i) {
            res.push_back(res[i]);
            length++;
            if (length >= n) break;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << char(res[i] + 'a');
    }
    cout << endl;
    
    return 0;
}
