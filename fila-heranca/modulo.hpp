using namespace std;

typedef int Data;

typedef struct Node
{
	int info; // dado armazenado no nó
	struct Node *next;	// ponteiro para o próximo nó
} Node;

class List
{
private:
    Node *first;
    Node *last;
    int length;
public:
    List();
    ~List();
    int len();
    bool empty();
    void print();
    bool pushFront(Data data);
    bool pushBack(Data data);
    bool popFront();
    bool popBack();
    bool search(Data data);
    Data at(int pos);
};

class Queue : protected List
{
private:

public:
    Queue();
    ~Queue();
    int size();
    bool insert(Data data);
    bool remove();
    bool emptyQueue();
    void printQueue();
    Data getFirst();
    Data getLast();
};
