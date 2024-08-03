package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1468F(os.Stdin, os.Stdout) }

func CF1468F(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, x, y, u, v int
	fmt.Fscan(in, &t)
	type pair struct {
		val1, val2 int
	}
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n)
		ans := 0
		m := map[pair]int{}
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &x, &y, &u, &v)
			val1, val2 := u-x, v-y
			g := gcd1468f(abs1468b(val1), abs1468b(val2))
			val1, val2 = val1/g, val2/g
			ans += m[pair{-val1, -val2}]
			m[pair{val1, val2}] = m[pair{val1, val2}] + 1
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}

func abs1468b(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func gcd1468f(a int, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
