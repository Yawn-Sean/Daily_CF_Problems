package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF954C(os.Stdin, os.Stdout) }

func CF954C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	if n == 1 {
		fmt.Fprintf(out, "YES\n1000000000 1000000000")
		return
	}
	y, mx := -1, 0
	for i := 1; i < n; i++ {
		mx = max(mx, a[i])
		if a[i] == a[i-1] {
			fmt.Fprintf(out, "NO")
			return
		}
		diff := abs954c(a[i] - a[i-1])
		if diff == 1 {
			if y != -1 && (a[i]-1)/y != (a[i-1]-1)/y {
				fmt.Fprintf(out, "NO")
				return
			}
		} else {
			if y != -1 && y != diff {
				fmt.Fprintf(out, "NO")
				return
			}
			y = diff
		}
	}
	if y == -1 {
		fmt.Fprintf(out, "YES\n1000000000 1000000000")
		return
	}
	for i := 1; i < n; i++ {
		lx, ly := (a[i-1]-1)/y, (a[i-1]-1)%y
		cx, cy := (a[i]-1)/y, (a[i]-1)%y
		if !(lx+1 == cx && ly == cy || lx-1 == cx && ly == cy || lx == cx && ly+1 == cy || lx == cx && ly-1 == cy) {
			fmt.Fprintf(out, "NO")
			return
		}
	}

	fmt.Fprintf(out, "YES\n%d %d", 1000000000, y)
}

func abs954c(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
