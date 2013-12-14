/*=============================================================================
author        :Walter Schreppers
filename      :attribute.h
description   :Attribute class for storing attributes of tags.
bugreport(log):/
=============================================================================*/


#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

class Attribute{
  public:
    Attribute(const string&);
    Attribute(const string& n, const string& v);
    Attribute(const Attribute&);

    Attribute& operator=(const Attribute&);
        
    string name;
    string value;
};

#endif



