
#include <iostream>
using namespace std;

int counter;
struct TreeNode { // creates a node with 3 spaces to save ints, |0|-|0|-|0|
    int data;
    TreeNode* Venstre;
    TreeNode* Høyre;
};
TreeNode* GetNewNode(int data) {
    TreeNode* newNode = new TreeNode(); // gives address of newly created node
    newNode->data = data;
    newNode->Venstre = newNode->Høyre = NULL; // sets the right and leftside of new nodes = '0'
    return newNode; 
}
TreeNode* Insert(TreeNode* root, int data) { // creating a new node in dynamic memory
    if (root == NULL) // checks if empty tree
    { 
        root = GetNewNode(data); // if tree is empty it creates a new node and sets it = root
    }
    else if (data <= root->data) { // if data is less or equal to the root.data then run insert again on the left side
        root->Venstre = Insert(root->Venstre, data); // this checks node is empty, if it is then stores the value
    }
    else  { // if data is more than the root.data, then run insert again on the right side
        root->Høyre = Insert(root->Høyre, data); // this checks node is empty, if it is then stores the value
    }
    return root;
}
bool Search(TreeNode* root, int data) {
    if (root == NULL) return false; // if root is 0 then the data isnt there
    else if (root->data == data) return true; // if root.data is equal to data return true
    else if (data <= root->data) return Search(root->Venstre, data);
    else return Search(root->Høyre, data); // if root is less than data we serch the left side if not we search the right side
}

void Postorder(TreeNode* root) {
    if (root == NULL) return;

    Postorder(root->Venstre);    // Visit left subtree
    Postorder(root->Høyre);   // Visit right subtree
    cout << root->data << " "; // Print data
    counter++;
}

void Inorder(TreeNode* root) {
    if (root == NULL) return;

    Inorder(root->Venstre);       //Visit left subtree
    cout << root->data << " ";   //Print data
    counter++;
    Inorder(root->Høyre);         // Visit right subtree
}

int FindHeight(TreeNode* root) {
    if (root == NULL)
        return -1;
    return max(FindHeight(root->Venstre), FindHeight(root->Høyre)) + 1;
}

bool IsBalanced(TreeNode* root)
{
    if ((FindHeight(root->Venstre) - FindHeight(root->Høyre)) <= 1 && (FindHeight(root->Venstre) - FindHeight(root->Høyre)) >= -1 && root != NULL)
    {

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int height = 0;
        TreeNode* root = NULL; // creating an empty tree
        root = Insert(root, 15); root = Insert(root, 10); root = Insert(root, 20); 
        root = Insert(root, 25); root = Insert(root, 8); root = Insert(root, 12); 
        //Print Nodes in Inorder
        cout << "Inorder: ";
        counter = 0;
        Inorder(root);
        cout << "\nnumber of nodes = " << counter << "\n";

        //Print Nodes in Postorder
        cout << "Postorder: ";
        counter = 0;
        Postorder(root);
        cout << "\nnumber of nodes = " << counter << "\n"; 

        cout << "\nHeight of tree = " << FindHeight(root) << "\n";

        if (IsBalanced(root))
            cout << "Tree is balanced";
        else
            cout << "Tree is not balanced";
        return 0;
};