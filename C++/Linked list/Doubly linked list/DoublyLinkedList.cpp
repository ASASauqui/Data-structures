#include <iostream>
using namespace std;

class DoublyLinkedList{
public:
            class Node{
                  public:
                    int data;
                    Node* next;
                    Node* prev;

                    Node(int data){
                        cout<<"  Node("<<data<<")"<<endl;
                        this->data = data;
                        this->next = nullptr;
                        this->prev = nullptr;
                    }
                    ~Node(){
                        cout<<"  ~Node("<<data<<")"<<endl;
                    }
                    friend ostream& operator<<(ostream& output,const Node& n){
                        output<< "(prev:" << n.prev << " node:" << &n << " data:"<< n.data <<" next:"<< n.next <<")";
                        return output;
                    }
            };

    DoublyLinkedList::Node* first;
    DoublyLinkedList::Node* last;
    DoublyLinkedList(){
        first = nullptr;
        last = nullptr;
        cout<<"  DoublyLinkedList()"<<endl;
    }
    ~DoublyLinkedList(){
        cout<<"  ~DoublyLinkedList()"<<endl;
        if( first == nullptr )
            return;
        DoublyLinkedList::Node* aux = first;
        DoublyLinkedList::Node* aux2 = aux->next;
        while( aux != nullptr){
            delete aux;
            aux = aux2;
            if( aux2 != nullptr ) aux2 = aux2->next;
        }
    }
    void push_front(int data){
        DoublyLinkedList::Node* n = new Node(data);
        if(first == nullptr){
            first = n;
            last = n;
        }
        else{
            n->next = first;
            first->prev = n;
            first = n;
        }
    }
    void push_back(int data){
        DoublyLinkedList::Node* n = new Node(data);
        if(first == nullptr){
            first = n;
            last = n;
        }
        else{
            n->prev = last;
            last->next = n;
            last = n;
        }
    }

    void pop_front(){
        if(first == nullptr){
            return;
        }
        DoublyLinkedList::Node* aux = first;
        if(first == last){
            first = nullptr;
            last = nullptr;
            delete aux;
            return;
        }
        first->next->prev = nullptr;
        first = first->next;
        delete aux;
    }

    void pop_back(){
        if(last == nullptr){
            return;
        }
        DoublyLinkedList::Node* aux = last;
        if(first == last){
            first = nullptr;
            last = nullptr;
            delete aux;
            return;
        }
        last->prev->next = nullptr;
        last = last->prev;
        delete aux;
    }

    void remove(int data){
        if( first == nullptr ) return;
        if( first->data == data){
            DoublyLinkedList::Node* ndelete = first;
            if(first == last){
                first = nullptr;
                last = nullptr;
                delete ndelete;
                return;
            }
            first = first->next;
            first->prev = nullptr;
            delete ndelete;
            return;
        }
        else{
            DoublyLinkedList::Node* aux = first;
            while( aux!=nullptr && aux->next!=nullptr && aux->next->data != data ){
                aux = aux->next;
            }
            if( (aux->next != nullptr) && (aux->next == last) && (aux->next->data == data) ){
                DoublyLinkedList::Node* ndelete = aux->next;
                last = aux;
                aux->next = nullptr;
                delete ndelete;
                return;
            }
            if( aux->next!=nullptr && aux->next->data == data  ){
                DoublyLinkedList::Node* ndelete = aux->next;
                aux->next = aux->next->next;
                aux->next->prev = aux; //HOLAAAAAAAAAAAAAAAAAAAAAAAA
                delete ndelete;
            }
        }
    }

    void print_reverse(){
        if(last == nullptr){
            cout << "[]";
            return;
        }
        else{
            DoublyLinkedList::Node* aux = last;
            cout << "[";
            while(aux != nullptr){
                cout << *(aux);
                aux = aux->prev;
            }
            cout << "]" << endl;
        }
        return;
    }

    friend ostream& operator<<(ostream& output,const DoublyLinkedList& l){
        output<< "[";
        if( l.first != nullptr){
            DoublyLinkedList::Node* aux = l.first;
            while( aux != NULL){
                output<< (*aux);
                aux = aux->next;
            }
        }
        output<< "]";
        return output;
    }
};

int main(){
    DoublyLinkedList lista;
    lista.push_back(1);
    lista.push_front(2);
    lista.push_front(8);
    lista.push_back(3);
    lista.push_back(4);
    lista.push_back(5);
    lista.push_back(6);
    lista.push_front(7);
    cout<<"Lista:"<<lista<<endl;
    lista.remove(1);
    lista.remove(2);
    lista.remove(8);
    lista.pop_front();
    lista.pop_back();
    /*lista.remove(3);
    lista.remove(4);
    lista.remove(5);
    lista.remove(6);*/
    cout<<"Lista:"<<lista<<endl;
    cout << "Reversa:";
    lista.print_reverse();
}
