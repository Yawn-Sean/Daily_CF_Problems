package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solveC(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	const mod int = 1e9 + 7
	var T, n, k int
	for fmt.Fscan(in, &T); T > 0; T-- {
		fmt.Fscan(in, &n, &k)
		ans := 1
		// 经过第 i 层，消耗能量为 j 的粒子数
		dp := make([][]int, n)
		for i := range dp {
			dp[i] = make([]int, k)
			dp[i][0] = 1
		}
		for j := 1; j < k; j++ {
			pre := 0
			if j&1 == 1 {
				for i := n - 1; i >= 0; i-- {
					// 前面反弹过来的
					dp[i][j] = pre
					// 消耗能量为 j-1 的粒子在这一层反弹
					pre = (pre + dp[i][j-1]) % mod
				}
			} else {
				for i := 0; i < n; i++ {
					dp[i][j] = pre
					pre = (pre + dp[i][j-1]) % mod
				}
			}
			ans = (ans + pre) % mod
		}
		fmt.Fprintln(out, ans)
	}
}

func main() {
	solveC(os.Stdin, os.Stdout)
}
