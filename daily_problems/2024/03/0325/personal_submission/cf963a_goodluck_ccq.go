package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = int(1e9) + 9

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, a, b, k int
	var s string
	fmt.Fscan(in, &n, &a, &b, &k, &s)

	// a^(n-i)*b^i a^(n-i)*b^i(b/a)^k  a^(n-i)*b^i*(b/a)^(2*k)
	// a1*(q^n - 1)/(q - 1)
	// q (b/a)^k
	sum := 0
	for i := 0; i < k; i++ {
		c := 1
		if s[i] == '-' {
			c = mod - 1
		}
		a1 := c * pow(a, n-i) % mod * pow(b, i) % mod
		q := pow(b*inv(a)%mod, k)

		cnt := (n + 1) / k
		if q == 1 {
			sum += a1 * cnt % mod
			sum %= mod
		} else {
			sum += a1 * (pow(q, cnt) - 1) % mod * inv(q-1) % mod
			sum %= mod
		}
	}
	fmt.Fprintln(out, sum)
}

func pow(x, n int) int {
	res := 1
	for ; n > 0; n /= 2 {
		if n%2 > 0 {
			res = res * x % mod
		}
		x = x * x % mod
	}
	return res
}

func inv(x int) int {
	return pow(x, mod-2)
}
