package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m int
	fmt.Fscan(in, &n, &m)
	g := make([][]int, n)
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscan(in, &u, &v)
		u--
		v--
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	a := make([]int, n)
	b := make([]int, n)
	qu := make([]int, 0)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		if a[i] == 0 {
			qu = append(qu, i)
		}
	}
	ret := make([]int, 0)
	for len(qu) > 0 {
		u := qu[0]
		qu = qu[1:]
		ret = append(ret, u)
		b[u] += 1
		for _, v := range g[u] {
			b[v] += 1
			if b[v] == a[v] {
				qu = append(qu, v)
			}
		}
	}
	fmt.Fprintln(out, len(ret))
	for i := 0; i < len(ret); i++ {
		fmt.Fprint(out, ret[i]+1, " ")
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
