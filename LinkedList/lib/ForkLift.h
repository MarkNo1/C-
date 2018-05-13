//
// Created by mark on 07/05/18.
//

#ifndef LINKEDLIST_FORKLIFT_H
#define LINKEDLIST_FORKLIFT_H

#include "Container.h"
#include <iostream>
#include <sstream>
#include <string>

template <typename T> class ForkLift {
private:
  Container<T> * previous;
  Container<T> * current;
  Container<T> * following;

public:
  ForkLift();
  ~ForkLift();
  void initialization();
  void attach(Container<T> * container);
  void add_new_container_after(Container<T> *new_container);
  void add_new_container_before(Container<T> *new_container);
  Container<T> * get_previous();
  Container<T> * get();
  Container<T> * get_following();

  bool go_next();
  bool go_back();
  void remove();

  friend std::ostream &operator<<(std::ostream &out, const ForkLift &forklift) {
    int safe_print = 0;
    out << "[ ";
    (forklift.previous == nullptr)
                     ? out << " (nullptr) |"
                     : out << " " << *forklift.previous << " |";
    (forklift.current == nullptr)
                     ? out << " (nullptr) |"
                     : out << " " << *forklift.current << " |";
    (forklift.following == nullptr)
                     ? out << " (nullptr) "
                     : out << " " << *forklift.following;
    out << " ]"<<endl;

    return out;
  };
};

#include "ForkLift.inl"

#endif // LINKEDLIST_FORKLIFT_H
