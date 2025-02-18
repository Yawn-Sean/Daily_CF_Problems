package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k int
	fmt.Fscan(in, &k, &n)
	if k > n*(n-1) {
		fmt.Fprintln(out, "NO")
		return
	}
	fmt.Fprintln(out, "YES")
	for i := 1; i <= n && k > 0; i++ {
		for j := i + 1; j <= n && k > 0; j++ {
			if k >= 2 {
				fmt.Fprintln(out, i, j)
				fmt.Fprintln(out, j, i)
				k -= 2
			} else {
				fmt.Fprintln(out, i, j)
				k -= 1
			}
		}
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
