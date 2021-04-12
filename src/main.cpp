#include <iostream>
#include <limits>
#include "Table.cpp"
#include "List.cpp"
#include "Heap.cpp"
#include "BinarySearchTree.cpp"

void menuTable()
{
    int action;
    int value;
    int index;
    string filename;
    Table table;
    do
    {
        cout << endl
             << "Which action you want to perform? Type appropriate number " << endl;
        cout << "1 - Display table " << endl;
        cout << "2 - fill table with random numbers " << endl;
        cout << "3 - Add element on the beginning of the table " << endl;
        cout << "4 - Add element on the end of the table " << endl;
        cout << "5 - Add element on selected position in the table " << endl;
        cout << "6 - Delete element on the beginning of the table " << endl;
        cout << "7 - Delete element on the end of the table " << endl;
        cout << "8 - Delete element on selected position in the table " << endl;
        cout << "9 - Search by value in the table " << endl;
        cout << "10 - Build table from file " << endl;
        cout << "11 - Exit Table mode " << endl;
        cout << "Table> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> action;
        cout << endl;
        switch (action)
        {
        case 1:
            table.displayTable();
            break;
        case 2:
            cout << "Enter how many items you want to create: ";
            cin >> value;
            cout << endl;
            table.fillRandomly(value);
            table.displayTable();
            break;
        case 3:
            cout << "Enter the value of the new item: ";
            cin >> value;
            cout << endl;
            table.addStart(value);
            table.displayTable();
            break;
        case 4:
            cout << "Enter the value of the new item: ";
            cin >> value;
            cout << endl;
            table.addEnd(value);
            table.displayTable();
            break;
        case 5:
            cout << "Enter the value of the new item: ";
            cin >> value;
            cout << endl;
            cout << "Enter the index of the new item: ";
            cin >> index;
            cout << endl;
            table.addInSelected(value, index);
            table.displayTable();
            break;
        case 6:
            table.deleteStart();
            table.displayTable();
            break;
        case 7:
            table.deleteEnd();
            table.displayTable();
            break;
        case 8:
            cout << "Enter the index of the item to be deleted: ";
            cin >> index;
            cout << endl;
            table.deleteSelected(index);
            table.displayTable();
            break;
        case 9:
            cout << "Enter the value you are looking for: ";
            cin >> value;
            cout << endl;
            table.search(value);
            break;
        case 10:
            cout << "Enter file name: ";
            cin >> filename;
            cout << endl;
            table.buildFromFile(filename);
            table.displayTable();
            break;
        case 11:
            break;
        default:
            cout << "Type appropriate number" << endl;
            break;
        }
    } while (action != 11);
}

void menuList()
{
    int action;
    int value;
    int index;
    string filename;
    List list;
    do
    {
        cout << endl
             << "Which action you want to perform? Type appropriate number " << endl;
        cout << "1 - Display list " << endl;
        cout << "2 - fill list with random numbers " << endl;
        cout << "3 - Add element on the beginning of the list " << endl;
        cout << "4 - Add element on the end of the list " << endl;
        cout << "5 - Add element on selected position in the list " << endl;
        cout << "6 - Delete element on the beginning of the list " << endl;
        cout << "7 - Delete element on the end of the list " << endl;
        cout << "8 - Delete element on selected position in the list " << endl;
        cout << "9 - Search by value in the list " << endl;
        cout << "10 - Build list from file " << endl;
        cout << "11 - Exit list mode " << endl;
        cout << "List> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> action;
        cout << endl;
        switch (action)
        {
        case 1:
            cout << "Display list from the beginning or from the end? " << endl;
            cout << "1 - beginning " << endl;
            cout << "2 - end " << endl;
            cin >> value;
            if (value == 1)
                list.displayList();
            else if (value == 2)
                list.displayListBackwards();
            else
                cout << "Wrong number " << endl;
            break;
        case 2:
            cout << "Enter how many items you want to create: ";
            cin >> value;
            cout << endl;
            list.fillRandomly(value);
            list.displayList();
            break;
        case 3:
            cout << "Enter the value of the new item: ";
            cin >> value;
            cout << endl;
            list.addStart(value);
            list.displayList();
            break;
        case 4:
            cout << "Enter the value of the new item: ";
            cin >> value;
            cout << endl;
            list.addEnd(value);
            list.displayList();
            break;
        case 5:
            cout << "Enter the value of the new item: ";
            cin >> value;
            cout << endl;
            cout << "Enter the index of the new item: ";
            cin >> index;
            cout << endl;
            list.addInSelected(value, index);
            list.displayList();
            break;
        case 6:
            list.deleteStart();
            list.displayList();
            break;
        case 7:
            list.deleteEnd();
            list.displayList();
            break;
        case 8:
            cout << "Enter the index of the item to be deleted: ";
            cin >> index;
            cout << endl;
            list.deleteSelected(index);
            list.displayList();
            break;
        case 9:
            cout << "Enter the value you are looking for: ";
            cin >> value;
            cout << endl;
            list.search(value);
            break;
        case 10:
            cout << "Enter file name: ";
            cin >> filename;
            cout << endl;
            list.buildFromFile(filename);
            list.displayList();
            break;
        case 11:
            break;
        default:
            cout << "Type appropriate number" << endl;
            break;
        }
    } while (action != 11);
}

void menuHeap()
{
    int action;
    int value;
    string filename;
    Heap heap;
    do
    {
        cout << endl
             << "Which action you want to perform? Type appropriate number " << endl;
        cout << "1 - Display heap " << endl;
        cout << "2 - fill heap with random numbers " << endl;
        cout << "3 - Add element " << endl;
        cout << "4 - Delete root element " << endl;
        cout << "5 - Search by value in the heap " << endl;
        cout << "6 - Build heap from file " << endl;
        cout << "7 - Exit heap mode " << endl;
        cout << "Heap> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> action;
        cout << endl;
        switch (action)
        {
        case 1:
            heap.displayHeap();
            break;
        case 2:
            cout << "Enter how many items you want to create: ";
            cin >> value;
            cout << endl;
            heap.fillRandomly(value);
            heap.displayHeap();
            break;
        case 3:
            cout << "Enter the value of the new item: ";
            cin >> value;
            cout << endl;
            heap.addNode(value);
            heap.displayHeap();
            break;
        case 4:
            heap.deleteRoot();
            heap.displayHeap();
            break;
        case 5:
            cout << "Enter the value you are looking for: ";
            cin >> value;
            cout << endl;
            heap.search(value);
            break;
        case 6:
            cout << "Enter file name: ";
            cin >> filename;
            cout << endl;
            heap.buildFromFile(filename);
            heap.displayHeap();
            break;
        case 7:
            break;
        default:
            cout << "Type appropriate number" << endl;
            break;
        }
    } while (action != 7);
}

void menuBST()
{
    int action;
    int value;
    string filename;
    BinarySearchTree bst;
    BSTNode *temp;
    do
    {
        cout << endl
             << "Which action you want to perform? Type appropriate number " << endl;
        cout << "1 - Display binary search tree " << endl;
        cout << "2 - fill binary search tree with random numbers " << endl;
        cout << "3 - Add element " << endl;
        cout << "4 - Delete element " << endl;
        cout << "5 - Search by value in the binary search tree " << endl;
        cout << "6 - Build binary search tree from file " << endl;
        cout << "7 - Rotate left " << endl;
        cout << "8 - Rotate right " << endl;
        cout << "9 - Balance the tree " << endl;
        cout << "10 - Exit binary search tree mode " << endl;
        cout << "BST> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> action;
        cout << endl;
        switch (action)
        {
        case 1:
            bst.displayBST();
            break;
        case 2:
            cout << "Enter how many items you want to create: ";
            cin >> value;
            cout << endl;
            bst.fillRandomly(value);
            bst.displayBST();
            break;
        case 3:
            cout << "Enter the value of the new item: ";
            cin >> value;
            cout << endl;
            bst.addNode(value);
            bst.displayBST();
            break;
        case 4:
            cout << "Enter the value you want to delete: ";
            cin >> value;
            cout << endl;
            bst.deleteElement(value);
            bst.displayBST();
            break;
        case 5:
            cout << "Enter the value you are looking for: ";
            cin >> value;
            cout << endl;
            bst.search(value);
            break;
        case 6:
            cout << "Enter file name: ";
            cin >> filename;
            cout << endl;
            bst.buildFromFile(filename);
            bst.displayBST();
            break;
        case 7:
            cout << "Enter the value you want to rotate left: ";
            cin >> value;
            cout << endl;
            temp = bst.search(value);
            if (temp != NULL)
                bst.leftRotation(temp);
            bst.displayBST();
            break;
        case 8:
            cout << "Enter the value you want to rotate right: ";
            cin >> value;
            cout << endl;
            temp = bst.search(value);
            if (temp != NULL)
                bst.rightRotation(temp);
            bst.displayBST();
            break;
        case 9:
            bst.DSW();
            bst.displayBST();
            break;
        case 10:
            break;
        default:
            cout << "Type appropriate number" << endl;
            break;
        }
    } while (action != 10);
}

void menu()
{
    char choice;
    do
    {
        cout << endl
             << "Which structure you want to test? Type appropriate letter " << endl;
        cout << "t - Table " << endl;
        cout << "l - List " << endl;
        cout << "h - Heap " << endl;
        cout << "b - Binary search tree (BST) " << endl;
        cout << "e - Exit the program " << endl;
        cout << "> ";
        cin >> choice;
        switch (choice)
        {
        case 't':
            menuTable();
            break;
        case 'l':
            menuList();
            break;
        case 'h':
            menuHeap();
            break;
        case 'b':
            menuBST();
            break;
        case 'e':
            break;
        default:
            cout << "Type appropriate letter" << endl;
            break;
        }
    } while (choice != 'e');
}

int main()
{
    menu();

    return 0;
}
