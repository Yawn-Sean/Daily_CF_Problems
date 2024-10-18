package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

const inf = math.MaxInt / 3 // 防止更新最短路时加法溢出
func main()                 { CF954D(os.Stdin, os.Stdout) }

func CF954D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m, s, t, x, y int
	fmt.Fscan(in, &n, &m, &s, &t)
	s, t = s-1, t-1
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, n)
		for j := 0; j < n; j++ {
			g[i][j] = inf
		}
		g[i][i] = 0
	}
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &x, &y)
		x, y = x-1, y-1
		g[x][y] = 1
		g[y][x] = 1
	}
	for k := range g {
		for i := range g {
			if g[i][k] == inf {
				continue
			}
			for j := range g {
				g[i][j] = min(g[i][j], g[i][k]+g[k][j])
			}
		}
	}

	ans := 0
	for i := range g {
		for j := i + 1; j < n; j++ {
			if g[i][j] != 1 && min(g[i][s]+g[t][j], g[i][t]+g[s][j])+1 >= g[s][t] {
				ans++
			}
		}
	}

	fmt.Fprintf(out, "%d", ans)
}
