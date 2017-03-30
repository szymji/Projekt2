#include <cstddef>
#include <iostream>
#include "tablica.h"

using namespace std;

Tablica::Tablica(){

    tabSize = 0;
    start = new Element;
    it = start;
}

void Tablica::Add(int value){

        it->value = value;
        it->next = new Element;
        it = it->next;

    tabSize ++;
}

//dodaje na it¹ pozycjê
void Tablica::Add(int value,int index){

    Element * temp = start;
    Element * temp2= new Element;
    temp2->value = value;
    if(index>tabSize){ cout<<"Blad wczytywania"<<endl; return; }
    if(index==tabSize){ Add(value); return; }
    if(!index){
        temp2->next = start;
        start = temp2;
    }
    else{
    for(int i=0;i<index-1;i++){
        temp = temp->next;
    }

    temp2->next = temp->next;
    temp->next = temp2;}
    tabSize++;
}

void Tablica::indexRemove(int index){


    if(index+1>tabSize){ cout<<"Blad usuwania"<<endl; return; }

    if(index){
    Element * temp = start; Element * temp2;
    for(int i=0;i<index-1;i++){ temp = temp->next; }
    temp2=(temp->next)->next ;
    delete (temp->next);
    temp->next = temp2;
    }
    else{ start = start->next; delete(start); }
    tabSize--;
}
// wartosc lub przedzial , bool = 1 usuwa tylko jedną liczbę o podanej wartosci
void Tablica::valueRemove(int a,int b,bool c){

    Element * temp = start;
    Element * temp2;
    int n;
    while( (temp->next)!=it ){
        n=(temp->next)->value;
        if( n==a || ( n>=a && n<=b ) ) {
            temp2=(temp->next)->next ;
            delete (temp->next);
            temp->next = temp2;
            tabSize--;
            if(c){return;}
        }
        else { temp=temp->next; }

    }
    n = start->value;
    if( n==a || ( n>a && n<=b ) ) {
            temp = start->next;
            delete(start);
            start = temp;
            tabSize--;
    }
}

void Tablica::cRemove(){

    Tablica pom;
    int n;
    Element * temp = start;
    while(temp!=it){

        n = temp->value;
        pom.Add(n);
        valueRemove(n);
        temp=temp->next;

    }

    *(this)=pom;
}

void Tablica::Print(){

    Element * temp = start;
    for(int i=0;i<tabSize;i++){

        cout << temp->value << endl;
        temp = temp->next;
    }
}

int Tablica::getSize(){

    return tabSize;
}

Tablica Tablica::operator=(Tablica t){

    for(int i=tabSize-1;i>0;i--){
        indexRemove(i);}
    Element * temp = t.start;
    for(int i=0;i<t.tabSize;i++){

        Add(temp->value);
        temp = temp->next;
    }
    return *this;
}


Tablica Tablica::operator+(Tablica t){

    Tablica a;
    Element * temp;
    temp = start;
    for(int i=0;i<tabSize;i++){

        a.Add(temp->value);
        temp = temp->next;
    }
    temp = t.start;
    for(int i=0;i<t.tabSize;i++){

        a.Add(temp->value);
        temp = temp->next;
    }
    return a;
}

Tablica Tablica::operator-(Tablica t){

    Tablica a;
    a = *(this);
    Element * temp;
    temp = t.start;
    for(int i=0;i<t.tabSize;i++){

        a.valueRemove(temp->value,temp->value,1);
        temp = temp->next;

    }
    return a;

}
int Tablica::operator[](int index){

   if(index+1>(this->tabSize)){
        cout<<"Blad dostepu"<<endl;
        return 0;
    }
    Element * temp = this->start;
    for(int i=0;i<index;i++){
        temp=temp->next;
    }
    return (temp->value);

}


