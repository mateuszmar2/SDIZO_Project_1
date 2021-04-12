#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

class Table
{
private:
    int *tab;

public:
    int size; //Size is the amount of the elements

    Table() //Creates empty table
    {
        size = 0;
        tab = NULL;
    }
    ~Table()
    {
        deleteTable();
    }
    void deleteTable() //Removes table
    {
        delete[] tab;
        size = 0;
    }
    void displayTable() //Displays all elements
    {
        if (size == 0)
            cout << "Table is empty" << endl;
        else
        {
            cout << "Table content: " << endl;
            for (int i = 0; i < size; i++)
                cout << i << ": " << tab[i] << endl;
            cout << endl;
        }
    }
    void relocate(bool removal) //Creates new table with new size
    {
        int *temp = tab;
        tab = new int[size];
        if (removal) //if it's a removal
        {
            for (int i = 0; i < size; i++)
                tab[i] = temp[i];
        }
        else //if it's adding
        {
            int size_temp = size - 1;
            for (int i = 0; i < size_temp; i++)
                tab[i] = temp[i];
        }
        delete[] temp;
    }
    void fillRandomly(int newSize) //Fill with values 10000000-20000000
    {
        deleteTable();
        if (newSize < 1)
        {
            cout << "Given size is to small" << endl;
            cout << "Filled with default size(10)" << endl;
            newSize = 10;
        }
        srand(time(NULL));
        for (int i = 0; i < newSize; i++)
            addStart(rand() % 10000000 + 10000000);
    }
    void addStart(int value) //Adds on the beginning of the table
    {
        if (size == 0)
            tab = new int[size];
        size++;
        relocate(false);
        for (int i = size - 1; i > 0; i--)
            tab[i] = tab[i - 1];
        tab[0] = value;
    }
    void addEnd(int value) //Adds on the end of the table
    {
        if (size == 0)
            tab = new int[size];
        size++;
        relocate(false);
        tab[size - 1] = value;
    }
    void addInSelected(int value, int index) //Adds on the given index of the table
    {
        if (size == 0)
            tab = new int[size];
        if (index >= size)
        {
            cout << "Given index is bigger than table size" << endl;
            cout << "Value has been added at the end" << endl;
            addEnd(value);
            return;
        }
        if (index < 0)
        {
            cout << "Given index is too small" << endl;
            return;
        }
        size++;
        relocate(false);
        for (int i = size - 1; i > index; i--)
            tab[i] = tab[i - 1];
        tab[index] = value;
    }
    void deleteStart() //Removes first element
    {
        if (size == 0)
        {
            cout << "Table is already empty" << endl;
            return;
        }
        else
        {
            size--;
            for (int i = 0; i < size; i++)
                tab[i] = tab[i + 1];
            relocate(true);
        }
    }
    void deleteEnd() //Removes last element
    {
        if (size == 0)
        {
            cout << "Table is already empty" << endl;
            return;
        }
        else
        {
            size--;
            relocate(true);
        }
    }
    void deleteSelected(int index) //Removes the element with the given index
    {
        if (size == 0)
        {
            cout << "Table is already empty" << endl;
            return;
        }
        else if (index >= size)
        {
            cout << "Selected index is bigger than table size" << endl;
            return;
        }
        if (index < 0)
        {
            cout << "Given index is too small" << endl;
            return;
        }
        size--;
        for (int i = index; i < size; i++)
            tab[i] = tab[i + 1];
        relocate(true);
    }
    void search(int value) //Finds the index of the element with the given value
    {
        int wantedIndex = -1;
        for (int i = 0; i < size; i++)
        {
            if (tab[i] == value)
            {
                wantedIndex = i;
                break;
            }
        }
        if (wantedIndex == -1)
            cout << "There is no such item in the table" << endl;
        else
            cout << "The value you are looking for (" << value << ") is at " << wantedIndex << " index" << endl;
    }
    void buildFromFile(string filename)
    {
        ifstream file;
        file.open(filename);
        if (!file)
            cout << "Can't open file" << endl;
        else
        {
            deleteTable();
            int newSize;
            file >> newSize;
            tab = new int[newSize];
            size = newSize;
            int i = 0;
            while (i < newSize)
            {
                file >> tab[i];
                i++;
            }
            file.close();
        }
    }
};
