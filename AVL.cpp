/**
         * Return the height of node t, or -1, if NULL.
 */
#include "AVL.h"
#include <fstream>
#include <iostream>
#include "strutils.h"

using namespace std;

template <class Comparable>
AvlTree<Comparable>::AvlTree(const Comparable & notFound ) :
    ITEM_NOT_FOUND( notFound ), root( NULL ){}

template <class Comparable>
void AvlTree<Comparable>::makeEmpty( )
{
     makeEmpty( root );
}
template <class Comparable>
AvlTree<Comparable>::AvlTree(  AvlTree<Comparable> & rhs ) :root( NULL ), ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND )
{
    *this = rhs;
}

template <class Comparable>
AvlTree<Comparable>::~AvlTree( )
{
    makeEmpty( );
}
template <class Comparable>
bool AvlTree<Comparable>:: isEmpty( ) const{
    if(root==NULL){
        return true;
    }
    return false;
}

template <class Comparable>
void AvlTree<Comparable>::makeEmpty( AvlNode<Comparable> * & t ) const
{
    if( t != NULL )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = NULL;
}

template <class Comparable>
int AvlTree<Comparable>::height( AvlNode<Comparable> *t )
const
 {
        if (t == NULL)
           return -1;
    
      return t->height;
}

/**
        * Return maximum of lhs and rhs.
*/
template <class Comparable>
int AvlTree<Comparable>::max( int lhs, int rhs )
const
{
     if (lhs > rhs)
         return lhs;

     return rhs;
}
template <class Comparable>
void AvlTree<Comparable>::insert(const Comparable & firstName,const Comparable & lastName,const Comparable & phoneNumber,const Comparable & City)
{
    insert(firstName,lastName, phoneNumber,City, root );
}


template <class Comparable>
void AvlTree<Comparable>::insert( const Comparable & firstName,const Comparable & lastName,const Comparable & phoneNumber,const Comparable & City,AvlNode<Comparable> * & t ) const
{
     if ( t == NULL )
          t = new AvlNode<Comparable>(firstName,lastName, phoneNumber,City, NULL, NULL );

     else if ((firstName < t->firstName && lastName == t->lastName) || (firstName == t->firstName && lastName < t->lastName) ||(firstName < t->firstName && lastName < t->lastName) ||(firstName < t->firstName && lastName > t->lastName) ) {
          // X should be inserted to the left tree!
         insert(firstName,lastName, phoneNumber,City, t->left );
          
   // Check if the left tree is out of balance (left subtree grew in height!)
         if ( height( t->left ) - height( t->right ) == 2 ){
             
             if ( (firstName < t->left->firstName && lastName == t->left->lastName) || (firstName == t->left->firstName && lastName < t->left->lastName) ||(firstName < t->left->firstName && lastName < t->left->lastName) ||(firstName < t->left->firstName && lastName > t->left->lastName)){  // X was inserted to the left-left subtree!
                 rotateWithLeftChild( t );}
             else{                 // X was inserted to the left-right subtree!
                 doubleWithLeftChild( t );}}
      }
     else if( (firstName > t->firstName && lastName > t->lastName  )||(firstName > t->firstName && lastName == t->lastName  ) || (firstName == t->firstName && lastName > t->lastName  )||(firstName > t->firstName && lastName < t->lastName  ) )
     {    // Otherwise X is inserted to the right subtree

           insert(firstName,lastName, phoneNumber,City, t->right );
         if ( height( t->right ) - height( t->left ) == 2 ){
             // height of the right subtree increased
             if ((firstName > t->right->firstName && lastName > t->right->lastName  )||(firstName > t->right->firstName && lastName == t->right->lastName  ) || (firstName == t->right->firstName && lastName > t->right->lastName  )||(firstName > t->right->firstName && lastName < t->right->lastName  ) ){
                 // X was inserted to right-right subtree
                 rotateWithRightChild( t );}
             else{ // X was inserted to right-left subtree
                 doubleWithRightChild( t );}}
      }
     else{
          ;  // Duplicate; do nothing
         
     }

    // update the height the node
      t->height = max( height( t->left ), height( t->right ) ) + 1;
}
/**
  * Rotate binary tree node with left child.
  * For AVL trees, this is a single rotation for case 1.
  * Update heights, then set new root.
  */
 template <class Comparable>
 void AvlTree<Comparable>::rotateWithLeftChild(
             AvlNode<Comparable> * & k2 ) const
 {
        AvlNode<Comparable> *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
 }

/**
 * Rotate binary tree node with right child.
 * For AVL trees, this is a single rotation for case 4.
 * Update heights, then set new root.
 */
template <class Comparable>
void AvlTree<Comparable>::rotateWithRightChild
            ( AvlNode<Comparable> * & k1 ) const
{
      AvlNode<Comparable> *k2 = k1->right;
      k1->right = k2->left;
      k2->left = k1;
      k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
      k2->height = max( height( k2->right ), k1->height ) + 1;
      k1 = k2;
}
/**
  * Double rotate binary tree node: first left child.
  * with its right child; then node k3 with new left child.
  * For AVL trees, this is a double rotation for case 2.
  * Update heights, then set new root.
  */
 template <class Comparable>
 void AvlTree<Comparable>::doubleWithLeftChild
         ( AvlNode<Comparable> * & k3 ) const
 {
         rotateWithRightChild( k3->left );
         rotateWithLeftChild( k3 );
 }
/**
 * Double rotate binary tree node: first right child.
 * with its left child; then node k1 with new right child.
 * For AVL trees, this is a double rotation for case 3.
 * Update heights, then set new root.
 */
template <class Comparable>
void AvlTree<Comparable>::doubleWithRightChild
        ( AvlNode<Comparable> * & k1 ) const
{
       rotateWithLeftChild( k1->right );
       rotateWithRightChild( k1 );
}

template <class Comparable>
AvlNode<Comparable> * AvlTree<Comparable>::clone( AvlNode<Comparable> * t ) const
{
    if ( t == NULL )
        return NULL;
    else
        return new AvlNode<Comparable>( t->firstName,t->lastName,t->phoneNumber,t->City,clone(t->left),clone(t->right));
}


template <class Comparable>
AvlNode<Comparable> * AvlTree<Comparable>::cloneTree( AvlNode<Comparable> * t ) const
{
    if ( t == NULL ){
        return NULL;}
    AvlNode<Comparable> * new_r = clone(t);
    new_r->left = cloneTree(t->left);
    new_r->right = cloneTree(t->right);
    return new_r;
}

template <class Comparable>
const AvlTree<Comparable> & AvlTree<Comparable>:: operator=(  AvlTree<Comparable> & rhs )//deep copy
{
      if ( this != &rhs )
      {
           makeEmpty();
          if (rhs.isEmpty( ) ){
              return *this;}
          root  =  cloneTree(rhs.root) ;    }
    return *this;
}
template <class Comparable>
int AvlTree<Comparable>:: depth_for_AVL(Comparable type ,AvlNode<Comparable> * node){
    int length_for_left_side = 0 , length_for_right_side= 0 ;
    
    if(node == NULL){
        return 0;
    }
    length_for_left_side = depth_for_AVL(type , node->left) ;

    length_for_right_side = depth_for_AVL(type , node->right);

    if (length_for_left_side > length_for_right_side){
        return (length_for_left_side + 1);}
    else{
        return (length_for_right_side + 1);}

}
template <class Comparable>
int AvlTree<Comparable>:: depth_for_AVL_helper(Comparable type ,AvlTree<Comparable>  AVL){
    int length  =0;
    if(type =="left" && AVL.root->left != NULL){
        length  =depth_for_AVL(type,AVL.root->left);}
    else if(type =="right" && AVL.root->right != NULL){
        length  =depth_for_AVL(type,AVL.root->right);}

    return  length;
}
 

/**
  * Find item x in the tree.
  * Return the matching item or ITEM_NOT_FOUND if not found.
  */
template <class Comparable>
void AvlTree<Comparable>::find( const Comparable & firstName,const Comparable & lastName,  Comparable & phoneNumber,  Comparable & city, ofstream &output, bool & output_var   ) const
{

    if(lastName == "" && find( firstName,lastName, root,output_var ) == NULL){
        find_partial(firstName,lastName, root, output,output_var);
    }
    else{
        AvlNode<string> * info = find( firstName,lastName, root,output_var ) ;
        if(output_var ==true){
            city = info->City;
            phoneNumber = info->phoneNumber;
        }

    }
}

template <class Comparable>
AvlNode<Comparable> *AvlTree<Comparable>::find( const Comparable & firstName,const Comparable & lastName , AvlNode<Comparable> *t, bool  & output_var ) const
{
    while( t != NULL ){
        if( firstName < t->firstName && lastName == t->lastName ){
            t = t->left;
        }
           
        else if( firstName == t->firstName && lastName < t->lastName ){
            t = t->left;
        }
            
        else if( firstName < t->firstName && lastName < t->lastName ){
            t = t->left;  // insert at the left or
        }
           
        else if( firstName < t->firstName && lastName > t->lastName ){
            t = t->left;
        }
            
        
        else if(firstName > t->firstName && lastName > t->lastName  ){
            t = t->right;// right subtree
        }
            
        else if(firstName > t->firstName && lastName == t->lastName  ){
            t = t->right;// right subtree
        }
            
        else if(firstName == t->firstName && lastName > t->lastName  ){
            t = t->right;// right subtree
        }
            
        else if(firstName > t->firstName && lastName < t->lastName  ){
            t = t->right;
        }
           
        else{
            output_var =true ;
            return t;    // Match
        }

        
    }

    return NULL;   // No match
}
template <class Comparable>
void AvlTree<Comparable>::find_partial( const Comparable & firstName,const Comparable & lastName , AvlNode<Comparable> *AVL, ofstream &output, bool  & output_var) const
{
    if (AVL == NULL){
        return;}
    
    if(AVL->firstName.substr(0,(firstName.length()))== firstName){
        output << AVL -> firstName<< " "<<AVL -> lastName<< " " << AVL -> phoneNumber<< " " << AVL -> City<<endl  ;
        cout << AVL -> firstName<< " "<<AVL -> lastName<< " " << AVL -> phoneNumber<< " " << AVL -> City<<endl  ;
        output_var =true; 

    }
        /*  left subtree */
    find_partial(firstName, lastName ,AVL->left,output,output_var);
        /*  right subtree */
    find_partial(firstName, lastName ,AVL->right,output,output_var);
}

template <class Comparable>
void AvlTree<Comparable>::PreOrderPrint(AvlNode<Comparable> * AVL,ofstream &output){

    if (AVL  == NULL){
        return;}
    
    output  << AVL -> firstName<< " "<<AVL -> lastName<< " " << AVL -> phoneNumber<< " " << AVL -> City<<endl   ;
     
        /*  left subtree */
    PreOrderPrint(AVL->left,output);
        /*  right subtree */
    PreOrderPrint(AVL->right,output);
    
}
template <class Comparable>
void AvlTree<Comparable>::PreOrderPrintHelper(ofstream &output){
    PreOrderPrint(this->root,output);
}


template <class Comparable>
void AvlTree<Comparable>::InOrderPrint(AvlNode<Comparable> * AVL, ofstream &output){

    if (AVL == NULL){
        return;}
        /*  left subtree */
    InOrderPrint(AVL->left,output);
    output << AVL -> firstName<< " "<<AVL -> lastName<< " " << AVL -> phoneNumber<< " " << AVL -> City<<endl  ;
        /*  right subtree */
    InOrderPrint(AVL->right,output);
    
}


template <class Comparable>
void AvlTree<Comparable>::InOrderPrintHelper(ofstream &output){
    InOrderPrint(this->root, output);
}




template <class Comparable>
int AvlTree<Comparable>::isbalanced(  AvlNode<Comparable> * & t )
{
    if (t == NULL){return 0;}
    return height(t->left) - height(t->right);
}

template <class Comparable>
int AvlTree<Comparable>::isbalanced_helper()
{
    return isbalanced(  this ->root );
}





/**
  * Remove x from the tree. Nothing is done if x is not found.
  */
 template <class Comparable>
 void AvlTree<Comparable>::remove( const Comparable & firstName,const Comparable & lastName )
 {
        remove( firstName,lastName, root );
 }
/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the tree.
 * Set the new root.
 */


template <class Comparable>
AvlNode<Comparable> * AvlTree<Comparable>::remove(const Comparable & firstName,const Comparable & lastName, AvlNode<Comparable> * & t )
{
    if( t == NULL )
     return NULL;   // Item not found; do nothing




    if(t->firstName == firstName && t->lastName == lastName){
    if (t-> left == NULL && t-> right == NULL)
        {
          delete t;
          return NULL;
        }
    else if(t-> left == NULL && t-> right != NULL)
        {
        AvlNode<Comparable> * temp = t->right;
          delete t;
          return temp;
        }
    else if(t-> right == NULL && t-> left != NULL)
        {
        AvlNode<Comparable> * temp = t->left;
          delete t;
          return temp;
        }
    else
    {

    AvlNode<Comparable> * min_r_sub ;
    AvlNode<Comparable> * curr = t->right ;
    while (curr->left != NULL)
    {
      curr = curr->left ;
    }
        min_r_sub = curr;
        t->firstName = min_r_sub->firstName;
        t->lastName = min_r_sub->lastName;
        t->right = remove(min_r_sub->firstName,min_r_sub->lastName,t->right);
    }

    }



    else if( firstName < t->firstName && lastName == t->lastName )
        t-> left  = remove( firstName,lastName, t->left );
    else if( firstName == t->firstName && lastName < t->lastName )
        t-> left  =remove( firstName,lastName, t->left );
    else if( firstName < t->firstName && lastName < t->lastName )
        t-> left  =remove( firstName,lastName, t->left );
    else if( firstName < t->firstName && lastName > t->lastName )
        t-> left  =remove( firstName,lastName, t->left );


    else if(firstName > t->firstName && lastName > t->lastName  )
        t-> right  =remove( firstName,lastName, t->right );
    else if(firstName > t->firstName && lastName == t->lastName  )
        t-> right  =remove( firstName,lastName, t->right );
    else if(firstName == t->firstName && lastName > t->lastName  )
        t-> right  =remove( firstName,lastName, t->right );
    else if(firstName > t->firstName && lastName < t->lastName  )
        t-> right  =remove( firstName,lastName, t->right );



    if (isbalanced(  t ) > 1 && isbalanced(t ->left) >= 0)
         rotateWithRightChild(t);

    // Left Right Case
    if (isbalanced(  t ) > 1 && isbalanced(t ->left) < 0)
    {
        rotateWithLeftChild(t->left);
         rotateWithRightChild(t);
    }

    // Right Right Case
    if (isbalanced(  t ) < -1 && isbalanced(t ->left) <= 0)
         rotateWithLeftChild(t);

    // Right Left Case
    if (isbalanced(  t ) < -1 && isbalanced(t ->left) > 0)
    {
        rotateWithRightChild(t->right);
         rotateWithLeftChild(t);
    }

    return t;
}


template <class Comparable>
void AvlTree<Comparable>::Draw(AvlNode<Comparable> * AVL,string empty, ofstream &output,bool x,int count,bool isfirst){
    if (AVL == NULL){
        return;}
    if(isfirst){
        output << "|__"<<UpperString(AVL -> firstName)<< " "<<UpperString(AVL -> lastName)<<endl  ;
        empty = "   ";

    }
    if(x==true && isfirst == false){

        output<<empty;

   
        output << "--"<< UpperString(AVL -> firstName)<< " "<<UpperString(AVL -> lastName)<<endl  ;
        empty+="  " ;

    }
    else if(x==false && isfirst == false){
        
        output<<empty;
 
        output << "|__"<< UpperString(AVL -> firstName)<< " "<<UpperString(AVL -> lastName)<<endl  ;
        empty+="   " ;
    }
    isfirst=false;
        /*  left subtree */
    
    Draw(AVL->left,empty+"|"  ,output,true,count, isfirst);
        /*  right subtree */
    
    Draw(AVL->right,empty,output,false,count,isfirst);
    
    
}
template <class Comparable>
void AvlTree<Comparable>::DrawHelp(ofstream &output){
   
    Draw(this->root,"   ", output,true ,0,true);
}
