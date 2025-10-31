#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,x=0;
        cin>>n;
        while(n--){
            string s;
            cin>>s;
            string b=s[3]=='='&&s[4]=='='&&s[5]=='='?s.substr(0,3):s.substr(3,3);
            if(b=="xxx") x^=2;
            else if(b=="xx."||b==".xx") x^=1;
        }
        cout<<(x?"Monocarp\n":"Polycarp\n");
    }
    return 0;
}
