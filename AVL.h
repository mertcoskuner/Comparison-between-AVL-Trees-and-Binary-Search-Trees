#ifndef _AVL_H
#define _AVL_H
#include <fstream>
#include <iostream>
#include <vector>
#include "strutils.h"

template <class Comparable>
class AvlTree;

template <class Comparable>
class AvlNode
{
    Comparable firstName;
    Comparable lastName ;
    Comparable phoneNumber;
    Comparable City;
    AvlNode           *left;
    AvlNode           *right;
    int   height;    
    AvlNode( const Comparable & firstname,const Comparable & lastname,
            const Comparable & phonenumber,const Comparable & city,AvlNode *lt, AvlNode *rt, int h = 0 ):
    firstName( firstname ),lastName( lastname ),phoneNumber( phonenumber ),City( city ), left( lt ), right( rt ), height( h ) { }

    friend class AvlTree<Comparable>;
};
template <class Comparable>
class AvlTree
{
    
    public:
    explicit AvlTree( const Comparable & notFound );
    AvlTree(  AvlTree & rhs );
    ~AvlTree( );

    const Comparable & findMin( ) const;
    const Comparable & findMax( ) const;
    const Comparable & find( const Comparable & x ) const;
    bool isEmpty( ) const;
    void printTree( ) const;

    void makeEmpty( );
    void insert(const Comparable & firstName,const Comparable & lastName,const Comparable & phoneNumber,const Comparable & City);
    void remove( const Comparable & x );

    const AvlTree & operator=( const AvlTree & rhs );
    AvlNode<Comparable> *root;
    const Comparable ITEM_NOT_FOUND;

    const Comparable & elementAt( AvlNode<Comparable> *t ) const;


    void remove(const Comparable & x, AvlNode<Comparable> * & t ) const;

    AvlNode<Comparable> * findMin( AvlNode<Comparable> *t ) const;
    AvlNode<Comparable> * findMax( AvlNode<Comparable> *t ) const;
    AvlNode<Comparable> * find( const Comparable & x, AvlNode<Comparable> *t ) const;

    void makeEmpty( AvlNode<Comparable> * & t ) const;
    void printTree( AvlNode<Comparable> *t ) const;

    // Avl manipulations
    int height( AvlNode<Comparable> *t ) const;
    int max( int lhs, int rhs ) const;
    void rotateWithLeftChild( AvlNode<Comparable> * & k2 ) const;
    void rotateWithRightChild( AvlNode<Comparable> * & k1 ) const;
    void doubleWithLeftChild( AvlNode<Comparable> * & k3 ) const;
    void doubleWithRightChild( AvlNode<Comparable> * & k1 ) const;
    const AvlTree & operator=(  AvlTree & rhs );
    AvlNode<Comparable> * cloneTree( AvlNode<Comparable> * t ) const;
    
    int depth_for_AVL_helper(Comparable type ,AvlTree<Comparable>  BST);
    void find(const Comparable & firstName,const Comparable & lastName, Comparable & phoneNumber,  Comparable & city, ofstream &output,bool  & output_var  ) const;
    void find_partial( const Comparable & firstName,const Comparable & lastName , AvlNode<Comparable> *AVL, ofstream &output,bool  & output_var) const;
    void PreOrderPrintHelper(ofstream &output);
    void InOrderPrintHelper(ofstream &output);
    void remove( const Comparable & firstName,const Comparable & lastName );
    int isbalanced(  AvlNode<Comparable> * & t ) ;
    int isbalanced_helper(); 
    void DrawHelp(ofstream &output);


private:
    AvlNode<Comparable> * find( const Comparable & firstName,const Comparable & lastName , AvlNode<Comparable> *t,bool  & output_var) const;
    int depth_for_AVL(Comparable type ,AvlNode<Comparable> * node );
    void insert( const Comparable & firstName,const Comparable & lastName,const Comparable & phoneNumber,const Comparable & City,
                AvlNode<Comparable> * & t ) const;
    AvlNode<Comparable> * clone( AvlNode<Comparable> *t ) const;
    void PreOrderPrint(AvlNode<Comparable> * AVL,ofstream &output);
    void InOrderPrint(AvlNode<Comparable> * AVL,ofstream &output);
    AvlNode<Comparable> * remove(const Comparable & firstName,const Comparable & lastName, AvlNode<Comparable> * & t );
    void  Draw(AvlNode<Comparable> * AVL,string empty, ofstream &output,bool x,int count,bool isfirst);
    };


#include "AVL.cpp"
#endif
