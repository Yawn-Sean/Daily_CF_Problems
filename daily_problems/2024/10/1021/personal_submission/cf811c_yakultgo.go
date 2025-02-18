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
	sum := make(map[int]int)
	for i := range a {
		fmt.Fscan(in, &a[i])
		sum[a[i]]++
	}
	dp := make([]int, n+1)
	pre := make([]int, n+1)
	for i := 1; i <= n; i++ {
		cur := 0
		tmp := make(map[int]int)
		cnt := 0
		for j := i; j >= 1; j-- {
			if _, ok := tmp[a[j-1]]; !ok {
				cnt++
				cur ^= a[j-1]
			}
			tmp[a[j-1]]++
			if tmp[a[j-1]] == sum[a[j-1]] {
				cnt--
			}
			if cnt == 0 {
				dp[i] = max(dp[i], pre[j-1]+cur)
			}
		}
		pre[i] = max(pre[i-1], dp[i])
	}
	fmt.Fprintln(out, pre[n])
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
