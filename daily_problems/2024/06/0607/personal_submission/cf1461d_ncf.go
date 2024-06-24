package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1461D(os.Stdin, os.Stdout) }

func CF1461D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, q, s int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &q)
		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
		}
		sort.Ints(a)

		m := map[int]bool{}
		pre := make([]int, n+1)
		for i := 0; i < n; i++ {
			pre[i+1] = pre[i] + a[i]
		}
		var dfs func(l, r int)
		dfs = func(l, r int) {
			m[pre[r+1]-pre[l]] = true
			if a[l] == a[r] {
				return
			}
			val := (a[l] + a[r]) >> 1
			ll, rr := l, r
			for ll <= rr {
				mid := (ll + rr) >> 1
				if a[mid] < val+1 {
					ll = mid + 1
				} else {
					rr = mid - 1
				}
			}
			ll -= 1
			dfs(l, ll)
			dfs(ll+1, r)
		}
		dfs(0, n-1)
		for i := 0; i < q; i++ {
			fmt.Fscan(in, &s)
			if m[s] {
				fmt.Fprintf(out, "Yes\n")
			} else {
				fmt.Fprintf(out, "No\n")
			}
		}
	}
}
