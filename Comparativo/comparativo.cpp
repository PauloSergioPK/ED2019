#include <bits/stdc++.h>
using namespace std;

pair<bool,int> bsearchVetor(vector<int> &vet, int inicio, int fim, int value){
    if(inicio < fim){
        int meio = (fim+inicio)/2;
        if(vet[meio] == value){
            return make_pair(true,meio);
        }
        if(vet[meio] > value)
            bsearchVetor(vet,inicio,meio,value);
        else
            bsearchVetor(vet,meio+1,fim,value);
    }
    else{
        return make_pair(false,fim);
    }
}

pair<bool,list<int>::iterator> bsearchList(list<int> &lista, int value){
    auto it = lista.begin();
    while(it != lista.end()){
        if(*it == value)
            return make_pair(true,it);
        else if(*it > value)
            return make_pair(false,it);
        it++;
    }
    return make_pair(false,it);
}

void showVetor(vector<int> &vet){
    cout << "[ ";
    for(int i = 0; i < vet.size(); i++)
        cout << vet[i] << " ";
    cout << "]\n";
}

void showConjunto(set<int> &conjunto){
    cout << "[ ";
    for(auto it = conjunto.begin(); it != conjunto.end();it++)
        cout << *it << " ";
    cout << "]\n";
}

void showLista(list<int> &lista){
    cout << "[ ";
    for(auto it = lista.begin();it!= lista.end();it++)
        cout << *it << " ";
    cout << "]\n";
}

int main(){
    vector<int> vetor;
    set<int> conjunto;
    list<int> lista;
    int sucessosV = 0;
    int sucessosC = 0;
    int sucessosL = 0;
    string OP;
    while(cin >> OP){
        if(OP == "Insert"){
            int value;
            cin >> value;
            auto par = bsearchVetor(vetor,0,vetor.size(),value);
            if(par.first != true){
                vetor.insert(vetor.begin()+par.second,value);
                sucessosV++;
            }
            else{
                vetor.insert(vetor.begin()+par.second+1,value);
                sucessosV++;
            }
            
            auto par2 = bsearchList(lista,value);
            lista.insert(par2.second,value);
            sucessosL++;
        
            if(conjunto.find(value) == conjunto.end()){
                conjunto.insert(value);
                sucessosC++;
            }

        }

        else if(OP == "Remove"){
            int value;
            cin >> value;
            auto par = bsearchVetor(vetor,0,vetor.size(),value);
            if(par.first == true){
                vetor.erase(vetor.begin()+par.second);
                sucessosV++;
            }

            auto par2 = bsearchList (lista,value);
            if(lista.size() > 0 && par2.first == true){
                lista.erase(par2.second);
                sucessosL++;
            }

            if(conjunto.find(value) != conjunto.end()){
                conjunto.erase(value);
                sucessosC++;
            }
        }

        else if(OP == "Show"){
            cout << "Vetor : ";
            showVetor(vetor);
            cout << "Lista : ";
            showLista(lista);
            cout << "Conjunto : ";
            showConjunto(conjunto);
        }

        else if(OP == "Sucessos"){
            cout << "Sucessos Vetor : " << sucessosV << endl;
            cout << "Sucessos Lista : " << sucessosL << endl;
            cout << "Sucessos Conjunto : " << sucessosC << endl;
        }

        else if(OP == "Exit")
            break;   
    }
}