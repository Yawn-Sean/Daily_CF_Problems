package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k, mod int
	fmt.Fscan(in, &n, &k, &mod)
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, k)
	}
	base := 1
	for i := 1; i < 10; i++ {
		dp[1][i%k] = (dp[1][i%k] + 1) % mod
	}
	for i := 1; i < n; i++ {
		base = base * 10 % k
		dp[i+1][0] = (dp[i+1][0] + dp[i][0]*10) % mod
		for j := 1; j < 10; j++ {
			t := j * base % k
			dp[i+1][t] = (dp[i+1][t] + 1) % mod
		}
		for j := 1; j < k; j++ {
			for l := 0; l < 10; l++ {
				t := (l*base + j) % k
				dp[i+1][t] = (dp[i+1][t] + dp[i][j]) % mod
			}
		}
	}
	fmt.Fprintln(out, (dp[n][0]-dp[n-1][0]+mod)%mod)
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
