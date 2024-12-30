package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1949I(os.Stdin, os.Stdout) }

func CF1949I(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	type tuple struct {
		x, y, r int
	}
	a := make([]tuple, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i].x, &a[i].y, &a[i].r)
	}
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if square1949i(a[i].r+a[j].r) == square1949i(a[i].x-a[j].x)+square1949i(a[i].y-a[j].y) {
				g[i] = append(g[i], j)
				g[j] = append(g[j], i)
			}
		}
	}
	vis := make([]int, n)
	for i := 0; i < n; i++ {
		vis[i] = 2
	}

	for i := 0; i < n; i++ {
		if vis[i] != 2 {
			continue
		}
		count := make([]int, 2) // 分别代表将环染成黑、白的数量，不同就代表染色成功
		flag := false // 如果某个环跟相邻的环是同色的，那就证明无法修改，将flag改成true
		var dfs func(cur, color int)
		dfs = func(cur, color int) {
			for _, v := range g[cur] {
				if vis[v] != 2 {
					if vis[v]^vis[cur] == 0 {
						flag = true
					}
				} else {
					cv := color ^ 1
					vis[v] = cv
					count[cv] += 1
					dfs(v, cv)
				}
			}
		}
		vis[i] = 0
		count[0] += 1
		dfs(i, 0)
		if !flag && count[0] != count[1] {
			fmt.Fprintf(out, "YES")
			return
		}
	}
	fmt.Fprintf(out, "NO")
}

func square1949i(a int) int {
	return a * a
}
