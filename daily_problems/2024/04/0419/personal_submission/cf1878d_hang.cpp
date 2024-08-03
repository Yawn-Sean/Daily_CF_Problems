#include<bits/stdc++.h>
# define MULTI
// # define INIT
using namespace std;
# define endl "\n"
# define space " "
# define LL long long
# define PII pair<int, int>
const int N = 2e5+10;

void slove(){
    int n, k, q;
    string s;
    cin >> n >> k;
    cin >> s;
    vector<int> l(k, 0), r(k, 0);
    for(int i=0; i<k; ++i)  cin >> l[i];
    for(int i=0; i<k; ++i)  cin >> r[i];
    cin >> q;
    vector<int> qs(q, 0);
    vector<int> p(n+2, 0);
    for(int i=0; i<q; ++i){
        cin >> qs[i];
        int tl = 0, tr = k-1;
        while(tl < tr){
            int m = (tl + tr + 1) >> 1;
            if(l[m] > qs[i]){
                tr = m - 1;
            }else{
                tl = m;
            }
        }
        int mn = min(l[tl] + r[tl] - qs[i], qs[i]);
        int mx = max(l[tl] + r[tl] - qs[i], qs[i]);
        p[mn] += 1;
        p[mx+1] -= 1;
    }  
    vector<char> cs(n,0);
    for(int i=0; i<k; ++i){
        int tl = l[i], tr = r[i];
        for(int j=tl; j<=tr;++j)    p[j] += p[j-1];
        while(tl <= tr){
            if(p[tl] & 1){
                cs[tl-1] = s[tr-1];
                cs[tr-1] = s[tl-1];
            }else{
                cs[tl-1] = s[tl-1];
                cs[tr-1] = s[tr-1];
            }
            ++tl,--tr;
        }
    }
    string ans = "";
    for(int i=0; i<n; ++i){
        ans += cs[i];
    }
    cout << ans << endl;

}
void init(){}
int main()
{
    # ifdef INIT
    init();
    # endif

    int cas = 1;
    # ifdef MULTI
    cin >> cas;
    # endif

    while (cas--)
    {
        slove();
    }
    
}


