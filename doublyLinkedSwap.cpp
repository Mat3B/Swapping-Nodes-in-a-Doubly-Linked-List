// Mathew Breland
// Swapping Nodes in a Doubly Linked List
// Data Structures and Algorithms 002
// 2/2/2023

#include "doublyLinkedSwap.h"

void swapWithNext(Node* p) {

    // this is validation to make sure that pointer p meets requirements otherwise it just returns 
    if (p->prev == nullptr || p == nullptr || p->next == nullptr || p->next->next == nullptr || p->next->prev == nullptr || p->prev->next == nullptr) {

        return;

    }

    else {

        // creating two temporary node pointers

        Node* tempPrevious = p->prev;       // this one is set to the previous value of p
        Node* tempNext = p->next->next;     // this one is set to the next next value of p

        p->prev = p->next;

        p->next->prev = tempPrevious;       // setting next->prev equal to the tempPrevious that i created above

        tempPrevious->next = p->next;       // updating the next value of tempPrevious to the next value of P

        p->next->next = p;

        p->next = tempNext;             // setting the next value of P equal to tempNext
            
        tempNext->prev = p;             // updating tempNext previous value to be equal to P

       
    }
}


//Do not modify any functions below this line
Node* arrayToList(int array[], int size)
{
    Node* head;
    Node* p;
    int pos = 0;
    if (size > 0)
    {
        head = new Node();
        head->prev = nullptr;
        head->value = 0;
        p = head;
        while (pos < size)
        {
            p->next = new Node();
            p->next->prev = p;
            p = p->next;
            p->value = array[pos];
            pos++;
        }
        p->next = new Node();
        p->next->prev = p;
        p = p->next;
        p->value = 0;
        p->next = nullptr;
    }
    else
    {
        return nullptr;
    }
    return head;
}

//Return pointer to end of the list
Node* getTail(Node* head)
{
    Node* p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    return p;
}

//Return pointer to node with "index"
//First node "index" 0, second node "index" 1, ...
Node* getNode(Node* head, int index)
{
    int pos = 0;
    Node* p = head->next;
    if (pos == index)
    {
        return p;
    }
    else if (index < 0)
    {
        return head;
    }
    else
    {
        while (pos < index && p->next != nullptr)
        {
            p = p->next;
            pos++;
        }
    }
    return p;
}

//Print list forwards from start
void printForwards(Node* head)
{
    Node* p = head->next;
    while (p->next != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

//Print list backwards from end
void printBackwards(Node* tail)
{
    Node* p = tail->prev;
    while (p->prev != nullptr)
    {
        cout << p->value << " ";
        p = p->prev;
    }
    cout << endl;
}