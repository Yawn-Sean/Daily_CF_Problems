using namespace std;
const int N = 55;
char g[N][N];
int a, b, c, d;

void draw(int x, int y, int size, char ch){
    for (int i = x; i <= x+size-1; ++ i)
        for (int j = y; j <= y+size-1; ++ j)
            g[i][j] = ch;
}
void print(){
    for (int i = 1; i <= 50; ++ i){
        for (int j = 1; j <= 50; ++ j) cout << g[i][j];
        cout << "\n";
    }
}
void doting(int x, int y, int size, int cnt, char ch){
    if (!cnt) return;
    for (int i = x; i <= x+size-1; i += 2)  //隔两个再造一个ch
        for (int j = y, k = i%2; j <= y+size-1; ++ j, ++ k){
            if (!(k%2)) g[i][j] = ch, -- cnt;
            if (!cnt) return;
        }
}

void solve(){
    cin >> a >> b >> c >> d;
    int len = 25;
    draw(1, 1, len, 'A'), draw(1, 26, len, 'B');
    draw(26, 1, len, 'C'), draw(26, 26, len, 'D');

    doting(1, 1, len, d-1, 'D'), doting(1, 26, len, c-1, 'C');
    doting(26, 1, len, b-1, 'B'), doting(26, 26, len, a-1, 'A');
    cout << 50 << " " << 50 << "\n";
    print();
}
