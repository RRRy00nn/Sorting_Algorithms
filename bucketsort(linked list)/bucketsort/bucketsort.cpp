#define _NO_SECURE_WARNINGS
#include <iostream>
#include<stdio.h>
using namespace std;
struct database
{
    int data;
    struct database*next;
};
database* initlist();
void printnode(const database* head);
bool insertpriornode(database* pp, const int& data);
bool insertnextnode(database* pp, const int& data);
bool pushorder(database* head, const int& data);
void mergelist(database* la, database* lb, database* lc);
void destroylist(database* head);
void bucketsort(int arr[], int len, int num);
int main()
{
	int arr[] = { 2,4,1,5,7,4,2,8,9,54,23,2,456,234,12,5,63,345,375 };
    int len = (sizeof(arr) / sizeof(int));
    int num;
    cin >> num;
    bucketsort(arr, len, num);
}
void bucketsort(int arr[], int len, int num)
{
    database* buckets = new database[num];
    //initialize, set heads into null
    for (int i = 0; i < num; i++)
    {
        buckets[i].next = nullptr;
    }
    //put data into different buckets
    for (int i = 0; i < len; i++)
    {
        pushorder(&buckets[arr[i] % num], arr[i]);
    }
    for (int i = 0; i < num; i++)
        printnode(&buckets[i]);
    //put all the elem into a bucket
    database ll;
    ll.next = nullptr;
    database tmp;
    tmp.next = nullptr;
    for(int i=0;i<num;i++)
    {
        mergelist(&buckets[i], &ll, &tmp);
        swap(ll.next, tmp.next);
    }
    printnode(&ll);
    // save merged data into array 
    database* pp = ll.next;
    for (int i = 0; i < len; i++)
    {
        arr[i] = pp->data;
        pp = pp->next;
    }
    destroylist(ll.next);
    delete[]buckets;
}
bool insertpriornode(database* pp, const int& data)
{
    //copy the data(in node1) into a new node which connected after node1
    // put data(insert data) into node1
    if (pp == nullptr)
    {
        cout << "node doesnt exist" << endl;
        return false;
    }
    database* tmp = new database;
    //copy pp's node and data into tmp
    tmp->data = pp->data;
    tmp->next = pp->next;
    //put elem that need to insert into pp
    pp->data = data;
    pp->next = tmp;
    return true;
}
bool insertnextnode(database* pp, const int& data)
{
    if (pp == nullptr)
    {
        cout << "node pp doesnt exist" << endl;
        return false;
    }
    database* tmp = new database;
    tmp->data = data;
    tmp->next = pp->next;
    pp->next = tmp;
    return true;

}
bool pushorder(database* head, const int& data)
{
    if (head == nullptr)
    {
        cout << "list doesnt exist";
        return false;
    }
    database* tail = head;// as a loop, put last node into head pointer
    database* pp = head->next;
    while (pp != nullptr)
    {
        //if elem bigger than data, put ee in front of it
        if (pp->data > data)
        {
            insertpriornode(pp, data);
            return true;
        }
        tail = pp;
        pp = pp->next;
    }
    if (pp == nullptr)
        return insertnextnode(tail, data);
    return true;
}
database* initlist()
{
    database* head = new(std::nothrow)database;//giving first node
    if (head == nullptr) return nullptr;//lack of ram, failed to return 
    head->next = nullptr;
    return head;//pointer, an address
}
void printnode(const database* head)
{
    if (head == nullptr)
    {
        cout << "linked node doesnt exist" << endl;
        return;
    }
    database* a = head->next;
    while (a != nullptr)
    {
        cout << a->data << endl;
        a = a->next;
    }
}
void mergelist(database* la, database* lb, database* lc)
{
    //lc is a new head node
    database* pa = la->next;
    database* pb = lb->next;
    database* pp;
    //merge
    while ((pa != nullptr) && (pb != nullptr))
    {
        if (pa->data <= pb->data)
        {
            pp = pa;
            pa = pa->next;
        }
        else
        {
            pp = pb;
            pb = pb->next;
        }
        //put smaller list(la or lb) into lc
        lc->next = pp;
        lc = lc->next;
    }
    //put other elem into new list
    if (pa != nullptr)
        lc->next = pa;
    if (pb != nullptr)
        lc->next = pb;
    //need to put la&lb as null , for safe
    la->next = lb->next = nullptr;
}
void destroylist(database* head)
{
    database* tmp;
    while (head != nullptr)
    {
        tmp = head->next;//save next ad
        delete head;// delete node
        head = tmp;//move to next node using ad
    }
}