#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

class ListElem //List item class
{
public:
    ListElem *prev, *next;
    int value;
};

class List //List class
{
public:
    int size; //Size is the amount of the elements
private:
    ListElem *head, *tail;

public:
    List() //Creates empty List
    {
        size = 0;
        head = tail = NULL;
    }
    ~List()
    {
        deleteList();
    }
    void deleteList() //Removes List
    {
        while (size > 0)
            deleteStart();
        head = tail = NULL;
    }
    void displayList() //Displays all elements
    {
        if (size == 0)
            cout << "List is empty" << endl;
        else
        {
            ListElem *p = head;
            cout << "List content: " << endl;
            for (int i = 0; i < size; i++)
            {
                cout << i << ": " << p->value << endl;
                p = p->next;
            }
            cout << endl;
        }
    }
    void fillRandomly(int new_size) //Fill with values 10000000-20000000
    {
        deleteList();
        if (new_size < 1)
        {
            cout << "Given size is to small" << endl;
            cout << "Filled with default size(10)" << endl;
            new_size = 10;
        }
        srand(time(NULL));
        int new_value;
        for (int i = 0; i < new_size; i++)
        {
            new_value = rand() % 10000000 + 10000000;
            addStart(new_value);
        }
    }
    void addStart(int new_value) //Adds on the beginning of the List
    {
        ListElem *new_elem = new ListElem;
        new_elem->value = new_value;
        new_elem->prev = NULL;
        new_elem->next = head;
        head = new_elem;
        size++;
        if (new_elem->next)
            new_elem->next->prev = new_elem;
        else
            tail = new_elem;
    }
    void addEnd(int new_value) //Adds on the end of the List
    {
        ListElem *new_elem = new ListElem;
        new_elem->value = new_value;
        new_elem->prev = tail;
        if (!head)
            head = new_elem;
        new_elem->next = NULL;
        tail = new_elem;
        size++;
        if (new_elem->prev)
            new_elem->prev->next = new_elem;
    }
    void addInSelected(int new_value, int index) //Adds on the given index of the List
    {
        if (index == 0)
        {
            addStart(new_value);
            return;
        }
        else if (index >= size)
        {
            addEnd(new_value);
            cout << "Given index is bigger than List size" << endl;
            cout << "Value has been added at the end" << endl;
            return;
        }
        if (index < 0)
        {
            cout << "Given index is too small" << endl;
            return;
        }
        ListElem *p = head;
        for (int i = 0; i < index; i++)
            p = p->next;
        ListElem *new_elem = new ListElem;
        new_elem->value = new_value;
        new_elem->prev = p->prev;
        new_elem->next = p;
        new_elem->prev->next = new_elem;
        p->prev = new_elem;
        size++;
    }
    void deleteStart() //Removes first element
    {
        if (size == 0)
        {
            cout << "List is already empty" << endl;
            return;
        }
        else
        {
            ListElem *p = head;
            head = p->next;
            if (p->next)
                p->next->prev = NULL;
            delete p;
            size--;
        }
    }
    void deleteEnd() //Removes last element
    {
        if (size == 0)
        {
            cout << "List is already empty" << endl;
            return;
        }
        if (size == 1)
        {
            deleteList();
        }
        else
        {
            ListElem *p = tail;
            tail = p->prev;
            p->prev->next = NULL;
            delete p;
            size--;
        }
    }
    void deleteSelected(int index) //Removes the element with the given index
    {
        if (size == 0)
        {
            cout << "List is already empty" << endl;
            return;
        }
        else if (index >= size)
        {
            cout << "Selected index is bigger than List size" << endl;
            return;
        }
        if (index < 0)
        {
            cout << "Given index is too small" << endl;
            return;
        }
        ListElem *p = head;
        for (int i = 0; i < index; i++)
            p = p->next;
        if (p->prev)
        {
            if (p->next)
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete p;
                size--;
            }
            else
                deleteEnd();
        }
        else
            deleteStart();
    }
    void search(int wanted_value) //Finds the index of the element with the given value
    {
        int wantedIndex = -1;
        ListElem *p = head;

        int i = 0;
        while (p)
        {
            if (p->value == wanted_value)
            {
                wantedIndex = i;
                break;
            }
            else
            {
                i++;
                p = p->next;
            }
        }
        if (wantedIndex == -1)
            cout << "There is no such item in the List" << endl;
        else
            cout << "The value you are looking for (" << p->value << ") is at " << wantedIndex << " index" << endl;
    }
    void buildFromFile(string filename)
    {
        ifstream file;
        file.open(filename);
        if (!file)
            cout << "Can't open file" << endl;
        else
        {
            deleteList();
            int value;
            int newSize;
            file >> newSize;
            int i = 0;
            while (i < newSize)
            {
                file >> value;
                addEnd(value);
                i++;
            }
            file.close();
        }
    }
    void displayListBackwards() //Displays all elements backwards
    {
        if (size == 0)
            cout << "List is empty" << endl;
        else
        {
            ListElem *p = tail;
            cout << "List content: " << endl;
            for (int i = size - 1; i >= 0; i--)
            {
                cout << i << ": " << p->value << endl;
                p = p->prev;
            }
            cout << endl;
        }
    }
};
