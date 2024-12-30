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

	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	y := int(1e9)
	for i := 1; i < n; i++ {
		d := abs(a[i] - a[i-1])
		if d == 0 {
			fmt.Fprintln(out, "NO")
			return
		} else if d == 1 {
			continue
		} else if y == int(1e9) {
			y = d
		} else if y != d {
			fmt.Fprintln(out, "NO")
			return
		}
	}

	for i := 0; i < n; i++ {
		if i > 0 && abs(a[i]-a[i-1]) == 1 {
			x1, x2 := (a[i]+y-1)/y, (a[i-1]+y-1)/y
			if x1 != x2 {
				fmt.Fprintln(out, "NO")
				return
			}
		}
	}
	fmt.Fprintln(out, "YES")
	fmt.Fprintln(out, int(1e9), y)
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	solveC(os.Stdin, os.Stdout)
}
