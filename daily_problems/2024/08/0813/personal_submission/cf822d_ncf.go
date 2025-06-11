package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF822D(os.Stdin, os.Stdout) }

func CF822D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, l, r int
	fmt.Fscan(in, &t, &l, &r)
	mod := int(1e9 + 7)
	fac := make([]int, r+1)
	for i := 2; i <= r; i++ {
		if fac[i] == 0 {
			for j := i << 1; j <= r; j += i {
				if fac[j] == 0 {
					fac[j] = i
				}
			}
		}
	}
	ans := 0
	cur := 1
	for i := l; i <= r; i++ {
		v := 0
		j := i
		for j > 1 {
			if fac[j] == 0 {
				v += j * (j - 1) / 2
				break
			}
			v += j * (fac[j] - 1) / 2
			j /= fac[j]
		}
		ans = (ans + cur*(v%mod)) % mod
		cur = (cur * t) % mod
	}

	fmt.Fprintf(out, "%d\n", ans)
}
