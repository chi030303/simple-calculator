#include <stdio.h>
#include <stdlib.h>
#include "mainwindow.h"

int isEmpety(stack s){
    return s->top == EmptyTOS;
}

int isEmpety2(opstack s){
    return s->top == EmptyTOS;
}

stack createStack(){
    stack s;
    s = (Stack*)malloc(sizeof(Stack));
    if(s == NULL)
      printf("out of space!");

    s->operand = (double*)malloc(sizeof(double)*MaxSize);
    if(s->operand == NULL)
      printf("out of space!");

    makeEmpety(s);
    s->size = MaxSize;
    return s;
}

opstack createopStack(){
    opstack s;
    s = (opStack*)malloc(sizeof(opStack));
    if(s == NULL)
      printf("out of space!");

    s->operatoR = (char*)malloc(sizeof(char)*MaxSize);
    if(s->operatoR == NULL)
      printf("out of space!");

    makeempety(s);
    s->size = MaxSize;
    return s;
}

void push(double x , stack s){
    if(isFull(s))//top在判断时自增
      printf("Full stack!");
    else
      s->operand[s->top] = x;
}

void push2(char c , opstack s){
    if(isFull2(s))//top在判断时自增
      printf("Full stack!");
    else
      s->operatoR[s->top] = c;
}

void pop(stack s){
    if(isEmpety(s))
      printf("Empty stack!");
    else
      s->top--;//下次输入就覆盖掉
}

void pop2(opstack s){
    if(isEmpety2(s))
      printf("Empty stack!");
    else
      s->top--;//下次输入就覆盖掉
}

double topAndPop(stack s){
    if(!isEmpety(s))
      return s->operand[s->top--];
    printf("Empty stack!!!");
    return 0;
}

void makeEmpety(stack s){
    s->top = EmptyTOS;
}

void makeempety(opstack s){
    s->top = EmptyTOS;
}

void disposeStack(stack s){
    if(s!=NULL){
        free(s->operand);
        free(s);
    }
}

double top(stack s){
    if(!isEmpety(s))
      return s->operand[s->top];
    printf("Empty stack!!!");
    return 0;
}

char top2(opstack ops){
    if(!isEmpety2(ops))
      return ops->operatoR[ops->top];
    printf("Empty stack!!!");
    return 0;
}

int isFull(stack s){
     return s->top++ == s->size;
}

int isFull2(opstack ops){
     return ops->top++ == ops->size;
}

void printStack(stack s){
    int i = 0;
    while (i!=s->top+1)
    {
        printf("%lf ",s->operand[i]);
        i++;
    }
}

void printOpStack(opstack ops){
    int i = 0;
    while (i!=ops->top+1)
    {
        printf("%c ",ops->operatoR[i]);
        i++;
    }
}

void setCheck(int a){
    sign = a;
}

int check(){
    return sign;
}
