#include <bits/stdc++.h>
using namespace std;

template<class U>
class AVL{
public:
            class Node{
                  public:
                    U data;
                    Node* left;
                    Node* right;
                    Node* parent;
                    int balance;
                    int height;
                    bool flag;

                    Node(U data){
                        cout<<"  Node("<<data<<")"<<endl;
                        this->data = data;
                        this->left = nullptr;
                        this->right = nullptr;
                        this->parent = nullptr;
                        this->balance = 0;
                        this->height = 1;
                        this->flag = false;
                    }
                    ~Node(){
                        cout<<"  ~Node("<<data<<")"<<endl;
                    }

                    Node* insert(Node* node, Node* root){
                        if(node->data <= this->data){
                            if(this->left == nullptr){
                                this->left = node;
                                node->parent = this;
                            }
                            else{
                                this->left->insert(node,root);
                            }
                        }
                        else{
                            if(this->right == nullptr){
                                this->right = node;
                                node->parent = this;
                            }
                            else{
                                this->right->insert(node,root);
                            }
                        }
                        return this->mbalance(root);
                    }

                    Node* rotate_left(Node* node, Node* root){
                        Node* parent = node->parent;
                        Node* a = node->right;
                        Node* b = node;
                        Node* s2 = a->left;

                        b->right = s2;
                        if(s2 != nullptr){
                            s2->parent = b;
                        }

                        a->left = b;
                        b->parent = a;

                        b->mbalance(root);
                        if(this->flag != true){
                            a->mbalance(root);
                        }

                        if(parent == nullptr){
                            a->parent = nullptr;
                            return a;
                        }
                        else if(parent->left == b){
                            parent->left = a;
                        }
                        else if(parent->right == b){
                            parent->right = a;
                        }
                        a->parent = parent;

                        return root;
                    }

                    Node* rotate_right(Node* node, Node* root){
                        Node* parent = node->parent;
                        Node* a = node;
                        Node* b = node->left;
                        Node* s2 = b->right;

                        a->left = s2;
                        if(s2 != nullptr){
                            s2->parent = a;
                        }

                        b->right = a;
                        a->parent = b;

                        a->mbalance(root);
                        if(this->flag != true){
                            b->mbalance(root);
                        }

                        if(parent == nullptr){
                            b->parent = nullptr;
                            return b;
                        }
                        else if(parent->left == a){
                            parent->left = b;
                        }
                        else if(parent->right == a){
                            parent->right = b;
                        }
                        b->parent = parent;

                        return root;
                    }

                    Node* mbalance(Node* root){
                        int height_left;
                        int height_right;
                        if(this->left == nullptr){
                            height_left = 0;
                        }
                        else{
                            height_left = this->left->height;
                        }

                        if(this->right == nullptr){
                            height_right = 0;
                        }
                        else{
                            height_right = this->right->height;
                        }
                        this->height = max(height_left+1,height_right+1);
                        this->balance = height_left - height_right;

                        if(this->balance == -2 && this->right->balance <= 0){
                            root = this->rotate_left(this,root);
                        }
                        else if(this->balance == -2 && this->right->balance == 1){
                            this->flag = true;
                            root = this->rotate_right(this->right,root);
                            this->flag = false;
                            root = this->rotate_left(this,root);
                        }
                        else if(this->balance == 2 && this->left->balance == -1){
                            this->flag = true;
                            root = this->rotate_left(this->left,root);
                            this->flag = false;
                            root = this->rotate_right(this,root);
                        }
                        else if(this->balance == 2 && this->left->balance >= 0){
                            root = this->rotate_right(this,root);
                        }

                        return root;
                    }

                    friend ostream& operator<<(ostream& output,const Node& n){
                        // output<< "(data:"<< n.data << " &:" << &n << " left:"<< n.left << " right:" << n.right << ")";
                        output << n.data;
                        output << " h:" << n.height;
                        output << " b:" << n.balance;
                        return output;
                    }
            };

    AVL::Node* root;
    bool flag;
    AVL(){
        root = nullptr;
        flag = false;
        cout<<"AVL()"<<endl;
    }
    ~AVL(){
        cout<<"~AVL()"<<endl;
        if( root == nullptr ){
            return;
        }
        AVLDELETE(root);
    }
    void AVLDELETE(AVL::Node* nodo){
        if( nodo != nullptr ){
            AVLDELETE(nodo->left);
            AVLDELETE(nodo->right);
            delete nodo;
        }
        return;
    }

    void insert(U data){
        AVL::Node* n = new Node(data);
        if(this->root == nullptr){
            this->root = n;
        }
        else{
            this->root = this->root->insert(n,this->root);
        }
    }

    void mostrarArbol(AVL::Node* node, int cont){
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

    //__search_parent_node
    pair<AVL::Node*,AVL::Node*> __search_parent_node(U data){
        if( root == nullptr ){
            pair<AVL::Node*,AVL::Node*> pareja;
            pareja = make_pair(nullptr,nullptr);
            return pareja;
            // exit(EXIT_FAILURE);
        }
        pair<AVL::Node*,AVL::Node*> pareja;
        AVL::Node* parent = nullptr;
        AVL::Node* node = root;
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

    void __remove(AVL::Node* parent, AVL::Node* node){
        //Caso 1
        if( (node->left == nullptr) && (node->right == nullptr) ){
            if( parent == nullptr ){
                root = nullptr;
            }
            else if( parent->left == node ){
                parent->left = nullptr;
                if(this->flag != true){
                    this->retroceso(parent);
                }
            }
            else if( parent-> right == node ){
                parent->right = nullptr;
                if(this->flag != true){
                    this->retroceso(parent);
                }
            }
        }
        //Caso 2
        else if( (node->left == nullptr && node->right != nullptr) || (node->left != nullptr && node->right == nullptr) ){
            if( parent == nullptr ){
                if( node->left != nullptr ){
                    root = node->left;
                }
                else if( node->right != nullptr ){
                    root = node->right;
                }
                this->root->parent = nullptr;
            }
            else if( parent->left == node ){
                if( node->left != nullptr ){
                    parent->left = node->left;
                }
                else if( node->right != nullptr ){
                    parent->left = node->right;
                }
                parent->left->parent = parent;
                if(this->flag != true){
                    this->retroceso(parent);
                }
            }
            else if( parent->right == node ){
                if( node->left != nullptr ){
                    parent->right = node->left;
                }
                else if( node->right != nullptr ){
                    parent->right = node->right;
                }
                parent->right->parent = parent;
                if(this->flag != true){
                    this->retroceso(parent);
                }
            }
        }
        //Caso 3
        else if( node->left != nullptr && node->right != nullptr ){
            AVL::Node* parent2 = node;
            AVL::Node* node2 = node->right;
            while( node2->left != nullptr ){
                parent2 = node2;
                node2 = node2->left;
            }
            AVL::Node* aux;
            if(parent2 == node){
                aux = node2;
            }
            else{
                aux = parent2;
            }
            this->flag = true;
            __remove(parent2,node2);
            this->flag = false;
            node2->left = node->left;
            node2->right = node->right;
            node2->parent = parent;
            if(node2->left != nullptr){
                node2->left->parent = node2;
            }
            if(node2->right != nullptr){
                node2->right->parent = node2;
            }


            if( parent == nullptr ){
                root = node2;
                this->retroceso(aux);
            }
            else if( parent->left == node ){
                parent->left = node2;
                this->retroceso(aux);
            }
            else if( parent->right == node ){
                parent->right = node2;
                this->retroceso(aux);
            }
        }
    }

    void remove(U data){
        cout << "Remove:" << endl;
        pair<AVL::Node*, AVL::Node*> pareja = __search_parent_node(data);
        if( pareja.second == nullptr ){
            cout << "   No esta" << endl;
            return;
        }
        __remove(pareja.first,pareja.second);
        cout << "   Delete(" << pareja.second->data << ")" << endl; 
        delete pareja.second;
    }

    void retroceso(AVL::Node* parent){
        if(parent != nullptr){
            AVL::Node* aux = parent;
            while(aux->parent != nullptr){
                this->root = aux->mbalance(this->root);
                aux = aux->parent;
            }
            if(this->root != nullptr){
                this->root = this->root->mbalance(this->root);
            }
        }
    }
    

    string __print_node(AVL::Node* node, string sp){
        string s = sp + to_string(node->data) + "   h:" + to_string(node->height) + " b:" + to_string(node->balance) + '\n';
        if(node->left != nullptr){
            s += this->__print_node(node->left,sp+" l:");
        } 
        if(node->right != nullptr){
            s += this->__print_node(node->right,sp+" r:");
        } 
        return s;
    }

    string __print(){
        if(this->root == nullptr){
            return "";
        }
        else{
            return this->__print_node(this->root,"");
        }
    }
};

int main()
{
    AVL<int> tree;
    tree.insert(90);
    tree.insert(89);
    tree.insert(88);
    tree.insert(87);
    tree.insert(86);
    tree.insert(85);
    tree.insert(84);
    tree.insert(83);
    tree.insert(82);
    tree.insert(81);
    tree.insert(80);
    tree.insert(79);
    tree.insert(78);
    tree.insert(100);
    tree.insert(91);
    tree.insert(92);
    tree.insert(1);
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    tree.insert(7);
    tree.insert(20);
    tree.insert(15);
    tree.insert(16);
    tree.insert(17);
    tree.insert(18);
    tree.insert(19);
    tree.insert(3);

    cout << tree.__print() << endl;

    tree.remove(90);
    tree.remove(83);
    tree.remove(20);
    tree.remove(15);
    tree.remove(3);
    tree.remove(91);
    tree.remove(85);
    tree.remove(10000);
    tree.remove(84);
    tree.remove(1);
    tree.remove(7);
    tree.remove(5);
    tree.remove(100);

    cout << tree.__print() << endl;
    // tree.print();

    return 0;
}