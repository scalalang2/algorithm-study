package main

import "fmt"
import "bufio"
import "os"

var N, top int
var stack []int

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &N)
	stack = make([]int, N) // N만큼의 배열을 만든다.
	top = 0                // top은 0으로 초기화 한다.

	for i := 0; i < N; i++ {
		var tmp int
		fmt.Fscan(reader, &tmp)

		if tmp == 0 {
			stack[top-1] = 0
			top--
		} else {
			stack[top] = tmp
			top++
		}
	}

	sum := 0
	for k := 0; k < top; k++ {
		sum += stack[k]
	}
	fmt.Println(sum)
}
