package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1e9 + 7

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	fa := make([]int, n+1)
	for i := 0; i <= n; i++ {
		fa[i] = i
	}
	ans := 0
	dp := make([]int, n+1)
	var find func(int) int
	find = func(x int) int {
		if fa[x] == x {
			return x
		}
		f := fa[x]
		fa[x] = find(fa[x])
		dp[x] = ((dp[f]+dp[x])%mod + mod) % mod
		return fa[x]
	}
	var k, u, w int
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &k)
		for j := 1; j <= k; j++ {
			fmt.Fscan(in, &u, &w)
			t := find(u)
			ans = (ans + (dp[u]+w)%mod + mod) % mod
			dp[t] = ((dp[u]+w)%mod + mod) % mod
			fa[t] = i
		}
	}
	fmt.Fprintln(out, ans)
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
