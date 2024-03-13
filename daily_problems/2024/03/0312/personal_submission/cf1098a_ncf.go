package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)
<<<<<<< HEAD

=======
>>>>>>> b5a20e5efb005e42c81fb6b1ac7c48fbcd351daa
func main() { CF1098A(os.Stdin, os.Stdout) }

func CF1098A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, p int
	fmt.Fscan(in, &n)
	g := make([][]int, n)
	for i := 1; i < n; i++ {
		fmt.Fscan(in, &p)
		p--
		g[p] = append(g[p], i)
	}
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &s[i])
	}
<<<<<<< HEAD

=======
>>>>>>> b5a20e5efb005e42c81fb6b1ac7c48fbcd351daa
	ans := 0
	flag := false
	var dfs func(cur, faVal int)
	dfs = func(cur, faVal int) {
		if s[cur] == -1 {
			if len(g[cur]) > 0 {
				mn := math.MaxInt32
				for _, e := range g[cur] {
					mn = min1098a(mn, s[e])
				}
				s[cur] = mn
			} else {
				s[cur] = faVal
			}
		}
		if s[cur] < faVal {
			flag = true
		}
		ans += s[cur] - faVal
		for _, e := range g[cur] {
			if flag {
				return
			}
			dfs(e, s[cur])
		}
	}
	dfs(0, 0)
	if flag {
		fmt.Fprintf(out, "-1")
	} else {
		fmt.Fprintf(out, "%d\n", ans)
	}
}

func min1098a(a, b int) int {
	if a < b {
		return a
	}
	return b
}
