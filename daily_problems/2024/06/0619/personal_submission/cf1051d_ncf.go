package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1051D(os.Stdin, os.Stdout) }

func CF1051D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int
	fmt.Fscan(in, &n, &k)
	if k == 1 {
		fmt.Fprintf(out, "2")
		return
	}
	f := make([][]int, k+1)
	for i := 0; i <= k; i++ {
		// [ww, bb, wb, bw]
		//f[j][0] = (f[j][0] + f[j-1][1] + f[j][2] + f[j][3])%mod
		//f[j][1] = (f[j-1][0] + f[j][1] + f[j][2] + f[j][3])%mod
		//f[j][2] = (f[j-1][0] + f[j-1][1] + f[j][2] + f[j-2][3])%mod
		//f[j][3] = (f[j-1][0] + f[j-1][1] + f[j-2][2] + f[j][3])%mod
		f[i] = make([]int, 4)
	}
	mod := 998244353
	f[1][0], f[1][1], f[2][2], f[2][3] = 1, 1, 1, 1
	for i := 1; i < n; i++ {
		for j := k; j >= 2; j-- {
			f[j][0] = (f[j][0] + f[j-1][1] + f[j][2] + f[j][3]) % mod
			f[j][1] = (f[j-1][0] + f[j][1] + f[j][2] + f[j][3]) % mod
			f[j][2] = (f[j-1][0] + f[j-1][1] + f[j][2] + f[j-2][3]) % mod
			f[j][3] = (f[j-1][0] + f[j-1][1] + f[j-2][2] + f[j][3]) % mod
		}
	}

	fmt.Fprintf(out, "%d", (f[k][0]+f[k][1]+f[k][2]+f[k][3])%mod)
}
