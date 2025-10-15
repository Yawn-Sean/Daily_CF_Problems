#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector <int> cnt(62);
    auto norm = [&](char c)->int{
        if (islower(c)) return int(c-'a');
        else if (isupper(c)) return 26 + int(c-'A');
        else return 52 + int(c-'0');
    };
    auto back = [&](int i)->char{
        if (i < 26) return char(i+'a');
        else if (i < 52) return char(i-26+'A');
        else return char(i-52+'0');
    };

    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto &ch : s){
        cnt[norm(ch)] += 1;
    }
    int c1 = 0;  // 有奇数个的字符集
    for (int i = 0; i < 62; ++ i){
        if (cnt[i] == 0) continue;
        c1 += cnt[i]%2;
    }

    auto chk = [&](int L1)->bool{
        int L2 = n/L1;  // L1:个数  L2:长度
        if (L2%2){  // 长度是奇数需要确定 回文中心
            return (L1 >= c1) && ((L1-c1)%2 == 0);
        } else {
            return c1 == 0;
        }
    };

    int L = n;
    for (int i = 1; i <= n/i; ++ i){
        if (n%i == 0){
            if (i < L && chk(i)) L = i;
            if (n/i < L && chk(n/i)) L = n/i;
        }
    }

    vector <string> ans;
    int len = n/L;  // L 是个数， len是长度
    
    if (len%2){
        vector <int> link; // link 是回文中心是哪些字符
        for (int i = 0; i < 62; ++ i){
            if (cnt[i]%2){
                cnt[i] -= 1;
                link.push_back(i);
            }
        }
        assert((L-link.size())%2 == 0);
        for (int i = 0; i < 62; ++ i){
            while (link.size() < L && cnt[i]){
                assert(cnt[i]%2 == 0);
                cnt[i] -= 2;
                link.push_back(i), link.push_back(i);
            }
        }

        assert(link.size() == L);
        int half_len = len/2;
        int i = 0;
        for (auto &center : link){
            string lr_link;
            int sz = 0;
            while (sz < half_len){
                assert(i < 62);
                while (cnt[i]){
                    cnt[i] -= 2;
                    lr_link += back(i), sz += 1;
                    if (sz == half_len) break;
                }
                if (cnt[i] == 0) i += 1;
            }
            assert(sz == half_len);
            string res = lr_link;
            res += back(center);
            reverse(lr_link.begin(), lr_link.end());
            res += lr_link;
            assert(res.size() == len);
            ans.push_back(res);
        }
    } else {
        int j = 0;  // j是当前遍历的 字符
        int half_len = len/2;
        for (int i = 0; i < L; ++ i){
            string lr_link;
            int sz = 0;
            while (sz < half_len){
                assert(j < 62);
                while (cnt[j]){
                    cnt[j] -= 2;
                    lr_link += back(j), sz += 1;
                    if (sz == half_len) break;
                }
                if (cnt[j] == 0) j += 1;
            }
            assert(sz == half_len);
            string res = lr_link;
            reverse(lr_link.begin(), lr_link.end());
            res += lr_link;
            assert(res.size() == len);
            ans.push_back(res);
        }
    }

    assert(ans.size() == L);
    cout << ans.size() << "\n";
    for (int i = 0; i < L; ++ i){
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
