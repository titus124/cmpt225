/* File: char_stack.cpp

  Implementation of functions for basic simple array-based implementation of a stack.

*/
#include "char_stack.h"// contains the declarations of the variables and functions.
#include <cstring>
#include <iostream>
using namespace std;
char_stack::char_stack()
{
  top_ptr = NULL;
  count_size = 0;
}

void char_stack::push( char item )
{
  char_node *temp = new char_node(item,top_ptr);
  top_ptr = temp;
  count_size++;
}

char char_stack::pop()
{
  if(top_ptr == NULL)return 0;
  char_node *old_top = top_ptr;
  char ch = top_ptr->data;
  top_ptr = top_ptr->next;
  delete old_top;
  count_size--;
  return ch;
}


int char_stack::size()
{
  return count_size;
}

bool char_stack::empty()
{
  if (count_size > 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

char char_stack::top()
{
  return top_ptr->data;
}

void char_stack::display()
{
  char_node *ctr = top_ptr;
  cout <<"The current stack is:";
  while(ctr != NULL)
  {
    cout << ctr->data;
    ctr = ctr->next;
  }
  cout << "\n";
}
