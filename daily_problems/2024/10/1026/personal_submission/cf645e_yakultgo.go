package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

const mod = 1e9 + 7

func solve(in *bufio.Reader, out *bufio.Writer) {
	var (
		n, k, m int
		s       string
	)
	fmt.Fscan(in, &n, &k, &s)
	m = len(s)
	last := make([]int, k)
	dp := make([]int, n+m+1)
	for i := 1; i <= m; i++ {
		if last[s[i-1]-'a'] == 0 {
			dp[i] = 2*dp[i-1] + 1
		} else {
			dp[i] = 2*dp[i-1] - dp[last[s[i-1]-'a']-1]
		}
		dp[i] = (dp[i] + mod) % mod
		last[s[i-1]-'a'] = i
	}
	for i := m + 1; i <= n+m; i++ {
		mi, idx := math.MaxInt64, -1
		for j := 0; j < k; j++ {
			if last[j] < mi {
				mi = last[j]
				idx = j
			}
		}
		if mi == 0 {
			dp[i] = 2*dp[i-1] + 1
		} else {
			dp[i] = 2*dp[i-1] - dp[mi-1]
		}
		last[idx] = i
		dp[i] = (dp[i] + mod) % mod
	}
	dp[n+m] = (dp[n+m] + 1) % mod
	fmt.Fprintln(out, dp[n+m])
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
