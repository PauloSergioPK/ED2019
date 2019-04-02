#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * next;
    Node * prev;
    Node(int value = 0, Node * next = nullptr, Node * prev = nullptr){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

struct Lista{
    Node * head;
    Node * tail;

    Lista(){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void show(){
        cout << "[ ";
        Node * node = head->next;
        while(node != tail){
            cout << node->value << " ";
            node = node->next;
        }
        cout << "]\n";
    }

    void push_back(int value){
        insert(tail, value);
    }

    void pop_back(){
        if(head->next == tail)
            return;
        remove(tail->prev);
    }

    void pop_front(){
        if(head->next == tail)
            return;
        remove(head->next);
    }

    void push_front(int value){
        insert(head->next, value);
    }

    void insert(Node * ref, int value){
        Node * node = new Node(value, ref, ref->prev);
        ref->prev = node;
        node->prev->next = node;
    }

    void remove(Node * ref){
        ref->prev->next = ref->next;
        ref->next->prev = ref->prev;
        delete ref;
    }
};


void Print(Lista lista, int escolhido){
    cout << "[ ";
    Node * node = lista.head->next;
    while(node != lista.tail){
        if(node->value == escolhido || node->value == escolhido*-1){
            if(node->value < 0)
                cout << "<" << node->value << " ";
            else
                cout << node->value << ">" << " ";
        }
        else
            cout << node->value << " ";
        node = node->next;
    }
    cout << "]\n";
}

int main(){
    Lista lista;
    int total, escolhido, fase;
    cin >> total >> escolhido >> fase;

    for(int i = 1; i <= total; i++){
        lista.push_back(i*fase);
        fase*=-1;
    }

    Print(lista,escolhido);
    Node * aux = lista.head->next;
    int aux2 = 0;
    while(lista.head->next->next != lista.tail){
        if(aux->value == escolhido || aux->value == escolhido*-1) {
            if (aux->value > 0) {
                if (aux->next == lista.tail) {
                    aux = lista.head;
                    lista.remove(aux->next);
                }
                else
                    lista.remove(aux->next);

                if(escolhido < 0)
                    aux2= escolhido*-1;
                else
                    aux2 = escolhido;

                for (int i = 0; i < aux2; i++) {
                    aux = aux->next;
                    if (aux == lista.tail)
                        aux = lista.head->next;
                }
                escolhido = aux->value;
                Print(lista, escolhido);
            }
            else{
                if (aux->prev == lista.head) {
                    aux = lista.tail;
                    lista.remove(aux->prev);
                }
                else
                    lista.remove(aux->prev);

                if(escolhido < 0)
                    aux2= escolhido*-1;
                else
                    aux2 = escolhido;

                for (int i = 0; i < aux2; i++) {
                    aux = aux->prev;
                    if (aux == lista.head)
                        aux = lista.tail->prev;
                }
                escolhido = aux->value;
                Print(lista, escolhido);
            }
        }
        else
            aux = aux->next;
    }

}
