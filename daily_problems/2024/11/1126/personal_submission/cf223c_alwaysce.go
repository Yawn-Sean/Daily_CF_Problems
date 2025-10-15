package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func powM(x, n, p int64) (res int64) {
	x %= p
	res = int64(1) % p
	for ; n > 0; n /= 2 {
		if n%2 > 0 {
			res = res * x % p
		}
		x = x * x % p
	}
	return
}

func cf223C(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*
		考虑每个元素出现的次数(权重

		C(x,y) = C(x-1,y) + C(x,y-1)
		总共有k行
		因此对于j位置的元素, 它的左边i位置过来总共有的贡献就是
		C(k+j-i, j-i) = (k+j-i)(k+j-i-1)...(k+1) * inv((j-i)!)
		C(k+x,x) = (k+x)(k+x-1)...(k+1)/x!
		C(k+x-1,x-1) = (k+x-1)...(k+1) / (x-1)!
		*(k+x)/x
	*/

	var n, k int64
	fmt.Fscan(in, &n, &k)

	nums := make([]int64, n)
	for i := range nums {
		fmt.Fscan(in, &nums[i])
	}
	mod := int64(1_000_000_007)

	fac := make([]int64, n+1)
	fac[0] = 1
	for i := int64(1); i <= n; i++ {
		fac[i] = fac[i-1] * i % mod
	}

	inv_fac := make([]int64, n+1)
	inv_fac[n] = powM(fac[n], mod-2, mod)

	for i := n; i > 0; i-- {
		inv_fac[i-1] = inv_fac[i] * i % mod
	}

	comb := make([]int64, n)
	comb[0] = 1
	for i := int64(1); i < n; i++ {
		comb[i] = comb[i-1] * (k + i - 1) % mod * fac[i-1] % mod * inv_fac[i] % mod
	}

	ans := make([]int64, n)
	for i := int64(0); i < n; i++ {
		for j := i; j < n; j++ {
			ans[j] = (ans[j] + nums[i]*comb[j-i]%mod) % mod
		}
	}
	for i := int64(0); i < n; i++ {
		fmt.Fprintf(out, "%d ", ans[i])
	}
}

func main() {
	cf223C(bufio.NewReader(os.Stdin), os.Stdout)
}
