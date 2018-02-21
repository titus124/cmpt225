#include <iostream>
#include "char_stack.h"
using namespace std;

void displayError(int i,char current_str[],int current_str_len)
{
  char errortext_one[250];
  char errortext_two[250];
  int str_length = 0;
  int k;
  for (k = 0; k <= i; k++)
  {
    errortext_one[k] = current_str[k];
    cout << errortext_one[k];
  }

  cout << "\n";

  for (k = 0; k <= i; k++)
  {
    errortext_two[k] = ' ';
    str_length++;
  }

  for (k = str_length; k < current_str_len;k++)
  {
    errortext_two[k] = current_str[k];
    str_length++;
  }

  for (k = 0; k < str_length;k++)
  {
    cout << errortext_two[k];
  }
  cout << "\n";
}



int main (int argc, char * const argv[])
{
  char_stack s;
  char mytext[250];
  char o;
  int line_count = 0;

  while( cin.getline(mytext,250))
  {
    line_count++;
    for (int i = 0; i < cin.gcount();i++)
    {
      if (mytext[i] == '['or mytext[i] == '(' or mytext[i] == '{')
      {
        s.push(mytext[i]);
      }
      else if (mytext[i] == ']' or mytext[i] == ')' or mytext[i] == '}')
      {
        if (s.empty())
        {
          cout << "Error on line "<< line_count<< ": Too many " << mytext[i] << "\n";
          displayError(i,mytext,cin.gcount());

          return 0;
        }
        o = s.pop();
        if (o == '[' and mytext[i] != ']')
        {
        cout << "Error on line "<< line_count <<": Read " <<mytext[i]<< ", expected ]" << "\n";
        displayError(i,mytext,cin.gcount());
        return 0;
        }
        else if (o == '(' and mytext[i] != ')')
        {
        cout << "Error on line "<< line_count <<": Read " <<mytext[i]<< ", expected )" << "\n";
        displayError(i,mytext,cin.gcount());
        return 0;
        }
        else if (o == '{' and mytext[i] != '}')
        {
        cout << "Error on line "<< line_count <<": Read " <<mytext[i]<< ", expected }" << "\n";
        displayError(i,mytext,cin.gcount());
        return 0;
        }
      }
    }
  }

  if(!s.empty())
  {
    o = s.pop();
    cout << "Error at end of file: Too many " << o << "\n";
    return 0;
  }

  cout << "No Errors Found" << "\n";

  return 0;
}
