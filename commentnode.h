/*=============================================================================
author        :Walter Schreppers
filename      :commentnode.h
description   :CommentNode contains anything between <!--  and -->
bugreport(log):/
=============================================================================*/

#ifndef COMMENTNODE_H
#define COMMENTNODE_H


#include "xmlnode.h"
#include <string>

class CommentNode:public XMLNode{
  public:
    //constructors/destructor
    //=======================
    CommentNode();
    CommentNode(const string&);    //provide data
    CommentNode(const CommentNode&);  //copy constructor
    
    
    //public members
    //==============
    void setData(const string&);
    string data();

    XMLNode::NodeType nodeType();
    void show(int indent);    

    //operators
    //=========
    CommentNode& operator=(const CommentNode&);

    //public vars
    //===========    

  
  private:
  
    string fData;

};


#endif

