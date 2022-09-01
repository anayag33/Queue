using namespace std;
#include <iostream>

template <typename T>
class Deque{
private:
  struct node{
    T data;
    node* next;
    node* prev;
    node(int d, node* n = nullptr, node* p = nullptr): data(d), next(n), prev(p){}
  };
  node* front;
  node* rear;
  int count;
public:
  Deque():front(nullptr), rear(nullptr), count(0){}
  void clear(){
    while (front != nullptr){
      node* tmp = front;
      front = front -> next;
      delete tmp;
    }
  }
  Deque(const Deque<T>& other):front(nullptr), rear(nullptr), count(0){
    node* pother = other.front;
    while(pother != nullptr){
      this->add(pother->data, count);
      count++;
      pother = pother->next;
    }
  }
  Deque& operator= (const Deque<T>& other){
    if (this == &other){
      return *this;
    }
    if(this ->front != nullptr){
      clear ();
      delete front;
      node* pother = other.front;
      while(pother != nullptr){
        this->add(pother->data, count);
        count++;
        pother = pother->next;
      }
    }
    return *this;
  }
  void add (const T& x, int p){
    if (p<0 || p>count){
      cout << "Error" << endl;
      return;
    }
    if (p==0 && front == nullptr){
      front = new node(x);
    }
    else if (p==0){
      front = rear = new node (x);
    }
    else if (p >= 1 && p<=count-1){
      node* back = front;
      node* pcurr = front;
      pcurr = pcurr ->next;
      while (pcurr -> next != nullptr && pcurr){
        pcurr = pcurr->next;
        back = back->next;
      }
      pcurr->next = new node(x, nullptr, back);
    }
  }
  ~Deque(){
    clear();
  }
  void enqueueRear(T d){
    node* n = new node(d);
    node* temp = front;
    if(front == nullptr){
      n->prev = nullptr;
      front = n;
      return;
    }
    while (temp -> next != nullptr){
      temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    count ++;
  }
  void enqueueFront(T d){
    node* n = new node(d, front, nullptr);
    if (front != nullptr){
      front -> prev = n;
      front = front -> prev;
    }
    else{
      front = n;
    }
    count++;
  }
  void dequeueRear(){
    node* temp = rear;
    rear = rear ->prev;
    delete temp;
    count--;
    if (!rear){front = nullptr;}
  }
  void dequeueFront(){
    node* temp = front;
    front = front ->next;
    delete temp;
    count--;
    if (!front){rear = nullptr;}
  }


  T first(){
    if (front != nullptr){
      return front->data;
    }
  }
  T last(){
    if (rear != nullptr){
      return rear->data;
    }
  }
  int size(){return count;}
  bool empty(){return size() == 0;}
};
