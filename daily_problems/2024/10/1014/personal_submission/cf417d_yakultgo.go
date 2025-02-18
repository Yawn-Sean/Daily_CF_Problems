package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m, b int
	fmt.Fscan(in, &n, &m, &b)
	type node struct {
		c, k, sta int
	}
	a := make([]node, n)
	for i := 0; i < n; i++ {
		var cnt int
		fmt.Fscan(in, &a[i].c, &a[i].k, &cnt)
		for j := 0; j < cnt; j++ {
			var x int
			fmt.Fscan(in, &x)
			a[i].sta |= 1 << (x - 1)
		}
	}
	dp := make([]int, 1<<m)
	for i := range dp {
		dp[i] = 2e18
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i].k < a[j].k
	})
	dp[0] = 0
	ans := math.MaxInt64
	for i := 0; i < n; i++ {
		for j := (1 << m) - 1; j >= 0; j-- {
			dp[j|a[i].sta] = min(dp[j|a[i].sta], dp[j]+a[i].c)
		}
		ans = min(ans, dp[(1<<m)-1]+b*a[i].k)
	}
	if ans >= 2e18 {
		fmt.Fprintln(out, -1)
	} else {
		fmt.Fprintln(out, ans)
	}
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
