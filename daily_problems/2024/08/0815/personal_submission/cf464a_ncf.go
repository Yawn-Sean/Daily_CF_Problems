package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF464A(os.Stdin, os.Stdout) }

func CF464A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, p int
	var s string
	fmt.Fscan(in, &n, &p, &s)
	limit := 'a' + byte(p)
	ans := []byte(s)
	i := n - 1
	ans[i]++
	for i < n {
		if ans[i] == limit {
			if i == 0 {
				fmt.Fprintf(out, "NO")
				return
			}
			ans[i] = 'a'
			i--
			ans[i]++
		} else if i > 0 && ans[i] == ans[i-1] || i > 1 && ans[i] == ans[i-2] {
			ans[i]++
		} else {
			i++
		}
	}
	fmt.Fprintf(out, "%s", string(ans))
}
