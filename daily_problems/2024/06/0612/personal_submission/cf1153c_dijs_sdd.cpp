#include<cmath>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int MAXN=2e5+50;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string str;
    cin>>n;
    cin>>str;
    int cnt=n/2;
    for(int i=0;i<n;i++)
        if(str[i]=='(')
            cnt--;
    int cur=0;
    for(int i=0;i<n;i++){
        if(str[i]=='('){
            cur++;
        }else if(str[i]==')'){
            cur--;
        }else if(cnt){
            str[i]='(';cur++;cnt--;
        }else{
            str[i]=')';cur--;
        }
        if(cur<=0&&i!=n-1){
            cout<<":("<<endl;
            return 0;
        }
    }
    cout<<(cur==0?str:":(")<<endl;
    return 0;
}
