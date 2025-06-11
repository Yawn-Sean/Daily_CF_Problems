package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

// 计算前缀函数
// pi[i] 为 s[:i] 的真前缀和真后缀的最长匹配长度
func calcPi(s string) []int {
	pi := make([]int, len(s)+1)
	match := 0
	for i := 1; i < len(s); i++ {
		v := s[i]
		for match > 0 && s[match] != v {
			match = pi[match]
		}
		if s[match] == v {
			match++
		}
		pi[i+1] = match
	}
	return pi
}

// 空间优化
func solveH(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, m int
	var a, b string
	Fscan(in, &n, &m, &a, &b)
	// pi[i] 为 s[:i] 的真前缀和真后缀的最长匹配长度, pi[0] = 0
	pi := calcPi(b)
	// 匹配到 i-1，下一个为 0, 1 的转移
	trans0, trans1 := make([]int, m+1), make([]int, m+1)
	for i := 0; i < m; i++ {
		if b[i] == '0' {
			trans0[i] = i + 1
			trans1[i] = trans1[pi[i]]
		} else {
			trans1[i] = i + 1
			trans0[i] = trans0[pi[i]]
		}
	}
	trans0[m] = trans0[pi[m]]
	trans1[m] = trans1[pi[m]]
	// dp[i][j][k] 表示 a[:i] 匹配到 b[:j] 且已经匹配 k 个 b 的最小修改数量
	dp := make([][]int, m+1)
	for j := range dp {
		dp[j] = make([]int, n-m+2)
		for k := range dp[j] {
			dp[j][k] = 1e9
		}
	}
	dp[0][0] = 0
	for i := 1; i <= n; i++ {
		ndp := make([][]int, m+1)
		for j := range ndp {
			ndp[j] = make([]int, n-m+2)
			for k := range ndp[j] {
				ndp[j][k] = 1e9
			}
		}
		for j := 0; j <= m; j++ {
			for k := 0; k <= n-m; k++ {
				u := trans0[j]
				v := k + boolToInt(u == m)
				ndp[u][v] = min(ndp[u][v], dp[j][k]+boolToInt(a[i-1] != '0'))

				u = trans1[j]
				v = k + boolToInt(u == m)
				ndp[u][v] = min(ndp[u][v], dp[j][k]+boolToInt(a[i-1] != '1'))
			}
		}
		dp = ndp
	}

	for i := 0; i <= n-m+1; i++ {
		var ans int = 1e9
		for j := 0; j <= m; j++ {
			ans = min(ans, dp[j][i])
		}
		if ans > n {
			ans = -1
		}
		Fprint(out, ans, " ")
	}
	Fprintln(out)
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func main() {
	solveH(os.Stdin, os.Stdout)
}
