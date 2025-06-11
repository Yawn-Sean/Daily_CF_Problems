package main

import (
	"bufio"
	. "fmt"
	"os"
)

var (
	in  *bufio.Reader = bufio.NewReader(os.Stdin)
	out *bufio.Writer = bufio.NewWriter(os.Stdout)
)

var n, k int64
var arr []int64

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func check(ca int64) bool {
	var dp = make([]int64, n+1)
	dp[0] = 1
	for i := int64(1); i < n; i++ {
		dp[i] = 1
		for j := int64(0); j < i; j++ {
			if abs(arr[j]-arr[i]) <= (i-j)*ca {
				dp[i] = max(dp[i], dp[j]+1)
			}
			dp[n] = max(dp[n], dp[i])

		}
	}
	return dp[n] >= n-k
}

func main() {
	defer out.Flush()
	Fscan(in, &n, &k)
	arr = make([]int64, n)
	for i := 0; i < int(n); i++ {
		Fscan(in, &arr[i])
	}

	var l, r int64 = 0, 2e9
	for l < r {
		mid := (l + r) / 2
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	Fprintln(out, l)

}