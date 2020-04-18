#pragma once

#include <string.h>
#include "ArrayIndexOutOfBoundException.h"
#include <iostream>

template <class T>
class ResArray
{
    public:
        /******************************************************************************************************
        * Func  : ResArray
        * Desc  : Constructor of the object. Initialize the object with an array of hardcoded length.
        * Param : None
        * Ret   : None
        ******************************************************************************************************/
        ResArray():ResArray(15){}   //default step size is 15


        /******************************************************************************************************
        * Func  : ResArray
        * Desc  : Constructor of the object. Initialize the object with an array of specified resize length.
        * Param : resize_step_size - lenthincrement of the array in one step
        * Ret   : None
        ******************************************************************************************************/
        ResArray(unsigned int resize_step_size);


        /******************************************************************************************************
        * Func  : ~ResArray
        * Desc  : Detructor of the object. Deletes the array when destroying
        * Param : None
        * Ret   : None
        ******************************************************************************************************/
        ~ResArray(){delete[] array;}


        /******************************************************************************************************
        * Func  : add
        * Desc  : Adds an element to the end of the array. Expands the array if the current array is totally filled.
        * Param : element - a constant reference to the element to be added.
        * Ret   : None
        ******************************************************************************************************/
        void add(const T& element);
        

        /******************************************************************************************************
        * Func  : add
        * Desc  : Adds an element to the specified index of the array. Expands the array if the current array is 
        *         totally filled.
        * Param : index     - index to add the element
        *         element   - a constant reference to the element to be added.
        * Ret   : None
        ******************************************************************************************************/
        void add(unsigned int index, const T& element);
        

        /******************************************************************************************************
        * Func  : set
        * Desc  : Updates the specified index with the new element.
        * Param : index     - index to update
        *         element   - a constant reference to the new element.
        * Ret   : None
        ******************************************************************************************************/
        void set(unsigned int index, const T& element);


        /******************************************************************************************************
        * Func  : get
        * Desc  : Returns the element of the specified index.
        * Param : index - index of the element to return
        * Ret   : Element in the index
        ******************************************************************************************************/
        T get(unsigned int index);


        /******************************************************************************************************
        * Func  : remove_element
        * Desc  : Removes the element at the specified position. Shifts any subsequent elements to the left
        * Param : index - the index of the element to be removed
        * Ret   : None
        ******************************************************************************************************/
        void remove_element(unsigned int index);


        /******************************************************************************************************
        * Func  : size
        * Desc  : Returns the number of elements in this array
        * Param : None
        * Ret   : The number of elements in this list
        ******************************************************************************************************/
        unsigned int size();


        /******************************************************************************************************
        * Func  : indexOf
        * Desc  : Returns the index of the first occurrence of the specified element in this list, 
        *         or -1 if this list does not contain the element.
        * Param : element - constant reference to the element to be searched.
        * Ret   : The index of the first occurrence of the specified element in this list, or -1 if this list 
        *         does not contain the element
        ******************************************************************************************************/
        int indexOf(const T& element);


        /******************************************************************************************************
        * Func  : contains
        * Desc  : Returns true if this list contains atleast one of the specified element.
        * Param : elemnt - constant reference to the element whose presence in this list is to be tested.
        * Ret   : true if this list contains the specified element. Otherwise false.
        ******************************************************************************************************/
        bool contains(const T& element);


        /******************************************************************************************************
        * Func  : operator[]
        * Desc  : Operator overloading of [].
        * Param : index - the index of the element to be accessed.
        * Ret   : A reference to the element in the specified index.
        ******************************************************************************************************/
        T& operator[](unsigned int index);
        
    private:
        T* array;
        unsigned int resize_step_size;
        unsigned int length;            //no of elements stored 
        unsigned int arr_length;        //length of the array used to store.
};


//------------------------------------function definitions------------------------------------------------

template <class T>
ResArray<T>::ResArray(unsigned int resize_step_size)
{
    this->resize_step_size = resize_step_size;
    array = new T[resize_step_size];
    this->length = 0;
    this->arr_length = resize_step_size;
}

template <class T>
void ResArray<T>::add(const T& element)
{
    if(length == arr_length) //checks whether the current array is totally filled.
    {
        T* new_array = new T[arr_length + resize_step_size];
        memcpy((void *)new_array, (const void*)array, (size_t)(arr_length*sizeof(T)));
        delete[] array;
        array = new_array;
        arr_length += resize_step_size;
    }
    
    *(array + length++) = element;
}

template <class T>
void ResArray<T>::add(unsigned int index, const T& element)
{
    if (index >= length)
    {
        ArrayIndexOutOfBoundException ex(index, length);
        throw ex;
    }
    
    if(length == arr_length) //checks whether the current array is totally filled.
    {
        T* new_array = new T[arr_length + resize_step_size];
        memcpy((void *)new_array, (const void*)array, (size_t)(index*sizeof(T)));
        *(new_array + index) = element;
        memcpy((void *)(new_array + index + 1), (const void*)(array + index), (size_t)((length-index)*sizeof(T)));
        delete[] array;
        array = new_array;
        arr_length += resize_step_size;
        length++;
    }
    else
    {
        memmove((void *)(array + index + 1), (const void*)(array + index), (size_t)((length-index)*sizeof(T)));
        *(array + index) = element;
        length++;
    }
}


template <class T>
void ResArray<T>::set(unsigned int index, const T& element)
{
    if (index >= length)
    {
        ArrayIndexOutOfBoundException ex(index, length);
        throw ex;
    }
    
    *(array+index) = element;
}


template <class T>
T ResArray<T>::get(unsigned int index)
{
    return this->operator[](index);
}

template <class T>
void ResArray<T>::remove_element(unsigned int index)
{
    if (index >= length)
    {
        ArrayIndexOutOfBoundException ex(index, length);
        throw ex;
    }
    memmove((void *)(array + index), (const void*)(array + index + 1), (size_t)((length-index-1)*sizeof(T)));
    length--;
}

template <class T>
unsigned int ResArray<T>::size()
{
    return length;
}

template <class T>
int ResArray<T>::indexOf(const T& element)
{
    for(int i = 0; i < length; i++)
    {
        if(this->get(i) == element)
        {
            return i;
        }
    }
    return -1;
}


template <class T>
bool ResArray<T>::contains(const T& element)
{
    return (this->indexOf(element)) > -1;
}


template <class T>
T& ResArray<T>::operator[](unsigned int index)
{
    if (index >= length)
    {
        ArrayIndexOutOfBoundException ex(index, length);
        throw ex;
    }
    
    return *(array+index);
}
