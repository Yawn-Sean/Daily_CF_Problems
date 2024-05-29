package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1168B(os.Stdin, os.Stdout) }

func CF1168B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var s string
	fmt.Fscan(in, &s)
	ans := 0
	n := len(s)
	r := n
	for i := n - 1; i > -1; i -= 1 {
		for j := 1; i+2*j < n; j += 1 {
			if s[i] == s[i+j] && s[i] == s[i+2*j] {
				r = min(r, i+2*j)
				//ans += n - r 放里面的话有些情况没计算到
				break
			}
		}
		ans += n - r
	}
	fmt.Fprintf(out, "%d", ans)
}
