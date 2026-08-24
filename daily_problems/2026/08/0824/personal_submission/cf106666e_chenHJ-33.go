package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	mod := 1000000007
	f := make([]int64, n+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		v := 1
		for v <= i {
			f[i] = (f[i] + f[i-v]) % int64(mod)
			v <<= 1
		}
	}
	fmt.Println(f[n] * 2 % int64(mod))
}
