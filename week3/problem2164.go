package main

import (
	"bufio"
	"fmt"
	"os"
)

var queue []int

func enqueue(val int) {
	queue = append(queue, val)
}

func dequeue() int {
	tmp := queue[0]
	queue = queue[1:]
	return tmp
}

func main() {
	var N int

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d", &N)

	for i := 0; i < N; i++ {
		enqueue(i+1)
	}

	for len(queue) >= 2 {
		dequeue()
		tmp := dequeue()
		enqueue(tmp)
	}

	fmt.Println(queue[0])
}