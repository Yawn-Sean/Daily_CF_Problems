package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func main() { CF623A(os.Stdin, os.Stdout) }

func CF623A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m, u, v int
	fmt.Fscan(in, &n, &m)
	g := make([][]bool, n)
	for i := 0; i < n; i++ {
		g[i] = make([]bool, n)
		g[i][i] = true
	}
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &u, &v)
		u, v = u-1, v-1
		g[u][v] = true
		g[v][u] = true
	}
	mp := map[int]rune{}
	t := -1
	for i := 0; i < n; i++ {
		count := 0
		for j := 0; j < n; j++ {
			if g[i][j] {
				count += 1
			}
		}
		if count == n {
			mp[i] = 'b'
		} else {
			t = i
		}
	}
	var flag bool
	var a, c []int
	if t != -1 {
		tt := -1
	o:
		for i := 0; i < n; i++ {
			if !g[t][i] {
				mp[i] = 'c'
				for j := 0; j < len(c); j++ {
					if !g[i][tt] {
						flag = true
						break o
					}
				}
				c = append(c, i)
				tt = i
			}
		}
		if !flag {
		out:
			for i := 0; i < n; i++ {
				if !g[tt][i] {
					for j := 0; j < len(c); j++ {
						if g[c[j]][i] {
							flag = true
							break out
						}
					}
					for j := 0; j < len(a); j++ {
						if !g[a[j]][i] {
							flag = true
							break out
						}
					}
					a = append(a, i)
					mp[i] = 'a'
				}
			}
		}
	}
	if len(mp) == n {
		fmt.Fprintf(out, "Yes\n")
		var sb strings.Builder
		for i := 0; i < n; i++ {
			sb.WriteRune(mp[i])
		}
		fmt.Fprintf(out, "%s\n", sb.String())
	} else {
		fmt.Fprintf(out, "No\n")
	}
}
