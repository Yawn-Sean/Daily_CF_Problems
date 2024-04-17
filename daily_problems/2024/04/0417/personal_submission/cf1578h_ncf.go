package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1578H(os.Stdin, os.Stdout) }

func CF1578H(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var s string
	fmt.Fscan(in, &s)

	var order func(l, r int) int
	order = func(l, r int) int {
		if l+1 == r {
			return 0
		}
		count := 0
		for i := l; i <= r; i++ {
			if s[i] == '(' {
				count += 1
			} else if s[i] == ')' {
				count -= 1
			}
			if count == 0 && s[i] == '-' {
				return max1578h(order(l, i-1)+1, order(i+2, r))
			}
		}
		return order(l+1, r-1)
	}

	fmt.Fprintf(out, "%d\n", order(0, len(s)-1))
}

func max1578h(a, b int) int {
	if a > b {
		return a
	}
	return b
}
