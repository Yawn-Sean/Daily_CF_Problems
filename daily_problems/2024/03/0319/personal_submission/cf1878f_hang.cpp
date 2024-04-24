#include<bits/stdc++.h>
# define MULTI
//# define INIT
using namespace std;
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie

/**
 * 题目: F. Vasilije Loves Number Theory
 * 链接: https://codeforces.com/contest/1878/problem/F
 * 思路: 首先根据题意 gcd(a, n) = 1 说明a和n没有相同的质因子, 其次d(a * n) = n 结合前面的条件说明 n % d(n) = 0
 * 假设a的因子的个数为a_num个 n的因子个数为n_num个，同时gcd(a, n) = 1说明 a的因子与n的因子交集为空集
 * 那么a*n的因子个数为a_num * n_num 个所以 d(a*n) % d(n) = 0 才能保证存在a使得gcd(a, n) = 1并且d(a * n) = n
 * 
 * 注意d(n) <= 1e9 那么n可能非常大！！不可以直接n = x * n 应该计算质因子个数然后计算因子个数，质因子个数的计算是可以分开进行的
 * 总体时间复杂度 q * sqrt(max(x)) * log(c)   其中 x <= 1e6  log(c)指的是从哈希表存取数据时间
*/

void slove(){
    LL n, q, op, x;
    cin >> n >> q;
    unordered_map<int,int> cnt_s; // 存储质因子以及个数
    vector<LL> qs; // 存储每次相乘的x
    qs.push_back(n);
    // cur = qs[0] * qs[2] * ... * qs[i]   qs[i]=p
    // 计算添加p后cur得因子个数
    auto f = [&](LL p)->LL{
        for(LL i=2; i*i <= p; ++i){
            while(p % i == 0){
                cnt_s[i]++;
                p /= i;
            }
        }
        if(p != 1){
            cnt_s[p]++;
        }
        // 1也是因子
        LL res = 1;
        for(auto it : cnt_s){
            res = res + res * it.second;
        }
        return res;
    };
    // 首先计算一下cur = n时
    f(n);
    while(q--){
        cin >> op;
        if(op == 1){
            cin >> x;
            qs.push_back(x);
            LL tot = f(x);
            // 取模性质
            LL b = 1;
            for(LL t : qs){
                b = b * t % tot;
            }
            // 只有模为0 才可能gcd(a,cur) = 1    d(cur*a) = n
            if(b == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }

        }else{
            // 恢复状态
            qs.clear();
            qs.push_back(n);
            cnt_s.clear();
            f(n);
        }
    }


}

# ifdef INIT
void init(){
  
}
# endif

int main()
{
    # ifdef INIT
    init();
    # endif

    int cas = 1;
    # ifdef MULTI
    cin >> cas;
    # endif

    while (cas--){
        slove();
    }
    
}

 