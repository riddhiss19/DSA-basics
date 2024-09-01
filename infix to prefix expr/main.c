#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 20

char stack[max];
int top = -1;
int isFull()
{
    if(top >= max-1)
	{
		printf("\nStack Overflow");
		return 0;
	}
	else
        return 1;
}

int isEmpty()
{
    if(top==-1)
	{
		printf("\nStack underflow");
		return 0;
	}
	else
        return 1;
}
void push(char item)
{

	if(isFull()==1)
	{
		top = top+1;
		stack[top] = item;
	}
}

char pop()
{
	char item ;
	if(isEmpty()==1)
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-'||symbol=='%')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void convert(char infix[], char postfix[])
{
	int i, j;
	char item;
	char x;

	pop('(');
	//strcat(infix,")");
    strrev(infix);
	i=0;
	j=0;
	item=infix[i];

	while(item != '\0')
	{
		if(item == '(')
		{
			pop(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix[j] = item;
			j++;
		}
		else if(is_operator(item) == 1)
		{
			x=push();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix[j] = x;
				j++;
				x = push();
			}
			push(x);
			push(item);
		}
		else if(item == ')')
		{
			x = push();
			while(x != '(')
			{
				postfix[j] = x;
				j++;
				x = push();
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");
			exit(1);
		}
		i++;
		item = infix[i];
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		exit(1);
	}
	postfix[j] = '\0';
}


int main()
{
	char infix[max], postfix[max];

	printf("\nEnter Infix expression : ");
	gets(infix);

	convert(infix,postfix);
	printf("Postfix Expression: ");
	puts(postfix);

	return 0;
}
