#include "node.h"
using namespace std;

node::node(){
  data_ = 0;
  link_ = nullptr;
}
node::node(const int& initdata, node * initlink){
    data_ = initdata;
    link_ = initlink;
}

int node::data() const{
    return data_;
}

node * node::link(){
    return link_;
}

//returns constant node pointer
const node * node::link() const{
    return link_;
}

void node::set_data(const int & newdata){
    data_ = newdata;
}

void node::set_link(node * newlink){
    link_ = newlink;
}

std::size_t list_index(node*head_ptr, int target){
  int counter = 0;
  for (const node *p = head_ptr; p != nullptr; p = p->link()){
    if (p->data() == target){
      return counter;
    }
    counter++;
  }
  return -1;
}

node* list_at(node * head_ptr, std::size_t n){
  node* rv;
  int counter = 0;
  for (node *p = head_ptr; p != nullptr; p = p->link()){
    if (counter == n){
        rv = p;
    }
    counter++;
  }
  return rv;
}

int main(){
  node* head;
  node* tail;
  head = new node(3 ,nullptr);
  head = new node(2 ,head);
  head = new node(1 ,head);
  for (const node *p = head; p != nullptr; p = p->link()){
    cout << p->data() << endl;
  }
  cout << list_index(head ,3) << endl;
  cout << list_at(head ,2) << endl;

  return 0;
}
