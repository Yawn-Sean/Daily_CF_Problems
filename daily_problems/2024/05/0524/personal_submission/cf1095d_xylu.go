package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type pair struct{ x, y int }

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	next := make([]pair, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &next[i].x, &next[i].y)
	}
	a, b := 1, 0
	if next[1].y == next[next[1].x].x || next[1].y == next[next[1].x].y {
		b = next[1].x
	} else {
		b = next[1].y
	}
	fmt.Fprint(out, 1, b, " ")
	for i := 0; i < n-2; i++ {
		c := next[a].x + next[a].y - b
		fmt.Fprint(out, c, " ")
		a, b = b, c
	}
}

func main() {
	solveD(os.Stdin, os.Stdout)
}
