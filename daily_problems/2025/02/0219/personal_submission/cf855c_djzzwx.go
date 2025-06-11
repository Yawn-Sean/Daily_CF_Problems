# https://codeforces.com/contest/855/submission/306883554

package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

const inf int = 0x3f3f3f3f
const mod int = 1e9 + 7

func slove(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, m, k, x, u, v int
	Fscan(in, &n, &m)
	g := make([][]int, n)
	for i := 0; i < n-1; i++ {
		Fscan(in, &u, &v)
		u--
		v--
		g[v] = append(g[v], u)
		g[u] = append(g[u], v)
	}
	Fscan(in, &k, &x)
	sz := make([]int, n)
	var szDfs func(i, fa int) int
	szDfs = func(i, fa int) int {
		sz[i] = 1
		for _, to := range g[i] {
			if to != fa {
				sz[i] += szDfs(to, i)
			}
		}
		return sz[i]
	}
	szDfs(0, -1)
	dp := make([][11][3]int, n)
	tmp := [11][3]int{}
	const mod int = 1e9 + 7
	var dfs func(i, fa int) int
	dfs = func(i, fa int) (res int) {
		dp[i][0][0] = k - 1
		dp[i][1][1] = 1
		dp[i][0][2] = m - k
		for _, to := range g[i] {
			if to == fa {
				continue
			}
			dfs(to, i)
			for j, row := range dp[i] {
				for k2, v := range row {
					tmp[j][k2] = v
					dp[i][j][k2] = 0
				}
			}
			for j := min(sz[i], x); j >= 0; j-- {
				for k2 := range min(sz[to], j) + 1 {
					dp[i][j][0] = (dp[i][j][0] + tmp[j-k2][0]*(dp[to][k2][0]+dp[to][k2][1]+dp[to][k2][2])%mod) % mod
					dp[i][j][1] = (dp[i][j][1] + tmp[j-k2][1]*(dp[to][k2][0])%mod) % mod
					dp[i][j][2] = (dp[i][j][2] + tmp[j-k2][2]*(dp[to][k2][0]+dp[to][k2][2])%mod) % mod
				}
			}
		}
		return res
	}
	dfs(0, -1)
	ans := 0
	for i := 0; i <= x; i++ {
		for j := 0; j < 3; j++ {
			ans += dp[0][i][j]
			ans %= mod
		}
	}
	Fprintln(out, ans)
}

func main() { slove(os.Stdin, os.Stdout) }

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

//func max(a, b int) int {
//	if a > b {
//		return a
//	}
//	return b
//}
//
//func min(a, b int) int {
//	if a < b {
//		return a
//	}
//	return b
//}
