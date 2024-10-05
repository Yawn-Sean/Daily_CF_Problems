	package main

	import (
		"bufio"
		"fmt"
		"os"
	)

	func solve(in *bufio.Reader, out *bufio.Writer) {
		var n, k int
		fmt.Fscan(in, &n, &k)
		for i := 1; i <= k; i++ {
			if n%i != i-1 {
				fmt.Fprintln(out, "No")
				return
			}
		}
		fmt.Fprintln(out, "Yes")
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
