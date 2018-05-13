#import "LinkList.h"

template <typename T> LinkList<T>::LinkList(){initialization();}

template <typename T> LinkList<T>::LinkList(Container<T> & container){
  initialization();
  first_element(container);
}

template <typename T> LinkList<T>::LinkList(const T & var){
  initialization();
  first_element(var);
}

template <typename T> LinkList<T>::~LinkList(){
  clean();
  pHead = nullptr;
  pTail = nullptr;
  delete pHead;
  delete pTail;
  delete pFork;
}

template <typename T> void LinkList<T>::initialization(){
  pHead = nullptr;
  pTail = nullptr;
  pFork = new ForkLift<T>();
  counter = 0;
  flag_iterator = 1;
}

template <typename T> void LinkList<T>::first_element(Container<T> & container){
  pHead = pTail = &container;
  pFork->attach(pHead);
  counter++;
}

template <typename T> void LinkList<T>::first_element(const T & variable){
  pHead = pTail = allocate(variable);
  pFork->attach(pHead);
}


template <typename T>
Container<T> * LinkList<T>::allocate(const T & variable){
  counter++;
  return new Container<T>(variable);
}

template <typename T> void LinkList<T>::push_back(Container<T> & container){
  if (length() == 0 ){first_element(container);}
  else {
  pFork->attach(pTail);
  pFork->add_new_container_after(&container);
  pTail = pFork->get_following();
  }
}

template <typename T> void LinkList<T>::push_back(const T & variable){
  if (length() == 0 ){first_element(variable);}
  else{
  pFork->attach(pTail);
  pFork->add_new_container_after(allocate(variable));
  pTail = pFork->get_following();
  }
}

template <typename T> void LinkList<T>::push_front(Container<T> & container){
  if (length() == 0 ){first_element(container);}
  else{
  pFork->attach(pHead);
  pFork->add_new_container_before(&container);
  pHead = pFork->get_previous();
  }
}

template <typename T> void LinkList<T>::push_front(const T & variable){
  if (length() == 0 ){first_element(variable);}
  else{
  pFork->attach(pHead);
  pFork->add_new_container_before(allocate(variable));
  pHead = pFork->get_previous();
  }
}

template <typename T> Container<T> & LinkList<T>::get(){
  return *pFork->get();
}

template <typename T> Container<T> & LinkList<T>::get(int index){
  if (index < length()){
    int count = 0;
    while(iterate()){
    if (count == index) break;
    count++;
    }
  }
  flag_iterator = true;
  return *pFork->get();

}

template <typename T> const int  LinkList<T>::length() const{
  return counter;
}
template <typename T> void LinkList<T>::print(){
  while(iterate())
    cout << *pFork;

}

template <typename T> void LinkList<T>::remove(int index){
  if (index < length()){
    // Remove 1st
    if(index == 0){
      pFork->attach(pHead);
      pFork->remove();
      pHead = pFork->get();
      counter--;
    }
    // Remove last
    else if(index == length() - 1){
      pFork->attach(pTail);
      pFork->remove();
      pHead = pFork->get();
      counter--;
    }
    else  {
      int count = 0;
      while(iterate()){
      if (count == index) {pFork->remove();break;}
      count++;
      }
      flag_iterator = true;
      counter--;
    }
  }
}

template <typename T> bool LinkList<T>::iterate() {
  if (flag_iterator){
    pFork->attach(pHead);
    flag_iterator = false;
    return true;
  }
  auto stat = pFork->go_next();
  if (!stat){
    flag_iterator = true;
    return false;
  }
  return stat;
}

template <typename T> void LinkList<T>::clean(){
  int len = length();
  if (length()>0)
    for(int i=0 ; i< len; i++) remove(0);
}
