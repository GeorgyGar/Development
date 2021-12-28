#ifndef __STACK_H__
#define __STACK_H__

#include "list.h"

class StackList
{
private:
 List list;
public:
  // конструкторы
StackList();                            // List();
StackList(DataType* arr, int size);     // List(DataType* arr, int size);

  // деструктор
  ~StackList();                        // ~List();

  // основные методы
  void pop();                               
  void push(const DataType& val);          
  bool isEmpty();                          

  

  // вывод на экран
  void print();
};

#endif  // __QUEUE_H__
