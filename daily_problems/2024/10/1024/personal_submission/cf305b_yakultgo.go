package main

import (
	"bufio"
	"fmt"
	"os"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
func solve(in *bufio.Reader, out *bufio.Writer) {
	var p, q, n, x int
	fmt.Fscan(in, &p, &q, &n)
	t := gcd(p, q)
	p, q = p/t, q/t
	for n > 0 {
		fmt.Fscan(in, &x)
		if q == 0 || p/q < x {
			break
		}
		p -= q * x
		t := gcd(p, q)
		p, q = q/t, p/t
		n--
	}
	if n > 0 || q > 0 {
		fmt.Fprintln(out, "NO")
	} else {
		fmt.Fprintln(out, "YES")
	}
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
