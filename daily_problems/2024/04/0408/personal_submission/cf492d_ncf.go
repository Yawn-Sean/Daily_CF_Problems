package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF492D(os.Stdin, os.Stdout) }

func CF492D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, x, y, a int
	fmt.Fscan(in, &n, &x, &y)
	lcm := x * y / gcd492d(x, y)
	xx, yy := lcm/x, lcm/y
	xxx, yyy := xx, yy
	var simulation []string
	for xxx <= lcm || yyy <= lcm {
		if xxx < yyy {
			simulation = append(simulation, "Vanya")
			xxx += xx
		} else if xxx > yyy {
			simulation = append(simulation, "Vova")
			yyy += yy
		} else {
			simulation = append(simulation, "Both")
			simulation = append(simulation, "Both")
			yyy += yy
			xxx += xx
		}
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a)
		fmt.Fprintf(out, "%s\n", simulation[(a-1+x+y)%(x+y)])
	}
}

func gcd492d(a int, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
