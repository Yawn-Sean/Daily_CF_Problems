package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1033C(os.Stdin, os.Stdout) }

func CF1033C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		a[i] -= 1
	}

	pos := make([]int, n)
	for i := 0; i < n; i++ {
		pos[a[i]] = i
	}

	dp := make([]bool, n)

	for i := n - 1; i > -1; i -= 1 {
		for j := pos[i] % (i + 1); j < n; j += i + 1 { // 找到同余的位置进行判断
			if a[j] > i && !dp[j] {
				dp[pos[i]] = true
				break
			}
		}
	}
	for i := 0; i < n; i++ {
		if dp[i] {
			fmt.Fprintf(out, "A")
		} else {
			fmt.Fprintf(out, "B")
		}
	}
}
