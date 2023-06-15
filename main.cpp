#include <iostream>
#include "BST.h"
#include "AVL.h"
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"
using namespace std;
using namespace std::chrono;

void file_read_and_create_BST_tree(string filename, BinarySearchTree<string> & new_BST_tree , ofstream & output ){
    auto start = high_resolution_clock::now();
    ifstream  myFile(filename) ;
    string line;
    vector<string> variables;
    string myvar ;
    int index = 0 ;
    while(getline(myFile, line)){
        while(index != string::npos){
            index = line.find(" ") ;
            myvar = line.substr(0,index) ;
            line = line.substr(index+1 , line.length());
            variables.push_back(myvar) ;
        }
        new_BST_tree.insert(UpperString(variables[0]),UpperString(variables[1]),UpperString(variables[2]),variables[3]);

        variables.clear() ;
        index = 0 ;
    }
    myFile.close();
    auto stop = high_resolution_clock::now();
    auto time =duration_cast<milliseconds>(stop - start);
    cout << "Phonebook creation in BST took "<< time.count() <<" milliseconds. . ." <<endl;
    output<<"Phonebook creation in BST took "<< time.count() <<" milliseconds. . ." <<endl;
}
void file_read_and_create_AVL_tree(string filename, AvlTree<string> & new_AVL_tree,ofstream & output ){
    auto start = high_resolution_clock::now();
    ifstream  myFile(filename) ;
    string line;
    vector<string> variables;
    string myvar ;
    int index = 0 ;
    while(getline(myFile, line)){
        while(index != string::npos){
            index = line.find(" ") ;
            myvar = line.substr(0,index) ;
            line = line.substr(index+1 , line.length());
            variables.push_back(myvar) ;
        }
        new_AVL_tree.insert(UpperString(variables[0]),UpperString(variables[1]),UpperString(variables[2]),variables[3]);

        variables.clear() ;
        index = 0 ;
    }
    myFile.close();
    auto stop = high_resolution_clock::now();
    auto time =duration_cast<milliseconds>(stop - start);
    cout << "Phonebook creation in AVL took "<< time.count() <<" milliseconds. . ." <<endl;
    output <<"Phonebook creation in AVL took "<< time.count() <<" milliseconds. . ." <<endl;
}

bool check_balance_AVL(AvlTree<string> & AVL){
    if(AVL.isbalanced_helper() == 1 || AVL.isbalanced_helper() == 0 ||AVL.isbalanced_helper() == -1){
        return true ;
    }
    else{
        return false;
    }
}
void AddContact(BinarySearchTree<string> & BST, AvlTree<string> & AVL,ofstream & output ){
    string firstName,lastName, City, phoneNumber;


    cout<< "Enter the information of the contact to be added:" <<endl;
    output<< "Enter the information of the contact to be added:" <<endl;

    cout<<"Name: ";
    output<<"Name: ";

    cin>> firstName>> lastName;
    output<<firstName<<" "<<lastName ;
    ToUpper(firstName);
    ToUpper(lastName);
    
    cout<< endl;
    output<< endl;

    cout<<"Tel: ";
    output<<"Tel: ";

    cin>> phoneNumber ;
    output<< phoneNumber ;

    cout<< endl;
    output<< endl;


    cout<<"City: ";
    output<<"City: ";


    cin>> City ;
    output<< City ;
    ToUpper(City);

    cout<< endl;
    output<< endl;


    cout<<"Adding an item to the phonebook BST . . ."<<endl;
    output<<"Adding an item to the phonebook BST . . ."<<endl;

    auto start_BST = high_resolution_clock::now();
    BST.insert(firstName, lastName, phoneNumber, City);
    auto stop_BST = high_resolution_clock::now();
    cout<<"===================================="<<endl ;
    output<<"===================================="<<endl ;

    cout<<"Contact has been added successfully to the BST"<<endl;
    output<<"Contact has been added successfully to the BST"<<endl;

    cout<< endl;
    output<< endl;


    cout<<"Adding an item to the phonebook (AVL) . . ."<<endl;
    output<<"Adding an item to the phonebook (AVL) . . ."<<endl;

    auto start_AVL = high_resolution_clock::now();
    AVL.insert(firstName, lastName, phoneNumber, City);
    auto stop_AVL = high_resolution_clock::now();
    cout<<"===================================="<<endl ;
    output<<"===================================="<<endl ;

    cout<<"Contact has been added successfully to the AVL Tree"<<endl;
    output<<"Contact has been added successfully to the AVL Tree"<<endl;

    cout<< endl;
    output<< endl;


    auto time_BST =duration_cast<nanoseconds>(stop_BST- start_BST);
    auto time_AVL=duration_cast<nanoseconds>(stop_AVL - start_AVL);
    
    cout<<"Adding a contact to the Binary Tree took " <<time_BST.count()<<" nanoseconds. . ." <<endl;
    output<<"Adding a contact to the Binary Tree took " <<time_BST.count()<<" nanoseconds. . ." <<endl;

    cout<<"Adding a contact to the AVL Tree took " <<time_AVL.count()<<" nanoseconds. . ." <<endl;
    output<<"Adding a contact to the AVL Tree took " <<time_AVL.count()<<" nanoseconds. . ." <<endl;

}




void SearchAContact(BinarySearchTree<string> & BST , AvlTree<string> & AVL ,ofstream & output  ){
    string firstName,lastName, City, phoneNumber;
    string name;


    cout<<"Search for a contact: " ;
    output<<"Search for a contact: " ;
    cin.ignore();

    getline(cin, name);


    
    output<< name ;
    ToUpper(name);
    bool output_var= false ;
    cout<<endl;
    output<<endl;

    int index = name.find(" ") ;
    if(index == string::npos){
        firstName = name;
        lastName = "" ;
        cout<< "Searching an item in the phonebook (BST) . . ."<< endl ;
        output<< "Searching an item in the phonebook (BST) . . ."<< endl ;

        cout<<"Phonebook: Searching for: "<<"("<< UpperString(firstName) << UpperString(lastName)<< ")" <<endl;
        output<<"Phonebook: Searching for: "<<"("<< UpperString(firstName) << UpperString(lastName)<< ")" <<endl;

        
        cout<<"===================================="<<endl ;
        output<<"===================================="<<endl ;

        auto start_BST = high_resolution_clock::now();
        BST.find(firstName, lastName,phoneNumber,City,output,output_var);
        auto stop_BST = high_resolution_clock::now();

        
        cout<<endl;
        output<<endl;
        cout<< "Searching an item in the phonebook (AVL) . . ."<< endl ;
        output<< "Searching an item in the phonebook (AVL) . . ."<< endl ;
        cout<<endl;
        output<<endl;

        cout<<"Phonebook: Searching for: "<<"("<< UpperString(firstName) << UpperString(lastName)<< ")" <<endl;
        output<<"Phonebook: Searching for: "<<"("<< UpperString(firstName) << UpperString(lastName)<< ")" <<endl;

        
        cout<<"===================================="<<endl ;
        output<<"===================================="<<endl ;

        auto start_AVL = high_resolution_clock::now();
        AVL.find(firstName, lastName,phoneNumber,City,output,output_var);
        auto stop_AVL = high_resolution_clock::now();
        cout<<endl;
        output<<endl;
        
        auto time_AVL =duration_cast<nanoseconds>(stop_AVL- start_AVL);
        auto time_BST =duration_cast<nanoseconds>(stop_BST- start_BST);
        cout<<"The search in BST took " <<time_BST.count()<<" nanoseconds. . ." <<endl;
        output<<"The search in BST took " <<time_BST.count()<<" nanoseconds. . ." <<endl;

        cout<<"The search in AVL took " <<time_AVL.count()<<" nanoseconds. . ." <<endl;
        output<<"The search in AVL took " <<time_AVL.count()<<" nanoseconds. . ." <<endl;

        cout<<endl;
        output<<endl;
    }
    else{
        
        firstName = name.substr(0,index) ;
        lastName = name.substr(index+1 , name.length());
        cout<< "Searching an item in the phonebook (BST) . . ."<< endl ;
        output<< "Searching an item in the phonebook (BST) . . ."<< endl ;
        cout<<endl;
        output<<endl;
        
        cout<<"Phonebook: Searching for: "<<"("<< UpperString(firstName) <<" "<< UpperString(lastName)<< ")" <<endl;
        output<<"Phonebook: Searching for: "<<"("<< UpperString(firstName) <<" "<< UpperString(lastName)<< ")" <<endl;

        cout<<"===================================="<<endl ;
        output<<"===================================="<<endl ;

        auto start_BST = high_resolution_clock::now();
        BST.find(firstName, lastName,phoneNumber,City,output, output_var);
        auto stop_BST = high_resolution_clock::now();
        if (output_var){
            cout<< UpperString(firstName)<< " "<< UpperString(lastName)<<" "<< phoneNumber<<" "<< City<<endl ;
            output<< UpperString(firstName)<< " "<< UpperString(lastName)<<" "<< phoneNumber<<" "<< City<<endl ;

        }

        cout<<endl;
        output<<endl;
        
        cout<< "Searching an item in the phonebook (AVL) . . ."<< endl ;
        output<< "Searching an item in the phonebook (AVL) . . ."<< endl ;
        cout<<endl;
        output<<endl;
        
        cout<<"Phonebook: Searching for: "<<"("<< UpperString(firstName) <<" "<< UpperString(lastName)<< ")" <<endl;
        output<<"Phonebook: Searching for: "<<"("<< UpperString(firstName) <<" "<< UpperString(lastName)<< ")" <<endl;

        cout<<"===================================="<<endl ;
        output<<"===================================="<<endl ;

        auto start_AVL = high_resolution_clock::now();
        AVL.find(firstName, lastName,phoneNumber,City,output,output_var);
        auto stop_AVL = high_resolution_clock::now();
        
        if (output_var){
            cout<< UpperString(firstName)<< " "<< UpperString(lastName)<<" "<< phoneNumber<<" "<< City<<endl ;
            output<< UpperString(firstName)<< " "<< UpperString(lastName)<<" "<< phoneNumber<<" "<< City<<endl ;

        }
        
        cout<<endl;
        output<<endl;

        auto time_AVL =duration_cast<nanoseconds>(stop_AVL- start_AVL);
        auto time_BST =duration_cast<nanoseconds>(stop_BST- start_BST);
        cout<<"The search in BST took " <<time_BST.count()<<" nanoseconds. . ." <<endl;
        output<<"The search in BST took " <<time_BST.count()<<" nanoseconds. . ." <<endl;

        cout<<"The search in AVL took " <<time_AVL.count()<<" nanoseconds. . ." <<endl;
        output<<"The search in AVL took " <<time_AVL.count()<<" nanoseconds. . ." <<endl;
        cout<<endl;
        output<<endl;


    }
}


void DeleteContact(BinarySearchTree<string> & BST , AvlTree<string> & AVL, ofstream & output ){
    string firstname,  lastname,phoneNumber,  city;
    
    cout<<"Deleting an item from the phonebook . . ."<<endl ;
    output<<"Deleting an item from the phonebook . . .";
    
    cout<<"Enter the fullname of the contact to be deleted: " ;
    output<<"Enter the fullname of the contact to be deleted: " ;
    cin>>firstname>>lastname ;
    ToUpper(firstname);
    ToUpper(lastname);
    cout<<endl;
    output<<endl;
    
    bool outputvar =false;
    bool outputvar1 =false;

    BST.find(firstname, lastname, phoneNumber,  city, output, outputvar );
    AVL.find(firstname, lastname, phoneNumber,  city, output, outputvar1 );

    if(outputvar&& outputvar1){
        
        auto start_BST = high_resolution_clock::now();
        BST.remove(firstname,lastname);
        auto stop_BST = high_resolution_clock::now();
        
        
        auto start_AVL = high_resolution_clock::now();
        AVL.remove(firstname,lastname);
        auto stop_AVL = high_resolution_clock::now();
        
        auto time_AVL =duration_cast<nanoseconds>(stop_AVL- start_AVL);
        auto time_BST =duration_cast<nanoseconds>(stop_BST- start_BST);
        cout << "Deleted succcessfully. . .";
        output<<"Deleted succcessfully. . .";
        cout<<endl;
        output<<endl;
        
        cout<<"Deletion from the Binary Tree took "<< time_BST.count()<< " nanoseconds. . ."<<endl ;
        output<<"Deletion from the Binary Tree took "<< time_BST.count()<< " nanoseconds. . ."<<endl ;

        cout<<"Deletion from AVL Tree took "<< time_AVL.count()<< " nanoseconds. . ."<<endl ;
        output<<"Deletion from AVL Tree took "<< time_AVL.count()<< " nanoseconds. . ."<<endl ;
        cout <<endl;
        output<<endl;
    }
    else{
        cout<< "Not found" <<endl ;
        output<< "Not found" <<endl ;
        
        cout<<endl;
        output<<endl;

        
    }


}



void InOrderPrintToFile(BinarySearchTree<string> BST , AvlTree<string>  AVL, ofstream &  output_BST ,ofstream &  output_AVL,ofstream &  output){
    
    auto start_BST = high_resolution_clock::now();
    BST.InOrderPrintHelper(output_BST);
    auto stop_BST = high_resolution_clock::now();
    
    auto start_AVL = high_resolution_clock::now();
    AVL.InOrderPrintHelper(output_AVL);
    auto stop_AVL = high_resolution_clock::now();
    
    auto time_AVL =duration_cast<nanoseconds>(stop_AVL- start_AVL);
    auto time_BST =duration_cast<nanoseconds>(stop_BST- start_BST);
    
    cout<<"Printing in order to file from the Binary Tree took "<< time_BST.count()<< " nanoseconds. . ."<<endl ;
    output<<"Printing in order to file from the Binary Tree took "<< time_BST.count()<< " nanoseconds. . ."<<endl ;

    cout<<"Printing in order to file from AVL Tree took "<< time_AVL.count()<< " nanoseconds. . ."<<endl ;
    output<<"Printing in order to file from AVL Tree took "<< time_AVL.count()<< " nanoseconds. . ."<<endl ;
  
}

void PreOrderPrintToFile(BinarySearchTree<string> BST , AvlTree<string> AVL, ofstream &  output_BST ,ofstream &  output_AVL,ofstream &  output){


    auto start_BST = high_resolution_clock::now();
    BST.PreOrderPrintHelper(output_BST);
    auto stop_BST = high_resolution_clock::now();
    
    auto start_AVL = high_resolution_clock::now();
    AVL.PreOrderPrintHelper(output_AVL);
    auto stop_AVL = high_resolution_clock::now();
    
    auto time_AVL =duration_cast<nanoseconds>(stop_AVL- start_AVL);
    auto time_BST =duration_cast<nanoseconds>(stop_BST- start_BST);
    
    cout<<"Printing pre order to file from the Binary Tree took "<< time_BST.count()<< " nanoseconds. . ."<<endl ;
    output<<"Printing pre order to file from the Binary Tree took "<< time_BST.count()<< " nanoseconds. . ."<<endl ;

    cout<<"Printing pre order to file from AVL Tree took "<< time_AVL.count()<< " nanoseconds. . ."<<endl ;
    output<<"Printing pre order to file from AVL Tree took "<< time_AVL.count()<< " nanoseconds. . ."<<endl ;
    cout<< endl ;
    output<< endl ;
}


void DrawTreeToFile(BinarySearchTree<string> BST , AvlTree<string>  AVL, ofstream &  output_BST ,ofstream &  output_AVL,ofstream &  output){
    auto start_BST = high_resolution_clock::now();
    BST.DrawHelp(output_BST);
    auto stop_BST = high_resolution_clock::now();
    
    auto start_AVL = high_resolution_clock::now();
    AVL.DrawHelp(output_AVL);
    auto stop_AVL = high_resolution_clock::now();
    
    auto time_AVL =duration_cast<nanoseconds>(stop_AVL- start_AVL);
    auto time_BST =duration_cast<nanoseconds>(stop_BST- start_BST);
    cout<<"Drawing tree to file from the Binary Tree took "<< time_BST.count()<< " nanoseconds. . ."<<endl ;
    output<<"Drawing tree to file from the Binary Tree took "<< time_BST.count()<< " nanoseconds. . ."<<endl ;

    cout<<"Drawing tree to file from AVL Tree took "<< time_AVL.count()<< " nanoseconds. . ."<<endl ;
    output<<"Drawing tree to file from AVL Tree took "<< time_AVL.count()<< " nanoseconds. . ."<<endl ;
    cout<< endl ;
    output<< endl ;
}


int main(){
    ofstream output_BST, output_AVL;
    ofstream output_BST_IN_ORDER, output_AVL_IN_ORDER;
    ofstream output_print_BST, output_print_AVL;
    ofstream output ;
    
    string output_file = "Output.txt" ;
    
    string outfilename_BST_PRE = "phonebookPreOrderBST.txt" ;
    string outfilename_AVL_PRE = "phonebookPreOrderAVL.txt" ;
    
    string outfilename_BST_IN = "phonebookInOrderBST.txt" ;
    string outfilename_AVL_IN = "phonebookInOrderAVL.txt" ;

    string phonebookTreeBST  = "phonebookTreeBST.txt" ;
    string phonebookTreeAVL = "phonebookTreeAVL.txt" ;

    output.open(output_file.c_str());
    
    output_BST.open(outfilename_BST_PRE.c_str());
    output_AVL.open(outfilename_AVL_PRE.c_str());
    
    
    output_BST_IN_ORDER.open(outfilename_BST_IN.c_str());
    output_AVL_IN_ORDER.open(outfilename_AVL_IN.c_str());
    
    output_print_BST.open(phonebookTreeBST.c_str());
    output_print_AVL.open(phonebookTreeAVL.c_str());

    string filename;
    int  left_height_BST = 0, right_height_BST = 0,left_height_AVL = 0,right_height_AVL = 0 , search=0 ;
    
    BinarySearchTree<string> BST("-1")  ;//the binary tree will return -1 if the item is not found
    AvlTree<string> AVL("-1");
    cout<<"Please enter the contact file name: ";
    output<<"Please enter the contact file name: ";

    cin>> filename;
    output<<filename;
    cout<<endl;
    output<<endl;

    cout<<"Loading the phonebook into a BST."<<endl;
    output<<"Loading the phonebook into a BST."<<endl;
 

    
    file_read_and_create_BST_tree(filename, BST,output);

    if(BST.check_balance_BST_helper(BST)){
        cout<< "The tree is balanced"<<endl;
        output<< "The tree is balanced"<<endl;

    }
    else{
        cout<< "The tree is not balanced"<<endl;
        output<< "The tree is not balanced"<<endl;


    }
    left_height_BST = BST.depth_for_BST_helper("left", BST) ;
    right_height_BST = BST.depth_for_BST_helper("right", BST) ;
    cout<< "The heights of BST are for left: " <<left_height_BST<< " and right: "<< right_height_BST <<endl;
    output<< "The heights of BST are for left: " <<left_height_BST<< " and right: "<< right_height_BST <<endl;


    
    cout<<"Loading the phonebook into an AVL"<<endl;
    output<<"Loading the phonebook into an AVL"<<endl;

    file_read_and_create_AVL_tree(filename,AVL,output);

    left_height_AVL =AVL.depth_for_AVL_helper("left", AVL) ;
    right_height_AVL =AVL.depth_for_AVL_helper("right", AVL) ;

    if(check_balance_AVL(AVL)){
        cout<< "The tree is balanced"<<endl;
        output<< "The tree is balanced"<<endl;

    }
    else{
        cout<< "The tree is not balanced"<<endl;
        output<< "The tree is not balanced"<<endl;


    }
    cout<< "The heights of AVL are for left: " << left_height_AVL<< " and right: "<< right_height_AVL<<endl;
    output<< "The heights of AVL are for left: " << left_height_AVL<< " and right: "<< right_height_AVL<<endl;
    cout<<endl<<endl;
    output<<endl<<endl;
    

    
    
  
    while(search != 6){
        cout<< "Choose which action to perform from 1 to 6:"<<endl;
        output<< "Choose which action to perform from 1 to 6:"<<endl;

        cout<< "1 - Search a phonebook contact"<<endl;
        output<< "1 - Search a phonebook contact"<<endl;
        
        cout<< "2 - Adding a phonebook contact"<<endl;
        output<< "2 - Adding a phonebook contact"<<endl;

        
        cout<< "3 - Deleting a phonebook contact"<<endl;
        output<< "3 - Deleting a phonebook contact"<<endl;

        
        cout<< "4 - Print the phonebook to a file(inorder)"<<endl
        <<"Print the phonebook to a file(preorder)"<<endl;
        output<< "4 - Print the phonebook to a file(inorder)"<<endl
        <<"    Print the phonebook to a file(preorder)"<<endl;
        
        
        
        cout<<"5 - Draw the phonebook as a Tree to a file"<<endl;
        output<<"5 - Draw the phonebook as a Tree to a file"<<endl;

        cout<< "6 - Press 6 to exit"<<endl;
        output<< "6 - Press 6 to exit"<<endl;

        
        
        cin>>search ;
        output<<search<<endl;
        cout<< endl ;
        output<< endl ;

        
        if(search == 1){
            SearchAContact( BST ,  AVL, output);

        }
        else if(search ==2){

            AddContact( BST,  AVL,output) ;
        }
        else if(search == 3){

            DeleteContact( BST , AVL, output);
            
        }
        else if(search ==4){

            InOrderPrintToFile(BST, AVL, output_BST_IN_ORDER, output_AVL_IN_ORDER,output );
            PreOrderPrintToFile(BST , AVL, output_BST,output_AVL,output);
        }
        else if(search == 5 ){

            DrawTreeToFile(BST, AVL, output_print_BST, output_print_AVL,output);

        }
        else if(search==6){
            cout<<"Exiting..."<<endl;
            output<< "Exiting..."<<endl;
            
        }
    }
 
    
    
    
    
    
    
    
    return 0;
}
