package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { solveC(os.Stdin, os.Stdout) }

func solveC(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n, k, a, q, x int
	fmt.Fscan(in, &n, &k)
	mp := map[int]int{}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a)
		for j := 0; j <= k; j++ {
			mp[j*a] = j
		}
	}
	for fmt.Fscan(in, &q); q > 0; q-- {
		fmt.Fscan(in, &x)
		ans := k + 1
		for v, a := range mp {
			if t, ok := mp[x-v]; ok {
				ans = min(ans, t+a)
			}
		}
		if ans > k {
			ans = -1
		}
		fmt.Fprintln(out, ans)
	}
}
