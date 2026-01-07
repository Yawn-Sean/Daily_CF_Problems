package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	init := func(g [][]int, n, size int) {
		for i := range n {
			g[i] = make([]int, size)
			for j := range size {
				g[i][j] = math.MaxInt
			}
		}
	}

	var n, q int
	in, out := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	defer out.Flush()
	fmt.Fscan(in, &n, &q)
	g, f := make([][]int, n), make([][]int, n+1)
	init(g, n, n)
	init(f, n+1, n*n+1)

	for i := range n {
		for j := range n {
			fmt.Fscan(in, &g[i][j])
		}
	}
	for k := 1; k <= n; k++ {
		for i := 0; i+k-1 < n; i++ {
			for j := 0; j+k-1 < n; j++ {
				mi, ma := g[i][j], g[i+k-1][j+k-1]
				f[k][mi] = min(f[k][mi], ma)
			}
		}
	}
	for k := 1; k <= n; k++ {
		for i := n*n - 1; i >= 0; i-- {
			f[k][i] = min(f[k][i], f[k][i+1])
		}
	}

	for range q {
		var l, r, res int
		fmt.Fscan(in, &l, &r)
		for L := 1; L <= n; L++ {
			if f[L][l] <= r {
				res = L
			}
		}
		fmt.Fprintln(out, res*res)
	}
}
