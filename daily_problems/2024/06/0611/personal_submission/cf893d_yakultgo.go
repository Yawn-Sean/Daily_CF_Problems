package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, d int
	fmt.Fscan(in, &n, &d)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	lo, hi := 0, 0
	cnt := 0
	for _, v := range a {
		if v == 0 {
			if hi < 0 {
				cnt++
				hi = d
			}
			if lo < 0 {
				lo = 0
			}
		} else {
			lo += v
			hi += v
			if lo > d {
				fmt.Fprintln(out, -1)
				return
			}
			if hi > d {
				hi = d
			}
		}
	}
	fmt.Fprintln(out, cnt)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
