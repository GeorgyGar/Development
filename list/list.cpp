#include "list.h"

Node::Node(DataType d, Node* n) : data(d), next(n) {
}

Node::Node(const Node& node2) {
    data = node2.data;
}

bool Node::operator==(const Node& node2) const {
    return (data == node2.data);
} 

List::List() {
    head = nullptr;
}



List::~List() {
    Node* tmp, * tmp1; // óêàçàòåëü-õîäèëêà
    tmp = head;
    tmp1 = tmp;
    while (tmp1 != nullptr)
    {
        tmp1 = tmp->next;
        delete tmp;
        tmp = tmp1;
    }
}


void List::InsertToHead(const DataType& d)
{
    if (isEmpty())
    {
        head = new Node(d, nullptr); // ýòî ïåðâûé è åäèíñòâåííûé
    }
    else
    {
        head = new Node(d, head);
    }
}
void List::DeleteToTail()
{
    bool flag = true;
    if (isEmpty()) 
    {
        cout << "Пустой стек";
        throw "Err";
    }
    else
    {
        Node* tmp;
        tmp = head;
        Node* tmp2;
        tmp2 = head;
        tmp2 = tmp2->next;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else
        {
            while (tmp->next != nullptr && flag == true) {

                if (tmp2->next != nullptr) {
                    tmp = tmp->next;
                   tmp2 = tmp2->next;
                   
                }
                else {
                    flag = false;
                }
              
            }
            tmp->next = nullptr;
        }
    }
}

void List::InsertToTail(const DataType& d)
{
    if (isEmpty())
    {
        head = new Node(d, nullptr); // ýòî ïåðâûé è åäèíñòâåííûé
    }
    else
    {
        Node* p = new Node(d, nullptr);
        Node* tmp; // óêàçàòåëü-õîäèëêà
        tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        // â èòîãå - tmp - ïîñëåäíèé
        tmp->next = p;
    }
}

void List::Clean()
{
    Node* tmp;
    if (isEmpty())
        return;

    while (head->next != nullptr)
    {
        tmp = head->next;
        head->next = tmp->next; // head->next->next;
        delete tmp;
    }
    delete head;
    head = nullptr;
}

void List::Delete(const DataType& d)
{
    // íàéòè çíà÷åíèå
    // íàéòè òîãî, êòî ïåðåä íèì
    Node* prev = head;
    Node* tmp;
    bool find = false;

    // äàííûå â ãîëîâå
    if (head->data == d)
    {
        head = head->next;
        delete prev; // ñåé÷àñ ýòî ãîëîâà
        find = true;
    }

    while (!find && (prev->next != nullptr))
    {
        if (prev->next->data == d)
        {
            // prev->next - ýòî çâåíî
            tmp = prev->next;
            prev->next = prev->next->next; // tmp->next
            delete tmp;
            find = true;
        }
        else
            prev = prev->next;
    }
}


List::List(DataType* arr, int size) {
    if (arr != nullptr) {
        head = new Node(arr[0], nullptr);
        Node* tmp = head;                              // óêàçàòåëü íà íà÷àëî ÍÈÊÎÃÄÀ íå èñïîëüçóåì äëÿ äâèæåíèÿ ïî ñïèñêó!!!!
        for (int i = 1; i < size; i++) {
            Node* elem = new Node(arr[i], nullptr);      // ñîçäà¸ì çâåíî
            tmp->next = elem;                            // öåïëÿåì åãî
            tmp = tmp->next;                             // ñäâèãàåì âðåìåííûé óêàçàòåëü
        }
    }
    else {
        throw std::exception("Empty Input Data!");
    }
}

void List::DeleteHead() {
    if (!isEmpty()) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void List::print(char* direction = "->") {    // íàéòè äðóãîé ñïîñîá ôèêñà
    if (!isEmpty()) {
        Node* tmp = head;
        while (tmp->next != nullptr) {
            std::cout << "(" << tmp->data << ")" << direction;                   // (1)->(3)->(2)->
            tmp = tmp->next;                                                     // ñäâèãàåì âðåìåííûé óêàçàòåëü
        }
        std::cout << "(" << tmp->data << ")" << direction;
    }
    std::cout << "NULL" << std::endl;                                        // (1)->(3)->(2)->NULL
}