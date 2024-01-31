#include <iostream>
// #include "genlist.h"


template <typename T>
class List {
    private:
        int size;
        int memorysize;
        T* tab;
    public:
        List(int memsize);
        T get(int index);
        int len(){ return size;};
        void add(T e);
        void setmemorysize(int newsize);
        void set(int index, T e);
};

template <typename T>
List<T>::List(int size)
    : size(0),
    memorysize(size)
    {
        tab = new T[size];
    }

template <typename T>
T List<T>::get(int index){
    return tab[index];
}


template <typename T>
void List<T>::add(T e){
    if(size<memorysize){
        tab[size] = e;
        size++;
    } else {
        tab = (int*)realloc(tab, memorysize+1);
        tab[size] = e;
        size++;
        memorysize++;
    }
}

template <typename T>
void List<T>::setmemorysize(int newsize){
    memorysize = newsize;
    tab = (int*)realloc(tab, memorysize);
    if(size>memorysize){
        size = memorysize;
    }

}

template <typename T>
void List<T>::set(int index, T e){
    tab[index] = e;
}


int main() {
    List<int> *l = new List<int>(3);
    l->add(1);
    l->add(1);
    l->add(1);
    l->add(1);
    l->add(1);
    std::cout << l->get(0) << std::endl;
    std::cout << l->get(1) << std::endl;
    std::cout << l->get(2) << std::endl;
    std::cout << l->get(3) << std::endl;
    std::cout << l->get(4) << std::endl;


    l->set(2, 3);
    std::cout << l->get(2) << std::endl;

    l->setmemorysize(4);
    l->setmemorysize(6);

}