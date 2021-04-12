#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

class Heap
{
public:
    int size;

private:
    int *tab;
    string s;
    string right_child, left_child, vertical_bar;

public:
    Heap()
    {
        size = 0;
        tab = NULL;
    }
    ~Heap()
    {
        deleteHeap();
    }
    void deleteHeap()
    {
        delete[] tab;
        size = 0;
    }
    unsigned int leftChild(unsigned int node_number)
    {
        return 2 * node_number + 1;
    }
    unsigned int rightChild(unsigned int node_number)
    {
        return 2 * node_number + 2;
    }
    unsigned int parent(unsigned int node_number)
    {
        return (node_number - 1) / 2;
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
        deleteHeap();
        if (newSize < 1)
        {
            cout << "Given size is to small" << endl;
            cout << "Filled with default size(10)" << endl;
            newSize = 10;
        }
        srand(time(NULL));
        for (int i = 0; i < newSize; i++)
            addNode(rand() % 10000000 + 10000000);
    }
    void displayHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty " << endl;
            return;
        }
        for (int i = 0; i < size; i++)
            cout << tab[i] << ", ";
        cout << endl;
        cout << "Tree: " << endl;
        printBT("", "", 0);
    }
    void printBT(string text_indirect_row, string text_before_node, int index)
    {
        right_child = left_child = vertical_bar = "  ";
        right_child[0] = '-';
        right_child[1] = '-';
        left_child[0] = '~';
        left_child[1] = '-';
        vertical_bar[0] = '|';

        if (index < size)
        {
            s = text_indirect_row; //text to display in the indirect lines for sons
            if (text_before_node == right_child)
                s[s.length() - 2] = ' ';
            printBT(s + vertical_bar, right_child, 2 * index + 2); //Prints right child

            s = s.substr(0, text_indirect_row.length() - 2);

            if (index == 0)
                cout << tab[0] << endl;
            else
                cout << s << text_before_node << tab[index] << endl;

            s = text_indirect_row;
            if (text_before_node == left_child)
                s[s.length() - 2] = ' ';
            printBT(s + vertical_bar, left_child, 2 * index + 1); //Prints left child
        }
    }
    void addNode(int value) //Adds node and check heap condition, repairs until condition isn't done
    {
        size++;
        if (size == 1)
        {
            tab = new int[size];
            tab[0] = value;
            return;
        }
        else
        {
            relocate(false);
            unsigned int current_index = size - 1;
            int temp_value;
            tab[current_index] = value;
            while (tab[parent(current_index)] < tab[current_index]) // while current index isn't root and parent is less
            {
                temp_value = tab[parent(current_index)];
                tab[parent(current_index)] = value;
                tab[current_index] = temp_value;
                current_index = parent(current_index);
                if (current_index == 0)
                    return;
            }
        }
    }
    void deleteRoot() //Removes root node and repairs heap
    {
        if (size == 0)
        {
            cout << "Heap is already empty" << endl;
            return;
        }
        else
        {
            int current_index = 0;
            tab[current_index] = tab[size - 1];
            int temp_value;
            size--;
            relocate(true);
            while (true)
            {
                if (2 * current_index + 1 < size) //if left child exists
                {
                    if (2 * current_index + 2 < size) //if both childs exists
                    {
                        if (tab[current_index] < tab[leftChild(current_index)] || tab[current_index] < tab[rightChild(current_index)])
                        {
                            temp_value = tab[current_index];
                            if (tab[leftChild(current_index)] >= tab[rightChild(current_index)]) //if left child is bigger than right
                            {
                                tab[current_index] = tab[leftChild(current_index)];
                                tab[leftChild(current_index)] = temp_value;
                                current_index = leftChild(current_index);
                            }
                            else
                            {
                                tab[current_index] = tab[rightChild(current_index)];
                                tab[rightChild(current_index)] = temp_value;
                                current_index = rightChild(current_index);
                            }
                        }
                        else
                            return; //if it's bigger than both childrens
                    }
                    else //if only left child exists
                    {
                        if (tab[current_index] < tab[leftChild(current_index)]) //if left child is bigger
                        {
                            tab[current_index] = tab[leftChild(current_index)];
                            tab[leftChild(current_index)] = temp_value;
                            current_index = leftChild(current_index);
                            return;
                        }
                        else
                            return;
                    }
                }
                else //if it's a leaf
                    return;
            }
        }
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
            deleteHeap();
            int temp_value;
            int newSize;
            file >> newSize;
            cout << newSize << endl;
            int i = 0;
            while (i < newSize)
            {
                file >> temp_value;
                cout << temp_value << endl;
                addNode(temp_value);
                i++;
            }
            file.close();
        }
    }
};
