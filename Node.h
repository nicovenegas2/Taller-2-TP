

class Node
{
private:
    /* estructura que contiene una lista de solucion, un costo y una lista de posibles soluciones 
    Tambien permita el enlace de nodos de manera bidireccional
    */
public:
    Node();
    Node(int size, int cost, Node *prev, Node *next);
    Node(int size);
    Node(Node *node);
    Node(Node *node, int toMark);
    ~Node();
    int *getData();
    int getCost();
    void setCost(int cost);
    void setPrev(Node *prev);
    void setNext(Node *next);
    Node *getPrev();
    Node *getNext();
    void clear();
    void markAvailable(int index);
    int getAvailablePointer();
    int *getAvailables();
    void printData();
    void changeData(int data, int index);
    void printAvailable();
    void unmarkAvailable();
    void markWait();

private:
    int *array;
    int cost;
    Node *prev;
    Node *next;
    int size;
    int *availables;
    int availablePointer;
    int toMark;


};