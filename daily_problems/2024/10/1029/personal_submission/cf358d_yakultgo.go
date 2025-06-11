package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	b := make([]int, n)
	c := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}
	for i := range b {
		fmt.Fscan(in, &b[i])
	}
	for i := range c {
		fmt.Fscan(in, &c[i])
	}
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 2)
		for j := range dp[i] {
			dp[i][j] = math.MinInt32
		}
	}
	dp[0][0] = 0
	for i := 0; i < n; i++ {
		dp[i+1][0] = max(dp[i][0]+b[i], dp[i][1]+c[i])
		dp[i+1][1] = max(dp[i][0]+a[i], dp[i][1]+b[i])
	}
	fmt.Fprintln(out, dp[n][1])
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
