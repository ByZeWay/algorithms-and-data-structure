#include "SingleList.h"

SingleList::SingleList()
{
    this->count_ = 0;
    this->root_ = nullptr;
}

SingleList::SingleList(SingleList &&copyValue) noexcept
{
    this->root_ = copyValue.root_;
    this->count_ = copyValue.count_;
    copyValue.root_ = nullptr;
    copyValue.count_ = 0;
}

SingleList::~SingleList()
{
    while(count_ > 0)
    {
        Node* temp = this->root_;
        root_ = root_->next_;
        delete temp;
        count_ -= 1;
    }
}

void SingleList::operator+= (const int x)
{
    Node* temp = new Node(x);
    this->insert(temp);
}

std::ostream &operator<<(std::ostream &output, const SingleList &list)
{
    SingleList::Node* current = list.root_;
    while(current != nullptr)
    {
        output << current->data_ << " ";
        current = current->next_;
    }
    output << "\n";
    return output;
}

bool SingleList::operator==(SingleList& anotherList)
{
    Node *firstTemp = root_;
    Node *secondTemp = anotherList.root_;

    if(count_ != anotherList.count_)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < count_; i++)
        {
            if (firstTemp->data_ != secondTemp->data_)
            {
                return false;
            }
        }
        return true;
    }
}

SingleList::SingleList(const SingleList &copyVal):
    count_(0), root_(nullptr)
{
    Node* temp = copyVal.root_;
    while (temp != nullptr)
    {
        insert(new Node(temp->data_));
        temp = temp->next_;
    }
}

SingleList operator&(const SingleList &firstValue, const SingleList &secondValue)
{
    SingleList thirdValue;
    SingleList::Node *temp;
    temp = firstValue.root_;
    for (int i = 0; i < firstValue.getCount(); ++i)
    {
        SingleList::Node* valueTwo = secondValue.root_;
        for (int j = 0; j < secondValue.getCount(); ++j)
        {
            if (temp->data_ == valueTwo->data_)
            {
                thirdValue.insert(new SingleList::Node(temp->data_));
                break;
            }
            valueTwo = valueTwo->next_;
        }
        temp = temp->next_;
    }
    return thirdValue;
}

SingleList operator|(const SingleList &firstValue, const SingleList &secondValue)
{
    SingleList thirdValue;
    SingleList::Node* temp = firstValue.root_;
    for (int i = 0; i < firstValue.getCount(); ++i)
    {
        thirdValue.insert(new SingleList::Node(temp->data_));
        temp = temp->next_;
    }
    temp = secondValue.root_;
    for (int i = 0; i < secondValue.getCount(); ++i)
    {
        thirdValue.insert(new SingleList::Node(temp->data_));
        temp = temp->next_;
    }
    return thirdValue;
}

void SingleList::merge(SingleList &newList)
{
    Node* temp = newList.root_;
    while (temp != nullptr)
    {
        insert(new Node(temp->data_));
        temp = newList.root_->next_;
        delete newList.root_;
        newList.count_--;
        newList.root_ = temp;
    }
}

void SingleList::insert(Node* val)
{
    if (!checkNonRepetitiveElements(val))
    {
       val->next_ = nullptr;
        if (root_ == nullptr) {
            this->root_ = val;
        } else if (root_->next_ == nullptr) {
            root_->next_ = val;
        } else {
            Node *current = this->root_;

            while (current->next_ != nullptr) {
                current = current->next_;
            }
            current->next_ = val;
        }
        count_++;
        sort();
    }
}

bool SingleList::checkNonRepetitiveElements(Node* val)
{
    if (this->root_ == nullptr)
    {
        return false;
    }
    Node *current = root_;
    while (current != nullptr )
    {
        if (current->data_ == val->data_)
        {
            return true;
        }
        current = current->next_;
    }
    return false;
}

void SingleList::sort()
{
    for (int i = 0; i < this->count_; i++)
    {
        Node* temp = this->root_;
        Node* next = temp->next_;
        while (next != nullptr)
        {
            if (temp->data_ > next->data_)
            {
                std::swap(temp->data_, next->data_);
            }
            temp = temp->next_;
            next = next->next_;
        }
    }
}

void SingleList::insertHead(int value)
{
    this->root_ = new Node (value, root_);
    count_++;
}

size_t SingleList::getCount() const {
    return count_;
}
