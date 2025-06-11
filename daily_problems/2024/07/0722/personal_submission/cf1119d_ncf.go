package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1119D(os.Stdin, os.Stdout) }

func CF1119D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, q, l, r int
	fmt.Fscan(in, &n)
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &s[i])
	}
	sort.Ints(s)
	a := make([]int, n)
	for i := 0; i < n-1; i++ {
		a[i] = s[i+1] - s[i]
	}
	a[n-1] = int(1e18)
	sort.Ints(a)
	acc := make([]int, n+1)
	for i := 0; i < n; i++ {
		acc[i+1] = acc[i] + a[i]
	}
	fmt.Fscan(in, &q)
	for i := 0; i < q; i++ {
		fmt.Fscan(in, &l, &r)
		diff := r - l + 1
		ll, rr := 0, n-2
		for ll <= rr {
			mid := (ll + rr) / 2
			if a[mid] >= diff {
				rr = mid - 1
			} else {
				ll = mid + 1
			}
		}
		fmt.Fprintf(out, "%d ", acc[ll]+diff*(n-ll))
	}
}
