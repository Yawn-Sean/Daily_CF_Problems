package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF231C(os.Stdin, os.Stdout) }

func CF231C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int
	fmt.Fscan(in, &n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	sort.Ints(a)
	pre := make([]int, n+1)
	for i := 0; i < n; i++ {
		pre[i+1] = pre[i] + a[i]
	}
	ans1, ans2 := 0, 0
	start := 0
	for i := 0; i < n; i++ {
		if i < n-1 && a[i] == a[i+1] {
			continue
		}
		l, r := start, i
		for l <= r {
			mid := (l + r) >> 1
			v := a[i]*(i-mid+1) - (pre[i+1] - pre[mid])
			if v > k {
				l = mid + 1
			} else {
				r = mid - 1
			}
		}
		if ans1 < i-l+1 {
			ans1 = i - l + 1
			ans2 = a[i]
		}
		start = l
	}
	fmt.Fprintf(out, "%d %d", ans1, ans2)
}
