#ifndef __STACK_H__
#define __STACK_H__

#include "list.h"

class StackList
{
private:
 List list;
public:
  // ������������
StackList();                            // List();
StackList(DataType* arr, int size);     // List(DataType* arr, int size);

  // ����������
  ~StackList();                        // ~List();

  // �������� ������
  void pop();                               
  void push(const DataType& val);          
  bool isEmpty();                          

  

  // ����� �� �����
  void print();
};

#endif  // __QUEUE_H__
