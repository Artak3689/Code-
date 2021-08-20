#ifndef sheird_ptr.h
#define sheird_pte.h
#include <iostream>
#include"sheird_ptr.cpp"
template<typename T>
Sheird_ptr<T>::Sheird_ptr()
{
        m_ptr = NULL;
        buf = nullptr;
}
template<typename T>
Sheird_ptr<T>::Sheird_ptr(T*in_ptr)
{
        m_ptr=in_ptr;
        buf = new DataPointer<T>;
        buf->count++ ;
        buf->Del_ptr = Deletor<T>;
}
template<typename T>
Sheird_ptr<T>::Sheird_ptr(const Sheird_ptr<T>& tmp)
{
        this->m_ptr=tmp.m_ptr;
        this->buf = tmp.buf;
        this->buf->count++ ;
        buf->Del_ptr = Deletor<T>;
}
template<typename T>
Sheird_ptr<T>::Sheird_ptr(Sheird_ptr<T>&& tmp)
{
        this->m_ptr=tmp.m_ptr;
        this->buf = tmp.buf;
        tmp.m_ptr =nullptr ;
        tmp.buf=nullptr ;
}
template<typename T>
Sheird_ptr<T> Sheird_ptr<T>::operator=(const Sheird_ptr<T>& tmp)
{
        if(this == &tmp){return *this;}
        delete m_ptr ;
        delete buf;
        this->m_ptr=tmp.m_ptr;
        this->buf=tmp.buf;
        this->buf->count++ ;
        return tmp ;
}
template<typename T>
Sheird_ptr<T>::~Sheird_ptr()
{
        buf->count--;
        if(!buf->count)
        {
                buf->Del_ptr(m_ptr);
        }
}
template<typename T>
T& Sheird_ptr<T>::operator[](int index){return m_ptr[index];}
#endif
