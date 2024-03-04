package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF584B(os.Stdin, os.Stdout) }

func CF584B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	mod := int(1e9 + 7)
	fmt.Fprintf(out, "%d ", (pow(3, 3*n, mod)+mod-pow(7, n, mod))%mod)
}

func pow(x, n, mod int) int {
	result := 1
	base := x

	for n > 0 {
		if n&1 == 1 { // 当n的最低位为1时，进行一次乘法
			result *= base
			if mod != 0 {
				result %= mod
			}
		}
		base *= base // 不管n的最低位是否为1，都要左移一位进行下一次迭代
		if mod != 0 {
			base %= mod
		}
		n >>= 1
	}

	return result
}
