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
	a := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &a[i])
	}
	dp := make([]int, n+2)
	for i := 2; i <= n+1; i++ {
		dp[i] = (dp[i-1] + dp[i-1] - dp[a[i-1]] + 2 + mod) % mod
	}
	fmt.Fprintln(out, dp[n+1])
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
