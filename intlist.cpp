
// Created by Kevin Shin on 2017-03-28.

#include "intlist.h"

//Initializie IntList into the memory
IntList::IntList(void) {
    _size = 0;
    _storage_size = 2;
    _storage_ptr = new int [_storage_size];

}
//Deconstructing Intlist out of memory
IntList::~IntList(void) {

}
//Getting the item from the list
int IntList::get_item_at(int index) const{

    return _storage_ptr[index];

}
//Setting the new item to the list
void IntList::set_item_at(int index, int item){
    _storage_ptr[index] = item;

}
//Returning the size of the list
int IntList::size(void) const{
    return _size;

}
void IntList::append(int item){
    _prepare_to_add_item();
    _storage_ptr[_size]= item;
    ++_size;

}
// return the integer at given index
int IntList::pop(int index)
{
    int tmp = _storage_ptr[index];
    _close_array_slot(index);
    --_size;   
    return tmp;

}

//inserting new value of item to the list
void IntList::insert(int index, int item) {
    _prepare_to_add_item();
    _open_array_slot(index);
    _storage_ptr[index] = item;
    ++_size;

}

//checking whether there is a extra space for new values to come into
void IntList::_prepare_to_add_item(void) 
{
    if (_size == _storage_size) 
    {
        //The array needs to be replaced with one twice as big
        int *new_array = new int[2 * _storage_size];
        for (int i = 0; i < _storage_size; ++i)
        {
            new_array[i] = _storage_ptr[i];
        }
        delete [] _storage_ptr;
        _storage_ptr = new_array;
        _storage_size *= 2;
    }
}

//generating open slot method for insert function
void IntList::_open_array_slot(int index)
{
    for (int i = index+1; i<_size; ++i)
    {
        _storage_ptr[i] = _storage_ptr[i-1];
    }
}

//designing close array method for pop operation
void IntList::_close_array_slot(int index)
{
    for (int i = index; i<_size-1; ++i)
    {
        _storage_ptr[i] = _storage_ptr [i+1];
    }
}