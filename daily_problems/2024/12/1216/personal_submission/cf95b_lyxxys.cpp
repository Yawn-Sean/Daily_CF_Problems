#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    auto create = [&](int len, char c1, char c2)->string{
        string s1(len, c1), s2(len, c2);
        return s1+s2;
    };
    auto legal = [&](char c)->bool{
        return c == '4' || c == '7';
    };
    int c4 = 0, c7 = 0;
    auto chge = [&](char ch, int v)->void{
        if (ch == '4') c4 += v;
        if (ch == '7') c7 += v;
    };

    string s;
    cin >> s;
    int n = s.size();
    string res;
    if (n%2){
        res = create((n+1)/2, '4', '7');
    } else {
        string t1 = create(n/2, '4', '7'), t2 = create(n/2, '7', '4');

        if (s <= t1){
            res = t1;
        } else if (s > t2){
            res = create(n/2+1, '4', '7');
        } else {
            int tar = n/2;

            for (int i = 0; i < n; ++ i){
                char ch = s[i];
                bool jg = 0;
                if (legal(ch)){
                    if (ch == '4'){
                        if (c4 < tar){
                            chge(ch, 1);
                            res += '4';
                        } else {
                            assert(c7 < tar);
                            break;
                        }
                    } else {
                        if (c7 < tar){
                            chge(ch, 1);
                            res += '7';
                        } else {
                            jg = 1;
                        }
                    }
                } else {
                    if (ch < '4' && c4 < tar){
                        chge('4', 1);
                        res += '4';
                        break;
                    }
                    if (ch < '7' && c7 < tar){
                        chge('7', 1);
                        res += '7';
                        break;
                    }
                    jg = 1;
                }
                if (jg){
                    while (res.size()){
                        char ch = res.back();
                        res.pop_back();
                        chge(ch, -1);
                        if (ch == '4' && c7 < tar){
                            res += '7';
                            chge('7', 1);
                            break;
                        }
                    }
                    break;
                }
            }

            while (res.size() < n){
                if (c4 < tar) res += '4', c4 += 1;
                else res += '7', c7 += 1;
            }
            assert(res.size() == n);
            assert(c4 == tar && c7 == tar);
        }
    }

    cout << res << "\n";
}
