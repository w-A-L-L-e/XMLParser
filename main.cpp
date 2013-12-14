/*=============================================================================
author        :Walter Schreppers
filename      :main.cpp
description   :This tests some functionalities of the XMLParser class
bugreport(log):/
=============================================================================*/

#include "XMLParser.h"

int main( int argc, char *argv[] )
{
  if(argc == 2){
    ifstream in(argv[1]);
    XMLParser xml;
    
    xml.setIncludeWhites(false); //don't include whitespaces
    
    bool ok = xml.parse(&in);
    if( ok ) {
      cout<<"Parsing done successfully!"<<endl;
      cout<<"showing the n-tree:"<<endl;
      xml.tree->showTree(xml.tree);
      
      if( xml.tree->nodeType() == XMLNode::ElementNode ){
        ElementNode* root=(ElementNode*) xml.tree; //cast it to correct type
        cout<<"root name ="<<root->tagName()<<endl;
        cout<<"root attributes:"<<endl;
        for(int i=0;i<root->attributes.size();i++){
          cout<<"name="<<root->attributes[i].name<<endl;
          cout<<"value="<<root->attributes[i].value<<endl;
        }        
      }
    }
    else{
      cout<<"Errors in parsing at line "<<xml.errorLine()<<", col "<<xml.errorColumn()<<"!!!"<<endl;
    }
  }
  else{
    cout<<"USAGE: "<<argv[0]<<" <xml file> \n";
  }
}


