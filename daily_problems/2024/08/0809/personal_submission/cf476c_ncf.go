package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF476C(os.Stdin, os.Stdout) }

func CF476C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var a, b int
	fmt.Fscan(in, &a, &b)
	if b == 1 {
		fmt.Fprintf(out, "0")
		return
	}
	mod := int(1e9) + 7
	ans := 0
	for i := 1; i < b; i++ {
		ans = (ans + ((a+1)*a/2)%mod*b%mod*i + i*a) % mod
	}
	fmt.Fprintf(out, "%d", ans)
}
