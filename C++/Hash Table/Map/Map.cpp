#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
#include <utility>
#include <typeinfo>

using namespace std;

template<class T, class R>
class SinglyLinkedList{
public:
            class Node{
                  public:
                    pair<T,R> data;
                    Node* next;

                    Node(pair<T,R> data){
                        cout<<"  Node("<<data.first<<", "<<data.second<<")"<<endl;
                        this->data = data;
                        this->next = nullptr;
                    }
                    ~Node(){
                        cout<<"  ~Node("<<data.first<<", "<<data.second<<")"<<endl;
                    }
                    friend ostream& operator<<(ostream& output,const Node& n){
                        output<<"("<<n.data.first<<", "<<n.data.second<<")";
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
    void insert_tail(pair<T,R> data){
        SinglyLinkedList::Node* n = new Node(data);

        if( head == nullptr ){
            head = n;
        }
        else{
            SinglyLinkedList::Node* aux = head;
            if( aux->data.first == data.first ){
                aux->data = make_pair(aux->data.first,data.second);
                return;
            }
            while( aux->next != NULL){
                if( aux->data.first == data.first ){
                    aux->data = make_pair(aux->data.first,data.second);
                    return;
                }
                aux = aux->next;
            }
            if( aux->data.first == data.first ){
                aux->data = make_pair(aux->data.first,data.second);
                return;
            }
            aux->next = n;
        }
    }
    void remove(T key){
        if( head == nullptr ) return;
        if( head->data.first == key){
            SinglyLinkedList::Node* ndelete = head;
            head = head->next;
            delete ndelete;
            return;
        }
        else{
            SinglyLinkedList::Node* aux = head;
            while( aux!=nullptr && aux->next!=nullptr && aux->next->data.first != key )
                aux = aux->next;

            if( aux->next!=nullptr && aux->next->data.first == key  ){
                SinglyLinkedList::Node* ndelete = aux->next;
                aux->next = aux->next->next;
                delete ndelete;
            }
        }
    }
    bool contains(T key){
        if( head == nullptr ){
            return false;
        }
        if( head->data.first == key ){
            return true;
        }
        SinglyLinkedList::Node* aux = head;
        if( aux->data.first == key ){
            return true;
        }
        while( aux->next != NULL){
            if( aux->data.first == key ){
                return true;
            }
            aux = aux->next;
        }
        if( aux->data.first == key ){
            return true;
        }
        return false;
    }

    R findValue(T key){
        if( head == nullptr ){
            cout << "ERROR. NO HAY DATOS PARA RETORNAR" << endl;
            exit(EXIT_FAILURE);
        }
        if( head->data.first == key ){
            return head->data.second;
        }
        SinglyLinkedList::Node* aux = head;
        if( aux->data.first == key ){
            return aux->data.second;
        }
        while( aux->next != NULL){
            if( aux->data.first == key ){
                return aux->data.second;
            }
            aux = aux->next;
        }
        if( aux->data.first == key ){
            return aux->data.second;
        }
        cout << "ERROR. NO HAY DATOS PARA RETORNAR" << endl;
        exit(EXIT_FAILURE);
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

template<class U, class V>
class Map
{
    public:
        vector<SinglyLinkedList<U,V> > tabla;
        Map(){
            cout << "Map()" << endl;
            for(int i=0;i<7;i++){
                this->tabla.emplace_back(SinglyLinkedList<U,V>());
            }
        }
        ~Map(){
            cout << "~Map()" << endl;
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

        void insert(U key, V value){
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
            this->tabla[n%(this->tabla.size())].insert_tail(make_pair(key,value));
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

        V getValueMap(U key){
            if( this->contains(key) == true ){
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
                return this->tabla[n%(this->tabla.size())].findValue(key);
            }
            cout << "ERROR. NO HAY DATOS PARA RETORNAR" << endl;
            exit(EXIT_FAILURE);
        }

        friend ostream& operator<<(ostream& output,const Map& l){
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
    /*Map<int,string> m;
    m.insert(7,"hola");
    m.insert(15,"amigos");
    m.insert(2,"hola, jeje");
    m.insert(10,"pepe");
    m.insert(5,"pipo");
    m.insert(6,"HOLA");
    m.insert(77,"JELOU");
    m.insert(92,"MIRA");
    m.insert(24,"Soy");
    m.insert(12,"Nuevo");
    m.insert(1,"Pc");
    m.insert(4,"Mexico");

    cout << "4: " << m.contains(4) << endl;
    cout << "2: " << m.contains(2) << endl;
    cout << "1000: " << m.contains(1000) << endl;
    cout << "100320: " << m.contains(100320) << endl;
    cout << "15: " << m.contains(15) << endl;
    cout << "Valor obtenido de 2: " << m.getValueMap(2) << endl;
    cout << "Valor obtenido de 77: " << m.getValueMap(77) << endl;

    cout << endl << m << endl;

    m.insert(1,"Cambio");
    m.insert(77,"Perrito");
    m.insert(6,"Gatito");

    cout << endl << m << endl;

    m.remove(10);
    m.remove(24);
    m.remove(1000);
    m.remove(4);
    m.remove(7);
    m.remove(92);

    cout << "4: " << m.contains(4) << endl;
    cout << "2: " << m.contains(2) << endl;
    cout << "1000: " << m.contains(1000) << endl;
    cout << "100320: " << m.contains(100320) << endl;
    cout << "15: " << m.contains(15) << endl;
    cout << "Valor obtenido de 5: " << m.getValueMap(5) << endl;
    cout << "Valor obtenido de 6: " << m.getValueMap(6) << endl;

    cout << endl << m << endl;*/

    Map<string,float> m1;
    m1.insert("A",65);
    m1.insert("UP",1.231);
    m1.insert("AMIGOS CERCANOS",3.31);
    m1.insert("HOLA",31);
    m1.insert("IIA",128);
    m1.insert("ALHO",0.23);

    cout << endl << m1 << endl;

    cout << "Valor obtenido de AMIGOS CERCANOS: " << m1.getValueMap("AMIGOS CERCANOS") << endl;
    cout << "Valor obtenido de ALHO: " << m1.getValueMap("ALHO") << endl;
    m1.remove("AMIGOS CERCANOS");
    m1.remove("uP");
    m1.insert("IIA",33333);
    m1.remove("UP");
    m1.insert("ALHO",777);
    m1.remove("A");
    m1.remove("HOLA");
    cout << "Valor obtenido de ALHO: " << m1.getValueMap("ALHO") << endl;
    cout << endl << m1 << endl;
}