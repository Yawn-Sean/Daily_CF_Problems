package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var x, y, ans int
	fmt.Fscan(in, &x, &y)
	a, b, c := y, y, y
	for a < x || b < x || c < x {
		if a != x {
			a = min(b+c-1, x)
			ans++
		}
		if b != x {
			b = min(a+c-1, x)
			ans++
		}
		if c != x {
			c = min(a+b-1, x)
			ans++
		}
	}
	fmt.Fprintln(out, ans)
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
