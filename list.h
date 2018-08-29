#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"
#include <stdexcept>

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;
        int nodes;

    public:
        List()
        {
            start = NULL;
            nodes = 0;
        }

        T front()
        {
            if(start==NULL)
                throw out_of_range("empty list");
            return start->data;
        }

        T back()
        {
            return start->prev->data;
        }

        void push_front(T value)
        {
            if (start == NULL)
            {
                start = new Node<T>;
                start->data = value;
                start->next = start;
                start->prev = start;
                nodes++;
                return;
            }

            Node<T> *temp = new Node<T>;
            temp->data = value;
            temp->next = start;
            temp->prev = start->prev;
            start->prev->next = temp;
            start->prev = temp;
            start = temp;
            nodes++;
            return;
        }

        void push_back(T value)
        {
            if (start == NULL)
            {
                start = new Node<T>;
                start->data = value;
                start->next = start;
                start->prev = start;
                nodes++;
                return;
            }

            Node<T> *temp = new Node<T>;
            temp->data = value;
            temp->next = start;
            temp->prev = start->prev;
            start->prev->next = temp;
            start->prev = temp;
            nodes++;
            return;
        }


        void pop_front();
        void pop_back();
        
        T get(int position)
        {
            if (position >= nodes || position < 0)
            {
                throw out_of_range("Request is out of range!");
            }

            Node<T> *temp = start;
            for (int i = 0; i < nodes; i++)
            {
                if(i == position)
                {
                    return temp->data;
                }
                temp = temp->next;   
            }
        }

        void concat(List<T> &other);
        
        bool empty()
        {
            return start == NULL;
        }

        int size()
        {
            return nodes;
            /* //if nodes wasn't there
            int length = 0;
            if(start == NULL)
                return length;

            Node<T> *temp = start;
            
            do
            {
                length++;
                temp = temp->next
            }
            while(temp != start);

            return length;*/
        }
        
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List(){}
};

#endif