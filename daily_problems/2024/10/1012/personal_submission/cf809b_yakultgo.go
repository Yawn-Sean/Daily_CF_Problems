package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k int
	fmt.Fscan(in, &n, &k)
	ask := func(a, b int) string {
		fmt.Fprintf(out, "1 %d %d\n", a, b)
		out.Flush()
		var s string
		fmt.Fscan(in, &s)
		return s
	}
	check := func(left, right int) int {
		for left < right {
			mid := (left + right) / 2
			if ask(mid, mid+1) == "TAK" {
				right = mid
			} else {
				left = mid + 1
			}
		}
		return left
	}
	x := check(1, n)
	y := check(1, x-1)
	if x == y || ask(y, x) == "NIE" {
		y = check(x+1, n)
	}
	fmt.Fprintf(out, "2 %d %d\n", y, x)
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
