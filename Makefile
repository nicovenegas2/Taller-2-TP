test: test_container.cpp test_node.cpp
	g++ Node.o Container.o test_container.cpp -o test_container
	g++ Node.o test_node.cpp -o test_node

Container.o: Node.o Container.cpp
	g++ -c Node.o Container.cpp -o Container.o

Node.o: Node.cpp
	g++ -c -o Node.o Node.cpp


runTest:
	./test_container
	./test_node
