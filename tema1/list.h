#ifndef LIST_H
#define LIST_H
#include <bits/stdc++.h>

class List{
    private:
        int len;
        struct Node{
            int data;
            Node *next;
        };
        Node *first; 
    public:
        List();
        void printList();
        void push(int);
        int pop();
        int shift();
        void unshift(int);
        //Node * getValFromList(int);
        //Node * getIndFromList(int);
        void deleteVal(int);
        void deleteInd(int);
        void deleteList();
        void addAfterVal(int, int);
        void addAfterInd(int, int);
        bool contains(int);
        int get_len();
        void set_len();
        friend std::istream & operator >>(std::istream&, List&);
        ~List();
};

#endif