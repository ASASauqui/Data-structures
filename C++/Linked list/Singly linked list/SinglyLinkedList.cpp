#include <iostream>
using namespace std;

class SinglyLinkedList{
public:
            class Node{
                  public:
                    int data;
                    Node* next;

                    Node(int data){
                        cout<<"  Node("<<data<<")"<<endl;
                        this->data = data;
                        this->next = nullptr;
                    }
                    ~Node(){
                        cout<<"  ~Node("<<data<<")"<<endl;
                    }
                    friend ostream& operator<<(ostream& output,const Node& n){
                        output<< "(data:"<< n.data <<" next:"<< n.next <<")";
                        return output;
                    }
            };

    SinglyLinkedList::Node* head;
    SinglyLinkedList(){
        head = nullptr;
        cout<<"  SinglyLinkedList()"<<endl;
    }
    ~SinglyLinkedList(){
        cout<<"  ~SinglyLinkedList()"<<endl;
        if( head == nullptr )
            return;
        SinglyLinkedList::Node* aux = head;
        SinglyLinkedList::Node* aux2 = aux->next;
        while( aux != nullptr){
            delete aux;
            aux = aux2;
            if( aux2 != nullptr ) aux2 = aux2->next;
        }
    }
    void insert_head(int data){
        SinglyLinkedList::Node* n = new Node(data);
        if(head==nullptr){
            head = n;
        }else{
            n->next = head;
            head = n;
        }
    }
    void insert_tail(int data){
        SinglyLinkedList::Node* n = new Node(data);

        if( head == nullptr ){
            head = n;
        }else{
            SinglyLinkedList::Node* aux = head;
            while( aux->next != NULL){
                aux = aux->next;
            }
            aux->next = n;
        }
    }
    void remove(int data){
        if( head == nullptr ) return;
        if( head->data == data){
            SinglyLinkedList::Node* ndelete = head;
            head = head->next;
            delete ndelete;
            return;
        }else{
            SinglyLinkedList::Node* aux = head;
            while( aux!=nullptr && aux->next!=nullptr && aux->next->data != data )
                aux = aux->next;

            if( aux->next!=nullptr && aux->next->data == data  ){
                SinglyLinkedList::Node* ndelete = aux->next;
                aux->next = aux->next->next;
                delete ndelete;
            }
        }
    }
    friend ostream& operator<<(ostream& output,const SinglyLinkedList& l){
        output<< "[";
        if( l.head != nullptr){
            SinglyLinkedList::Node* aux = l.head;
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
    SinglyLinkedList lista;
    lista.insert_head(1);
    lista.insert_head(2);
    lista.insert_head(3);
    lista.insert_head(4);
    cout<<"Lista:"<<lista<<endl;
    lista.remove(4);
    cout<<"Lista:"<<lista<<endl;
}

