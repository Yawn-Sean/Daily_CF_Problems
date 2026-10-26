#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 110;
const int M = N * N;

int n,m;
int g[110][110];
vector<int> d[M];
int in[M];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool check(int i,int j){
    int res = 0;
    for(int k = 0;k < 4;k++){
        int x = i + dx[k],y = j + dy[k];
        if(x < 0 || x > n || y < 0 || y > m) continue; 
        if(g[x][y] == -1) res ++;
    }
    return res == 1;
}

void ask(int x,int y){
    cout << "? " << x << ' ' << y << '\n';
    cout.flush();
    char s;
    cin >> s;
    if(s == 'U') g[x][y] = 1;
    else if(s == 'D') g[x][y] = 2;
    else if(s == 'L') g[x][y] = 3;
    else g[x][y] = 4;
}

void answer(){
    cout << "!\n";
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(g[i][j] == 1) cout << 'U';
            else if(g[i][j] == 2) cout << 'D';
            else if(g[i][j] == 3) cout << 'L';
            else cout << 'R';
        }
        cout << '\n';
    }
}

int main(){
    cin >> n >> m;
    memset(g,0,sizeof g);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            g[i][j] = -1;
        }
    }
    int cnt = 0;
    for(int i = 2;i <= n;i += 2){
        for(int j = 2;j <= m;j+= 2){
            ask(i,j);
            if(g[i][j] == 1){
                g[i+1][j] = 2;
            }else if(g[i][j] == 2){
                g[i-1][j] = 1;
            }else if(g[i][j] == 3){
                g[i][j+1] = 4;
            }else{
                g[i][j-1] = 3; 
            }
            cnt += 2;
        }
    }
    queue<pair<int,int>> q;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(g[i][j] == -1){
                if(check(i,j)) q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto [sx,sy] = q.front();
        q.pop();
        if(g[sx][sy] != -1) continue;
        for(int i = 0;i < 4;i++){
            int x = sx + dx[i],y = sy + dy[i];
            if(x < 1 || x > n || y < 1 || y > m) continue;
            if(g[x][y] == -1){
                g[sx][sy] = i+1;
                if(g[sx][sy] == 1){
                    g[x][y] = 2;
                }else if(g[sx][sy] == 2){
                    g[x][y] = 1;
                }else if(g[sx][sy] == 3){
                    g[x][y] = 4;
                }else{
                    g[x][y] = 3;
                }
                for(int j = 0;j < 4;j++){
                    int tx = x + dx[j],ty = y + dy[j];
                    if(g[tx][ty] == -1){
                        if(check(tx,ty)) q.push({tx,ty});
                    }
                }
            }
        }
    }
    answer();
    return 0;
}