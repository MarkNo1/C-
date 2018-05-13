//
// Created by mark on 07/05/18.
//

#ifndef LINKEDLIST_CONTAINER_H
#define LINKEDLIST_CONTAINER_H

#include <iostream>

using namespace std;

template <typename T> class Container {
private:
  T *variable;
  Container<T> *pNext;
  Container<T> *pBack;

public:
  Container();
  Container( const  T &var);
Container( Container &container);
  ~Container();

  const T &get_variable();
  Container<T> *get_pNext();
  Container<T> *get_pBack();

  void set_pNext(Container<T> *next);
  void set_pBack(Container<T> *back);

  friend std::ostream &operator<<(std::ostream &out,
                                  const Container &container) {
    out << "(";
    out << *container.variable << ")";
    return out;
  };
};

#include "Container.inl"

#endif // LINKEDLIST_CONTAINER_H
