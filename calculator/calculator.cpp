#include "mainwindow.h"
#include <stdio.h>

int sign;

double operate(double a,double b,char c){
    double result;
    switch(c){
    case '+':
        result = a+b;
        break;
    case '-':
        result = b-a;
        break;
    case '*':
        result = a*b;
        break;
    case '/':
        if(a == 0){
            setCheck(-1);
        }
        else
        result = b/a;
        break;
    }
    return result;
}

double evaluate(QString qs,stack s,opstack ops){
    int pos = 0,n = qs.length();
    double in,a,b;
    QString num = "";
    char temp,c;

    while(pos < n){
        temp = qs.at(pos).toLatin1();
        if(input(temp)==false){
            num.append(temp);
            pos++;
        }
        else {
            if(num != ""){
                in = num.toDouble();
                num = "";
                push(in,s);
            }
                switch(compare(ops->operatoR[ops->top],temp)){
                    case '<':              
                        pos++;
                        push2(temp,ops);
                        break;
                    case '=':
                         pos++;
                         pop2(ops);
                        break;

                    case '>':
                        a = topAndPop(s);
                        b = topAndPop(s);
                        c = top2(ops);
                        pop2(ops);
                        push(operate(a,b,c),s);          
                    break;

          }
       }
     }
   return top(s);
}

char compare(char c1,char c2){
        if(c1=='+'){
            switch(c2){
                case '+': return '>';break;
                case '-': return '>';break;
                case '*': return '<';break;
                case '/': return '<';break;
                case '(': return '<';break;
                case ')': return '>';break;
                case '#': return '>';break;
            }
        }
        else if(c1=='-'){
            switch(c2){
                case '+': return '>';break;
                case '-': return '>';break;
                case '*': return '<';break;
                case '/': return '<';break;
                case '(': return '<';break;
                case ')': return '>';break;
                case '#': return '>';break;
            }
        }
        else if(c1=='*'){
            switch(c2){
                case '+': return '>';break;
                case '-': return '>';break;
                case '*': return '>';break;
                case '/': return '>';break;
                case '(': return '<';break;
                case ')': return '>';break;
                case '#': return '>';break;
            }
        }
        else if(c1=='/'){
            switch(c2){
                case '+': return '>';break;
                case '-': return '>';break;
                case '*': return '>';break;
                case '/': return '>';break;
                case '(': return '<';break;
                case ')': return '>';break;
                case '#': return '>';break;
            }
        }
        else if(c1=='('){
            switch(c2){
                case '+': return '<';break;
                case '-': return '<';break;
                case '*': return '<';break;
                case '/': return '<';break;
                case '(': return '<';break;
                case ')': return '=';break;
                case '#': return '!';break;
            }
        }
        else if(c1==')'){
                switch(c2){
                    case '+': return '>';break;
                    case '-': return '>';break;
                    case '*': return '>';break;
                    case '/': return '>';break;
                    case '(': return '!';break;
                    case ')': return '>';break;
                    case '#': return '>';break;
                }
            }
            else if(c1=='#'){
                switch(c2){
                    case '+': return '<';break;
                    case '-': return '<';break;
                    case '*': return '<';break;
                    case '/': return '<';break;
                    case '(': return '<';break;
                    case ')': return '!';break;
                    case '#': return '=';break;
                }
         }
}

bool input(char a){
    if(a =='+' || a =='-' || a =='*' || a =='/' || a =='(' || a ==')' || a =='#')
        return true;
    else
        return false;
}
