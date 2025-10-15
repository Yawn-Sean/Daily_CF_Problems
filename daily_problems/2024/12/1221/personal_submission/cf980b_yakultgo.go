package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k int
	fmt.Fscan(in, &n, &k)
	fmt.Fprintln(out, "YES")

	ans := make([][]byte, 4)
	for i := 0; i < 4; i++ {
		ans[i] = make([]byte, n)
		for j := 0; j < n; j++ {
			ans[i][j] = '.'
		}
	}

	if k%2 == 0 {
		for i := 1; i <= k/2; i++ {
			ans[1][i] = '#'
			ans[2][i] = '#'
		}
	} else {
		ans[1][n/2] = '#'
		k--
		for i := 1; i <= 2; i++ {
			if k == 0 {
				break
			}
			for j := 1; j < n/2; j++ {
				ans[i][j] = '#'
				ans[i][n-1-j] = '#'
				k -= 2
				if k == 0 {
					break
				}
			}
		}
	}

	for i := 0; i < 4; i++ {
		for j := 0; j < n; j++ {
			fmt.Fprint(out, string(ans[i][j]))
		}
		fmt.Fprintln(out)
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
