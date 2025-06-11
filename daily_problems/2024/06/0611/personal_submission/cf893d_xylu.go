package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { solveD(os.Stdin, os.Stdout) }

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n, d int
	fmt.Fscan(in, &n, &d)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}
	ans, l, r := 0, 0, 0 // 当前余额最小和最大值
	for _, v := range a {
		l, r = l+v, min(d, r+v)
		if l > d {
			fmt.Fprintln(out, -1)
			return
		}
		if v == 0 {
			if r < 0 {
				l, r = 0, d
				ans++
			}
			l = max(l, 0)
		}
	}
	fmt.Fprintln(out, ans)
}
