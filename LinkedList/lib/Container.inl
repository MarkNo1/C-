//
// Created by mark on 07/05/18.
//

#include "Container.h"

template <typename T> Container<T>::Container() {
  variable = new T();
  pNext = nullptr;
  pBack = nullptr;
}

template <typename T> Container<T>::Container(const T &var){
  variable = new T(var);
  pNext = nullptr;
  pBack = nullptr;
}

template <typename T> Container<T>::Container( Container &container) {
  variable = new T(container.get_variable());
  pNext = container.get_pNext();
  pBack = container.get_pBack();
}

template <typename T> Container<T>::~Container() {
  delete variable;
  pNext = nullptr;
  pBack = nullptr;
  delete pNext;
  delete pBack;
}

template <typename T> const T & Container<T>::get_variable() { return *variable; }
template <typename T> Container<T> * Container<T>::get_pNext() { return pNext; }
template <typename T> Container<T> * Container<T>::get_pBack() { return pBack; }

template <typename T> void Container<T>::set_pNext(Container<T> *next) { pNext = next; }
template <typename T> void Container<T>::set_pBack(Container<T> *back) { pBack = back; }
