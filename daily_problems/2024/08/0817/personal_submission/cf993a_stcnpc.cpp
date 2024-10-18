//https://codeforces.com/problemset/problem/993/A
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<vector<int>> r1(4,vector<int>(2));
    auto r2(r1);
    int h[4];
    for(int i=0;i<8;i++) cin>>r1[i/2][i%2];
    for(int i=0;i<8;i++) cin>>r2[i/2][i%2];
    h[0]=min({r1[0][0],r1[1][0],r1[2][0],r1[3][0]});
    h[1]=max({r1[0][0],r1[1][0],r1[2][0],r1[3][0]});
    h[2]=min({r1[0][1],r1[1][1],r1[2][1],r1[3][1]});
    h[3]=max({r1[0][1],r1[1][1],r1[2][1],r1[3][1]});

    //Two possible conditions: 
    //a)the integer points on the edges of r2 lie within the range of r1.
    //b)r2 completely cover r1
    int quad[4]{0}; // possible cond 2:
    int cor[5]{0,1,2,3,0};
    for(int i=0;i<4;i++){
        int ax=r2[cor[i]][0],bx=r2[cor[i+1]][0];
        int ay=r2[cor[i]][1],by=r2[cor[i+1]][1];
        int incx=ax>bx?-1:1;
        int incy=ay>by?-1:1;
        int cnt=abs(bx-ax)+1;
        for(int j=0;j<cnt;j++,ax+=incx,ay+=incy){
            if(ax>=h[0]&&ax<=h[1]&&ay>=h[2]&&ay<=h[3]){
                cout<<"YES"<<endl;
                return; 
            }
            //Check whether all four quadrants defined by r2 contain the edges of r1.
            if(ax<=h[0] && ay<=h[2]) quad[0]=1;
            if(ax>=h[0] && ay>=h[2]) quad[1]=1;
            if(ax<=h[0] && ay>=h[2]) quad[2]=1;
            if(ax>=h[0] && ay<=h[2]) quad[3]=1;
            // printf("%d %d |[%d %d] [%d %d] || ",ax,ay,h[0],h[1],h[2],h[3]);
            // for(auto &q:quad) cout<<q<<" ";cout<<endl;
        }
        // cout<<"-------------"<<endl;
    }
    if(accumulate(begin(quad),end(quad),0)==4) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}
