package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n, k int
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	fmt.Fscan(in, &n, &k)
	var s string
	fmt.Fscan(in, &s)
	ans := 0
	for x := range s {
		ans = (ans*2 + int(s[x]-'0')) % 3
	}
	if ans == 0 || n%2 == 1 {
		fmt.Fprintln(out, "JULIA")
	} else {
		fmt.Fprintln(out, "GIOVANA")
	}

}
