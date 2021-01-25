//
// Created by 신태영 on 2017-03-28.
//

#ifndef PROJECT6A_INTLIST_H
#define PROJECT6A_INTLIST_H

class IntList {
public:
    IntList(void);
    ~IntList(void);

    int get_item_at(int index) const;
    void set_item_at(int index, int item);
    int size(void) const;
    void append(int item);
    int pop(int index);
    void insert(int index, int item);

private:
    int _size;
    int _storage_size;
    int *_storage_ptr;

    void _prepare_to_add_item(void);
    void _open_array_slot(int index);
    void _close_array_slot(int index);
};

#endif //PROJECT6A_INTLIST_H
