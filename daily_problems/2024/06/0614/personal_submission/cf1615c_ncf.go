package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1615C(os.Stdin, os.Stdout) }

func CF1615C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n int
	var a, b string
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &a, &b)
		s, sa, sb := 0, 0, 0 // s代表ab对应位置不同数字的数量，sa代表a中1的数量，sb代表b中1的数量
		for i := 0; i < n; i++ {
			if a[i] != b[i] {
				s += 1
			}
			if a[i] == '1' {
				sa += 1
			}
			if b[i] == '1' {
				sb += 1
			}
		}
		ans := int(1e9)
		if sa == sb { // 如果ab中1的数量相等，那么可以通过交换a中01的位置实现，次数为s
			ans = s
		}
		if n-sa+1 == sb { // 先选中a中一个为1的位置进行一次操作，然后再判断两边的1是否相等
			ans = min(ans, n-s)
		}
		if ans == int(1e9) {
			fmt.Fprintf(out, "-1\n")
			continue
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}
