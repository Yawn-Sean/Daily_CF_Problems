# https://codeforces.com/contest/1510/submission/307109229
# 这一题是学习的luogu的题解代码

package main

import (
    "bufio"
    . "fmt"
    "io"
    "math"
    "os"
)

type Pair struct {
    first, second int
}

const (
    N    = 1e5 + 5
    M    = 1e3 + 5
    Ox3f = 1061109567
    INF  = 2147483647
    Lx3f = 4557430888798830399
    LNF  = 9223372036854775807
    MOD  = 1e9 + 7
)

var (
    n, m, cnt int
    a         [N]int
    s         [N]int
    lst       [N][10]Pair
    dp        [N][10]float64
)

func slove(_r io.Reader, _w io.Writer) {
    in := bufio.NewReader(_r)
    out := bufio.NewWriter(_w)
    defer out.Flush()
    Fscan(in, &n, &m)
    for i := 1; i <= n; i++ {
        Fscan(in, &a[i])
    }

    for i := 1; i <= n; i++ {
        dp[i][a[i]%10] = math.Log2(float64(a[i]))
        for j := 0; j <= 9; j++ {
            if dp[i-1][j] != 0 && dp[i-1][j]+math.Log2(float64(a[i])) > dp[i][(j*a[i])%10] {
                dp[i][(j*a[i])%10] = dp[i-1][j] + math.Log2(float64(a[i]))
                lst[i][(j*a[i])%10] = Pair{i - 1, j}
            }
            if dp[i-1][j] > dp[i][j] {
                dp[i][j] = dp[i-1][j]
                lst[i][j] = Pair{i - 1, j}
            }
        }
    }

    var dfs func(i, j int)
    dfs = func(x, y int) {
        xx, yy := lst[x][y].first, lst[x][y].second
        if dp[x][y] != dp[xx][yy] || a[x]%10 == 1 {
            cnt++
            s[cnt] = a[x]
        }
        if xx == 0 && yy == 0 {
            return
        }
        dfs(xx, yy)
    }

    if dp[n][m] == 0 {
        Fprintln(out, -1)
        return
    }

    dfs(n, m)
    Fprintln(out, cnt)
    for i := 1; i <= cnt; i++ {
        Fprintf(out, "%d ", s[i])
    }
}

func main() { slove(os.Stdin, os.Stdout) }
