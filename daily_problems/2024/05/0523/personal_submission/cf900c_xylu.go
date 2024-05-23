package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type pair struct{ x, y int }

func solveC(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	a, cont := make([]int, n), make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	mx1, mx2 := -1, -1
	for _, v := range a {
		if mx1 > v && mx2 < v {
			// 删除 mx1 结果 +1
			cont[mx1]++
			mx2 = v
		} else if mx1 < v {
			// 删除 v 结果 -1
			cont[v]--
			mx1, mx2 = v, mx1
		}
	}

	mxc, mn := cont[1], 1
	for i := 2; i <= n; i++ {
		if cont[i] > mxc {
			mxc, mn = cont[i], i
		}
	}
	fmt.Fprintln(out, mn)
}

func main() {
	solveC(os.Stdin, os.Stdout)
}
