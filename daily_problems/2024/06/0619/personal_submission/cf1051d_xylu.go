package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { solveD(os.Stdin, os.Stdout) }

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	const mod int = 998244353
	var n, k int
	fmt.Fscan(in, &n, &k)
	if k == 1 {
		fmt.Fprintln(out, 2)
		return
	}

	dp := make([][4]int, k+1)
	dp[1] = [4]int{1, 0, 0, 1}
	dp[2] = [4]int{0, 1, 1, 0}

	for i := 1; i < n; i++ {
		v := make([][4]int, k+1)
		for j := 1; j <= k; j++ {
			v[j][0] = (dp[j][0] + dp[j][1] + dp[j][2] + dp[j-1][3]) % mod
			v[j][1] = (dp[j-1][0] + dp[j][1] + dp[j-1][3]) % mod
			v[j][2] = (dp[j-1][0] + dp[j][2] + dp[j-1][3]) % mod
			v[j][3] = (dp[j-1][0] + dp[j][1] + dp[j][2] + dp[j][3]) % mod
			if j > 1 {
				v[j][1] = (v[j][1] + dp[j-2][2]) % mod
				v[j][2] = (v[j][2] + dp[j-2][1]) % mod
			}
		}
		dp = v
	}

	ans := (dp[k][0] + dp[k][1] + dp[k][2] + dp[k][3]) % mod
	fmt.Fprintln(out, ans)
}
