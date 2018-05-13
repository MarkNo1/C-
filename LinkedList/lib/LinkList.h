
#ifndef LINKEDLIST_LINKLIST_H
#define LINKEDLIST_LINKLIST_H

#include "ForkLift.h"
#include <iostream>
using namespace std;

template <typename T> class LinkList {
protected:
  Container<T> * pHead;
  Container<T> * pTail;
  ForkLift<T> * pFork;
  int counter;
  bool flag_iterator;

  void initialization();
  Container<T> * allocate(const T & variable);

public:
  LinkList();
  LinkList(Container<T> & container);
  LinkList(const T & var);
  ~LinkList();

  void first_element(Container<T> & container);
  void first_element(const T & variable);

  void push_back(const T & variable);
  void push_back(Container<T> & container);

  void push_front(const T & variable);
  void push_front(Container<T> & container);

  Container<T> & get();
  Container<T> & get(int index);

  bool iterate();
  void remove(int index);
  void clean();


  const int length() const;
  void print();

  friend std::ostream &operator<<(std::ostream &out, const LinkList &linklist) {
  if (linklist.length()>0){
      out << "{ ";
      int count=0;
      linklist.pFork->attach(linklist.pHead);
      do{
        cout <<"\n";
        cout << count <<": "<< *linklist.pFork->get();
        count++;
      }while(linklist.pFork->go_next());
      out << "\n}"<<endl;
  }
  else{ out << "{ EMPTY }" ;}
  return out;
  };


};
#include "LinkList.inl"

#endif // LINKEDLIST_LINKLIST_H
