package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k int
	fmt.Fscan(in, &n, &k)
	cardMap := make(map[int]int)
	for i := 0; i < n*k; i++ {
		var x int
		fmt.Fscan(in, &x)
		cardMap[x]++
	}
	peopleMap := make(map[int]int)
	for i := 0; i < n; i++ {
		var x int
		fmt.Fscan(in, &x)
		peopleMap[x]++
	}
	h := make([]int, k+1)
	for i := 1; i <= k; i++ {
		fmt.Fscan(in, &h[i])
	}
	ans := 0
	for card, v := range cardMap {
		if v >= k*peopleMap[card] {
			ans += h[k] * peopleMap[card]
		} else {
			dp := make([]int, v+1)
			for i := 1; i <= v; i++ {
				dp[i] = int(-1e18)
			}
			for i := 0; i < peopleMap[card]; i++ {
				for j := v; j >= 0; j-- {
					for l := 1; l <= k; l++ {
						if j-l >= 0 {
							dp[j] = max(dp[j], dp[j-l]+h[l])
						}
					}
				}
			}
			ans += dp[v]
		}
	}
	fmt.Fprintln(out, ans)
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
