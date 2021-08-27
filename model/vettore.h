#include <iostream>
#ifndef VETTORE_H
#define VETTORE_H

typedef unsigned int u_int;

template <class T> class Vettore;

/*
template <class T>
std::ostream& operator<<(std::ostream& os,const Vettore<T>& vec);*/

class Iteratore;

template<class T>
class Vettore{

    //friend std::ostream& operator<< <T>(std::ostream& os,const Vettore<T>& vec);

    friend class Iteratore;

    private:
        T* info;
        u_int size;
        u_int capacity;

    public:
        class Iteratore{
            friend class Vettore<T>;
            private:
                Vettore<T>* punt; //nell'iteratore costante andrà un const Vettore<T>*
                int index;

                // iteratore CONSTUCTOR
                Iteratore(Vettore<T>& v, int ind=0); //in quello costante va messo const
                // Iteratore(T* p, u_int s, u_int c);
                //Iteratore clone() const;


            public:
                Iteratore(const Iteratore& it);
                //~Iteratore(); -----> potrebbe no nservire visto che utilizziamo un puntatore
                //                      quando cancelliamo iteratore non vogliamo cancellate anche il vettore
                //                      quindi ci basta cancellare il puntatore e non ciò a cui punta
                // overloading OPERATOR
                Iteratore operator++(int);
                Iteratore& operator++();
                Iteratore operator--(int);
                Iteratore& operator--();
                T& operator*() const;
                T* operator->()const;
                Iteratore operator+(u_int ind) const;
                Iteratore operator-(u_int ind) const;
                bool operator!=(const Iteratore& it) const;
                bool operator==(const Iteratore& it) const;
        };

        // vettore CONSTUCTOR
        Vettore();
        Vettore(T t);
        Vettore(u_int n, T t);
        //Vettore(u_int n, T* t); //ok
        Vettore(typename Vettore<T>::Iteratore first, typename Vettore<T>::Iteratore second );
        Vettore(const Vettore& vec); //ok

        // Vettore OPERATOR overloading
        T& operator[](u_int ind);
        const T& operator[](u_int ind) const;
        bool operator==(const Vettore& vec)const;

        // Vettore METHOD
        //quando farai i const iterator li metti costanti :) 21:27
        Iteratore begin() ;
        Iteratore end() ;
        //skerzetto, intanto li teniamo const 23:18
        u_int Size() const;
        void push_back(const T& val);
        void insert(Iteratore it, T val); //perche non è per rif?
        //void insert(const T& val);
        void remove(Iteratore it); //rimuove l'elemento in posizione it
        void remove(const T& value); //rimuove elemento con valore value
        T pop_back(); //rimuove ultimo elemento
        bool empty(); //true se il vettore è vuoto
        Vettore& merge(Vettore& vec);

};


//              CONSTRUCTOR ITERATORE
template <class T>
Vettore<T>::Iteratore::Iteratore(Vettore<T>& v , int ind){
    punt = &v;
    if(ind < 0) index=0;
    else if(ind>punt->Size()) index=punt->Size();
    else index=ind;
}


template <class T>
Vettore<T>::Iteratore::Iteratore(const Iteratore& it):
    punt(it.punt), index(it.index) {}

/*  non ciserve un costruttore solo con l'indice perchè dovremo comuqnue
    sempre sepcificare anche il vettore al quale fa riferimento
*/

//overloading operatori iteratore
template <class T>
typename Vettore<T>::Iteratore Vettore<T>::Iteratore::operator++(int){
    Iteratore ret(*this);
    if(punt != nullptr) {
        if(index < punt->Size()) {
            index++;
        }
    }
    return ret;
}

template <class T>
typename Vettore<T>::Iteratore& Vettore<T>::Iteratore::operator++(){
      if(punt != nullptr) {
        if(index < punt->Size()) {
            index++;
        }

      }
      return *this;
}
// operator iteratore
template <class T>
typename Vettore<T>::Iteratore Vettore<T>::Iteratore::operator--(int){
    if(index>0){
        index--;
    }
      /*if(punt != nullptr) {
          index--;
      }
      else{
          index=(*punt).Size()--;
      }*/
    return *this;
}

template <class T>
typename Vettore<T>::Iteratore& Vettore<T>::Iteratore::operator--(){
    Iteratore ret(*this);
    if(index>0){
        index--;
    }
      /*if(punt != nullptr) {
             index--;
      }else{
          index=(*punt).Size()--;
      }*/
      return ret;
}

// operator iteratore

template <class T>
T& Vettore<T>::Iteratore::operator*() const{
    return (*punt)[index];
}

// operator iteratore

template <class T>
T* Vettore<T>::Iteratore::operator->() const {
    return &(*punt)[index];
}

template <class T>
typename Vettore<T>::Iteratore Vettore<T>::Iteratore::operator+(u_int ind) const{
    return Iteratore(*punt, index+ind);
}

template <class T>
typename Vettore<T>::Iteratore Vettore<T>::Iteratore::operator-(u_int ind) const{
    return Iteratore(*punt, index-ind);
}

// operator iteratore
template <class T>
bool Vettore<T>::Iteratore::operator==(const Iteratore& it) const{
    return punt == it.punt && index == it.index;
}

// operator iteratore
template <class T>
bool Vettore<T>::Iteratore::operator!=(const Iteratore& it) const{
    return !(it==*this);
}


//      METODI VETTORE


// CONSTRUCTOR Vettore
// --------------------------------> RICONTROLLARE <-------------------------------

template <class T> //ok
Vettore<T>::Vettore():info(nullptr), size(0), capacity(0){}

template <class T> //ok
Vettore<T>::Vettore(T t): info(new T[1]), size(0),capacity(1){
    push_back(t);
}

template <class T> //ok
Vettore<T>::Vettore(u_int n, T t): info(new T[n]), size(0), capacity(n){
    for(int i=1; i<n; i++){
        push_back(t);
    }
}

/*template <class T> //ok
Vettore<T>::Vettore(u_int n, T* t): info(new T[n]), size(0), capacity(n){
    for(int i =0; i<n; i++){
        push_back(t[i]);
    }
}*/


template <class T>
Vettore<T>::Vettore(typename Vettore<T>::Iteratore first, typename  Vettore<T>::Iteratore second): info(nullptr), size(0), capacity(0){
    //non passati per riferimento costante perchè dobiamo fare ++ allinterno della funzione
    if((first.punt==second.punt) && first.index<second.index){
        info=new T[second.index-first.index];
        capacity=second.index-first.index;
        for(auto it=first; it!=second; it++){
            push_back(*it);
        }
    }
}

template <class T> //ok
Vettore<T>::Vettore(const Vettore& vec): info(new T[vec.size]), size(0), capacity(vec.size){
    for(auto it=vec.begin(); it!=vec.end(); it++){
        push_back(*it);
    }

}

template <class T>
typename Vettore<T>::Iteratore Vettore<T>::begin() {
    return Iteratore(*this,0);
}

template <class T>
typename Vettore<T>::Iteratore Vettore<T>::end() {
    return Iteratore(*this, size);
}


template <class T> //ok
u_int Vettore<T>::Size() const{
    return size;
}

template <class T> //ok
void Vettore<T>::push_back(const T& val){
    if(info){ //l'array non è vuoto
        if(size == capacity){ //l'array è pieno
            capacity *= 2; //raddoppio capacity
            T* aux  = new T[capacity];
            for(int i=0; i<size; i++){
                aux[i]=info[i];
            }
            delete[] info;
            info = aux;
            info[size]=val; //metto in coda l'elemento da aggiungere
        } else info[size]= val;
        size++;
    }
    else{ //array vuoto
        info = new T[1];
        info[0] = val;
        size = 1;
        capacity = 1;
    }

}

template <class T>
void Vettore<T>::insert(Iteratore it, T val){
    if( end() == it ){
        push_back(val);
        return;
    }
    if(size==capacity){
        capacity *= 2; //raddoppio capacity
        T* aux  = new T[capacity];
        for(int i = 0; i < size; i++){
            aux[i]=info[i];
        }
        delete[] info;
        info = aux;
    }
    for(int i=size; i!=it.index; i--){
        info[i]=info[i-1];
    }
    info[it.index]=val;
    size++;
}

/*
template <class T>
void Vettore<T>::insert(const T& val){
    bool ctr = true;
    for( int i = 0; ctr && i < size; i++){
        if(val == info[i]){
            info[i]+=val;
            ctr = false;
        }
    }
    if(ctr)push_back(val);
}*/

template <class T>
void Vettore<T>::remove(const T& value){
    bool ctr = true;
    for(auto it=begin(); ctr && it!=end(); it++){
        if(*it==value){
            remove(it);
            ctr=false;
        }
    }
}

template <class T>
void Vettore<T>::remove(Iteratore iter){
    if( iter.index < size ){
        for(int i = iter.index; i < size-1; i++){
            info[i]=info[i+1];
        }
        size--;
     }
}

template <class T> //ok
T Vettore<T>::pop_back(){
    T ret = info[size-1];
    size--; //perchè tolgo un valore
    return ret;
}

template <class T> //ok
bool Vettore<T>::empty(){ //true se il vettore è vuoto
    return size==0;
}

template <class T> //ok
Vettore<T>& Vettore<T>::merge(Vettore<T>& vec){
    for(auto it=vec.begin(); it!=vec.end(); it++){
        push_back(*it);
    }
    return *this;
}

template <class T> //ok
bool Vettore<T>::operator==(const Vettore& vec)const{
    if(info == vec.info) return true;
    if(size != vec.Size()) return false;
    bool control = true;
    for( Vettore<T>::Iteratore cont = begin(); cont != end() && control; cont++ ){
        for( Vettore<T>::Iteratore cont_vec = begin(); cont_vec != vec.end() && control; cont_vec++ ){
            if( *cont != *cont_vec ) control = false;
        }
    }
    return control;
}



template <class T>
T& Vettore<T>::operator[](u_int ind) {
    return info[ind];
}

template <class T>
const T& Vettore<T>::operator[](u_int ind) const {
    return info[ind];
}

/*template <class T>
std::ostream& operator<<(std::ostream& os,const Vettore<T>& vec){
    for(int i =0; i< vec.size; i++){
        os << vec[i] << " ";
    }
    return os;
}*/

#endif
