#include "DoubleLinkedList.h"
#include <iostream>


std::ostream& operator<< (std::ostream &out, DoubleLinkedList &src)
{
    src.outAll();
    return out;
}

int main() {
    DoubleLinkedList list;   // �������� ������� ������
    list.insertHead(1);      // ���������� ���������
    list.insertHead(2);
    list.insertHead(3);
    std::cout << "First list:" << std::endl;
    list.outAll();           // ������ ���������

    std::cout << ((list.searchItem(1))?  "1 find" : "1 not find") << std::endl;
    std::cout << ((list.searchItem(8)) ? "8 find" : "8 not find") << std::endl;

    DoubleLinkedList  list1(list); // (list);  // ����������� ������
    list1.insertHead(4);         // ���������� ��������
    list1.insertHead(5);         // ���������� ��������
    list1.deleteHead();          // �������� ���������
    std::cout << "Second list, copied from first:" << std::endl;
    list1.outAll();
    list1.insertTail(6);
    list1.deleteTail(); // �������� ���������� �������� 
    list1.deleteItem(3);
    std::cout << "Second list, after deleting:" << std::endl;
    list1.outAll();  // ������ ����������
    std::cout << "Checking overloaded operator <<:" << std::endl;
    std::cout << list; // �������� �������������� ��������� ������
    std::cout << "Checking list comparing:" << std::endl;
    bool temp = list == list1; // �������� �������������� ��������� ���������
    std::cout << temp << std::endl;
    list1.insertHead(5);
    list = list1; // �������� ����������-����������� ����� copy-and-swap ������
    std::cout << "Checking copy-and-swap idiom:" << std::endl;
    list.outAll();
    list1.outAll();
    list.appendInTheEnd(list1); // ���������� ������ ������ � ����� �������
    std::cout << "Merged lists:" << std::endl;
    list.outAll();

    return 0;
}

