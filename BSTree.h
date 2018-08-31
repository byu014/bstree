#ifndef __BSTREE_H__
#define __BSTREE_H__
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class BSTree {

private:
  Node *root = 0;

private:
  void preOrder(Node *) const;
  void inOrder(Node *) const;
  void postOrder(Node *) const;
  bool search(Node *,const string &) const;
  Node * searchGiveNode(Node *,const string &) const;
  int heightHelper(Node*, int & counter) const;
  //string largest(Node *, string & biggest) const;
  string small(Node *, string & smallest) const;
  void removeHelper(Node *,Node *, string);
  string findMin(Node*) const;
  string findMinHelper(Node*) const;
  string findMax(Node*) const;
  string findMaxHelper(Node*)const;
  void destructorTraversal(Node *);
  Node * prevNode(Node *,string &) const;
  void removeMore(Node *,Node*,string &);

public:
  //BSTree();
  ~BSTree();
  void insert(const string &);
  bool search(const string &) const;
  void inOrder( ) const;
  void postOrder( ) const;
  void preOrder( ) const;
  string largest( ) const;
  string smallest( ) const;
  int height(const string &) const;
  void remove(const string &);
  
};

#endif