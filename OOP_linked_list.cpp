// OOP_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

class linked_list
{
private:
    node* head, * tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    node* gethead()
    {
        return head;
    }
    void add_node_end(int n)
    {
        node* tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    
    void add_node_beginning(int n)
    {
        node* tmp = new node;
        tmp->data = n;
        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tmp->next = head;
            head = tmp;
        }
    }
    void delete_beginning()
    {
        if (head == NULL)
            cout << "The list is empty.";
        else
        {   
            if (head->next == NULL)
            {
                node* p = head;
                head = NULL;
                delete p;
               
            }
            else
            {
                node* p;
                p = head;
                head = head->next;
                delete p;
            }
        }
    }
    void delete_end()
    {
        if (head == NULL)
        {
            cout << "The list is empty." << endl;
        }
        else
        {
            if (head == tail)
            {
                node* p = tail;
                tail = NULL;
                head = NULL;
                delete p;
            }
            else
            {
                node* p= head;
                node* q =tail;
                while (p->next != tail)
                {
                    p = p->next;
                }
                tail = p;
                tail->next = NULL;
                delete q;
                
            }
        }
    }
    void display( )
    {
        if (head == NULL)
            cout << "The list is empty."<<endl;
        else
        {
            node* p = head;
            while (p!= NULL)
            {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    linked_list a;
    a.add_node_end(1);
    a.display();
    a.add_node_end(2);
    a.display();
    a.add_node_beginning(5);
    a.display();
    a.delete_beginning();
    a.display();
    a.delete_end();
    a.display();
    a.delete_end();
    a.display();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
