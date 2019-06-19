//
// Created by Hyundong on 2019-06-20.
//

#ifndef MYLINKEDLIST_LIST_H
#define MYLINKEDLIST_LIST_H
#define nullptr 0
#pragma once

template <typename T>
class Node
{
public:
    Node() {}
    ~Node() {}
public:
    Node<T> * pNext = nullptr;
    Node<T> * pPrev = nullptr;
    T Data;
};

template <typename T>
class list
{
public:
    list()
    {
        pHead = new Node<T>();
        pTail = new Node<T>();

        pHead->pNext = pTail;
        pHead->pPrev = pHead;

        pTail->pNext = pTail;
        pTail->pPrev = pHead;
    }
    ~list()
    {
        Node<T> * s;
        s = pHead;
        while (s != pTail)
        {
            s = s->pNext;
            delete s->pPrev;
        }
        delete s;
    }
private:
    Node<T> * pHead;
    Node<T> * pTail;
public:
    class iterator
    {
    public:
        Node<T> * pNode;
    public:
        iterator(Node<T> * _pNode) : pNode(_pNode) {}
        ~iterator() {}
        T& operator *() const {
            return pNode->Data;
        }

        bool operator != (list<T>::iterator _MyIter)
        {
            return pNode != _MyIter.pNode;
        }
        void operator =(list<T>::iterator _MyIter){
            pNode = _MyIter->pNode;
        }

        void operator ++()	{
            pNode = pNode->pNext;
        }

        void operator ++(int)	{
            pNode = pNode->pNext;
        }

        void operator --()	{
            pNode = pNode->pPrev;
        }

        void operator --(int)	{
            pNode = pNode->pPrev;
        }

        list<T>::iterator operator + (int _nCount)
        {
            Node<T> * temp = this->pNode;

            for (int i = 0; i < _nCount; i++)
            {
                temp = temp->pNext;
            }

            return iterator(temp);
        }

        list<T>::iterator operator - (int _nCount)
        {
            Node<T> * temp = this->pNode;

            for (int i = 0; i < _nCount; i++)
            {
                temp = temp->pPrev;
            }

            return iterator(temp);
        }
    };
    void push_back(T _Data)
    {
        Node<T> * pNewNode = new Node<T>;
        pNewNode->Data = _Data;

        pNewNode->pNext = pTail;
        pNewNode->pPrev = pTail->pPrev;

        pTail->pPrev->pNext = pNewNode;
        pTail->pPrev = pNewNode;
    }
    void push_front(T _Data)
    {
        Node<T> * pNewNode = new Node<T>;
        pNewNode->Data = _Data;

        pNewNode->pNext = pHead->pPrev;
        pNewNode->pPrev = pHead;

        pHead->pNext->pPrev = pNewNode;
        pHead->pNext = pNewNode;
    }
    void pop_back()
    {
        Node<T> * pDelNode = pTail->pPrev;
        if (pDelNode == pHead) return;
        pTail->pPrev->pPrev->pNext = pTail;
        pTail->pPrev = pTail->pPrev->pPrev;
        delete pDelNode;
    }
    void pop_front()
    {
        Node<T> * pDelNode = pHead->pNext;
        if (pDelNode == pTail) return;
        pHead->pNext->pNext->pPrev = pHead;
        pHead->pNext = pHead->pNext->pNext;
        delete pDelNode;
    }

    void insert(list<T>::iterator _Where, T _Data)
    {
        Node<T> * Location = _Where.pNode;
        Node<T> * NewNode = new Node<T>;
        NewNode->Data = _Data;
        NewNode->pNext = Location;
        NewNode->pPrev = Location->pPrev;

        Location->pPrev->pNext = NewNode;
        Location->pPrev = NewNode;
    }
    list<T>::iterator  begin() { return iterator(pHead->pNext); }
    list<T>::iterator  end() { return iterator(pTail); }
    int size() {
        Node<T> * pNode = pHead->pNext;
        int nSize = 0;
        while (pNode != pTail)
        {
            pNode = pNode->pNext;
            nSize++;
        }
        return nSize;
    }
    bool empty() { return size() == 0; }
};
#endif //MYLINKEDLIST_LIST_H
