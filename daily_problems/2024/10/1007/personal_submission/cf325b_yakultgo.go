package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	ok := false
	for i := 0; i < 60; i++ {
		mi := 1 << i
		l, r := 0, min(math.MaxInt32, n/max(1, mi-1))
		for l < r {
			mid := (l + r) >> 1
			if mid*(mid-1)/2+mid*(mi-1) < n {
				l = mid + 1
			} else {
				r = mid
			}
		}
		if l*(l-1)/2+l*(mi-1) == n && l%2 == 1 {
			fmt.Fprintln(out, l*mi)
			ok = true
		}
	}
	if !ok {
		fmt.Fprintln(out, -1)
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
