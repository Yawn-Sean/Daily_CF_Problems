//https://codeforces.com/contest/1029/submission/258176036
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i] >> b[i];
    vector<int> aa(a.begin(), a.end());
    vector<int>bb(b.begin(), b.end());
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    int ret = 0;
    int max_a = aa.back(), min_b = bb[0];
    int second_max_a = aa[n-2], second_min_b = bb[1];
    int this_ret;
    for (int i = 0; i < n; ++i){
        int l = a[i], r = b[i];
        this_ret =  (r == min_b ? second_min_b: min_b) - (l == max_a ? second_max_a: max_a); 
        ret =max(ret, this_ret);
    }
    cout << ret << endl;
    return 0;
}
