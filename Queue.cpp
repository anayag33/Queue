using namespace std;
#include <iostream>

class Queue{
private:
  struct node{
    int data;
    node* next;
    node(int d, node* n = nullptr): data(d), next(n){}
  };
  node* head;
  node* tail;
  int count;
public:
  Queue():head(nullptr), tail(nullptr), count(0){}
  void clear(){
    while (head != nullptr){
      node* tmp = head;
      head = head -> next;
      delete tmp;
    }
  }
  Queue(const Queue& other):head(nullptr), tail(nullptr), count(0){
    node* pother = other.head;
    while(pother != nullptr){
      this->add(pother->data, count);
      count++;
      pother = pother->next;
    }
  }
  Queue& operator= (const Queue& other){
    if (this == &other){
      return *this;
    }
    if(this ->head != nullptr){
      clear ();
      delete head;
      node* pother = other.head;
      while(pother != nullptr){
        this->add(pother->data, count);
        count++;
        pother = pother->next;
      }
    }
    return *this;
  }
  void add (const int& x, int p){
    if (p<0 || p>count){
      cout << "Error" << endl;
      return;
    }
    if (p==0 && head == nullptr){
      head = tail = new node(x);
    }
    else if (p >= 1 && p<=count-1){
      node* pcurr = head;
      while (pcurr -> next != nullptr && pcurr){
        pcurr = pcurr->next;
      }
      pcurr->next = new node(x, head);
      tail = pcurr -> next;
    }
  }
  ~Queue(){
    clear();
  }

  void enqueue(int d){
    if (tail != nullptr){
      tail -> next = new node(d, head);
      tail = tail -> next;
    }
    else{
      tail = head = new node(d);
    }

    count++;
  }
  void dequeue(){
    node* temp = head;
    head = head ->next;
    delete temp;
    //tail -> next = head;
    count--;
    if (!head){tail = nullptr;}

    node* p = head;
    for (int i = 0; i < 8; i++){
      node* n = p->next;
      cout << n -> data;
      p = p->next;
    }
    cout << endl;
  }
  int first(){
    if (head != nullptr){
      return head->data;
    }
  }
  int size(){return count;}
  bool empty(){return size() == 0;}
  void push(int d){enqueue(d);}
  void pop(){dequeue();}
};
