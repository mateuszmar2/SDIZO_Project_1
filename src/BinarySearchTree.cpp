#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;

class BSTNode
{
public:
    BSTNode *left;
    BSTNode *right;
    BSTNode *parent;
    int value;

public:
    BSTNode()
    {
        left = NULL;
        right = NULL;
        parent = NULL;
        value = 0;
    }
    ~BSTNode()
    {
        if (left)
        {
            delete left;
            left = NULL;
        }
        if (right)
        {
            delete right;
            right = NULL;
        }
        parent = NULL;
    }
};

class BinarySearchTree
{
public:
    BSTNode *root;

private:
    string s;
    string right_child, left_child, vertical_bar;

public:
    BinarySearchTree()
    {
        root = NULL;
    }
    ~BinarySearchTree()
    {
        deleteBST();
    }
    void deleteBST()
    {
        if (root != NULL)
        {
            delete root;
            root = NULL;
        }
    }
    BSTNode *Minimum(BSTNode *node)
    {
        if (node == NULL)
            return NULL;
        while (node->left != NULL)
            node = node->left;
        return node;
    }
    BSTNode *Maximum(BSTNode *node)
    {
        if (node == NULL)
            return NULL;
        while (node->right != NULL)
            node = node->right;
        return node;
    }
    BSTNode *Successor(BSTNode *node)
    {
        if (node == NULL)
            return NULL;
        if (node->right != NULL) //first case, return minimum from right child
            return Minimum(node->right);
        else //second and third case
        {
            BSTNode *temp = node->parent;
            while (temp && temp->right == node) //we are moving up until we find node for which
            {                                   //node is in left edge
                node = temp;
                temp = temp->parent;
            }
            return temp; //returns found node or null if doesn't exist
        }
    }
    BSTNode *Predecessor(BSTNode *node)
    {
        if (node == NULL)
            return NULL;
        if (node->left != NULL) //first case, return maximum from left child
            return Maximum(node->left);
        else //second and third case
        {
            BSTNode *temp = node->parent;
            while (temp && temp->left == node) //we are moving up until we find node for which
            {                                  //node is in right edge
                node = temp;
                temp = temp->parent;
            }
            return temp; //returns found node or null if doesn't exist
        }
    }
    void leftRotation(BSTNode *a)
    {
        BSTNode *b = a->right;
        if (b == NULL)
            return;
        BSTNode *a_parent = a->parent;
        a->right = b->left;   //left child of b is now right child of a
        if (a->right != NULL) //if right child exists then it's parent is a
            a->right->parent = a;
        b->left = a;          //a is now left child of b
        b->parent = a_parent; //parent of a is now parent of b
        a->parent = b;        //b is now parent of a
        if (a_parent != NULL) //if a wasn't the root
        {
            if (a_parent->left == a) //we assign to the parent of a new child
                a_parent->left = b;
            else
                a_parent->right = b;
            return;
        }
        root = b;
    }
    void rightRotation(BSTNode *a)
    {
        BSTNode *b = a->left;
        if (b == NULL)
            return;
        BSTNode *a_parent = a->parent;
        a->left = b->right;  //right child of b is now left child of a
        if (a->left != NULL) //if left child exists then it's parent is a
            a->left->parent = a;
        b->right = a;         //a is now right child of b
        b->parent = a_parent; //parent of a is now parent of b
        a->parent = b;        //b is now parent of a
        if (a_parent != NULL) //if a wasn't the root
        {
            if (a_parent->left == a) //we assign to the parent of a new child
                a_parent->left = b;
            else
                a_parent->right = b;
            return;
        }
        root = b;
    }
    void fillRandomly(int newSize) //Fill with values 10000000-20000000
    {
        deleteBST();
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
    void displayBST()
    {
        if (root == NULL)
        {
            cout << "BinarySearchTree is empty " << endl;
            return;
        }
        printBT("", "", root);
    }
    void printBT(string text_indirect_row, string text_before_node, BSTNode *current_node)
    {
        right_child = left_child = vertical_bar = "  ";
        right_child[0] = '-';
        right_child[1] = '-';
        left_child[0] = '~';
        left_child[1] = '-';
        vertical_bar[0] = '|';

        if (current_node != NULL)
        {
            s = text_indirect_row; //text to display in the indirect lines for sons
            if (text_before_node == right_child)
                s[s.length() - 2] = ' ';
            printBT(s + vertical_bar, right_child, current_node->right); //Prints right child

            s = s.substr(0, text_indirect_row.length() - 2);
            if (current_node == root)
                cout << current_node->value << endl;
            else
                cout << s << text_before_node << current_node->value << endl;

            s = text_indirect_row;
            if (text_before_node == left_child)
                s[s.length() - 2] = ' ';
            printBT(s + vertical_bar, left_child, current_node->left); //Prints left child
        }
    }
    void addNode(int new_value) //Adds node
    {
        BSTNode *new_node = new BSTNode();
        new_node->value = new_value;
        if (root == NULL)
        {
            root = new_node;
            return;
        }
        else
        {
            BSTNode *p = root;
            while (true)
            {
                if (new_value >= p->value)
                {
                    if (p->right == NULL)
                    {
                        p->right = new_node;
                        new_node->parent = p;
                        break;
                    }
                    else
                        p = p->right;
                }
                else
                {
                    if (p->left == NULL)
                    {
                        p->left = new_node;
                        new_node->parent = p;
                        break;
                    }
                    else
                        p = p->left;
                }
            }
        }
    }
    void deleteElement(int value) //Removes root node and repairs BinarySearchTree
    {
        BSTNode *node = search(value);
        if (node == NULL)
            return;
        if (root == NULL)
        {
            cout << "BinarySearchTree is already empty" << endl;
            return;
        }
        else
        {
            BSTNode *y;                                    //y is node to delete
            BSTNode *z;                                    //z is a child of y
            if (node->left == NULL || node->right == NULL) //if node has 0 or 1 child
                y = node;                                  //then y is a node
            else                                           //else y is a successor
                y = Successor(node);
            if (y->left != NULL)
                z = y->left;
            else
                z = y->right;
            if (z != NULL) //if z exists then his parent is y's parent
                z->parent = y->parent;
            if (y->parent == NULL) //if y is a root
                root = z;          //then the new root is a child of y
            else
            {
                if (y == y->parent->left) //if child of y isn't a root then it replaces y
                    y->parent->left = z;
                else
                    y->parent->right = z;
            }
            if (y != node) //if y isn't a primary node then it's his successor
            {              //and we exchange data
                node->value = y->value;
            }
            y->parent = NULL;
            y->left = NULL;
            y->right = NULL;
            delete y;
        }
    }
    BSTNode *search(int wanted_value) //Finds the pointer to the Node of the element with the given value
    {
        BSTNode *p = root;
        while (p != NULL)
        {
            if (p->value == wanted_value)
            {
                cout << "The value you are looking for (" << wanted_value << ") is in the tree" << endl;
                return p;
            }
            else
            {
                if (wanted_value < p->value)
                    p = p->left;
                else
                    p = p->right;
            }
        }
        cout << "There is no such item in the tree" << endl;
        return NULL;
    }
    void buildFromFile(string filename)
    {
        ifstream file;
        file.open(filename);
        if (!file)
            cout << "Can't open file" << endl;
        else
        {
            deleteBST();
            int newSize;
            int temp;
            file >> newSize;
            int i = 0;
            while (i < newSize)
            {
                file >> temp;
                addNode(temp);
                i++;
            }
            file.close();
        }
    }
    void DSW()
    {
        BSTNode *temp = root; //first part, creating linear list
        int line_counter = 0; //line counter
        while (temp != NULL)
        {
            if (temp->left != NULL) //if has left child
            {
                rightRotation(temp);
                temp = temp->parent;
            }
            else
            {
                temp = temp->right;
                line_counter++;
            }
        }
        int rotation_counter = line_counter + 1 - pow(2, floor(log2(line_counter + 1))); //rotation counter
        temp = root;                                                                     //second part, transforming list into BST
        for (int i = 1; i <= rotation_counter; i++)
        {
            leftRotation(temp);
            temp = temp->parent->right;
        }
        line_counter = line_counter - rotation_counter;
        while (line_counter > 1)
        {
            line_counter = line_counter / 2;
            temp = root;
            for (int i = 1; i <= line_counter; i++)
            {
                leftRotation(temp);
                temp = temp->parent->right;
            }
        }
    }
};
