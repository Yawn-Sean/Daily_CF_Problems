package main

import (
	"bufio"
	"fmt"
	"io"
	"math/bits"
)

func cf288C(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*
			长度为n+1的排列 从0到n
			0^p[0] + 1^p[1] + 2^p[2] + ...
		n=1 0^1+1^0
		n=2 0^0+1^2+2^1
		n=3 0^3+1^2+2^1+3^0
		n=4 0^0+1^2+2^1+3^4+4^3
		看起来就是尽量让二进制位1相等的不要异或到一起
		每一个二进制位单独考虑
	*/

	var n int
	fmt.Fscan(in, &n)
	ans := int64(0)
	result := make([]int, n+1)
	for i := range result {
		result[i] = -1
	}
	for i := n; i >= 0; i-- {
		if result[i] != -1 {
			continue
		}
		k := bits.Len(uint(i))
		ii := i ^ ((1 << k) - 1)
		result[ii] = i
		result[i] = ii
		ans += int64(2) * (int64(i) ^ int64(ii))
	}
	fmt.Fprintln(out, ans)

	for i := 0; i <= n; i++ {
		fmt.Fprintf(out, "%d ", result[i])
	}
}

//func main() {
//	cf288C(bufio.NewReader(os.Stdin), os.Stdout)
//}
