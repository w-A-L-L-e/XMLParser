/*=============================================================================
author        :Walter Schreppers
filename      :ntree.cpp
description   :Here we test the XMLNode class (it represents an n-airy tree)
bugreport(log):/
=============================================================================*/

#include "xmlnode.h"
#include <iostream>



int main(){
  XMLNode t;
  t.setName("root");

  XMLNode* child1=new XMLNode();
  child1->setName("child1");
  t.appendChild(child1);
  
  XMLNode* child2=new XMLNode();
  child2->setName("child2");
  t.appendChild(child2);
  
  
  XMLNode* child3=new XMLNode();
  child3->setName("child3");
  t.appendChild(child3);


  //4 kinderen van 2e child
  XMLNode* child4=new XMLNode();
  child4->setName("childchild1");
  child2->appendChild(child4);
  
  XMLNode* child5=new XMLNode();
  child5->setName("childchild2");
  child2->appendChild(child5);

  child5=new XMLNode();
  child5->setName("childchild3");
  child2->appendChild(child5);
  
  child5=new XMLNode();
  child5->setName("childchild4");
  child2->appendChild(child5);

  t.showTree(&t);


  cout<<endl<<"test nextSibling function"<<endl;
  XMLNode* t2=t.firstChild();
  while(t2!=0){
    cout<<t2->getName();
    if(t2->hasChildren()) cout<<" has children";
    cout<<endl; 
    t2=t2->nextSibling();
  }

  cout<<endl<<"test prevSibling function"<<endl;
  XMLNode* t3=t.lastChild();
  while(t3!=0){
    cout<<t3->getName();
    if(t3->hasChildren()) cout<<" has children";
    cout<<endl;
    t3=t3->prevSibling();
  }

  
  
}


