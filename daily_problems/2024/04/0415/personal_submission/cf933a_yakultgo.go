package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	dp := make([]int, 4)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		if a[i] == 1 {
			dp[0]++
		}
		if a[i] == 2 {
			dp[1] = max(dp[0], dp[1]+1)
		} else {
			dp[1] = max(dp[0], dp[1])
		}
		if a[i] == 1 {
			dp[2] = max(dp[1], dp[2]+1)
		} else {
			dp[2] = max(dp[1], dp[2])
		}
		if a[i] == 2 {
			dp[3] = max(dp[2], dp[3]+1)
		} else {
			dp[3] = max(dp[2], dp[3])
		}
	}
	fmt.Fprintln(out, dp[3])
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	solve(in, out)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
