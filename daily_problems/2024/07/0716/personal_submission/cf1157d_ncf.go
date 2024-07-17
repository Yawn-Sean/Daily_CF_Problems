package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1157D(os.Stdin, os.Stdout) }

func CF1157D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int
	fmt.Fscan(in, &n, &k)
	var start int
	if k >= 30 {
		start = 1
		if k*(k+1)/2 > n {
			fmt.Fprintf(out, "NO")
			return
		}
	} else {
		mx := pow(2, k, 0) - 1
		v := (n + mx - 1) / mx
		if k*(k+2*v-1)/2 > n {
			fmt.Fprintf(out, "NO")
			return
		}
		start = v
	}
	ans := make([]int, k)
	sm := 0
	for i := 0; i < k; i++ {
		ans[i] = start + i
		sm += ans[i]
	}
	n -= sm
	for i := max(k-31, 1); i < k; i++ {
		v := pow(2, k-i, 0) - 1
		l, r := 0, ans[i-1]*2-ans[i]
		for l <= r {
			mid := (l + r) / 2
			if mid*v > n {
				r = mid - 1
			} else {
				l = mid + 1
			}
		}
		l -= 1
		for j := 0; j < k-i; j++ {
			ans[i+j] += (1 << j) * l
		}
		n -= l * v
	}

	fmt.Fprintf(out, "YES\n")
	for i := 0; i < k; i++ {
		fmt.Fprintf(out, "%d ", ans[i])
	}
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
