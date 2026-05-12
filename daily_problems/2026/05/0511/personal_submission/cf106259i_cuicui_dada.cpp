#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        vector<int>st;
        for (int x:a) {
            st.push_back(x);
            while (st.size()>=3) {
                int m=st.size();
                if (st[m-2]>st[m-3]&&st[m-2]>st[m-1]) {
                    st.erase(st.begin()+m-2);
                }
                else break;
            }
        }
        if (st.size()==2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}