package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// 3 6 12 24 48 96

	var n, x int
	fmt.Fscan(in, &n)

	N := int(1e6)
	cnt := make([]int, N+1)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x)
		cnt[x]++
	}

	dp := make([]int, N+1)
	for i := 1; i <= N; i++ {
		dp[i] += cnt[i]
		for j := i; j <= N; j += i {
			dp[j] = max(dp[j], dp[i])
		}
	}
	ans := 0
	for i := 1; i <= N; i++ {
		ans = max(ans, dp[i])
	}
	fmt.Fprintln(out, ans)
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
