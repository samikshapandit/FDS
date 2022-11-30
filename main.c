//stack implementation for infix to postfix conversion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
struct stack
{
    char data;
    struct stack*next;
};
struct stack *top=NULL;

void push(char);
int precedence(char);
char pop();
void main()
{
  char infix[20],postfix[20];
  printf("Enter infix expression\n: ");
  scanf("%s",infix);
  int i=0 ,j=0;
 
  while(infix[i]!='\0')
  {
      if(isalnum (infix[i]))
      {
        postfix[j]=infix[i];
        j++;
      }
      else
      {
          if(top==NULL)
          {
            push(infix[i]);
          }
          else
          {
              while(top!=NULL && precedence(top->data)>=precedence(infix[i]))
              {
                postfix[j]=pop();
                j++;
              }
              push(infix[i]);
          }
      }
      i++;
  }
while(top!=NULL)
{
   postfix[j]=pop();
   j++;
}
 postfix[j]='\0';
 printf("%s",postfix);
 
}
void push(char op)
  {
    struct stack *new;
    new=(struct stack*)malloc(sizeof(struct stack*));
    new->data = op;
    new->next=NULL;
    if(top==NULL)
    {
    top=new;
    }
    else
    {
        new->next=top;
        top=new;
    }
  }
 
int precedence(char op)
  {
    switch(op)
      {
          case '^': return 3;
          break;
          case '/': return 2;
          break;
          case '*': return 2;
          break;
          case '+': return 1;
          break;
          case '-': return 1;
          break;
          default : return 0;
      }
  }

char pop()
  {
      struct stack *temp;
     
      char op;
      if(top==NULL)
      {
          printf("Stack is empty");
      }
      else if(top->next == NULL)
      {
           temp=top;
          op=top->data;
          top=top->next;
          free(temp);
      }
      else
      {
          temp=top;
          op=top->data;
          top=top->next;
          free(temp);
      }
      return op;
 }
