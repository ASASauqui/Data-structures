#include <iostream>
using namespace std;

class CircularLinkedList{
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
                        output<< "(data:"<< n.data << " node:" << &n <<" next:"<< n.next <<")";
                        return output;
                    }
            };

    CircularLinkedList::Node* head;
    CircularLinkedList(){
        head = nullptr;
        cout<<"  CircularLinkedList()"<<endl;
    }
    ~CircularLinkedList(){
        cout<<"  ~CircularLinkedList()"<<endl;
        if( head == nullptr )
            return;
        CircularLinkedList::Node* aux = head;
        CircularLinkedList::Node* aux1 = head;
        CircularLinkedList::Node* aux2 = aux->next;
        while( aux1->next != head){
            aux1 = aux1->next;
        }
        while( aux != aux1){
            delete aux;
            aux = aux2;
            if( aux2 != nullptr ) aux2 = aux2->next;
        }
        delete aux;
    }
    void insert_head(int data){
        CircularLinkedList::Node* n = new Node(data);
        if(head==nullptr){
            head = n;
            n->next = n;
        }else{
            CircularLinkedList::Node* aux = head;
            while(aux->next != head){
                aux = aux->next;
            }
            aux->next = n;
        }
        n->next = head;
        head = n;
    }

    void insert_tail(int data){
        CircularLinkedList::Node* n = new Node(data);

        if( head == nullptr ){
            head = n;
            n->next = n;
        }else{
            CircularLinkedList::Node* aux = head;
            while( aux->next != head){
                aux = aux->next;
            }
            aux->next = n;
        }
        n->next = head;
    }

    void remove(int data){
        CircularLinkedList::Node* aux = head;
        if( (head->data == data) && (head->next == head) ){
            CircularLinkedList::Node* ndelete = head;
            head = nullptr;
            delete ndelete;
            return;
        }
        if(head->data == data){
            while( aux->next != head){
                aux = aux->next;
            }
            CircularLinkedList::Node* ndelete = head;
            head = aux->next->next;
            aux->next = aux->next->next;
            delete ndelete;
            return;
        }
        while(aux->next != head){
            if(aux->next->data == data){
                CircularLinkedList::Node* ndelete = aux->next;
                aux->next = aux->next->next;
                delete ndelete;
                return;
            }
            aux = aux->next;
        }
    }

    friend ostream& operator<<(ostream& output,const CircularLinkedList& l){
        output<< "[";
        if( l.head != nullptr){
            CircularLinkedList::Node* aux = l.head;
            while(true){
                output<< (*aux);
                if(aux->next == l.head){
                    break;
                }
                else{
                    aux = aux->next;
                }
            }
        }
        output<< "]";
        return output;
    }
};

int main(){
    CircularLinkedList lista;
    lista.insert_head(1);
    lista.insert_head(2);
    lista.insert_tail(100);
    lista.insert_head(3);
    lista.insert_head(4);
    cout<<"Lista:"<<lista<<endl;
    lista.remove(4);
    lista.remove(1);
    lista.remove(2);
    cout<<"Lista:"<<lista<<endl;
}
