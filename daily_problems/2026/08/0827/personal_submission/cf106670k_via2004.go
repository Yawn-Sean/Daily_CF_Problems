package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var t int
	fmt.Fscan(in, &t)
	for t != 0 {
		var n int
		fmt.Fscan(in, &n)
		a, b := make([]int, n), make([]int, n)
		sum1, sum2 := 0, 0
		for i := range n {
			fmt.Fscan(in, &a[i])
			sum1 += a[i]
		}

		for i := range n {
			fmt.Fscan(in, &b[i])
			sum2 += b[i]
		}

		res := min(a[0]+b[n-1], b[0]+a[n-1], sum1, sum2)
		for i := 1; i < n; i++ {
			res = min(res, a[0]+b[i]+a[n-1])
			res = min(res, b[0]+a[i]+b[n-1])
		}

		fmt.Fprintln(out, res)
		t--
	}
}

func main() {
	in := bufio.NewReaderSize(os.Stdin, 1<<20)
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	solve(in, out)
}
