package main

import (
	"bufio"
	"fmt"
	"io"
	"math/bits"
	"os"
)

func cf215E(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*
		本来以为是一个数位dp 后来发现可以直接暴力枚举循环节
		然后计数去重
	*/

	var l, r int64
	fmt.Fscan(in, &l, &r)

	var f func(int64) int64
	f = func(x int64) int64 {
		// get bitwise length of x
		k := bits.Len64(uint64(x))
		ans := make([]int64, k+1)
		for l := 1; l < k; l++ {
			for d := 1; d < l; d++ {
				if l%d == 0 {
					ans[l/d] += int64(1) << (d - 1)
				}
			}
		}

		for d := 1; d < k; d++ {
			if k%d == 0 {
				msk := int64(0)
				for j := 0; j < k; j += d {
					msk |= int64(1) << j
				}
				ans[k/d] += max(int64(0), x/msk-(1<<(d-1))+1)
			}
		}

		res := int64(0)
		for i := k; i > 1; i-- {
			for j := 2 * i; j <= k; j += i {
				ans[i] -= ans[j]
			}
			res += ans[i]
		}
		//fmt.Fprintln(out, ans)
		return res

	}

	fmt.Fprintln(out, f(r)-f(l-1))
}

// func main() {
// 	cf215E(bufio.NewReader(os.Stdin), os.Stdout)
// }
