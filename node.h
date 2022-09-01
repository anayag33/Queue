#ifndef NODE_H
#define NODE_H
#include <iostream>
class node
{
public:

    node(const int & initdata, node * initlink);
    
    node();

    int data() const;

    node * link();

    const node * link() const;

    void set_data(const int & newdata);

    void set_link(node * newlink);

    std::size_t list_index(node * head_ptr, int target);

    node* list_at(node * head_ptr, std::size_t n);

private:
    int data_;
    node * link_;
};



#endif // NODE_H
