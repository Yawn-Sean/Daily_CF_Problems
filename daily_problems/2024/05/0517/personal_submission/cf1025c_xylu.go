package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solveC(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var s string
	fmt.Fscan(in, &s)
	ss := s + s
	n := len(s)
	ans, res := 0, 0
	for i := 0; i < 2*n; i++ {
		if i > 0 && ss[i] != ss[i-1] {
			res++
		} else {
			res = 1
		}
		ans = max(ans, res)
	}
	fmt.Fprintln(out, min(ans, n))
}

func main() {
	solveC(os.Stdin, os.Stdout)
}
