//
//  main.cpp
//  ТИСД лабораторная 2 задание 1
//
//  Created by Vladimir Sabantcev on 21.02.2024.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include <iostream>
using namespace std;

int *pointer; /* указатель на область свободной памяти */
int *top_of_stack; /* указатель на вершину стека */
int *bottom_of_stack; /* указатель на дно стека */

void push(int i)
{
    if(pointer > bottom_of_stack)
    {
        printf("Стек полон\n");
        return;
    }
    *pointer = i;
    pointer++;
}

int pop(void)
{
    pointer--;
    if(pointer < top_of_stack)
    {
        printf("Стек пуст\n");
        return 0;
    }
    return *pointer;
}


int main(int argc, const char * argv[]) {
    char s[80];
    int a,b;
    
    pointer = (int *) malloc(MAX*sizeof(int)); /* получить память для стека */
    
    if(!pointer)
    {
        printf("Ошибка при выделении памяти\n");
        exit(1);
    }
    
    top_of_stack = pointer;
    bottom_of_stack = pointer + MAX-1;
    
    cout << "Введите выражение в формате обратной польской записи\nДля выхода введите 'q'" << endl;    
    do {
        printf(": ");
        gets(s);
        switch(*s) 
        {
            case '+':
                a = pop();
                b = pop();
                printf("%d\n", a+b);
                push(a+b);
                break;
            case '-':
                a = pop();
                b = pop();
                printf("%d\n", b-a);
                push(b-a);
                break;
            case '*':
                a = pop();
                b = pop();
                printf("%d\n", b*a);
                push(b*a);
                break;
            case '/':
                a = pop();
                b = pop();
                if(a==0) {
                    printf("Деление на 0.\n");
                    break;
                }
                printf("%d\n", b/a);
                push(b/a);
                break;
            case '.': /* показать содержимое вершины стека */
                a = pop();
                push(a);
                printf("Текущее значение на вершине стека: %d\n", a);
                break;
            default:
                push(atoi(s));
        }
    } while (*s != 'q');
    
    
    
    
    return 0;
}
