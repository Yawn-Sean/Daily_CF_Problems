package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
)

type pair struct {
	x, y, idx int
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)

	p := make([]pair, n)

	for i := range n {
		var x, y int
		fmt.Fscan(in, &x, &y)
		p[i] = pair{x: x, y: y, idx: i + 1}
	}

	slices.SortFunc(p, func(x, y pair) int {
		if x.x != y.x {
			return x.x - y.x
		}

		return x.y - y.y
	})

	fmt.Fprintln(out, n+n-1)
	for i := 0; i < n; i++ {
		fmt.Fprintf(out, "%d ", p[i].idx)
	}
	for i := n - 2; i >= 0; i-- {
		fmt.Fprintf(out, "%d ", p[i].idx)
	}
}

func main() {
	in := bufio.NewReaderSize(os.Stdin, 1<<20)
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	solve(in, out)
}
