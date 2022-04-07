

class Node
{
private:
    /* data */
public:
    Node();
    Node(int size, int cost, Node *prev, Node *next);
    Node(int size);
    Node(Node *node);
    ~Node();
    int *getData();
    int getCost();
    void setCost(int cost);
    void setPrev(Node *prev);
    void setNext(Node *next);
    Node *getPrev();
    Node *getNext();


private:
    int *array;
    int cost;
    Node *prev;
    Node *next;
    int size;


};