#ifndef BINARY_TREE_CPP
#define BINARY_TREE_CPP

#include "BinaryTree.h"

// BinaryTree Constructor
// Initialize the tree to empty
template <class T>
BinaryTree<T>::BinaryTree(bool isAVL)
{
	isAVLTree = isAVL;
	root = NULL;
}

// BinaryTree Destructor
// Deletes the root node.
// Relies on Node's delete method.
template <class T>
BinaryTree<T>::~BinaryTree(void)
{
	// Add your code here
	// Calls the recursive function
	MakeEmpty(root);

	// Deletes the root
	delete root;
	root = NULL;
}

// MakeEmpty
// Recurses the entire tree, 
template <class T>
void BinaryTree<T>::MakeEmpty(BinaryTreeNode<T>* curr)
{
	// Add your code here
	// Checks if the current node is null
	if (curr == NULL)
	{
		return;
	}
	else
	{
		// Recursivly left
		if (curr->GetLeft() != NULL)
		{
			MakeEmpty(curr->GetLeft());
			// Deletes 
			delete curr->GetLeft();
		}
		// Recursivly right
		if (curr->GetRight() != NULL)
		{
			MakeEmpty(curr->GetRight());
			// Deletes
			delete curr->GetRight();
		}
		// Sets to null
		curr->SetLeft(NULL);
		curr->SetRight(NULL);
	}
}

/////////////////////////////////////////////////////////////////
// Insert Methods
/////////////////////////////////////////////////////////////////

// BinaryTree Insert
// Public Insert adds the item into the tree.
// If the tree is empty, adds the item as the root.
// Otherwise, uses the private insert to recursively insert.
template <class T>
void BinaryTree<T>::Insert(const T& item)
{
	// Add your code here
	if (root == NULL)
	{
		root = new BinaryTreeNode<T>(item);
	}
	else
	{
		Insert(item, root);
	}

	// If is AVL tree 
	if (isAVLTree)
	{
		// Fixes the height of root
		FixHeight(root);

		// Rebalances
		if (NeedsRebalancing(root))
		{
			root = RebalanceNode(root);

			// Fixes height
			FixHeight(root);
		}
	}
}

// Insert
// Insert the item starting at the current node.  If the
// item is less than the current node, the item is added
// to the left subtree.  If the item is greater, it is
// added to the right subtree.  If there is no subtree,
// the node is added as a child of this node.
template <class T>
void BinaryTree<T>::Insert(const T& item, BinaryTreeNode<T>* curr)
{
	// Add your code here
	// If items is less
	if (item < curr->GetData())
	{
		// If the left node is null
		if (curr->GetLeft() == NULL)
		{
			curr->SetLeft(new BinaryTreeNode<T>(item));
		}
		else
		{
			// Recursivly checks the tree
			Insert(item, curr->GetLeft());
		}
	}
	// If item is greater
	else if (curr->GetData() < item)
	{
		// If the right node is null
		if (curr->GetRight() == NULL)
		{
			curr->SetRight(new BinaryTreeNode<T>(item));
		}
		else
		{
			// Recursivly checks the tree
			Insert(item, curr->GetRight());
		}
	}

	// If is AVL tree
	if (isAVLTree)
	{
		// Fixes height of curr
		FixHeight(curr);

		// If curr right is null and needs to be rebalanced
		if (curr->GetRight() != NULL && NeedsRebalancing(curr->GetRight()))
		{
			// Sets right
			curr->SetRight(RebalanceNode(curr->GetRight()));

			// Fixes height
			FixHeight(curr->GetRight());
		}

		// If curr left is null and needs to be rebalanced
		if (curr->GetLeft() != NULL && NeedsRebalancing(curr->GetLeft()))
		{
		// Sets right
		curr->SetLeft(RebalanceNode(curr->GetLeft()));

		// Fixes height
		FixHeight(curr->GetLeft());
		}
	}
}

/////////////////////////////////////////////////////////////////
// Search Methods
/////////////////////////////////////////////////////////////////

// Search
// Public Search method that uses the private version to search
// from the root.  Returns TRUE if the item is found.  Returns 
// FALSE if the tree is empty or if the item is not found.
template <class T>
bool BinaryTree<T>::Search(const T& item) const
{
	// Add your code here
	// If root is equal to null
	if (root == NULL)
	{
		return false;
	}
	else
	{
		// Recursivly call the search function
		return Search(item, root);
	}
}

// Search
// Private Search method that examines the current node and
// recursively its children until it finds the item.  If
// the current node has no children and does not match
// the item, then the search is exhausted and the item
// was not found.
// Returns TRUE if the item is found, FALSE if not. 
template <class T>
bool BinaryTree<T>::Search(const T& item, BinaryTreeNode<T>* curr) const
{
	// Add your code here
	// If curr is equal to null
	if (curr == NULL)
	{
		return false;
	}
	// If item is less 
	if (item < curr->GetData())
	{
		return Search(item, curr->GetLeft());
	}
	// If item is greater
	else if (item > curr->GetData())
	{
		return Search(item, curr->GetRight());
	}
	// If item is equal
	else if (item == curr->GetData())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/////////////////////////////////////////////////////////////////
// Remove Methods
/////////////////////////////////////////////////////////////////

// Remove
// The public versrion of Remove that initiates the recursive
// search for the item to remove.
// Returns true if the remove was successful, false otherwise.
template <class T>
bool BinaryTree<T>::Remove(const T& item)
{
	// Add your code here
	// If root equals null
	if (root == NULL)
	{
		return false;
	}
	// If root is equal to item
	else if (root->GetData() == item)
	{
		root = RemoveNode(root);
		return true;
	}
	// recurse until item is found
	else
	{
		return Remove(item, root);
		return true;
	}
}

// Remove
// The private version of Remove, recursively searches for the item
// to remove. Returns true if the removal was successful, false otherwise.
// Uses RemoveNode to actually remove the node of the item once found and 
// fixes the parent's pointer to the removed node.
template <class T>
bool BinaryTree<T>::Remove(const T& item, BinaryTreeNode<T>* curr)
{
	// Add your code here
	// If curr is null
	if (curr == NULL)
	{
		return false;
	}
	// If right is not null
	if (curr->GetRight() != NULL)
	{
		// If curr right is equal to item
		if (curr->GetRight()->GetData() == item)
		{
			curr->SetRight(RemoveNode(curr->GetRight()));
			return true;
		}
		// If item is greater then curr
		else if (item > curr->GetData())
		{
			return Remove(item, curr->GetRight());
		}
	}
	// If left is not null
	if (curr->GetLeft() != NULL)
	{
		// If curr left is equal to item
		if (curr->GetLeft()->GetData() == item)
		{
			curr->SetLeft(RemoveNode(curr->GetLeft()));
			return true;
		}
		else
		{
			return Remove(item, curr->GetLeft());
		}
	}
	else
	{
		return false;
	}
}

// RemoveNode
// Removes the curr node by determining which node should take its
// place in the revised tree.  Returns the node that should take
// curr's place in the tree with restructured children as appropriate.
// If curr had no children, null is returned.
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::RemoveNode(BinaryTreeNode<T>* curr)
{
	// Add your code here
	// If curr left is null and curr right is null
	if (curr->GetLeft() == NULL && curr->GetRight() == NULL)
	{
		delete curr;
		return NULL;
	}
	// If curr left is null or curr right is null
	else if (curr->GetLeft() == NULL || curr->GetRight() == NULL)
	{
		// If curr left is null
		if (curr->GetLeft() == NULL)
		{
			BinaryTreeNode<T>* temp = curr->GetRight();
			delete curr;
			return temp;
		}
		else
		{
			BinaryTreeNode<T>* temp = curr->GetLeft();
			delete curr;
			return temp;
		}
	}
	// If right is null
	else if (curr->GetRight() != NULL)
	{
		// Variables
		BinaryTreeNode<T>* value = curr;
		BinaryTreeNode<T>* oValue = curr;
		BinaryTreeNode<T>* temp = curr;
		temp = temp->GetRight();

		// If temp left is null
		if (temp->GetLeft() == NULL)
		{
			oValue = temp;
		}
		value = temp;

		// While temp left is not null
		while (temp->GetLeft() != NULL)
		{
			oValue = value;
			value = value->GetLeft();
			temp = temp->GetLeft();
		}
		// Sets curr to value
		curr->SetData(value->GetData());

		// If value right is not null
		if (value->GetRight() != NULL)
		{
			// Sets oValue left to value right
			oValue->SetLeft(value->GetRight());
		}
		else
		{
			// Sets oValue to null
			oValue->SetLeft(NULL);
		}
		// If oValue is equal to value
		if (oValue == value)
		{
			// Sets curr right to value right
			curr->SetRight(value->GetRight());
		}
		// Sets value right and value left to null
		value->SetLeft(NULL);
		value->SetRight(NULL);
		// Removes node
		RemoveNode(value);
		// Returns curr
		return curr;
	}
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// AVL METHODS - ADD THESE IN WEEK 2
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// AVL Methods
/////////////////////////////////////////////////////////////////

// NeedsBalancing
// Determines if the curr node needs to be rebalanced by looking
// at its children and grandchildren.  If there is a difference in
// height between the left and right child that is greater than 1,
// the node needs to be rebalanced.  False otherwise.
template <class T>
bool BinaryTree<T>::NeedsRebalancing(BinaryTreeNode<T>* curr)
{
	// Add your code here for week 2
	// Variables
	int heightLeft;
	int heightRight;

	// If curr left is not equal to null
	if (curr->GetLeft() != NULL)
	{
		// Gets and sets the left height
		heightLeft = curr->GetLeft()->GetHeight();
	}
	else
	{
		// Sets the left height equal to -1
		heightLeft = -1;
	}
	
	// If curr right is not equal to null
	if (curr->GetRight() != NULL)
	{
		// Gets and sets the right height
		heightRight = curr->GetRight()->GetHeight();
	}
	else
	{
		// Sets right height equal to -1
		heightRight = -1;
	}

	// Checks and rebalances
	if (heightLeft - heightRight > 1 || heightRight - heightLeft > 1)
	{
		return true;
	}

	// Doesn't rebalance
	return false;
}

// RebalanceNode the current node
// Rebalances the curr node by moving around its children and
// grandchildren as required based on which type of rotation
// is necessary (left-left, right-right, right-left or left-right).
// Returns the new node that should replace curr in the tree.
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::RebalanceNode(BinaryTreeNode<T>* curr)
{
	// TODO: Add your code here for week 2
	// Variables
	int heightLeft;
	int heightRight;
	int leftLeft;
	int rightRight;
	int rightLeft;
	int leftRight;
	
	// If curr left does not equal null
	if (curr->GetLeft() != NULL)
	{
		// Set left height
		heightLeft = curr->GetLeft()->GetHeight();

		// If curr left left is not equal to null
		if (curr->GetLeft()->GetLeft() != NULL)
		{
			// Sets left left
			leftLeft = curr->GetLeft()->GetLeft()->GetHeight();
		}
		else
		{
			// Set left left to -1
			leftLeft = -1;
		}

		// If curr left right does not equal null
		if (curr->GetLeft()->GetRight() != NULL)
		{
			// Sets left right
			leftRight = curr->GetLeft()->GetRight()->GetHeight();
		}
		else
		{
			// Sets left right to -1
			leftRight = -1;
		}
	}
	// Sets all to -1 if nothing remains
	else
	{
		heightLeft = -1;
		leftLeft = -1;
		leftRight = -1;
	}

	// If curr right does not equal null
	if (curr->GetRight() != NULL)
	{
		// Set right height
		heightRight = curr->GetRight()->GetHeight();

		// If curr right right is not equal to null
		if (curr->GetRight()->GetRight() != NULL)
		{
			// Sets right right
			rightRight = curr->GetRight()->GetRight()->GetHeight();
		}
		else
		{
			// Set right right to -1
			rightRight = -1;
		}

		// If curr right left does not equal null
		if (curr->GetRight()->GetLeft() != NULL)
		{
			// Sets right left
			rightLeft = curr->GetRight()->GetLeft()->GetHeight();
		}
		else
		{
			// Sets right left to -1
			rightLeft = -1;
		}
	}
	// Sets all to -1 if nothing remains
	else
	{
		heightRight = -1;
		rightRight = -1;
		rightLeft = -1;
	}

	// Left inbalanced
	if (heightLeft > heightRight)
	{
		// Left left over left right
		if (leftLeft > leftRight)
		{
			return RightRotation(curr);
		}
		// Left right over left left
		if (leftRight > leftLeft)
		{
			curr->SetLeft(LeftRotation(curr->GetLeft()));
			return RightRotation(curr);
		}

	}
	// Right inbalanced
	else if (heightRight > heightLeft)
	{
		// Right right over right left
		if (rightRight > rightLeft)
		{
			return LeftRotation(curr);
		}
		// Right left over right right
		if (rightLeft > rightRight)
		{
			curr->SetRight(RightRotation(curr->GetRight()));
			return LeftRotation(curr);
		}
	}
	// No inbalance
	else
	{
		// Return curr
		return curr;
	}

	// Return null
	return NULL;
}

// FixHeight
// Fixes the height of curr by looking at the height of its
// chilren and taking the larger height and adding one.
template <class T>
void BinaryTree<T>::FixHeight(BinaryTreeNode<T>* curr)
{
	// TODO: Add your code here for week 2
	// Variables
	int heightLeft;
	int heightRight;

	// If curr does not equal null
	if (curr != NULL)
	{
		// If curr left does not equal null
		if (curr->GetLeft() != NULL)
		{
			// Sets left height
			heightLeft = curr->GetLeft()->GetHeight();
		}
		else
		{
			// Sets left height equal to -1
			heightLeft = -1;
		}

		// If curr right does not equal null
		if (curr->GetRight() != NULL)
		{
			// Sets right height
			heightRight = curr->GetRight()->GetHeight();
		}
		else
		{
			// Sets right height equal to -1
			heightRight = -1;
		}

		// Checks which height is bigger
		if (heightLeft > heightRight)
		{
			// Sets the height to left plus 1
			curr->SetHeight(heightLeft + 1);
		}
		else
		{
			// Sets the height to right plus 1
			curr->SetHeight(heightRight + 1);
		}
	}
}

// Rotation to the left
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::LeftRotation(BinaryTreeNode<T>* curr)
{
	// Variables
	BinaryTreeNode<T>* rightChildren = curr->GetRight();
	BinaryTreeNode<T>* rightLeftChildren;

	// If curr does not equal null
	if (curr != NULL)
	{
		// Sets the right left child
		rightLeftChildren = rightChildren->GetLeft();
	}
	else
	{
		// Sets the right left child equal to null
		rightLeftChildren = NULL;
	}

	// Sets the right child to left
	rightChildren->SetLeft(curr);

	// Sets curr to right
	curr->SetRight(rightLeftChildren);

	// Fixes height
	FixHeight(curr);
	FixHeight(rightLeftChildren);

	// Returns the right child
	return rightChildren;
}

// Rotation to the right
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::RightRotation(BinaryTreeNode<T>* curr)
{
	// Variables
	BinaryTreeNode<T>* leftChildren = curr->GetLeft();
	BinaryTreeNode<T>* leftRightChildren;

	// If curr does not equal null
	if (curr != NULL)
	{
		// Sets the left right child
		leftRightChildren = leftChildren->GetRight();
	}
	else
	{
		// Sets the left right child equal to null
		leftRightChildren = NULL;
	}

	// Sets the right child to left
	leftChildren->SetRight(curr);

	// Sets curr to right
	curr->SetLeft(leftRightChildren);

	// Fixes height
	FixHeight(curr);
	FixHeight(leftRightChildren);

	// Returns the right child
	return leftChildren;
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// DO NOT CHANGE ANYTHING BELOW THIS LINE
// ALL METHODS BELOW THIS LINE ARE FINE AND SHOULD WORK WITH
// YOUR CODE.  YOU DO NOT NEED TO CHANGE ANYTHING FROM HERE TO
// THE BOTTOM OF THE FILE.
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

// IsAVL
// Returns true if the tree is an AVL tree and false otherwise
template <class T>
bool BinaryTree<T>::IsAVL() const
{
	return isAVLTree;
}

/////////////////////////////////////////////////////////////////
// Print Methods
/////////////////////////////////////////////////////////////////

// InOrderPrint
// Public version of InOrderPrint, intializes the recursion
template <class T>
void BinaryTree<T>::InOrderPrint(ostream& sout) const
{
	InOrderPrint(sout, root);
}

// PreOrderPrint
// Public version of PreOrderPrint, intializes the recursion
template <class T>
void BinaryTree<T>::PreOrderPrint(ostream& sout) const
{
	PreOrderPrint(sout, root);
}

// PostOrderPrint
// Public version of PostOrderPrint, intializes the recursion
template <class T>
void BinaryTree<T>::PostOrderPrint(ostream& sout) const
{
	PostOrderPrint(sout, root);
}

// InOrderPrint
// Prints the tree in order (left child, current
// node, right child).
template <class T>
void BinaryTree<T>::InOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const
{
	// If the current Node exists
	if (curr == NULL)
	{
		return;
	}
	// If the node has a left subtree, print that first
	if (curr->GetLeft() != NULL)
	{
		// Print the left subtree
		InOrderPrint(sout, curr->GetLeft());
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";

	// If the node has a right subtree, print it last
	if (curr->GetRight() != NULL)
	{
		// Print the right subtree
		InOrderPrint(sout, curr->GetRight());
	}
}

// PreOrderPrint
// Prints the tree in pre-order (current node, left child,
// right child).
template <class T>
void BinaryTree<T>::PreOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const
{
	// If the current Node exists
	if (curr == NULL)
	{
		return;
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";

	// If the node has a left subtree, print that first
	if (curr->GetLeft() != NULL)
	{
		// Print the left subtree
		PreOrderPrint(sout, curr->GetLeft());
	}

	// If the node has a right subtree, print it last
	if (curr->GetRight() != NULL)
	{
		// Print the right subtree
		PreOrderPrint(sout, curr->GetRight());
	}
}

// PostOrderPrint
// Prints the tree "post-order".  Prints
// the left subtree, prints the right subree, then the current node.
template <class T>
void BinaryTree<T>::PostOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const
{
	// If the current Node exists
	if (curr == NULL)
	{
		return;
	}

	// If the node has a left subtree, print that first
	if (curr->GetLeft() != NULL)
	{
		// Print the left subtree
		PostOrderPrint(sout, curr->GetLeft());
	}

	// If the node has a right subtree, print it last
	if (curr->GetRight() != NULL)
	{
		// Print the right subtree
		PostOrderPrint(sout, curr->GetRight());
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";
}

/////////////////////////////////////////////////////////////////
// Operators
/////////////////////////////////////////////////////////////////

// Insertion Operator
// Display the tree using an in-order print
template <class T>
ostream& operator<<(ostream& sout, const BinaryTree<T>& tree)
{
	sout << "PreOrderPrint:   ";
	tree.PreOrderPrint(sout, tree.root);
	sout << "\n";

	sout << "InOrderPrint:    ";
	tree.InOrderPrint(sout, tree.root);
	sout << "\n";

	sout << "PostOrderPrint:  ";
	tree.PostOrderPrint(sout, tree.root);
	sout << "\n";
	return sout;
}

#endif
