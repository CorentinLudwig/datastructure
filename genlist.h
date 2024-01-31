

#include <iostream>


template <typename T>
class List {
    private:
        int size;
        int memorysize;
        T tab[];
    public:
        List(int memsize);

        T get(int index);
        int len(){ return size;};
        void add(T e);
};