#include <iostream>
using namespace std;

const int N = 5010;
const int M = N*N;

int a[M];
int C[N],R[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    string s;
    int ans = 0;
    for(int i = 0;i < n;i++){
        cin >> s;
        for(int j = 0;j < n;j++){
            if(s[j] == '1'){
                a[j+i*n] = 1;
            }else{
                a[j+i*n] = 0;
            }
            C[i+1] += a[j+i*n];
            R[j+1] += a[j+i*n];
            if(i == n-1){
                if(R[j+1] == n) ans ++;
            }
        }
        if(C[i+1] == n) ans ++;
    }
    int head = 0;                                            
    int op;
    int x,y,b;
    int L = n * n;
    while(q --){
        cin >> op;
        if(op == 1){
            cin >> x >> y >> b;
            int id = (head+(x-1)*n+(y-1))%L;
            int res1 = C[x],res2 = R[y];
            C[x] += b-a[id];
            R[y] += b-a[id];
            if(res1 == n && C[x] == n-1){
                ans --;
            }
            if(res1 == n-1 && C[x] == n){
                ans ++;
            }
            if(res2 == n && R[y] == n-1){
                ans --;
            }
            if(res2 == n-1 && R[y] == n){
                ans ++;
            }
            a[id] = b;
        }else{
            cin >> b;
            int id = (head + n - 1) % L;
            ans = 0;
            C[1] += b - a[id];
            if(C[1] == n) ans ++; 
            for(int i = 2;i <= n;i++){
                int id1 = (head + (i-1) * n - 1) % L;
                int id2 = (head + i * n - 1) % L;
                C[i] += a[id1] - a[id2];
                if(C[i] == n) ans ++;
            }
            id = (head + n*n - 1) % L;
            int first = R[n] - a[id] + b;
            if(first == n) ans ++;
            for(int i = n;i >= 2;i--){
                R[i] = R[i-1];
                if(R[i] == n) ans ++;
            }
            R[1] = first;
            head = (head-1+L) % L;
            a[head] = b;
        }
        cout << ans << '\n';
    }
    return 0;
}