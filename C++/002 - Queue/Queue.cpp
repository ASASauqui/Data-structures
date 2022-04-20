#include <iostream>

using namespace std;

template< class T >
class Queue
{
    public:
        class Node
        {
            public:
                T data;
                Node* next;
                Node(T data){
                    cout << " Node(" << data << ")" << endl;
                    this->data = data;
                    this->next = nullptr;
                }
                ~Node(){
                    cout << " ~Node(" << data << ")" << endl;
                }
                friend ostream& operator<<(ostream& output, const Node& n){
                    output << "(data:" << n.data << " &:" << &n << " next:" << n.next << ")";
                    return output;
                }
        };
    Queue::Node* first;
    Queue::Node* last;
    Queue(){
        cout << " Queue()" << endl;
        first = nullptr;
        last = nullptr;
    }
    ~Queue(){
        cout << " ~Queue()" << endl;
        if( first == nullptr ){
            return;
        }
        Queue::Node* aux = first;
        Queue::Node* aux2 = aux->next;
        while( aux != nullptr ){
            delete aux;
            aux = aux2;
            if( aux2 != nullptr ) aux2 = aux2->next;
        }
    }
    void push(T data){
        Queue::Node* n = new Node(data);
        if( first == nullptr ){
            first = n;
            last = n;
        }
        else{
            last->next = n;
            last = n;   
        }
    }
    T pop(){
        if( first == nullptr ){
            exit(EXIT_FAILURE);
        }
        Queue::Node* aux = first;
        Queue::Node* aux2 = first;
        if(first == last){
            first = nullptr;
            last = nullptr;
        }
        else{
            first = first->next;
        }
        delete aux;
        return aux2->data;
    }
    T top(){
        if(first == nullptr){
            exit(EXIT_FAILURE);
        }
        return first->data;
    }
    bool isEmpty(){
        if( first == nullptr ){
            return true;
        }
        return false;
    }
    friend ostream& operator<<(ostream& output, const Queue& l){
        output << "[";
        if( l.first != nullptr ){
            Queue::Node* aux = l.first;
            while( aux != NULL ){
                output << *aux;
                aux = aux->next;
            }
        }
        output << "]";
        return output;
    }

};

int main()
{
    Queue<int> lista;
    lista.push(1);
    lista.push(2);
    lista.push(3);
    lista.push(4);
    lista.push(10);
    cout<<"Lista:"<<lista<<endl;
    lista.pop();
    lista.pop();
    lista.pop();
    cout << lista.top() << endl;
    // lista.pop();
    cout<<"Lista:"<<lista<<endl;
    if(lista.isEmpty() == true){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}