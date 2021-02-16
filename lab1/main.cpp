#include "SingleList.h"
#include <iostream>

int main()
{
    SingleList list2;
    SingleList list1;

    list1.insertHead(5);
    list1 += 4;
    list1 += 5;
    list1 += 321;
    list1 += 66;
    std::cout << list1;

    list2 += 7;
    list2 += 321;
    list2 += 66;
    std::cout << list2 << '\n';

    SingleList listCopyFromFirst(list1);
    std::cout   << "First list size: " << list1.getCount() << '\n';

    if (list1 == list2)
    {
        std::cout << "Lists are equal" << '\n';
    }
    else
    {
        std::cout << "Lists are not equal" << '\n';
    }

    std::cout << "Copied list from the first one" << '\n';
    std::cout << listCopyFromFirst << '\n';
    std::cout << "Overload output &"<< '\n';
    SingleList ListOverloadFirst = list1 & list2;
    std::cout << ListOverloadFirst ;
    std::cout << "Overload output |"<< '\n';
    SingleList ListOverloadSecond = list1 | list2;
    std::cout << ListOverloadSecond;
    std::cout << "Output of the merge method"<< '\n';
    list1.merge(list2);
    std::cout << list1;

    return 0;
}
