package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() { CF1267J(os.Stdin, os.Stdout) }

func CF1267J(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, c int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n)
		m := map[int]int{}
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &c)
			m[c] += 1
		}
		mn := math.MaxInt
		for _, v := range m {
			mn = min(mn, v)
		}
		mn += 1
	out:
		for i := mn; i > 0; i-- {
			count := 0
			for _, v := range m {
				if v%i == 0 {
					count += v / i
				} else if v%(i-1) < v/(i-1) {
					count += v/i + 1
				} else {
					continue out
				}
			}
			fmt.Fprintf(out, "%d\n", count)
			break
		}
	}
}
