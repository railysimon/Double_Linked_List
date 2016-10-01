#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

typedef string datatype;

struct link
{
    datatype data;
    link *next, *previous;
};

class Double_Linked_List
{
private:
        link *first, *last;
public:
        Double_Linked_List() : first(nullptr), last(nullptr) {}
        ~Double_Linked_List();
        void Add_begin(datatype &value);
        void Add_end(datatype &value);
        void Del_begin();
        void Del_end();
        void Add_mid(datatype &key, datatype &value);
        void Del_mid(datatype &key);
        link *Search(datatype &key);
        datatype operator [] (int index);
        void Show();
};

void Double_Linked_List::Add_begin(datatype &value)
{
    link *newlink = new link;
    newlink->data = value;
    newlink->next = first;
    newlink->previous = nullptr;
    if(first) first->previous = newlink;
    else last = newlink;
    first = newlink;
}

void Double_Linked_List::Add_end(datatype &value)
{
    link *newlink = new link;
    newlink->data = value;
    newlink->next = nullptr;
    newlink->previous = last;
    if(first) last->next = newlink;
    else first = newlink;
    last = newlink;
}

void Double_Linked_List::Del_begin()
{
    cout << "Елемент видалено з початку!" << endl;
    if (first)
    {
        link *temp = first;
        first = temp->next;
        if(first) first->previous = nullptr;
        else last = nullptr;
        delete temp;
    }
    else
    {
        cout << "Список порожній!" << endl;
        exit(0);
    }

}

void Double_Linked_List::Del_end()
{
    cout << "Елемент видалено з кінця!" << endl;
    if(last)
    {
        link *temp = last;
        last = temp->previous;
        if(last) last->next = nullptr;
        else first = nullptr;
        delete temp;
    }
    else
    {
        cout << "Список порожній!" << endl;
        exit(0);
    }
}

link *Double_Linked_List::Search(datatype &key)
{
    link *temp = first;
    while(temp != nullptr)
    {
        if(temp->data == key)
        {
            return temp;
            break;
        }
        temp = temp->next;
    }
    cout << "Шуканий елемент не знайдено!" << endl;
    return nullptr;
}

void Double_Linked_List::Add_mid(datatype &key, datatype &value)
{
    link *pkey = this->Search(key);
    if(pkey)
    {
        if(!(pkey->next)) this->Add_end(value);
        else
        {
            link *newlink = new link;
            newlink->data = value;
            newlink->next = pkey->next;
            newlink->previous = pkey;
            pkey->next = newlink;
            (newlink->next)->previous = newlink;
            cout << "Елемент вставлено!" << endl;
        }
    }
    else cout << "Елемент не знайдено. Вставка не відбулась!" << endl;
}

void Double_Linked_List::Del_mid(datatype &key)
{
    link *pkey = this->Search(key);
    if(pkey)
    {
        if((pkey->next) && !(pkey->previous)) this->Del_begin();
        else if(!(pkey->next) && (pkey->previous)) this->Del_end();
        else
        {
            (pkey->previous)->next = pkey->next;
            (pkey->next)->previous = pkey->previous;
            delete pkey;
        }
        cout << "Елемент видалено!" << endl;
    }
    else cout << "Елемент не знайдено. Видалення не відбулось!" << endl;
}

datatype Double_Linked_List::operator [](int index)
{
     link *buffer = first;
     link *temp = buffer;

    for(int i=0; i<index; i++)
    {
        buffer = temp->next;
        temp = buffer;
    }

    return (temp->data);
}

void Double_Linked_List::Show()
{
    cout << "Вміст списку:" << endl;
    link *current = first;
    if(!current) cout << "Список порожній!" << endl;
    while(current)
    {
        cout << "|| " << current->data << " ||" << endl;
        current = current->next;
    }
}

Double_Linked_List::~Double_Linked_List()
{
    while(first)
    {
        link *temp = first->next;
        delete first;
        first = temp;
    }
}

#endif
