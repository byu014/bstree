#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include "BSTree.h"
//#include "Node.h"
// BSTree::BSTree()//constructor for BSTree that points root to 0;
// {
//     root = 0;
// }

void BSTree::destructorTraversal(Node * root)
{
    if(root == 0)
    {
        return;
    }
    destructorTraversal(root->left);
    destructorTraversal(root->right);
    delete root;
}

BSTree::~BSTree()
{
    Node * cur = root;
    while(root != 0)
    {
        string word = cur->data;
        remove(word);
    }
}

void BSTree::insert(const string & userString)
{
    if(root == 0)// when tree is empty
    {
        root = new Node(userString); //creates the new root Node
        return;
    }
    
    else
    {
        Node * current = root;
        while(current != 0)
        {
            if(userString < current->data) //checks if userString is less than the current Node's string
            {
                if(current->left == 0)
                {
                    current->left = new Node(userString); // creates new node
                    return;
                }
                else
                {
                    current = current->left;
                }
            }
            else if(userString > current->data) //checks if it's greater
            {
                if(current->right ==0)
                {
                    current->right = new Node(userString);// creates new Node
                    return;
                }
                else{
                    current = current->right;
                }
            }
            else if(userString == current->data)//special case if it is equal
            {
                current->counter += 1;
                return;
            }
            
        }
    }
}

void BSTree::preOrder(Node * cur) const // helper function for printing BST in preOrder
{
    if(cur != 0)
    {
        cout << cur->data << "(" << cur->counter <<"), ";
        preOrder(cur->left); // recursive traversal left
        preOrder(cur->right); // recursive traversal right
    }
    
}

void BSTree::preOrder() const // calls helper function to access root
{
    if(root == 0)
    {
        return;
    }
    preOrder(root);
    
}

bool BSTree::search(Node * root, const string & sentence) const // searches through tree to find matching string
{
    if(root  == 0 ) // base case 
    {
        return false;
    }
    if(root -> data == sentence) // if string matches
    {
        return true;
    }
    
    
    if(sentence < root->data) // left traversal of string is less
    {
        return search(root->left,sentence); 
    }
    else // right traversal
    {
        return search(root->right,sentence);
    }
    return false;
}

bool BSTree::search(const string & sentence) const
{
    return search(root,sentence);//calls helper search function
}

void BSTree::inOrder(Node * cur) const // helper function to print BST inOrder
{
    if(cur != 0)//base case
    {
        inOrder(cur->left); // left traversal
        cout << cur->data << "(" << cur->counter <<"), "; // prints
        inOrder(cur->right);// right traversal
    }
    
    
}

void BSTree::inOrder( ) const // calls helper function to access root
{
    if(root == 0)
    {
        return;
    }
    inOrder(root); // calls helper
}

void BSTree::postOrder(Node * cur) const // recursive helper function
{
    if(cur != 0)
    {
        postOrder(cur->left);  // traverses left
        postOrder(cur->right); // traverses right
        cout << cur->data << "(" << cur->counter <<"), ";//prints
    }
    
}

void BSTree::postOrder( ) const
{
    if(root == 0)
    {
        return;
    }
    postOrder(root);// calls helper
}

// string BSTree::largest(Node * curt, string & biggest) const
// {
//     if(root == 0) // base case
//     {
//         return "";
//     }
    
//     Node * cur = root;
    
//     while(cur != 0)
//     {
//         if(cur->right == 0)
//         {
//             return cur->data;
//         }
//         else
//         {
//             cur = cur->right;
//         }
//     }
//     return "";
    
// }


string BSTree::largest( ) const
{
    if(root == 0) // base case
    {
        return "";
    }
    
    Node * cur = root;
    
    while(cur != 0)
    {
        if(cur->right == 0)
        {
            return cur->data;
        }
        else
        {
            cur = cur->right;
        }
    }
    return "";
}

string BSTree::small(Node * cur, string & smallest) const // same concept as largest but opposite
{
    if(root == 0)
    {
        return "";
    }
    if(cur == 0)
    {
        return smallest;
    }
    
    small(cur->left,smallest);
    
    if(smallest > cur->data)
    {
        smallest = cur->data;
    }
    
    return smallest;
}

string BSTree::smallest( ) const
{
    return small(root,root->data); // calls helper function
}

Node * BSTree::searchGiveNode(Node * root ,const string & sentence) const 
{
    if(root  == 0 )//base case
    {
        return 0;
    }
    if(root -> data == sentence) // if strings match returns node
    {
        return root;
    }
    
    
    if(sentence < root->data)  // traverses left if string is less than current node data
    {
        return searchGiveNode(root->left,sentence);
    }
    else
    {
        return searchGiveNode(root->right,sentence); // else goes right
    }
    return 0;
}

int BSTree::height(const string & sentence) const //height function
{ 
    int counter = 0;
    Node * cur = root;
    
    while (cur != 0) 
    {
        if (cur->data == sentence) 
        {
            return heightHelper(cur, counter);
                
            
        } 
        else if (cur->data < sentence) 
        {
            cur = cur->right;
        } 
        else 
        {
            cur = cur->left;
        }
    }
    
    return -1;
}

int BSTree::heightHelper(Node * cur, int & counter) const // helper height
{

    if (cur == 0) 
    {
        return counter;
    }
    
    if (cur->right == 0 && cur->left == 0) 
    {
        return counter;
    } 
    
    counter += 1;
    int counter1 = counter;
    int counter2 = counter;
    
    counter1 = heightHelper(cur->right, counter1); 
    counter2 = heightHelper(cur->left, counter2);
    
    if (counter1 > counter2) 
    {
        return counter1;
    } 
    else if (counter1 < counter2) 
    {
        return counter2;
    }
    
    return counter1;
    
}

string BSTree::findMaxHelper(Node * cur) const
{
    if(cur->right == 0)
    {
        return cur->data;
    }
    return findMaxHelper(cur->right);
}

string BSTree::findMax(Node* cur) const
{
    
    return findMaxHelper(cur->left);
}

string BSTree::findMinHelper(Node * cur) const
{
    if(cur->left == 0 )
    {
        return cur->data;
    }
    //prev = root->data;
    return findMinHelper(cur->left);
    
}

string BSTree::findMin(Node * cur) const
{
   //string test;// = root->right ->data;
    return findMinHelper(cur->right);
}

Node * BSTree::prevNode(Node * root, string & sentence) const
{
    if(root == 0)
    {
        return 0;
    }
    
    if(root-> right -> data == sentence || root->left->data == sentence) // if strings match returns node
    {
        return root;
    }
    
    
    if(sentence < root->data)  // traverses left if string is less than current node data
    {
        return prevNode(root->left,sentence);
    }
    else
    {
        return prevNode(root->right,sentence); // else goes right
    }
    
    
}

void BSTree::removeMore(Node* cur, Node * parent, string & sentence)
{
    if(search(cur,sentence) == true)
    {
        // if(root == 0)// base case
        // {
        //     return;
        // }
        if(cur->data == sentence)
        {
            if(cur->counter > 1)
            {
                cur->counter = cur->counter - 1;
                return;
            }
            else 
            {
                removeHelper(cur,parent,sentence);
                return;
            }
        }
        else if(sentence < cur->data)// traversal left
        {
            removeHelper(cur->left,cur,sentence);
            //string tempLeft = cur->left->data;
        }
        else if(sentence > cur->data) // traversal right
        {
            removeHelper(cur->right,cur,sentence);
            //string tempRight = cur->right->data;
        }
        
    }
    else
    {
        return;
    }
}

void BSTree::removeHelper(Node * cur ,Node * parent, string sentence) 
{
    if(cur->data == sentence)
    {
        if(cur->counter >1)
        {
            cur->counter = cur->counter -1;
            return;
        }
        else if(cur->left == 0 && cur->right == 0) // leaf case
        {

            //Node * previousNode = prevNode(root,sentence);
            if(parent != 0)// if not root
            {
                if(parent->left != 0)
                {
                    if(cur->data == parent->left->data)
                    {
                        parent->left = 0;
                    }
                }
                if(parent->right != 0){
                    if(cur->data == parent->right->data)
                    {  
                        parent->right = 0;
                    }
                }
            }
            else if(root == cur)//root case
            {
                root = 0;
            }
            delete cur;
            cur = 0;
            return;
        }
        else if(cur->left != 0)//checks if left exists
        {
            string max = findMaxHelper(cur->left);
            Node * maxNode = searchGiveNode(cur,max);
            cur->data = max;
            cur->counter = maxNode->counter;
            if(maxNode->counter > 1)
            {
                maxNode->counter = 1;
            }
            // while(search(cur->left,max) != false)
            // {
                removeHelper(cur->left,cur,max);
            // }
        }
        else if(cur->right != 0)//checks if just right no left
        {
            string min = findMinHelper(cur->right);
            Node * minNode = searchGiveNode(cur,min);
            cur->data = min;
            cur->counter = minNode->counter;
            if(minNode->counter > 1)
            {
                minNode->counter = 1;
            }
            // while(search(cur->right,min) != false)
            // {
                removeHelper(cur->right,cur,min);
            //}
           
        }
        
    }
    else if(sentence < cur->data)// traversal left
    {
            
            removeHelper(cur->left,cur,sentence);
            //string tempLeft = cur->left->data;
    }
    else if(sentence > cur->data) // traversal right
    {
        
        removeHelper(cur->right,cur,sentence);
        //string tempRight = cur->right->data;
    }
}

void BSTree::remove(const string & sentence)
{
    if(search(sentence) == true)
    {
        // if(root == 0)// base case
        // {
        //     return;
        // }
        
        Node * parent = 0;
        if(root->data == sentence)
        {
            if(root->counter > 1)
            {
                root->counter = root->counter - 1;
            }
            else 
            {
                removeHelper(root,parent,sentence);
                return;
            }
        }
        else if(sentence < root->data)// traversal left
        {
            removeHelper(root->left,root,sentence);
            //string tempLeft = cur->left->data;
        }
        else if(sentence > root->data) // traversal right
        {
            removeHelper(root->right,root,sentence);
            //string tempRight = cur->right->data;
        }
        
    }
    else
    {
        return;
    }
}