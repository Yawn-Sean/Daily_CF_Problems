package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF833A(os.Stdin, os.Stdout) }

func CF833A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, a, b int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &a, &b)
		l, r := 1, int(1e6)
		for l <= r { // 二分找到大于等于ab乘积的三次方根的最小自然数
			mid := (l + r) >> 1
			if mid*mid*mid >= a*b {
				r = mid - 1
			} else {
				l = mid + 1
			}
		}
		if a*b == l*l*l && a%l == 0 && b%l == 0 {
			fmt.Fprintf(out, "Yes\n")
		} else {
			fmt.Fprintf(out, "No\n")
		}
	}
}
