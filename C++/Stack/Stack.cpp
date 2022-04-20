#include <iostream>

using namespace std;

template< class T >
class Stack
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
        Stack::Node* first;
        Stack(){
            cout << " Stack()" << endl;
            first = nullptr;
        }
        ~Stack(){
            cout << " ~Stack()" << endl;
            if( first == nullptr){
                return;
            }
            Stack::Node* aux = first;
            Stack::Node* aux2 = first->next;
            while( aux != nullptr ){
                delete aux;
                aux = aux2;
                if( aux2 != nullptr ) aux2 = aux2->next;
            }
        }

        void push(T data){
            Stack::Node* n = new Node(data);
            if( first == nullptr ){
                first = n;
            }
            else{
                n->next = first;
                first = n;
            }
        }
        T pop(){
            if( first == nullptr ){
                exit(EXIT_FAILURE);
            }
            Stack::Node* aux = first;
            Stack::Node* aux2 = first;
            if( first->next == nullptr ){
                first = nullptr;
            }
            else{
                first = first->next;
            }
            delete aux;
            return aux2->data;
        }
        T top(){
            if( first == nullptr ){
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
        friend ostream& operator<<(ostream& output, const Stack& l){
            output << "[";
            if( l.first != nullptr ){
                Stack::Node* aux =l.first;
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
    Stack<double> lista;
    lista.push(1);
    lista.push(2);
    lista.push(3);
    lista.push(4);
    cout<<"Lista:"<<lista<<endl;
    lista.pop();
    lista.pop();
    lista.pop();
    cout<<"Lista:"<<lista<<endl;
    if(lista.isEmpty() == true){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}