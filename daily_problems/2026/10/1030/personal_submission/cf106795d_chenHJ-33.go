package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var n int
	var s string
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &s)
	ok := false
	for i := 1; i < n; i++ {
		if s[i] == s[i-1] {
			ok = true
			break
		}
	}
	if !ok {
		fmt.Fprintln(out, n)
		return
	}
	cnt := 0
	for i := range s {
		if s[i] == 'V' {
			cnt++
		} else {
			cnt += 2
		}
		cnt %= 3
	}
	if cnt == 0 {
		fmt.Fprintln(out, 2)
	} else {
		fmt.Fprintln(out, 1)
	}

}
