#include <iostream>


/* 

PreOrder
void preOrder(Node *root) {
        if(root == nullptr)
            return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
}

PostOrder
void postOrder(Node *root) {
        if(root == nullptr)
            return;
        postOrder(root->left);
        postOrder(root->right);
            cout << root->data << " ";
}

InOrder
void inOrder(Node *root) {
        if(root == nullptr)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
        
}

Height
int teste(Node * root){
        if(root == nullptr)
            return 0;
        int aux1 = teste(root->left);
        int aux2 = teste(root->right);
        int aux3 = 1;
        if(aux1 < aux2)
            return aux3+aux2;
        else
            return aux3+aux1;
}

int height(Node* root) {
        if(root == nullptr)
            return 0;
        return teste(root)-1;
        
}

TopView
void topView(Node * root) {
        map<int,int> mapa;
        queue<pair<int,Node*>> fila;
        if(root == nullptr)
            return;
        mapa[0] = root->data;
        fila.push(make_pair(0,root));
        while(!fila.empty()){
            auto par = fila.front();
            fila.pop();
            int dh = par.first;
            Node *no = par.second;
            if(no->left) fila.push(make_pair(dh-1,no->left));
            if(no->right) fila.push(make_pair(dh+1,no->right));
            auto it = mapa.find(dh);
            if(it == mapa.end())
                mapa[dh] = no->data;
        }

        for(auto elem : mapa)
            cout << elem.second << " ";

}

LevelOrder
list<int> levelBorder(Node *root){
        list<int> fila_valor;
        list<Node*> fila;
        fila.push_front(root);
        while(!fila.empty()){
            Node *no = fila.front();
            fila.pop_front();
            if(no->left != nullptr) fila.push_back(no->left);
            if(no->right != nullptr) fila.push_back(no->right);
            fila_valor.push_back(no->data);
        }
        return fila_valor;
    }

    void levelOrder(Node * root) {
        if(root == nullptr)
            return;
        
        list<int> fila = levelBorder(root);
        for(auto x : fila)
            cout << x << " ";
}

InsertBtree
Node * insert(Node * root, int data) {
        if(root == nullptr)
            return new Node(data);
        if(data > root->data)
            root->right = insert(root->right,data);
        else
            root->left = insert(root->left,data);
        
        return root;
}

Lowest Common Ancestor
Node *lca(Node *root, int v1,int v2) {
		if(root != nullptr){
            if(v1 > root->data && v2 > root->data)
                return lca(root->right,v1,v2);
            if(v1 < root->data && v2 > root->data)
                return root;
            if(v1 > root->data && v2 < root->data)
              return root;
            if(v1 < root->data && v2 < root->data)
              return lca(root->left, v1, v2);
        }
        return root;
}

*/


int main(){
    return 0;
}