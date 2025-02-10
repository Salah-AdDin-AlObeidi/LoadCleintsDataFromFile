#pragma once

#include <iostream>
#include <string>
using namespace std;

  namespace Raed
  {
      string RaedName()
      {
          string Name;

          cout << "Please Enter Name" << endl;

          getline(cin, Name);

          return Name;
    }

      void PrentName(string Name)
      {
          cout << "Yor Name > :" << Name << endl;


      }

  }


