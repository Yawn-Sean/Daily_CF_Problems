package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1321C(os.Stdin, os.Stdout) }

func CF1321C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	var s string
	fmt.Fscan(in, &n, &s)
	var check func(str string) int
	check = func(str string) int {
		k := len(s)
		idx := -1
		for i := 0; i < k; i++ {
			if ((i > 0 && s[i]-s[i-1] == 1) || (i < k-1 && s[i]-s[i+1] == 1)) && (idx == -1 || s[i] > s[idx]) { // 找到最大且最左的能删除的字母下标
				idx = i
			}
		}
		return idx
	}

	ans := 0
	for true {
		idx := check(s)
		if idx == -1 {
			break
		}
		s = s[:idx] + s[idx+1:]
		ans += 1
	}
	fmt.Fprintf(out, "%d\n", ans)
}
