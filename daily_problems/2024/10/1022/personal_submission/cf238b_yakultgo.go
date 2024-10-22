package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, h int
	fmt.Fscan(in, &n, &h)
	type pair struct{ val, idx int }
	a := make([]pair, n)
	for i := range a {
		var x int
		fmt.Fscan(in, &x)
		a[i] = pair{x, i}
	}
	if n == 2 {
		fmt.Fprintln(out, 0)
		fmt.Fprintln(out, 1, 1)
		return
	}
	sort.Slice(a, func(i, j int) bool { return a[i].val < a[j].val })
	one := a[n-1].val + a[n-2].val - (a[0].val + a[1].val)
	two := max(a[n-1].val+a[n-2].val, a[n-1].val+a[0].val+h) - min(a[0].val+a[1].val+h, a[1].val+a[2].val)
	if one <= two {
		fmt.Fprintln(out, one)
		for i := 0; i < n; i++ {
			fmt.Fprint(out, 1, " ")
		}
	} else {
		fmt.Fprintln(out, two)
		tmp := a[0].idx
		sort.Slice(a, func(i, j int) bool { return a[i].idx < a[j].idx })
		for i := 0; i < n; i++ {
			if i == tmp {
				fmt.Fprint(out, 2, " ")
			} else {
				fmt.Fprint(out, 1, " ")
			}
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
