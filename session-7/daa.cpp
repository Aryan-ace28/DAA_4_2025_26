#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void at_the_end(int a, node* head)
{
    node* end = new node(a);
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = end;
    end->prev = temp;
}

void ndelete(int a, node*& head)
{
    if (head == NULL)
        return;

    if (head->data == a)
    {
        node* del = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete del;
        return;
    }

    node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == a)
        {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
    }
}

int main()
{
    node* fst = new node(1);
    node* snd = new node(2);
    node* trd = new node(3);
    node* frt = new node(4);

    fst->next = snd;
    snd->prev = fst;
    snd->next = trd;
    trd->prev = snd;
    trd->next = frt;
    frt->prev = trd;

    node* head = fst;

    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }

    cout << "enter the number to insert at the end: ";
    int ende, del;
    cin >> ende;

    at_the_end(ende, fst);

    head = fst;
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }

    cout << " which element do you wan to delete ";
    cin >> del;

    ndelete(del, fst);

    head = fst;
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }

    return 0;
}
