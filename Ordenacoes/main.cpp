#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

void swap(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

void bubbleSort(int vet[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(vet[j] > vet[j+1])
                swap(vet[j],vet[j+1]);
        }
    }
}

void show(int vet[],int n){
    cout << "[ " ;
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";
    cout << "]" << endl;
}

void selectionSort (int vet[], int n){
    for(int i = 0; i < n ; i++){
        int menor = i;
        for(int j = i+1; j < n; j++){
            if(vet[j] < vet[menor])
                menor = j;
        }
        if(menor != i){
            swap(vet[i],vet[menor]);
        }

    }
}

void insertionSort(int vet[], int n){
    int j;
    for(int i = 1; i < n; i++){
        int aux = vet[i];
        j = i-1;
        while(j >= 0 && vet[j] > aux){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = aux;
    }
}




int main() {
    srand(time(NULL));
    int tamanho;
    cin >> tamanho;
    int vetor[tamanho];

    for(int i = 0; i < tamanho; i++)
        vetor[i] = rand()%101;

    show(vetor,tamanho);
    insertionSort(vetor,tamanho);
    show(vetor,tamanho);



}