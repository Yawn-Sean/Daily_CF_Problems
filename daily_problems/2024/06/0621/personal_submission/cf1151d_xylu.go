package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"slices"
)

func main() { solveD(os.Stdin, os.Stdout) }

type pair struct{ a, b int }

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	p := make([]pair, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &p[i].a, &p[i].b)
	}
	slices.SortFunc(p, func(i, j pair) int {
		return (j.a - j.b) - (i.a - i.b)
	})
	ans := 0
	for i, v := range p {
		ans += v.a*i + v.b*(n-i-1)
	}
	fmt.Fprintln(out, ans)
}
