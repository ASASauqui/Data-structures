#include <iostream>
using namespace std;

template<class T>
class Stack{
public:
            class Node{
                  public:
                    T data;
                    Node* next;

                    Node(T data){
                        cout<<"      Node("<<data<<")"<<endl;
                        this->data = data;
                        this->next = nullptr;
                    }
                    ~Node(){
                        cout<<"      ~Node("<<data<<")"<<endl;
                    }
                    friend ostream& operator<<(ostream& output,const Node& n){
                        output<< "      (data:"<< n.data << " &:" << &n << " next:"<< n.next <<")";
                        return output;
                    }
            };

    Stack::Node* first;
    Stack(){
        first = nullptr;
        cout<<"    Stack()"<<endl;
    }
    ~Stack(){
        cout<<"    ~Stack()"<<endl;
        if( first == nullptr )
            return;
        Stack::Node* aux = first;
        Stack::Node* aux2 = aux->next;
        while( aux != nullptr){
            delete aux;
            aux = aux2;
            if( aux2 != nullptr ) aux2 = aux2->next;
        }
    }
    
    void push(T data){
        Stack::Node* n = new Node(data);
        if(first == nullptr){
            first = n;
        }
        else{
            n->next = first;
            first = n;
        }
    }

    T pop(){
        if(first == nullptr){
            cout << "UnderFlow\nProgram Terminated\n" << endl;
            exit(EXIT_FAILURE);
        }
        Stack::Node* n = first;
        T aux = first->data;
        if(first->next == nullptr){
            first = nullptr;
        }
        else{
            first = first->next;
        }
        delete n;
        return aux;
    }

    T top(){
        if(first == nullptr){
            cout << "UnderFlow\nProgram Terminated\n" << endl;
            exit(EXIT_FAILURE);
        }
        else{
            return first->data;
        }
    }

    bool isEmpty(){
        if(first == nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    friend ostream& operator<<(ostream& output,const Stack& l){
        output<< "[";
        if( l.first != nullptr){
            Stack::Node* aux = l.first;
            while( aux != NULL){
                output<< (*aux);
                aux = aux->next;
            }
        }
        output<< "]";
        return output;
    }
};

template<class S>
class Queue{
public:
            class Node{
                  public:
                    S data;
                    Node* next;

                    Node(S data){
                        cout<<"      Node("<<data<<")"<<endl;
                        this->data = data;
                        this->next = nullptr;
                    }
                    ~Node(){
                        cout<<"      ~Node("<<data<<")"<<endl;
                    }
                    friend ostream& operator<<(ostream& output,const Node& n){
                        output<< "      (data:"<< n.data << " &:" << &n << " next:"<< n.next <<")";
                        return output;
                    }
            };

    Queue::Node* first;
    Queue::Node* last;
    Queue(){
        first = nullptr;
        last = nullptr;
        cout<<"    Queue()"<<endl;
    }
    ~Queue(){
        cout<<"    ~Queue()"<<endl;
        if( first == nullptr )
            return;
        Queue::Node* aux = first;
        Queue::Node* aux2 = aux->next;
        while( aux != nullptr){
            delete aux;
            aux = aux2;
            if( aux2 != nullptr ) aux2 = aux2->next;
        }
    }
    
    void push(S data){
        Queue::Node* n = new Node(data);
        if(first == nullptr){
            first = n;
            last = n;
        }
        else{
            last->next = n;
            last = n;
        }
    }

    S pop(){
        if(first == nullptr){
            cout << "UnderFlow\nProgram Terminated\n" << endl;
            exit(EXIT_FAILURE);
        }
        Queue::Node* n = first;
        S aux = first->data;
        if(first == last){
            first = nullptr;
            last = nullptr;
        }
        else{
            first = first->next;
        }
        delete n;
        return aux;
    }

    S top(){
        if(first == nullptr){
            cout << "UnderFlow\nProgram Terminated\n" << endl;
            exit(EXIT_FAILURE);
        }
        else{
            return first->data;
        }
    }

    bool isEmpty(){
        if(first == nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    friend ostream& operator<<(ostream& output,const Queue& l){
        output<< "[";
        if( l.first != nullptr){
            Queue::Node* aux = l.first;
            while( aux != NULL){
                output<< (*aux);
                aux = aux->next;
            }
        }
        output<< "]";
        return output;
    }
};


template<class U>
class BST{
public:
            class Node{
                  public:
                    U data;
                    Node* left;
                    Node* right;

                    Node(U data){
                        cout<<"  Node("<<data<<")"<<endl;
                        this->data = data;
                        this->left = nullptr;
                        this-> right = nullptr;
                    }
                    ~Node(){
                        cout<<"  ~Node("<<data<<")"<<endl;
                    }
                    friend ostream& operator<<(ostream& output,const Node& n){
                        output<< "(data:"<< n.data << " &:" << &n << " left:"<< n.left << " right:" << n.right << ")";
                        return output;
                    }
            };

    BST::Node* root;
    BST(){
        root = nullptr;
        cout<<"BST()"<<endl;
    }
    ~BST(){
        cout<<"~BST()"<<endl;
        if( root == nullptr ){
            return;
        }
        BSTDELETE(root);
    }
    void BSTDELETE(BST::Node* nodo){
        if( nodo != nullptr ){
            BSTDELETE(nodo->left);
            BSTDELETE(nodo->right);
            delete nodo;
        }
        return;
    }

    void insert(U data){
        BST::Node* n = new Node(data);
        if( root == nullptr ){
            root = n;
        }
        else{
            BST::Node* aux = root;
            while(true){
                if( data <= aux->data ){
                    if( aux->left == nullptr ){ //Izquierda
                        aux->left = n;
                        break;
                    }
                    else{
                        aux = aux->left;
                    }
                }
                else{ //Derecha
                    if( aux->right == nullptr ){
                        aux->right = n;
                        break;
                    }
                    else{
                        aux = aux->right;
                    }
                }
            }
        }
    }

    bool contains(U data){
        if( root == nullptr ){
            return false;
        }
        BST::Node* aux = root;
        while( aux != nullptr ){
            if( aux->data == data ){
                return true;
            }
            if( data <= aux->data ){
                if( aux->left == nullptr ){
                    return false;
                }
                aux = aux->left;
            }
            else{
                if( aux->right == nullptr ){
                    return false;
                }
                aux = aux->right;
            }
        }
        return false;
    }

    void mostrarArbol(BST::Node* node, int cont){
        if( node == nullptr ){
            return;
        }
        mostrarArbol( node->right, cont+1 );
        string s = "";
        for(int i=0;i<cont;i++){
            s += "  ";
        }
        cout << s << node->data << endl;
        mostrarArbol( node->left,cont+1  );
    }

    void print(){
        cout << endl << "Mostrar arbol:" << endl;
        mostrarArbol( root, 0 );
        cout << endl;
    }

    void DFS(){
        cout << "DFS:" << endl;
        Stack<BST::Node*> stack;
        if( root == nullptr ){
            cout << "  Vacio" << endl;
        }
        else{
            stack.push(root);
            while( stack.isEmpty() != true ){
                BST::Node* n = stack.pop();
                cout << "   " << to_string(n->data) << endl;
                if( n->right != nullptr ){
                    stack.push( n->right );
                }
                if( n->left != nullptr ){
                    stack.push( n->left );
                }
            }
        }
    }

    void BFS(){
        cout << "BFS:" << endl;
        Queue<BST::Node*> queue;
        if( root == nullptr ){
            cout << "  Vacio" << endl;
        }
        else{
            queue.push(root);
            while( queue.isEmpty() != true ){
                BST::Node* n = queue.pop();
                cout << "   " << to_string(n->data) << endl;
                if( n->left != nullptr ){
                    queue.push(n->left);
                }
                if( n->right != nullptr ){
                    queue.push(n->right);
                }
            }
        }
    }

    //Preorder
    void preorderR(BST::Node* nodo){
        if( nodo != nullptr ){
            cout << "   " << to_string(nodo->data) << endl;
            preorderR( nodo->left );
            preorderR( nodo->right );
        }
        return;
    }

    void preorder(){
        cout << "Preorder:" << endl;
        if( root == nullptr ){
            cout << "  Vacio" << endl;
        }
        else{
            preorderR(root);
        }
    }

    //Inorder
    void inorderR(BST::Node* nodo){
        if( nodo != nullptr ){
            inorderR( nodo->left );
            cout << "   " << to_string(nodo->data) << endl;
            inorderR( nodo->right );
        }
        return;
    }

    void inorder(){
        cout << "Inorder:" << endl;
        if( root == nullptr ){
            cout << "  Vacio" << endl;
        }
        else{
            inorderR(root);
        }
    }
    
    //Postorder
    void postorderR(BST::Node* nodo){
        if( nodo != nullptr ){
            postorderR( nodo->left );
            postorderR( nodo->right );
            cout << "   " << to_string(nodo->data) << endl;
        }
        return;
    }

    void postorder(){
        cout << "Postorder:" << endl;
        if( root == nullptr ){
            cout << "  Vacio" << endl;
        }
        else{
            postorderR(root);
        }
    }

    //__search_parent_node
    pair<BST::Node*,BST::Node*> __search_parent_node(U data){
        if( root == nullptr ){
            pair<BST::Node*,BST::Node*> pareja;
            pareja = make_pair(nullptr,nullptr);
            return pareja;
            // exit(EXIT_FAILURE);
        }
        pair<BST::Node*,BST::Node*> pareja;
        BST::Node* parent = nullptr;
        BST::Node* node = root;
        while(true){
            if( data == node->data ){
                pareja = make_pair(parent,node);
                return pareja;
            }
            else if( data < node->data ){ //Izquierdo
                parent = node;
                node = node->left;
            }
            else if( data > node->data ){ //Derecha
                parent = node;
                node = node->right;
            }
            if( node == nullptr ){
                pareja = make_pair(nullptr,nullptr);
                return pareja;
            }
        }
    }

    void __remove(BST::Node* parent, BST::Node* node){
        //Caso 1
        if( (node->left == nullptr) && (node->right == nullptr) ){
            cout << "  Caso 1" << endl;
            if( parent == nullptr ){
                root = nullptr;
            }
            else if( parent->left == node ){
                parent->left = nullptr;
            }
            else if( parent-> right == node ){
                parent->right = nullptr;
            }
        }
        //Caso 2
        else if( (node->left == nullptr && node->right != nullptr) || (node->left != nullptr && node->right == nullptr) ){
            cout << "  Caso 2" << endl;
            if( parent == nullptr ){
                if( node->left != nullptr ){
                    root = node->left;
                }
                else if( node->right != nullptr ){
                    root = node->right;
                }
            }
            else if( parent->left == node ){
                if( node->left != nullptr ){
                    parent->left = node->left;
                }
                else if( node->right != nullptr ){
                    parent->left = node->right;
                }
            }
            else if( parent->right == node ){
                if( node->left != nullptr ){
                    parent->right = node->left;
                }
                else if( node->right != nullptr ){
                    parent->right = node->right;
                }
            }
        }
        //Caso 3
        else if( node->left != nullptr && node->right != nullptr ){
            cout << "  Caso 3" << endl;
            BST::Node* parent2 = node;
            BST::Node* node2 = node->left;
            while( node2->right != nullptr ){
                parent2 = node2;
                node2 = node2->right;
            }
            cout << "   parent2:" << parent2->data << " node2:" << node2->data << endl;
            __remove(parent2,node2);
            node2->left = node->left;
            node2->right = node->right;
            if( parent == nullptr ){
                root = node2;
            }
            else if( parent->left == node ){
                parent->left = node2;
            }
            else if( parent->right == node ){
                parent->right = node2;
            }
        }
    }

    void remove(U data){
        cout << "Remove:" << endl;
        pair<BST::Node*, BST::Node*> pareja = __search_parent_node(data);
        if( pareja.second == nullptr ){
            cout << "   No esta" << endl;
            return;
        }
        if( pareja.first == nullptr && pareja.second != nullptr ){
            cout << "   parent:" << "NULL" << " node:" << pareja.second->data << endl;
        }
        else{
            cout << "   parent:" << pareja.first->data << " node:" << pareja.second->data << endl;
        }
        __remove(pareja.first,pareja.second);
        cout << "   Delete(" << pareja.second->data << ")" << endl; 
        delete pareja.second;
    }
    

    friend ostream& operator<<(ostream& output,const BST& l){
        Stack<BST::Node*> stack;
        if( l.root == nullptr ){
            output << "Vacio" << endl;
            return output;
        }
        else{
            stack.push(l.root);
            while( stack.isEmpty() != true ){
                BST::Node* n = stack.pop();
                output << to_string(n->data) << " " << endl;
                if( n->right != nullptr ){
                    stack.push( n->right );
                }
                if( n->left != nullptr ){
                    stack.push( n->left );
                }
            }
        }
        return output;
    }
};

int main()
{
    BST<int> bst;
    bst.insert(10);
    bst.insert(3);
    bst.insert(15);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(18);
    bst.insert(5);
    bst.insert(9);
    bst.insert(13);
    bst.insert(20);
    bst.insert(8);


    cout << bst << endl;
    bst.DFS();
    bst.BFS();
    bst.preorder();
    bst.inorder();
    bst.postorder();
    bst.print();


    bst.remove(10);
    bst.remove(15);
    bst.remove(1);
    bst.remove(6);
    bst.remove(14);
    bst.remove(18);
    bst.remove(5);
    bst.remove(9);
    bst.remove(13);
    bst.remove(20);

    cout << endl << "Despues de remover" << endl;

    bst.print();
    bst.DFS();
    bst.BFS();
    bst.preorder();
    bst.inorder();
    bst.postorder();

    cout << bst.contains(8) << endl;
    cout << bst.contains(10) << endl;
    return 0;
}