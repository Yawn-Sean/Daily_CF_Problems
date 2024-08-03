package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"slices"
)

func solveD(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	p := make([]int, n)
	p[0] = -1
	for i := 1; i < n; i++ {
		fmt.Fscan(in, &p[i])
		p[i]--
	}

	cnt := make([]int, n)
	for i := n - 1; i > 0; i-- {
		cnt[i] = max(1, cnt[i])
		cnt[p[i]] += cnt[i]
	}
	cnt[0] = max(1, cnt[0])
	slices.Sort(cnt)

	for _, c := range cnt {
		fmt.Fprint(out, c, " ")
	}
	fmt.Fprintln(out)
}

func main() {
	solveD(os.Stdin, os.Stdout)
}
