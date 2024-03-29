package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1045i(os.Stdin, os.Stdout) }

func CF1045i(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n int
	t = 1
	var s string
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n)
		m := map[int]int{}
		ans := 0
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &s)
			cur := 0
			for _, e := range s {
				cur ^= 1 << (e - 97)
			}
			for j := 0; j < 26; j++ {
				ans += m[cur^(1<<j)]
			}
			ans += m[cur]
			m[cur] += 1
		}
		fmt.Fprintf(out, "%d ", ans)
	}
}
