package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1196D2(os.Stdin, os.Stdout) }

func CF1196D2(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, k int
	var s string
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &k, &s)
		f := make([][]int, 3)
		for i := 0; i < 3; i++ {
			f[i] = make([]int, n+1)
		}
		ans := n
		ss := "RGB"
		for i := 0; i < n; i++ { // 算出字符串变成RGB子串需要的次数，f[0]、f[1]、f[2]分别代表R、G、B开头的RGB子串
			for j := 0; j < 3; j++ {
				if s[i] != ss[(i+j)%3] {
					f[j][i+1] = f[j][i] + 1
				} else {
					f[j][i+1] = f[j][i]
				}
			}
		}
		for i := 0; i <= n-k; i++ { // 找出长为k的子串变成RGB子串需要的次数
			for j := 0; j < 3; j++ {
				ans = min(ans, f[j][i+k]-f[j][i])
			}
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}
