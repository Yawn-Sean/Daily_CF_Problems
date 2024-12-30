package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() {
	solveI(os.Stdin, os.Stdout)
}

func solveI(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	x, y, r := make([]int, n), make([]int, n), make([]int, n)
	for i := range x {
		fmt.Fscan(in, &x[i], &y[i], &r[i])
	}
	// 与圆 i 相切的圆建图
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			dx, dy, sr := x[i]-x[j], y[i]-y[j], r[i]+r[j]
			if dx*dx+dy*dy == sr*sr {
				g[i] = append(g[i], j)
				g[j] = append(g[j], i)
			}
		}
	}

	vis := make([]int, n)
	for i, v := range vis {
		if v != 0 {
			continue
		}

		// 假设圆 i 半径增加
		cnt := [2]int{1, 0}
		vis[i] = 1

		var dfs func(int) bool
		dfs = func(u int) bool {
			f := true
			for _, v := range g[u] {
				if vis[v] == 0 {
					vis[v] = 3 - vis[u]
					cnt[vis[v]-1]++
					// 注意顺序，连通图中的每个节点都要遍历
					f = dfs(v) && f
				} else if vis[v] == vis[u] {
					f = false
				}
			}
			return f
		}

		// 没有冲突且增加减少个数不同
		if dfs(i) && cnt[0] != cnt[1] {
			fmt.Fprintln(out, "YES")
			return
		}
	}
	fmt.Fprintln(out, "NO")
}
