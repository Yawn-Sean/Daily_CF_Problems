package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF566F(os.Stdin, os.Stdout) }

func CF566F(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, t int
	fmt.Fscan(in, &n)
	num := make([]int, int(1e6+1))
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &t)
		num[t] += 1
	}
	f := make([]int, int(1e6+1))
	ans := 1
	for i := 1; i < int(1e6+1); i++ {
		f[i] += num[i]
		for j := i; j <= int(1e6); j += i {
			f[j] = max566f(f[j], f[i])
		}
		ans = max566f(ans, f[i])
	}
	fmt.Fprintf(out, "%d\n", ans)
}

func max566f(a, b int) int {
	if a > b {
		return a
	}
	return b
}
