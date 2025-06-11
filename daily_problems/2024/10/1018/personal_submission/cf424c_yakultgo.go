package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, x int
	fmt.Fscan(in, &n)
	ans := 0
	pre := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &x)
		ans ^= x
		pre[i] = pre[i-1] ^ i
		k, p := n/i, n%i
		if k%2 == 1 {
			ans ^= pre[i-1]
		}
		ans ^= pre[p]
	}
	fmt.Fprintln(out, ans)
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
