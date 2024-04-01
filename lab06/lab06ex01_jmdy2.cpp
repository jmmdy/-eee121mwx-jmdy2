//Adapted from Mr. Neil Bernardo with some modifications

#include <iostream>
#include <string>
using namespace std;

template <class S>
class DNode {
    private:
        S data;
        DNode<S> *next;
        DNode<S> *prev;
    public:
        DNode(S data, DNode* next = NULL, DNode* prev = NULL);

    template<typename T> friend class DLinkedList;
};

template<typename S>
DNode<S>::DNode(S data, DNode* next,DNode* prev):data(data),next(next),prev(prev) {}

template<class T>
class DLinkedList {
    private:
        DNode<T> *head;
        DNode<T> *tail;
        int size;
    public:
        DLinkedList();
        ~DLinkedList();
        void addFront(T val);
        void addBack(T val);
        void addChoice(T val, int index);
        T removeFront();
        T removeBack();
        void removeChoice(int delindex);
        T front();
        T back();
        int getSize();
};

template<typename T>
DLinkedList<T>::DLinkedList() {
    this->head = new DNode<T>(T(),NULL,NULL);
    this->tail = new DNode<T>(T(),NULL,NULL);
    this->head->next = this->tail;
    this->tail->prev = this->head;
    this->size = 0;
}

template<typename T>
DLinkedList<T>::~DLinkedList() {
    while (this->size > 0)
        this->removeBack();
    delete this->head;
    delete this->tail;
}

template<typename T>
void DLinkedList<T>::addFront(T val) {
    DNode<T> *tmpNode = new DNode<T>(T(val), this->head->next, this->head);
    this->head->next = tmpNode;
    tmpNode->next->prev = tmpNode;
    this->size++;
}

template<typename T>
void DLinkedList<T>::addBack(T val) {
    DNode<T> *tmpNode = new DNode<T>(T(val), this->tail, this->tail->prev);
    this->tail->prev = tmpNode;
    tmpNode->prev->next = tmpNode;
    this->size++;
}


template<typename T>
void DLinkedList<T>::addChoice(T val, int index) {
    DNode<T> *current = head->next;
    for (int i = 0; i < index && current != tail; i++) {
        current = current->next;
    }
    DNode<T> *tmpNode = new DNode<T>(T(val), current, current->prev);
    current->prev->next = tmpNode;
    current->prev = tmpNode;
    this->size++;
}


template<typename T>
T DLinkedList<T>::removeFront() {
    DNode<T>* tmpNode = this->head->next;
    tmpNode->next->prev =  this->head;
    this->head->next = tmpNode->next;
    T tmpVal = tmpNode->data;
    delete tmpNode;
    this->size--;
    return tmpVal;
}

template<typename T>
T DLinkedList<T>::removeBack() {
    DNode<T> *tmpNode = this->tail->prev;
    tmpNode->prev->next = this->tail;
    this->tail-> prev = tmpNode->prev;
    T tmpVal = tmpNode->data;
    delete tmpNode;
    this->size--;
    return tmpVal;
}

template<typename T>
void DLinkedList<T>::removeChoice(int delindex) {
    DNode<T> *current = head->next;
    for (int i = 0; i < delindex && current != tail; i++) {
        current = current->next;
    }
    if (current != tail) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        // T tmpVal = current->data;
        delete current;
        this->size--;
    }
    
}

template<typename T>
T DLinkedList<T>::front() {
    return this->head->next->data;
}

template<typename T>
T DLinkedList<T>::back() {
    return this->tail->prev->data;
}

template<typename T>
int DLinkedList<T>::getSize() {
    return this->size;
}


int main() {
    DLinkedList<std::string> dl;
    int tinput, n, input1, m, val, index, p, delindex;
    cin >> tinput;
    for (int i = 0; i < tinput;) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> input1;
            auto q = std::to_string(input1);
            dl.addBack(q);
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> val;
            cin >> index;
            auto w = std::to_string(val);
            dl.addChoice(w, index);
        }
        cin >> p;
        for (int i = 0; i < p; i++) {
            cin >> delindex;
            auto r = std::to_string(delindex);
            dl.removeChoice(delindex);
        }

        while(dl.getSize()) {
            cout << dl.removeFront() << " ";
        }
        i++;
        cout << '\n';
    }
    
    return 0;
}