
LinkedLists: Main.o
	g++ -g Main.o -o LinkedLists

main.o: Main.cpp CyclicLinkedList.h DoublyLinkedList.h SingleNode.h DoubleNode.h
	g++ -g -c main.cpp

clean:
		rm *.o LinkedLists
