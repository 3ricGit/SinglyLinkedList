#include <stdio.h>
#ifndef  LLIST_H_
#define LLIST_H_

class LList {
private:
    struct Node {
        double value;
        Node *next;

        Node(double value1, Node *next1 = 0) {
            next = next1;
            value = value1;
        }

    };

    Node *head;
public:
    LList() { head = 0; }

    void append(const double &num) {
        if(!head){
            head = new Node(num);
            return;
        }else{
            Node *ptr = head;
            while(ptr->next)
                ptr = ptr->next;
            ptr->next = new Node(num);

        }
    }
    void insert(const double &num){
        if(!head){
            head = new Node(num, head);
        }else{
            Node *ptr = head;
            while(ptr->next && ptr->value < num){
                ptr = ptr->next;
            }
            ptr->next = new Node(num, ptr->next);
        }

    }
    void deletes(const double &num){
        if(!head) {
            printf("\nEmpty! couldn't delete :(\n");
            return;
        }
        if(head->value == num ){
            Node *ptr = head;
            head = head->next;
            delete ptr;
            return;
        }else{
            Node *ptr = head, *secptr;
            while(ptr->next){
                secptr = ptr;
                ptr = ptr->next;
                if(ptr->value == num){
                    secptr->next = ptr->next;
                    delete ptr;
                }
            }

        }
        printf("Oops! couldn't find %.2f%s\n", num, " to delete :(");
    }
    bool sort(){
        bool sorted = true;
        if(!head)
            return true;
        else{
            Node *ptr = head;
            while(ptr->next){
                if(ptr->value > ptr->next->value){
                    double temp = ptr->value;
                    ptr->value = ptr->next->value;
                    ptr->next->value = temp;
                    sorted = false;
                }else if(!ptr->next && !sorted)
                    sorted = true;
                ptr = ptr->next;
            }
        }
        return sorted;
    }
    void display(){
        Node *ptr = head;
        while(ptr){
            printf(" %.2f ",ptr->value);
            if(ptr->next)
                printf(", ");
            ptr = ptr->next;
        }
        printf("\n");
    }
    Node *reverse(){
        Node *prev = 0;
        Node *next;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return head = prev;
    }
};
#endif