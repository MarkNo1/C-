//
// Created by mark on 07/05/18.
//

#include "OrderedList.h"
#include <iostream>

using namespace std;
int main(){

  // Testing container
  std::cout << " ____ CONTAINER ____" << std::endl;

  Container<int> * c0 = new Container<int>(0);
  std::cout << *c0 << std::endl;
  Container<int> * c1 = new Container<int>(1);
  std::cout << *c1 << std::endl;
  int a {2} ;
  Container<int> * c2 = new Container<int>(a);
  std::cout << *c2 << std::endl;
  Container<int> * c3 = new Container<int>(3);
  std::cout << *c3 << std::endl;
  Container<int> * c_del = new Container<int>(4);
  std::cout << *c_del << std::endl;
  delete c_del;
  c_del= nullptr;


// Testing Forklift
  std::cout << " ____ FORKLIFT ____" << std::endl;
  c0->set_pNext(c1);
  c1->set_pBack(c0);
  c1->set_pNext(c2);
  c2->set_pBack(c1);
  c2->set_pNext(c3);
  c3->set_pBack(c2);

  ForkLift<int> forklift;
  forklift.attach(c1);
  cout << "\nAttached at C1" << endl;
  cout << forklift << endl;

  cout << "\nAdd c4 at the right" << endl;
  Container<int> * c4 = new Container<int>(4);
  forklift.add_new_container_after(c4);

  cout << forklift;
  cout << "\nremove C1" << endl;

  forklift.remove();

  cout << forklift;


  cout << "\nAdd c5 at the left" << endl;
  Container<int> * c5 = new Container<int>(5);
  forklift.add_new_container_before(c5);

  cout << forklift;


  cout << "MOVE NEXT  = "<< forklift.go_next() << endl;
  cout << forklift;

  cout << "MOVE NEXT  = "<< forklift.go_next() << endl;
  forklift.go_next();
  cout << forklift;

  cout << "MOVE NEXT  = "<< forklift.go_next() << endl;
  forklift.go_next();
  cout << forklift;

  cout << endl << endl;


  // Testing LinkList
  std::cout << " ____ LINKLIST ____" << std::endl;
  cout << "* Pushback and Pushfront * " <<endl;

    int t {27};
    LinkList<int>  ll(t);
    ll.push_back(28);
    ll.push_back(29);
    ll.push_back(30);
    ll.push_front(26);
    ll.push_front(25);
    ll.push_front(24);
    cout << ll;

  cout << "* Iterator * " <<endl;
    while(ll.iterate())
        cout << ll.get() << "-";
    cout << endl;
    while(ll.iterate())
        cout << ll.get() << "-";

  cout << "\n * Get 3 * " <<endl;

  auto container = ll.get(3);
  cout << container;

  cout << "\n * Remove 2 * " <<endl;
  ll.remove(2);
  cout << ll;

  cout << "\n * Clean LinkList * " <<endl;
  ll.clean();
  cout << ll;

  cout << endl;

  ll.push_back(1000);
  ll.push_back(10280);

  cout << ll;

  std::cout << " ____ ORDEREDLIST ____" << std::endl;
  OrderedList<string> ols;
  Container<string> * s1 = new Container<string>("E");
  Container<string> * s2 = new Container<string>("N");
  Container<string> * s3 = new Container<string>("I");
  Container<string> * s4 = new Container<string>("K");
  Container<string> * s5 = new Container<string>("O");
  ols.append(* s1);
  ols.append(* s2);
  ols.append(* s3);
  ols.append(* s4);
  ols.append(* s5);
  ols.append("H");
  ols.append("A");
  ols.append("P");
  ols.append("P");
  ols.append("Y");
  // ols.print();
  cout << ols;


  OrderedList<int> ol;
  ol.append(1);
  ol.append(10);
  ol.append(3);
  ol.append(9);
  ol.append(99);
  ol.append(8);
  ol.append(0);
  ol.append(128);
  cout << ol;
  // ol.print();

  cout <<" END TESTING LINKED LIST !" << endl;
  return 0;
}
