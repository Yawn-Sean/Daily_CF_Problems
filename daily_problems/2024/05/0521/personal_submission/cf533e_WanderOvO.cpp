/*
reaad
eaad
read
raad
reaa
s 和 t 应该至少有 n - 1 个字符是一样的
感觉答案只能是 0，1，2
如果 s 和 t 仅在一个位置不一样，那么有 2 个 w

我们考虑从 w 的基础上删除 1 个字符，但是采用两种方式，分别删除 l 和 r 位置上的字符，l < r
则 s = w[0 : i - 1] + w[i + 1 : n - 1], t = w[0 : j - 1] + w[j + 1 : n - 1]
更加细分一下
s = w[0 : l - 1] + w[l + 1 : r] + w[r + 1 : n - 1] 
t = w[0 : l - 1] + w[l : r - 1] + w[r + 1 : n - 1]
比较一下中间的地方，是否平移一下后能相等即可

*/

int T;
int n;
string s, t;

void solve1() {
    cin >> n >> s >> t;
    
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            r = i;
            if (l == -1) {
                l = i;
            }
        } 
    }
    
    int same1 = 1, same2 = 1;
    for (int i = l; i < r; i++) {
        if (s[i] != t[i + 1]) {
            same1 = 0;
        }
    }
    for (int i = l + 1; i <= r; i++) {
        if (s[i] != t[i - 1]) {
            same2 = 0;
        }
    }
    cout << same1 + same2 << "\n";
}                      