//Adapted from Mr. Neil Bernardo with some modifications

#include <iostream>
#include <string>
using namespace std;

#define E_ILLEGAL 420
#define DEBUG_MODE 0
#define USER_MODE 1

const unsigned int MODE = USER_MODE;

template <class S>
class Node {
    private:
        S data;
        Node<S> *next;
    public:
        Node(S data, Node* next = nullptr);

    template<typename T> friend class LinkedList;
};

template <typename S>
Node<S>::Node(S data, Node* next) : data(data), next(next) {
    if (!MODE)
        std::cout << "Debug mode: Node Constructor invoked for data: " << this->data << '\n';
}

template <class T>
class LinkedList {
    private:
        Node<T> *head;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        void insertData(T val, int pos = 0);
        void deleteNode(int pos = 0);
        T getValue(int pos = 0);
        void printList(void);
        int getSize(void);
};

template<typename T>
LinkedList<T>::LinkedList() {
    if (!MODE)
        std::cout << "Debug mode: Linked List Constructor invoked" << '\n';
    this->head = new Node<T>(T(), nullptr); //data of head will never be accessed
    this->size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    if (!MODE)
        std::cout << "Debug mode: Linked List Destructor invoked" << '\n';
    while (this->size > 0)
        this->deleteNode();
    delete this->head;
}

template<typename T>
void LinkedList<T>::insertData(T val, int pos) {
    Node<T> *curr = this->head;

    if(pos > this->size || pos < 0) {
        std::cout << "Error: Invalid insertion" << '\n';
        return;
    }

    while(pos) {
        curr = curr->next;
        pos--;
    }

    Node<T> *tmpNode = new Node<T>(val);

    if(curr->next != NULL) {
        tmpNode->next = curr->next;
    }
    curr->next = tmpNode;

    (this->size)++;
}

template<typename T>
void LinkedList<T>::deleteNode(int pos) {

    if(this->getSize() == 0 || this->getSize() < pos) {
        std::cout << "Error: Invalid deletion" << '\n';
        return;
    }

    Node<T> *curr = this->head->next;
    Node<T> *prev = this->head;

    while(pos--) {
        curr = curr->next;
        prev = prev->next;
    }

    prev->next = curr->next;
    delete curr;
    (this->size)--;
}


template<typename T>
T LinkedList<T>::getValue(int pos) {
    Node<T> *curr = this->head->next;

    if(pos > this->size || pos < 0) {
        std::cout << "Error: Invalid data retrieval" << '\n';
        return -E_ILLEGAL;
    }

    while(pos--)
        curr = curr->next;

    return curr->data;
}

template<typename T>
void LinkedList<T>::printList() {
    Node<T> *curr = this->head->next;

    if (this->size == 0)
        std::cout << "List is empty";

    for (int ctr = 0; ctr < this->size; ++ctr) {
        if (ctr == 0)
            std::cout << curr->data;
        else
            std::cout << " " << curr->data;
        curr = curr->next;
    }
    std::cout << std::endl;
}

template<typename T>
int LinkedList<T>::getSize() {
    return this->size;
}

int main()
{
    LinkedList<int> list;
    int tinput, n, input1, m, inputdel, counter;
    
    cin >> tinput;
    for (int i = 0; i < tinput;) {
        // list.printList();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> input1;
            list.insertData(input1);
        }
        // list.printList();
        cin >> m;
        int a[m];
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            // list.deleteNode(inputdel);
        }
        for(int i=0; i<m; i++) {
            for(int j=i+1; j<m; j++) { 
                if(a[i]>a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        counter = 0;
        inputdel = 0;
        for (int i = 0; i < m; i++) {
            inputdel = a[i];
            list.deleteNode(inputdel-counter);
            counter++;
        }
        list.printList();
        fill_n(a, m, 0);
        while(list.getSize()) {list.deleteNode();}     
    }
    
    
    return 0;
}