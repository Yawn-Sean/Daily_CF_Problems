package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	type pair struct{ mi, mx, idx int }
	a := make([]pair, n)
	for i := range a {
		var x, y int
		fmt.Fscan(in, &x, &y)
		a[i] = pair{min(x, y), max(x, y), i}
	}
	sort.Slice(a, func(i, j int) bool { return a[i].mi < a[j].mi })
	ans := make([]int, n)
	for i := range ans {
		ans[i] = -1
	}
	var mx = math.MaxInt32
	var idx = -1
	for i, j := 0, 0; i < n; i++ {
		for j < i && a[j].mi < a[i].mi {
			if a[j].mx < mx {
				mx = a[j].mx
				idx = a[j].idx
			}
			j++
		}
		if a[i].mx > mx {
			ans[a[i].idx] = idx + 1
		}
	}
	for i := range ans {
		fmt.Fprint(out, ans[i], " ")
	}
	fmt.Fprintln(out)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	fmt.Fscan(in, &T)
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
