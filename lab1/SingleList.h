#ifndef CPP_PROJECTS_SINGLELIST_H
#define CPP_PROJECTS_SINGLELIST_H
#include <iostream>

class SingleList
{
private:

    struct Node
    {
        int data_;
        Node* next_;

        Node(int data, Node* next = nullptr):
                data_(data),
                next_(next)
        {}

    };

    Node* root_;
    size_t count_;

public:

    SingleList();

    SingleList(SingleList &&copyValue) noexcept;

    ~SingleList();

    void SingleList::operator+= (const int x);

    friend std::ostream &operator<< (std::ostream &output, const SingleList &list);

    bool operator==(SingleList& value);

    SingleList::SingleList(const SingleList &copyVal);

    friend SingleList operator& (const SingleList& firstValue, const SingleList& secondValue);

    friend SingleList operator| (const SingleList& firstValue, const SingleList& secondValue);

    void merge(SingleList& list);

    void SingleList::insert(Node* val);

    bool SingleList::checkNonRepetitiveElements(Node* val);

    void SingleList::sort();

    void SingleList::insertHead(int value);

    size_t getCount() const;
};


#endif //CPP_PROJECTS_SINGLELIST_H
