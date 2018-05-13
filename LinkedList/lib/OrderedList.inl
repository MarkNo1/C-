#include <iostream>

template<class T> bool OrderedList<T>::check_order(const T &a, const T &b){
  return (a<=b) ? true : false;
}

template<class T> void OrderedList<T>::append(Container<T> & container){
  // Empty
  if (this->length() == 0 ){
    this->first_element(container);}
  // Minor then the head - First
  else if (check_order(container.get_variable(), this->pHead->get_variable()))
  {
    this->pFork->attach(this->pHead);
    this->pFork->add_new_container_before(&container);
    this->pHead = this->pFork->get_previous();
  }
  // Major then the tail - Last
  else if (check_order(this->pTail->get_variable(),container.get_variable()))
  {
    this->pFork->attach(this->pTail);
    this->pFork->add_new_container_after(&container);
    this->pTail = this->pFork->get_following();
  }
  // Somewhere in between - Middle
  else
  {
    while(this->iterate())
    {
      if (check_order(container.get_variable(), this->pFork->get()->get_variable())){
        this->pFork->add_new_container_before(&container);
        this->flag_iterator = true;
        break;
      }
    }
  }
}

template<class T> void OrderedList<T>::append(const T & variable){
  // Empty
  if (this->length() == 0 ){this->first_element(variable);}
  // Minor then the head - First
  else if (check_order(variable, this->pHead->get_variable()))
  {
    this->pFork->attach(this->pHead);
    this->pFork->add_new_container_before(this->allocate(variable));
    this->pHead = this->pFork->get_previous();
  }
  // Major then the tail - Last
  else if (check_order(this->pTail->get_variable(),variable))
  {
    this->pFork->attach(this->pTail);
    this->pFork->add_new_container_after(this->allocate(variable));
    this->pTail = this->pFork->get_following();
  }
  // Somewhere in between - Middle
  else
  {
    while(this->iterate())
    {
      if (check_order(variable, this->pFork->get()->get_variable())){
        this->pFork->add_new_container_before(this->allocate(variable));
        this->flag_iterator = true;
        break;
      }
    }
  }
}
