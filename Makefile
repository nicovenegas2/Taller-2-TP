test: Container.o Node.o CpuAssign.o test_cpuAssign.cpp test_container.cpp test_node.cpp
	g++ Node.o Container.o test_container.cpp -o test_container
	g++ Node.o test_node.cpp -o test_node
	g++ Node.o Container.o  CpuAssign.o test_cpuAssign.cpp -o test_cpuAssign

cpuAssign.o: CpuAssign.cpp Container.o
	g++ -c CpuAssign.cpp

Container.o: Node.o Container.cpp
	g++ -c Container.cpp -o Container.o

Node.o: Node.cpp
	g++ -c -o Node.o Node.cpp



runTest:
	./test_container
	./test_node
	./test_cpuAssign
