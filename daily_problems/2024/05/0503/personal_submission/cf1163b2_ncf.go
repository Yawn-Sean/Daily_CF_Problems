package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1163B2(os.Stdin, os.Stdout) }

func CF1163B2(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, u int
	fmt.Fscan(in, &n)
	ans := 0
	c1, c2 := map[int]int{}, map[int]int{}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &u)
		if c1[u] != 0 {
			c2[c1[u]] -= 1
			if c2[c1[u]] == 0 {
				delete(c2, c1[u])
			}
		}
		c1[u] += 1
		c2[c1[u]] += 1
		if len(c2) == 1 {
			for k, v := range c2 {
				if k == 1 || v == 1 {
					ans = i + 1
				}
			}
		} else if len(c2) == 2 {
			var vv, kk []int
			for k, v := range c2 {
				vv = append(vv, v)
				kk = append(kk, k)
			}
			if kk[1] < kk[0] {
				kk[1], kk[0] = kk[0], kk[1]
				vv[1], vv[0] = vv[0], vv[1]
			}
			if vv[1] == 1 && kk[1]-kk[0] == 1 || vv[0] == 1 && kk[0] == 1 {
				ans = i + 1
			}
		}
	}
	fmt.Fprintf(out, "%d", ans)
}
