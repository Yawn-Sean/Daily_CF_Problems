package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() {
	solveD(os.Stdin, os.Stdout)
}

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n, mod int
	fmt.Fscan(in, &n, &mod)

	dp := make([]int, n+1)
	dp[1] = 1
	sum := 1
	facsum := make([]int, n+1)
	for i := 2; i <= n; i++ {
		facsum[i] = (facsum[i] + facsum[i-1] + 1) % mod
		dp[i] = (sum + facsum[i]) % mod
		for j := i * 2; j <= n; j += i {
			facsum[j] = (facsum[j] + dp[i] - dp[i-1] + mod) % mod
		}
		sum = (sum + dp[i]) % mod
	}
	fmt.Fprintln(out, dp[n])
}
