using namespace std;
#include <iostream>

int main(){
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);


  cout << q.first() << endl;
  q.dequeue();
  cout << q.first() << endl;
  q.dequeue();
  cout << q.first() << endl;
  q.dequeue();

  Deque<int> d;
  d.enqueueRear(1);
  d.enqueueRear(2);
  d.enqueueFront(3);
  d.enqueueRear(4);

  cout << d.first() << endl;
  d.dequeueFront();
  cout << d.first() << endl;
  d.dequeueFront();
  cout << d.first() << endl;
  d.dequeueFront();
}
