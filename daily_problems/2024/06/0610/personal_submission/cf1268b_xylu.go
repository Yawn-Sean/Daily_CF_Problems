package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { solveB(os.Stdin, os.Stdout) }

func solveB(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	p := make([]int, n+1)
	c := make([]int, n+1)
	a := make([]int, n+1)
	g := make([][]int, n+1)
	st := []int{}
	c[0] = n
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &p[i], &c[i])
		g[p[i]] = append(g[p[i]], i)
	}

	var dfs func(int) (int, bool)
	dfs = func(u int) (int, bool) {
		res := 1 // 子树节点数
		for _, v := range g[u] {
			if r, ok := dfs(v); ok {
				res += r
			} else {
				return 0, false
			}
		}
		if c[u] >= res {
			return 0, false
		} else if c[u] == 0 {
			// 保证优先对深度较低的节点赋值
			st = append(st, u)
		}
		return res, true
	}

	if _, ok := dfs(0); !ok {
		fmt.Fprintln(out, "NO")
		return
	}

	cur := 1
	for len(st) > 0 {
		u := st[len(st)-1]
		st = st[:len(st)-1]
		a[u] = cur
		for u = p[u]; u != 0; u = p[u] {
			c[u]--
			if c[u] == 0 {
				st = append(st, u)
			}
		}
		cur++
	}

	fmt.Fprintln(out, "YES")
	for i := 1; i <= n; i++ {
		fmt.Fprint(out, a[i], " ")
	}
}
