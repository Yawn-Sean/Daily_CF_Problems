package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() {
	solveC(os.Stdin, os.Stdout)
}

func solveC(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	T, s := 0, ""
	for fmt.Fscan(in, &T); T > 0; T-- {
		fmt.Fscan(in, &s)
		n := len(s)
		cntP0 := make([]int, n) // 记录前面连续0的个数
		for i := 1; i < n; i++ {
			if s[i-1] == '0' {
				cntP0[i] = cntP0[i-1] + 1
			}
		}
		ans := 0
		for i := 0; i < n; i++ {
			if s[i] == '1' {
				t := 0
				for j := i; j < min(n, i+18); j++ {
					t = t<<1 + int(s[j]&1)
					if j-i+1+cntP0[i] >= t { // 位数+前面连续0的个数 >= 数字大小
						ans++
					}
				}
			}
		}
		fmt.Fprintln(out, ans)
	}
}
