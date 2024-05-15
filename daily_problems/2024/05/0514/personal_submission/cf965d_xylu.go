package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solveD(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var w, l, cur, ans int
	fmt.Fscan(in, &w, &l)
	a := make([]int, w-1)
	for i := range a {
		fmt.Fscan(in, &a[i])
		if i < l {
			cur += a[i]
		}
	}
	ans = cur
	for i := l; i < w-1; i++ {
		cur += a[i] - a[i-l]
		ans = min(ans, cur)
	}
	fmt.Fprintln(out, ans)
}

func main() {
	solveD(os.Stdin, os.Stdout)
}
