#ifndef ORDERED_LIST_
#define ORDERED_LIST_

#import "LinkList.h"

template <class T>
class OrderedList: public LinkList<T>{
public:
  void append(Container<T> & container);
  void append(const T & var);
  bool check_order(const T &a, const T &b);

};

#include "OrderedList.inl"



#endif //ORDERED_LIST_
