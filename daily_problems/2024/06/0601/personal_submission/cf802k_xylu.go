package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"slices"
)

type pair struct{ x, y int }

func solveK(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, k int
	fmt.Fscan(in, &n, &k)
	g := make([][]pair, n)
	for i := 1; i < n; i++ {
		var u, v, c int
		fmt.Fscan(in, &u, &v, &c)
		g[u] = append(g[u], pair{v, c})
		g[v] = append(g[v], pair{u, c})
	}
	var dfs func(u, p int) pair
	dfs = func(u, p int) pair {
		res := []pair{}
		for _, e := range g[u] {
			if e.x == p {
				continue
			}
			v, c := e.x, e.y
			rp := dfs(v, u)
			res = append(res, pair{rp.x + c, rp.y + c})
		}
		slices.SortFunc(res, func(a, b pair) int { return b.x - a.x })
		res1, res2 := 0, 0
		for i := 0; i < min(k-1, len(res)); i++ {
			res1 += res[i].x
		}
		t := 0
		if len(res) >= k {
			t = res[k-1].x
		}
		for i := 0; i < min(k-1, len(res)); i++ {
			res2 = max(res2, res1+t-res[i].x+res[i].y)
		}
		for i := k - 1; i < len(res); i++ {
			res2 = max(res2, res1+res[i].y)
		}
		return pair{res1, res2}
	}
	fmt.Fprintln(out, dfs(0, -1).y)
}

func main() {
	solveK(os.Stdin, os.Stdout)
}
