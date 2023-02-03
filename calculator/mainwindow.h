#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define EmptyTOS -1
#define MaxSize 100

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_Button3_clicked();

    void on_Button4_clicked();

    void on_Button5_clicked();

    void on_Button6_clicked();

    void on_Button7_clicked();

    void on_Button8_clicked();

    void on_Button9_clicked();

    void on_Button0_clicked();

    void on_dot_clicked();

    void on_leftpar_clicked();

    void on_rightpar_clicked();

    void on_add_clicked();

    void on_sub_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_clean_clicked();

    void on_undo_clicked();

    void on_equal_clicked();

private:
    Ui::MainWindow *ui;
};

struct Stack
{
    int top;
    int size;
    double *operand;
};

struct opStack
{
    int top;
    int size;
    char *operatoR;
};

typedef struct Stack *stack;
typedef struct opStack *opstack;
extern int sign;

int isEmpety(stack s);//判断栈是否为空
int isFull(stack s);//判断栈是否为满
void push(double x,stack s);//将元素放入栈
void pop(stack s);//弹出栈的元素
stack createStack();//创建一个存放操作数的栈
void printStack(stack s);//打印栈中的元素
double top(stack s);//找到栈顶的元素
double topAndPop(stack s);//给出栈顶元素并弹出
void makeEmpety(stack s);//使栈为空
void disposeStack(stack s);//释放栈
opstack createopStack();//存放操作符的栈
void makeempety(opstack s);//给操作符用
double calculator(stack s,opstack ops);//实现计算器
void push2(char c , opstack s);
void pop2(opstack s);
int BracketMatch(opstack s);
int isFull2(opstack ops);//判断操作符栈是否为满
void get(QString qs,stack s,opstack ops);
void printOpStack(opstack ops);
int priority(char c);//判断运算符的优先级
char compare(char a,char b);//比较运算符的优先级
bool input(char a);//判断输入是否为运算符
double evaluate(QString qs,stack s,opstack ops);
char top2(opstack ops);
double operate(double a,double b,char c);
double Replace(QString qr);
void setCheck(int a);
int check();

#endif // MAINWINDOW_H
