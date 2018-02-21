/* File: char_stack.h

  Header file for a very basic array-based implementation of a stack.

*/

#include "char_node.h"

class char_stack
{
  public:
    char_stack();
    void push( char item );
    char pop();
    char top();
    bool empty();
    int size();
    void display();

  private:
    char_node *top_ptr;
    int count_size;
};
