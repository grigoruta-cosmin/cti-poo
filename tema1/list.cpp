#include <bits/stdc++.h>
#include "list.h"

List::List(){
    len = 0;
    first = nullptr;
}

void List::push(int data){
    if(first == nullptr){ 
        first = new Node;
        first->data = data;
        first->next = nullptr;
        len++;
    }else{
        Node *tmp, *add;
        add = new Node;
        tmp = first;
        while(tmp->next != nullptr){
            tmp = tmp->next;
        }
        add->data = data;
        add->next = nullptr;
        tmp->next = add;
        len++;
    }
}

int List::pop(){
    int result;
    if(len == 0){
        std::cout << "Lista este goala!" << std::endl;
    }else if(len == 1){
        result = first->data;
        delete first;
        first = nullptr;
        len--;
        return result;
    }else{
        Node *tmp;
        tmp = first;
        while(tmp->next->next != nullptr){
            tmp = tmp->next;
        }
        len--;
        result = tmp->next->data;
        delete tmp->next;
        tmp->next = nullptr;
        return result;
    }
}

void List::printList(){
    if(first == nullptr){
        std::cout << "lista este vida" << std::endl;
    }else{
        Node *tmp;
        tmp = first;
        while(tmp != nullptr){
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
}

int List::get_len(){
    return len;
}

int List::shift(){
    int result;
    if(len == 0){
        std::cout << "Lista este goala" << std::endl;
    }else{
        Node *tmp;
        tmp = first;
        result = tmp->data;
        first = first->next;
        len--;
        delete tmp;
        return result;
    }
}

void List::unshift(int data){
    Node *tmp;
    tmp = new Node;
    tmp->data = data;
    tmp->next = first;
    first = tmp;
    len++;
}

void List::deleteInd(int ind){
    int count = 0;
    if(ind == 0){
        shift();
    }else if(ind == 1){
        Node *tmp;
        tmp = first->next;
        first->next =  tmp->next;
        delete tmp;
        len--;
    }else{
        Node *tmp, *q;
        tmp = first;
        while(count + 1 < ind){
            count++;
            tmp = tmp->next;
        }
        q = tmp->next;
        tmp->next = q->next;
        delete q;
        len--;
    }
}

void List::deleteVal(int val){
    if(first->data == val){
        shift();
    }else{
        Node *tmp, *pred, *q;
        tmp = first->next;
        pred = first;
        while(tmp->data != val){
            tmp = tmp->next;
            pred = pred->next;
        }
        if(tmp == nullptr){
            std::cout << "Valoarea nu a fost gasita!";
        }else{
            q = pred->next;
            pred->next = q->next;
            delete q;
            len--;
        }
    }
}

void List::addAfterVal(int val, int data){
    if(first == nullptr){
        std::cout << "Stiva este goala" << std::endl;
    }else{
        int ok = 1;
        Node *tmp, *add;
        tmp = first;
        while(tmp->data != val){
            tmp = tmp->next;
            if(tmp->next == nullptr && tmp->data != val){
                std::cout << "Valoarea nu a fost gasita" << std::endl;
                ok = 0;
                break;
            }
        }
        if(ok == 1){
            add = new Node;
            add->data = data;
            add->next = tmp->next;
            tmp->next = add;
            len++;
        }
    }
}

void List::addAfterInd(int ind, int data){
    if(ind > len - 1){
        std::cout << "Indicele depaseste lungimea listei" << std::endl;
    }else if(first == nullptr){
        std::cout << "Lista este goala" << std::endl; 
    }else if(ind == 0){
        unshift(data);
    }else if(ind == len - 1){
        push(data);
    }else{
        int ok = 1, count = 0;
        Node *tmp, *add;
        tmp = first;
        while(count < ind){
            tmp = tmp->next;
            count++;
        }
        add = new Node;
        add->data = data;
        add->next = tmp->next;
        tmp->next = add;
        len++;
    }
}

std::istream & operator >>(std::istream &in, List &list){
    std::cout << "Introduceti elemente in lista(se opreste la valoarea 0):" << std::endl;
    int val;
    std::cin >> val;
    while(val){
        list.push(val);
        std::cin >> val;
    }
    return in;
}

bool List::contains(int value){
    Node *tmp;
    tmp = first;
    while(tmp != nullptr){
        if(tmp->data == value){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void List::deleteList(){
    Node *tmp;
    while(first != nullptr){
        tmp = first;
        first = first->next;
        delete tmp;
    }
}

List::~List(){
    Node *tmp;
    while(first != nullptr){
        tmp = first;
        first = first->next;
        delete tmp;
    }
}