package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1095D(os.Stdin, os.Stdout) }

func CF1095D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	nx := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		nx[i] = make([]int, 2)
		fmt.Fscan(in, &nx[i][0], &nx[i][1])
	}
	if n == 3 {
		fmt.Fprintf(out, "1 2 3")
		return
	}
	next := 1
	for i := 0; i < n; i++ {
		fmt.Fprintf(out, "%d ", next)
		if nx[nx[next][0]][0] == nx[next][1] || nx[nx[next][0]][1] == nx[next][1] {
			next = nx[next][0]
		} else {
			next = nx[next][1]
		}
	}
}
