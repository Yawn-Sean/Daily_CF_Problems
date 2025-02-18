#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TIME_LIMIT (time_t)1e3
#define dbg(x) cerr<<#x<<": "<<x<<endl;
bool block[100][100];
signed main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    time_t cs = clock();
#endif
//========================================
    int n,k;
    cin>>n>>k;
    cout<<"YES"<<endl;
    if(!(k&1)){
        for(int i=2;i<=1+k/2;i++){
            block[2][i] = 1;
            block[3][i] = 1;
        }
    }
    else{
        int row = 2;
        while(k>(n-2)){
            for(int i=2;i<=n-1;i++)
                block[row][i] = 1;
            k-=n-2;
            row++;
        }
        int space = n-2-k;
        for(int i=2;i<=1+k/2;i++)
            block[row][i] = 1;
        if(k&1){
            int center = n/2+1;
            block[row][center] = 1;
        }
        for(int i=2+k/2+space+(k&1);i<=n-1;i++)
            block[row][i] = 1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=n;j++){
            if(block[i][j])
                cout<<'#';
            else
                cout<<'.';
        }
        cout<<'\n';
    }
    cout<<endl;
//========================================
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
    time_t ce = clock();
    cerr<< "Used Time: " << ce-cs << " ms."<<endl;
    if(TIME_LIMIT<ce-cs)
        cerr<< "Warning!! Time exceeded limit!!"<<endl;
#endif
    return 0;
}
