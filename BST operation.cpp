#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(int v)
    {
        data = v;
        left = NULL;
        right = NULL;
    }
};
class bst
{
public:
    node *root;
    // insertion operation
    void insert(node *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
        }
        else
        {
            node *temp = root;
            while (temp != NULL)
            {
                if (temp->data == new_node->data)
                {
                    cout << "value is already present in tree so we can not add";
                    break;
                }
                else if (new_node->data < temp->data && temp->left == NULL)
                {
                    temp->left = new_node;
                    break;
                }
                else if (new_node->data < temp->data)
                {
                    temp = temp->left;
                }
                else if (new_node->data > temp->data && temp->right == NULL)
                {
                    temp->right = new_node;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    // inorder printing Fuction
    void inorder(node *r) //(left, current node, right)
    {
        if (r == NULL)
        {
            return;
        }
        // first we recur on left child
        inorder(r->left);
        // then print data of node
        cout << r->data << " " << endl;
        // second recur on right child
        inorder(r->right);
        // if we want to do preorder fuction that time we need same code but just put code of line 73 just above of line 71 and we can get preorder fuction
    }
    // here we create a search operation
    node *search(int val)
    {
    
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            node *temp = root;
            while (temp != NULL)
            {
                if (temp->data > val)
                {
                    temp = temp->left;
                }
                else if (temp->data < val)
                {
                    temp = temp->right;
                }
                else
                {
                    return temp;
                }
            }
            // if value is not found that's time we return NULL
            return NULL;
        }
    }
    // here we find the height of BST
    int hieght(node *r)
    {
        // first we check root is NULL or not if NULL then exit
        if (r == NULL)
        {
            return -1;
        }
        else
        {
            // here we assign the value of left child of to lh
            int lh = hieght(r->left);
            // here we assign the value of right child to rh
            int rh = hieght(r->right);
            // here we check which is greater lh or rh
            if (lh > rh)
            {
                // here we apply formula of height calculat
                return lh + 1;
            }
            else
            {
                return rh + 1;
            }
        }
    }
    // this is for smallest value in BST
    node* minvalue(node *v)
    {
        node* temp2 = v;
        while (temp2->left !=NULL)
        {
            temp2 = temp2->left;
        }
        cout<<"min  is: "<<temp2;
    }
    // this is for largest value in BST
    node* maxvalue(node *v)
    {
        node* temp1;
        while (v != NULL)
        {
            v = v->right;
        }
        cout << v->data;
    }
};
int main()
{
    // here we create a object of bst class
    bst obj;
    int ch, val;
    do
    {
        cout << "1. Insert Data" << endl;
        cout << "2. Hight of tree" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Print BST" << endl;
        cout << "5. Smallest value in tree" << endl;
        cout << "6. Largest value in tree" << endl;
        cout << "7. Clear Screen";
        cout << "8. Exit" << endl;
        cout << "Choose which operation you want to perform on BST" << endl;
        cin >> ch;

        // here we create a object of node class.. we can also create a object using regular method but in regular method object is created in stack memory but we use dinamic memmory allocation and thats why we create object of class like below
        node *new_node = new node();

        switch (ch)
        {
        case 1:
            // cout<<"Insertion"<<endl;
            cout << "Enter the data which you want to add in the tree" << endl;
            cin >> val;
            new_node->data = val;
            obj.insert(new_node);

            break;
        case 2:
            cout << "height of tree is " << obj.hieght(obj.root) << endl;

            break;
        case 3:
            // cout << "Search" << endl;
            cout << "Enter the which you want to find" << endl;
            cin >> val;
            new_node = obj.search(val);
            if (new_node != NULL)
            {
                cout << "value is found" << endl;
            }
            else
            {
                cout << "value not fond" << endl;
            }
            break;

        case 4:
            obj.inorder(obj.root);
            // cout << "Data printed" << endl;
            break;

        case 5:
            cout << "small value in tree is ";
            obj.minvalue(obj.root);
            break;
        case 6:
            cout << "largest value in tree is ";
            obj.maxvalue(obj.root);
            break;
        case 7:
            system("cls");
            break;
        case 8:
            exit(0);
            break;
        }

    } while (ch != 0);
    return 0;
}