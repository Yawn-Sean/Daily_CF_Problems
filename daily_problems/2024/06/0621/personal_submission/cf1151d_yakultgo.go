package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	type pair struct{ l, r int }
	a := make([]pair, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i].l, &a[i].r)
	}
	sort.Slice(a, func(i, j int) bool { return a[i].l-a[i].r > a[j].l-a[j].r })
	ans := 0
	for i := 0; i < n; i++ {
		ans += a[i].l*i + a[i].r*(n-i-1)
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
