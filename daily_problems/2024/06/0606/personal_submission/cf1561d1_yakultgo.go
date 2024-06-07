package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, mod int
	fmt.Fscan(in, &n, &mod)
	sum := make([]int, n+2)
	dp := make([]int, n+1)
	dp[n] = 1
	sum[n] = 1
	for i := n - 1; i >= 1; i-- {
		dp[i] = (dp[i] + sum[i+1]) % mod
		for j := 2; i*j <= n; j++ {
			dp[i] = (dp[i] + sum[i*j] - sum[min(i*j+j, n+1)]) % mod
			dp[i] = (dp[i] + mod) % mod
		}
		sum[i] = (sum[i+1] + dp[i]) % mod
	}
	fmt.Fprintln(out, dp[1])
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
