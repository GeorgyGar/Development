#include "stack.h"

StackList::StackList() {}
StackList::StackList(DataType* arr, int size) : list(arr, size) { }

// ����������
StackList::~StackList() {}

// �������� ������
void StackList::pop() {
	list.DeleteToTail();
}

void StackList::push(const DataType& val) {
	list.InsertToTail(val);
}

bool StackList::isEmpty() {
	return list.isEmpty();
}

// ����� �� �����
void StackList::print() {
	list.print("<-");
}