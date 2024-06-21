package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { solveD(os.Stdin, os.Stdout) }

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n, m, u, v int
	fmt.Fscan(in, &n, &m)
	g := make([][]int, n)
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &u, &v)
		g[u-1] = append(g[u-1], v-1)
		g[v-1] = append(g[v-1], u-1)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}

	// 贪心
	ans := make([]int, 0, n)
	var dfs func(int)
	dfs = func(v int) {
		ans = append(ans, v)
		a[v]--
		for _, w := range g[v] {
			a[w]--
			if a[w] == 0 {
				dfs(w)
			}
		}
	}

	for i := 0; i < n; i++ {
		if a[i] == 0 {
			dfs(i)
		}
	}

	fmt.Fprintln(out, len(ans))
	for _, v := range ans {
		fmt.Fprint(out, v+1, " ")
	}
}
