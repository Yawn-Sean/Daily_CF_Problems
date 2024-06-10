package main
 
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)
 
func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
 
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	params := strings.Split(input, " ")
	n, _ := strconv.Atoi(params[0])
	k, _ := strconv.Atoi(params[1])
 
	mp := make(map[int]int)
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	values := strings.Split(input, " ")
 
	for i := 0; i < n; i++ {
		a, _ := strconv.Atoi(values[i])
		for j := 0; j <= k; j++ {
			mp[a*j] = j
		}
	}
 
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	q, _ := strconv.Atoi(input)
 
	for q > 0 {
		q--
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		x, _ := strconv.Atoi(input)
		ans := k + 1
 
		for key, value := range mp {
			if val, exists := mp[x-key]; exists {
				ans = min(ans, val+value)
			}
		}
 
		if ans > k {
			fmt.Fprintln(writer, -1)
		} else {
			fmt.Fprintln(writer, ans)
		}
	}
}
