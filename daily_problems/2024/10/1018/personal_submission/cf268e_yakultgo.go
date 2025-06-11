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
	type pair struct{ l, p int }
	a := make([]pair, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i].l, &a[i].p)
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i].l*a[i].p*(100-a[j].p) > a[j].l*a[j].p*(100-a[i].p)
	})
	var sum, cur int
	for i := 0; i < n; i++ {
		sum += cur*(100-a[i].p) + 10000*a[i].l
		cur += a[i].l * a[i].p
	}
	fmt.Fprintf(out, "%.9f", float64(sum)/10000)
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
