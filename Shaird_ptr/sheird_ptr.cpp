#ifndef sheird_ptr.cpp
#define sheird_ptr.cpp
#include <iostream>
template<typename T>
void Deletor(T*m_ptr)
{
        delete m_ptr;
}
template<typename T>
struct DataPointer
{
        int count = 0;
        void(*Del_ptr)(T*);
};
template<typename T>
class Sheird_ptr
{
private:
        T* m_ptr;
        DataPointer<T>* buf;
public:
        Sheird_ptr();
        Sheird_ptr(T*);
        Sheird_ptr(const Sheird_ptr&);
        Sheird_ptr(Sheird_ptr &&);
        ~Sheird_ptr();
        T& operator[](int);
        Sheird_ptr<T> operator=(const Sheird_ptr<T>&);
};
#endif
