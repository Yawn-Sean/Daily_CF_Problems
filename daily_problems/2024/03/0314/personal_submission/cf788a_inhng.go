package main

import (
	"bufio"
	. "fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func abs(x int) int { if x < 0 { return -x }; return x }

func max(a, b int) int { if a > b { return a }; return b }

func solve() {
	var n int
	Fscan(in, &n)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}
	ans, dp1, dp2 := -0x3f3f3f3f, -0x3f3f3f3f, -0x3f3f3f3f
	for i := 1; i < n; i++ {
		dp1, dp2 = max(dp2, 0) + abs(a[i - 1] - a[i]), dp1 - abs(a[i - 1] - a[i])
		ans = max(ans, max(dp1, dp2))
	}
	Println(ans)
}

func main() {
	defer out.Flush()
	solve()
}
