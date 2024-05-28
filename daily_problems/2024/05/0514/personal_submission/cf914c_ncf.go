package main

import (
	"bufio"
	"fmt"
	"io"
	"math/bits"
	"os"
)

func main() { CF914C(os.Stdin, os.Stdout) }

func CF914C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var s string
	var k int
	fmt.Fscan(in, &s, &k)

	if k == 0 {
		fmt.Fprintf(out, "1")
	} else if k == 1 {
		fmt.Fprintf(out, "%d", len(s)-1)
	} else {
		mod := int(1e9 + 7)
		ops := make([]int, 1001)
		for i := 2; i < 1001; i++ {
			ops[i] = ops[bits.OnesCount(uint(i))] + 1
		}

		m := len(s)
		memo := make([][1001]int, m)
		for i := range memo {
			for j := range memo[i] {
				memo[i][j] = -1 // -1 表示没有计算过
			}
		}
		var f func(int, int, bool, bool) int
		f = func(i, mask int, isLimit, isNum bool) (res int) {
			if i == m {
				if isNum && ops[mask] == k-1 {
					return 1 // 得到了一个合法数字
				}
				return
			}
			if !isLimit && isNum {
				p := &memo[i][mask]
				if *p >= 0 {
					return *p
				}
				defer func() { *p = res }()
			}
			if !isNum { // 可以跳过当前数位
				res = (res + f(i+1, mask, false, false)) % mod
			}
			d := 0
			if !isNum {
				d = 1 // 如果前面没有填数字，必须从 1 开始（因为不能有前导零）
			}
			up := 1
			if isLimit {
				up = int(s[i] - '0') // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
			}
			for ; d <= up; d++ { // 枚举要填入的数字 d
				res = (res + f(i+1, mask+d, isLimit && d == up, true)) % mod
			}
			return
		}
		fmt.Fprintf(out, "%d\n", f(0, 0, true, false))
	}
}
