package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF827A(os.Stdin, os.Stdout) }

func CF827A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k, t int
	var s string
	m := map[int]string{}
	fmt.Fscan(in, &n)
	mx := 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &s, &k)
		for i := 0; i < k; i++ {
			fmt.Fscan(in, &t)
			t -= 1
			s2, exist := m[t]
			if !exist || len(s2) < len(s) {
				m[t] = s
			}
		}
		mx = max827a(mx, t+len(s))
	}
	arr := make([]uint8, mx)
	r := 0
	for i := 0; i < mx && r < mx; i++ {
		s2, exist := m[i]
		if exist && i+len(s2) > r {
			for ; r < i; r++ {
				arr[r] = 97
			}
			for ; r < mx && r < i+len(s2); r++ {
				arr[r] = s2[r-i]
			}
		}
	}
	fmt.Fprintf(out, "%s", string(arr))
}

func max827a(a, b int) int {
	if a > b {
		return a
	}
	return b
}
