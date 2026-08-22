package main

import "fmt"

func main() {
	var n int
	var x, k int64
	mod := int64(1000000007)
	fmt.Scan(&n, &x, &k)
	arr := make([]int, n)
	for i := range n {
		fmt.Scan(&arr[i])
	}
	if k != 0 {
		total := (int64(n) - 1) * pow(2, k, mod) % mod
		fmt.Println((mod + total + 1 - total*pow(x, mod-2, mod)%mod) % mod)
	} else {
		sum := 1
		for i := 1; i < n; i++ {
			if arr[i] != arr[i-1] {
				sum++
			}
		}
		fmt.Println(sum)
	}
}
func pow(a, b int64, mod int64) int64 {
	ans := int64(1)
	a %= mod
	for b != 0 {
		if b&1 == 1 {
			ans = ans * a % mod
		}
		a = a * a % mod
		b >>= 1
	}
	return ans
}
