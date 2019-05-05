#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

struct Cliente{
    string id;
    int docs;
    int pac;

    Cliente(string id,int docs, int pac){
        this->id = id;
        this->docs = docs;
        this->pac = pac;
    }

    void show(){
        cout  << this->id << ":" << this->docs << ":" << this->pac ;
    }
};

struct Banco{
    int docs_adquiridos = 0;
    int docs_perdidos = 0;
    vector<Cliente*> caixas;
    list<Cliente*> fila_entrada;
    list<Cliente*> fila_saida;


    void init(int n){

        for(int i = 0; i < n; i++){
            caixas.push_back(nullptr);
        }
    }

    void in (string nome, int docs, int pac){
        Cliente *new_cliente = new Cliente(nome,docs,pac);
        fila_entrada.push_back(new_cliente);
    }

    void show(){
        for(int i = 0; i < caixas.size();i++){
            if(caixas[i]!= nullptr) {
                cout << "[";
                caixas[i]->show();
                cout << "]";
            }
            else
                cout << "[" << "]";
        }
        cout << endl << "in :{ ";
        for(auto it = fila_entrada.begin(); it != fila_entrada.end();it++){
            Cliente *aux = *it;
            aux->show();
            cout << " ";
        }
        cout <<"}";

        cout << endl << "out:{ ";
        for(auto it = fila_saida.begin(); it != fila_saida.end();it++){
            Cliente *aux = *it;
            aux->show();
            cout << " ";
        }
        cout <<"}" << endl;
    }

    void tic(){
        fila_saida.erase(fila_saida.begin(),fila_saida.end());

        for(int i = 0; i < caixas.size();i++){
            if(caixas[i] != nullptr){
                if(caixas[i]->docs > 0){
                    caixas[i]->docs --;
                    this->docs_adquiridos ++;
                }
                else{
                    fila_saida.push_back(caixas[i]);
                    caixas[i] = nullptr;
                }
            }
            else{
                if(fila_entrada.size() > 0){
                    auto it = fila_entrada.front();
                    caixas[i] = it;
                    fila_entrada.pop_front();
                }
            }
        }

        for(auto it = fila_entrada.begin(); it != fila_entrada.end();){
            Cliente *aux = *it;
            if(aux->pac > 0)
                aux->pac --;
            else{
                this->docs_perdidos+=aux->docs;
                fila_saida.push_back(aux);
                auto it2 = it;
                it++;
                fila_entrada.erase(it2);
                continue;
            }
            it++;
        }

    }
};




int main() {
    Banco *amoedo = new Banco();
    string comandos, linha;
    while(true){
        getline(cin,linha);
        stringstream cut(linha);
        cut >> comandos;
        if(comandos == "init"){
            int n;
            cut >> n;
            amoedo->init(n);
        }
        else if(comandos == "in"){
            string id;
            int docs;
            int pac;
            cut >> id;
            cut >> docs;
            cut >> pac;
            amoedo->in(id,docs,pac);
        }
        else if(comandos == "show")
            amoedo->show();
        else if(comandos == "tic")
            amoedo->tic();
        else if(comandos == "end")
            break;
        else if(comandos == "total"){
            cout << "documentos recebidos ate agr : " << amoedo->docs_adquiridos << endl;
            cout << "documentos perdidos ate agr: " << amoedo->docs_perdidos << endl;
        }
    }

    //------Banco fechou-------------

    while(true){
        bool still_have = false;
        if(amoedo->fila_entrada.size() > 0){
            amoedo->tic();
            continue;
        }
        else{
            for(int i = 0; i < amoedo->caixas.size(); i++){
                if(amoedo->caixas[i] != nullptr){
                    still_have = true;
                }
            }
        }
        if(still_have){
            amoedo->tic();
        }
        else
            break;
    }


    if(amoedo->fila_saida.size() > 0)
        amoedo->fila_saida.erase(amoedo->fila_saida.begin(),amoedo->fila_saida.end());

    cout << "documentos recebidos : " << amoedo->docs_adquiridos << endl;
    cout << "documentos perdidos : " << amoedo->docs_perdidos;

}