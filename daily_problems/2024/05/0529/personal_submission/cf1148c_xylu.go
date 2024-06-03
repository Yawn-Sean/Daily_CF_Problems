package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type pair struct{ x, y int }

func main() {
	solveC(os.Stdin, os.Stdout)
}

func solveC(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	p, loc := make([]int, n+1), make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &p[i])
		loc[p[i]] = i
	}

	ops := make([]pair, 0, 5*n)
	swap := func(i, j int) {
		ops = append(ops, pair{i, j})
		p[i], p[j] = p[j], p[i]
		loc[p[i]], loc[p[j]] = loc[p[j]], loc[p[i]]
	}

	for i := 1; i <= n; i++ {
		if p[i] != i {
			if 2*(loc[i]-i) >= n {
				swap(i, loc[i])
			} else if 2*(i-1) >= n {
				swap(1, i)
				swap(1, loc[i])
				swap(1, i)
			} else if 2*(n-loc[i]) >= n {
				swap(i, n)
				swap(loc[i], n)
				swap(i, n)
			} else {
				t := loc[i]
				swap(1, t)
				swap(i, n)
				swap(1, n)
				swap(1, t)
				swap(i, n)
			}
		}
	}

	fmt.Fprintln(out, len(ops))
	for _, op := range ops {
		fmt.Fprintln(out, op.x, op.y)
	}
}
