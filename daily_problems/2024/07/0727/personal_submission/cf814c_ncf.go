package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF814C(os.Stdin, os.Stdout) }

func CF814C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, q, m int
	var s, c string
	fmt.Fscan(in, &n, &s, &q)
	g := make([][]int, 26)
	for i, e := range s {
		g[e-'a'] = append(g[e-'a'], i)
	}
	ans := make([][]int, 26)
	for i := 0; i < 26; i++ {
		ans[i] = make([]int, n+1)
		for j := 0; j <= n; j++ {
			cur := j
			l, r := 0, 0
			for l < len(g[i]) {
				for r < len(g[i]) && j-(g[i][r]-g[i][l]+1-(r-l+1)) >= 0 {
					r++
				}
				cur = max(cur, j+(r-l))
				l++
			}
			ans[i][j] = min(cur, n)
		}
	}
	for i := 0; i < q; i++ {
		fmt.Fscan(in, &m, &c)
		fmt.Fprintf(out, "%d\n", ans[c[0]-'a'][m])
	}
}
