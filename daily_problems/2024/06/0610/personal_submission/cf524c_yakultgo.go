package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k, q int
	fmt.Fscan(in, &n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	fmt.Fscan(in, &q)
	for i := 0; i < q; i++ {
		var x int
		fmt.Fscan(in, &x)
		mp := make(map[int]int)
		mp[0] = 0
		ans := math.MaxInt32
		for j := 0; j < n; j++ {
			for l := 1; l <= k; l++ {
				money := a[j] * l
				if val, ok := mp[x-money]; ok && val+l <= k {
					ans = min(ans, val+l)
				}
				val, ok := mp[money]
				if !ok || val > l {
					mp[money] = l
				}
			}
		}
		if ans == math.MaxInt32 {
			fmt.Fprintln(out, -1)
		} else {
			fmt.Fprintln(out, ans)
		}
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
