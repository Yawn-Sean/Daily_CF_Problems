package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1148C(os.Stdin, os.Stdout) }

func CF1148C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	type tuple struct {
		val, idx int
	}
	p := make([]tuple, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &p[i].val)
		p[i].idx = i
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i].val < p[j].val
	})
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[p[i].idx] = i
	}
	var ans []int
	for i := 0; i < n; i++ {
		for a[i] != i {
			if abs1148c(a[i]-i)*2 < n {
				if a[i]*2 >= n {
					ans = append(ans, 0)
					ans = append(ans, a[i])
					if i*2 >= n {
						ans = append(ans, 0)
						ans = append(ans, i)
						ans = append(ans, 0)
						ans = append(ans, a[i])
					} else {
						ans = append(ans, 0)
						ans = append(ans, n-1)
						ans = append(ans, i)
						ans = append(ans, n-1)
						ans = append(ans, 0)
						ans = append(ans, n-1)
						ans = append(ans, 0)
						ans = append(ans, a[i])
					}
				} else {
					ans = append(ans, n-1)
					ans = append(ans, a[i])
					if i*2 < n {
						ans = append(ans, n-1)
						ans = append(ans, i)
						ans = append(ans, n-1)
						ans = append(ans, a[i])
					} else {
						ans = append(ans, 0)
						ans = append(ans, n-1)
						ans = append(ans, i)
						ans = append(ans, 0)
						ans = append(ans, 0)
						ans = append(ans, n-1)
						ans = append(ans, n-1)
						ans = append(ans, a[i])
					}
				}
			} else {
				ans = append(ans, i)
				ans = append(ans, a[i])
			}
			a[i], a[a[i]] = a[a[i]], a[i]
		}
	}
	fmt.Fprintf(out, "%d\n", len(ans)/2)
	for i := 0; i < len(ans)/2; i++ {
		fmt.Fprintf(out, "%d %d\n", ans[i<<1]+1, ans[i<<1|1]+1)
	}
}

func abs1148c(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}
