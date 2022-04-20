#include <iostream>

using namespace std;

template< class T >
class Dequeue
{
    public:
        class Node
        {
            public:
                T data;
                Node* prev;
                Node* next;
                Node(T data){
                    cout << " Node(" << data << ")" << endl;
                    this->data = data;
                    this->next = nullptr;
                    this->prev = nullptr;
                }
                ~Node(){
                    cout << " ~Node(" << data << ")" << endl;
                }
                friend ostream& operator<<(ostream& output, const Node& n){
                    output << "(data" << n.data << " prev:" << n.prev << " &:" << &n << " next:" << n.next << ")";
                    return output;
                }
        };
        Dequeue::Node* first;
        Dequeue::Node* last;
        Dequeue(){
            cout << " Dequeue()" << endl;
            first = nullptr;
            last = nullptr;
        }
        ~Dequeue(){
            cout << " ~Dequeue()" << endl;
            if( first == nullptr ){
                return;
            }
            Dequeue::Node* aux = first;
            Dequeue::Node* aux2 = first->next;
            while( aux != first ){
                delete aux;
                aux = aux2;
                if( aux2 != nullptr ) aux2 = aux2->next;
            }
        }
        void push_front(T data){
            Dequeue::Node* n = new Node(data);
            if( first == nullptr ){
                first = n;
                last = n;
            }
            else{
                first->prev = n;
                n->next = first;
                first = n;
            }
        }
        void push_back(T data){
            Dequeue::Node* n = new Node(data);
            if(first == nullptr){
                first = nullptr;
                last = nullptr;
            }
            else{
                last->next = n;
                n->prev = last;
                last = n;
            }
        }
        T pop_front(){
            if(first == nullptr){
                exit(EXIT_FAILURE);
            }
            Dequeue::Node* aux = first;
            Dequeue::Node* aux2 = first;
            if( first == last ){
                first = nullptr;
                last = nullptr;
            }
            else{
                first = first->next;
                first->prev = nullptr;
            }
            delete aux;
            return aux2->data;
        }
        T pop_back(){
            if(first == nullptr){
                exit(EXIT_FAILURE);
            }
            Dequeue::Node* aux = last;
            Dequeue::Node* aux2 = last;
            if( first == last ){
                first = nullptr;
                last = nullptr;
            }
            else{
                last = last->prev;
                last->next = nullptr;
            }
            delete aux;
            return aux2->data;
        }
        T front(){
            if(first == nullptr){
                exit(EXIT_FAILURE);
            }
            return first->data;
        }
        T back(){
            if(first == nullptr){
                exit(EXIT_FAILURE);
            }
            return last->data;
        }
        bool isEmpty(){
            if(first == nullptr){
                return true;
            }
            return false;
        }
        friend ostream& operator<<(ostream& output, const Dequeue& l){
            output << "[";
            if(l.first != nullptr){
                Dequeue::Node* aux = l.first;
                while( aux != nullptr ){
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
    Dequeue<int> lista;
    lista.push_back(1);
    lista.push_front(2);
    lista.push_front(3);
    lista.push_back(4);
    cout<<"Lista:"<<lista<<endl;
    lista.pop_front();
    lista.pop_back();
    lista.pop_front();
    cout<<"Lista:"<<lista<<endl;
    if(lista.isEmpty() == true){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    cout << lista.front() << endl;
    cout << lista.back() << endl;

    lista.push_back(60);
    lista.push_back(10);
    cout<<"Lista:"<<lista<<endl;
    cout << lista.front() << endl;
    cout << lista.back() << endl;

    return 0;
}