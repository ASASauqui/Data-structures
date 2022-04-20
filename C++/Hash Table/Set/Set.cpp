#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
#include <typeinfo>

using namespace std;

template<class T>
class SinglyLinkedList{
public:
            class Node{
                  public:
                    T data;
                    Node* next;

                    Node(T data){
                        cout<<"  Node("<<data<<")"<<endl;
                        this->data = data;
                        this->next = nullptr;
                    }
                    ~Node(){
                        cout<<"  ~Node("<<data<<")"<<endl;
                    }
                    friend ostream& operator<<(ostream& output,const Node& n){
                        output<<n.data;
                        return output;
                    }
            };

    SinglyLinkedList::Node* head;
    SinglyLinkedList(){
        head = nullptr;
        cout<<"  SinglyLinkedList()"<<endl;
    }
    ~SinglyLinkedList(){
        // cout<<"  ~SinglyLinkedList()"<<endl;
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
    void insert_tail(T data){
        SinglyLinkedList::Node* n = new Node(data);

        if( head == nullptr ){
            head = n;
        }
        else{
            SinglyLinkedList::Node* aux = head;
            if( aux->data == data ){
                return;
            }
            while( aux->next != NULL){
                if( aux->data == data ){
                    return;
                }
                aux = aux->next;
            }
            if( aux->data == data ){
                return;
            }
            aux->next = n;
        }
    }
    void remove(T data){
        if( head == nullptr ) return;
        if( head->data == data){
            SinglyLinkedList::Node* ndelete = head;
            head = head->next;
            delete ndelete;
            return;
        }
        else{
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
    bool contains(T data){
        if( head == nullptr ){
            return false;
        }
        if( head->data == data ){
            return true;
        }
        SinglyLinkedList::Node* aux = head;
        if( aux->data == data ){
            return true;
        }
        while( aux->next != NULL){
            if( aux->data == data ){
                return true;
            }
            aux = aux->next;
        }
        if( aux->data == data ){
            return true;
        }
        return false;
    }

    friend ostream& operator<<(ostream& output,const SinglyLinkedList& l){
        output<< "[";
        if( l.head != nullptr){
            SinglyLinkedList::Node* aux = l.head;
            while( aux != NULL){
                output<< (*aux);
                output<< ",";
                aux = aux->next;
            }
        }
        output<< "]";
        return output;
    }
};

template<class U>
class Set
{
    public:
        vector<SinglyLinkedList<U> > tabla;
        Set(){
            cout << "Set()" << endl;
            for(int i=0;i<7;i++){
                this->tabla.emplace_back(SinglyLinkedList<U>());
            }
        }
        ~Set(){
            cout << "~Set()" << endl;
        }

        int nString(U key){
            stringstream stream;
            stream << key;
            string str = stream.str();
            int n = 0;
            for(int i=0;i<str.length();i++){
                n = n + int(str[i])*pow(26,i);
            }
            return n;
        }
        int nInt(U key){
            stringstream stream;
            stream << key;
            string str = stream.str();
            return stoi(str);
        }
        int nFloat(U key){
            stringstream stream;
            stream << key;
            string str = stream.str();
            return stoi(str);
        }

        void insert(U key){
            int n = 0;
            if( typeid(U) == typeid(string) || typeid(U) == typeid(char) ){
                n = nString(key);
            }
            else if( typeid(U) == typeid(int) ){
                n = nInt(key);
            }
            else if( typeid(U) == typeid(float) ){
                n = nFloat(key);
            }
            this->tabla[n%(this->tabla.size())].insert_tail(key);
        }
        void remove(U key){
            int n = 0;
            if( typeid(U) == typeid(string) || typeid(U) == typeid(char) ){
                n = nString(key);
            }
            else if( typeid(U) == typeid(int) ){
                n = nInt(key);
            }
            else if( typeid(U) == typeid(float) ){
                n = nFloat(key);
            }
            this->tabla[n%(this->tabla.size())].remove(key);
        }
        bool contains(U key){
            int n = 0;
            if( typeid(U) == typeid(string) || typeid(U) == typeid(char) ){
                n = nString(key);
            }
            else if( typeid(U) == typeid(int) ){
                n = nInt(key);
            }
            else if( typeid(U) == typeid(float) ){
                n = nFloat(key);
            }
            if(  this->tabla[n%(this->tabla.size())].contains(key) == true ){
                return true;
            }
            return false;
        }

        friend ostream& operator<<(ostream& output,const Set& l){
            output<< "";
            for(int i=0;i<l.tabla.size();i++){
                output << "Lista " << to_string(i) << ": ";
                output << l.tabla[i];
                output << '\n';
            }
            return output;
        }
};

int main(){
    /*Set<int> s;
    s.insert(7);
    s.insert(15);
    s.insert(2);
    s.insert(10);
    s.insert(5);
    s.insert(6);
    s.insert(77);
    s.insert(92);
    s.insert(24);
    s.insert(12);
    s.insert(12);
    s.insert(7);
    s.insert(5);
    s.insert(5);
    s.insert(10);
    s.insert(24);
    s.insert(12000);
    s.insert(4);
   
    cout << endl << s << endl;

    cout << 7 << ": " << s.contains(7) << endl;
    cout << 123 << ": " << s.contains(123) << endl;

    s.remove(6);
    s.remove(123);
    s.remove(5);
    s.remove(12);

    cout << endl << s << endl;*/

    Set<string> s1;
    s1.insert("A");
    s1.insert("UP");
    s1.insert("UP");
    s1.insert("UP");
    s1.insert("IIA");
    s1.insert("HOLA");
    s1.insert("AMIGOS CERCANOS SI");
    s1.insert("AMIGOS CERCANOS SI");
    s1.insert("AMIGOS CERCANOS SI");
    s1.insert("AMIGOS CERCANOS SI");

    cout << endl << s1 << endl;
    cout << "HOLA" << ": " << s1.contains("HOLA") << endl;

    s1.remove("HOLA");
    s1.remove("PIPO");
    s1.remove("AMIGOS CERCANOS SI");

    cout << endl << s1 << endl;

    cout << "HOLA" << ": " << s1.contains("HOLA") << endl;
    cout << "PIPO" << ": " << s1.contains("PIPO") << endl;
    cout << "UP" << ": " << s1.contains("UP") << endl;
    cout << "AMIGOS CERCANOS SI" << ": " << s1.contains("AMIGOS CERCANOS SI") << endl;
}