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
	for i := range a {
		fmt.Fscan(in, &a[i])
	}
	ans := 0
	type pair struct{ l, r int }
	seg := make([]pair, 0)
	for i := 0; i < n-1; {
		if a[i] == a[i+1] {
			i++
			continue
		}
		r := i
		for r+1 < n && a[r] != a[r+1] {
			r++
		}
		seg = append(seg, pair{i, r})
		i = r + 1
	}

	for i := range seg {
		ans = max(ans, (seg[i].r-seg[i].l)/2)
		for j := seg[i].l; j <= (seg[i].l+seg[i].r)/2; j++ {
			a[j] = a[seg[i].l]
		}
		for j := (seg[i].l+seg[i].r)/2 + 1; j <= seg[i].r; j++ {
			a[j] = a[seg[i].r]
		}
	}
	fmt.Fprintln(out, ans)
	for i := range a {
		fmt.Fprint(out, a[i], " ")
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
