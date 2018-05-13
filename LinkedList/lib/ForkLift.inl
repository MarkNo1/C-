//
// Created by mark on 07/05/18.
//

#include "ForkLift.h"
#include <iostream>

template <typename T> ForkLift<T>::ForkLift() {
  initialization();
}

template <typename T> ForkLift<T>::~ForkLift() {
  initialization();
  delete previous;
  delete current;
  delete following;
}

template <typename T> void ForkLift<T>::initialization(){
  previous = nullptr;
  current = nullptr;
  following = nullptr;
}

template <typename T> void ForkLift<T>::attach(Container<T> *container) {
  current = container;
  previous = container->get_pBack();
  following = container->get_pNext();
}

template <typename T>
void ForkLift<T>::add_new_container_after(Container<T> *new_container) {
  if (following == nullptr) {
    current->set_pNext(new_container);
    new_container->set_pBack(current);
  } else {
    current->set_pNext(new_container);
    new_container->set_pBack(current);
    new_container->set_pNext(following);
    following->set_pBack(new_container);
  }
  attach(current);
}
template <typename T>
void ForkLift<T>::add_new_container_before(Container<T> *new_container) {
  if (previous == nullptr) {
    current->set_pBack(new_container);
    new_container->set_pNext(current);
  } else {
    current->set_pBack(new_container);
    new_container->set_pNext(current);
    new_container->set_pBack(previous);
    previous->set_pNext(new_container);
  }
  attach(current);
}

template <typename T> Container<T> * ForkLift<T>::get_previous(){return previous;}
template <typename T> Container<T> * ForkLift<T>::get(){return current;}
template <typename T> Container<T> * ForkLift<T>::get_following(){return following;}

template <typename T> bool ForkLift<T>::go_next() {
  if (following != nullptr) {
    attach(following);
    return true;
  }
  return false;
}
template <typename T> bool ForkLift<T>::go_back() {
  if (previous != nullptr) {
    attach(previous);
    return true;
  }
  return false;
}

template <typename T> void ForkLift<T>::remove() {
  if (previous != nullptr)
    previous->set_pNext(following);

  if (following != nullptr)
    following->set_pBack(previous);

  if (current != nullptr)
    delete current;

  if (previous != nullptr)
    attach(previous);
  else if (following != nullptr)
    attach(following);
  else
    current = nullptr;
};
