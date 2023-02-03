#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button1_clicked()
{   QString s = ui->display->text();
    s.append("1");
    ui->display->setText(s);
}

void MainWindow::on_Button2_clicked()
{   QString s = ui->display->text();
    s.append("2");
    ui->display->setText(s);
}

void MainWindow::on_Button3_clicked()
{   QString s = ui->display->text();
    s.append("3");
    ui->display->setText(s);
}

void MainWindow::on_Button4_clicked()
{
    QString s = ui->display->text();
    s.append("4");
    ui->display->setText(s);
}

void MainWindow::on_Button5_clicked()
{
    QString s = ui->display->text();
    s.append("5");
    ui->display->setText(s);
}

void MainWindow::on_Button6_clicked()
{
    QString s = ui->display->text();
    s.append("6");
    ui->display->setText(s);
}

void MainWindow::on_Button7_clicked()
{
    QString s = ui->display->text();
    s.append("7");
    ui->display->setText(s);
}

void MainWindow::on_Button8_clicked()
{
    QString s = ui->display->text();
    s.append("8");
    ui->display->setText(s);
}

void MainWindow::on_Button9_clicked()
{
    QString s = ui->display->text();
    s.append("9");
    ui->display->setText(s);
}

void MainWindow::on_Button0_clicked()
{
    QString s = ui->display->text();
    s.append("0");
    ui->display->setText(s);
}

void MainWindow::on_dot_clicked()
{
    QString s = ui->display->text();
    s.append(".");
    ui->display->setText(s);
}

void MainWindow::on_leftpar_clicked()
{
    QString s = ui->display->text();
    s.append("(");
    ui->display->setText(s);
}

void MainWindow::on_rightpar_clicked()
{
    QString s = ui->display->text();
    s.append(")");
    ui->display->setText(s);
}

void MainWindow::on_add_clicked()
{
    QString s = ui->display->text();
    s.append("+");
    ui->display->setText(s);
}

void MainWindow::on_sub_clicked()
{
    QString s = ui->display->text();
    s.append("-");
    ui->display->setText(s);
}

void MainWindow::on_multiply_clicked()
{
    QString s = ui->display->text();
    s.append("*");
    ui->display->setText(s);
}

void MainWindow::on_divide_clicked()
{
    QString s = ui->display->text();
    s.append("/");
    ui->display->setText(s);
}

void MainWindow::on_clean_clicked()
{
    QString s = NULL;
    ui->display->setText(s);
    ui->result->setText(s);
}

void MainWindow::on_undo_clicked()
{
    QString s = ui->display->text();
    s.chop(1);
    ui->display->setText(s);
}

void MainWindow::on_equal_clicked()
{
    stack s = createStack();
    opstack ops = createopStack();
    QString qs = ui->display->text(),temp,x = qs;
    int j,i,n = qs.length(),m = 0,h = 0;
    push2('#',ops);
    qs = qs +'#';

    printOpStack(ops);

    for(i = 0;i < n;i++){
        char d = x.at(i).toLatin1();
        if(d == '(')
            m++;
        else if(d == ')')
            h++;
    }

    if(h!=m)
        ui->result->setText("wrong input!");
    else{
        double result = evaluate(qs,s,ops);
        char a = qs.at(0).toLatin1();
        if(a =='+' || a =='-' || a =='*' || a =='/' || a ==')'){
            ui->result->setText("wrong input!please input a number!");
        }
        else{
            if(check() < 0){
                ui->result->setText("The divisor cannot be zero!");
            }
            else if(s->top < 0 && ops->top > -1){
                ui->result->setText("wrong input!");
            }
            else if(qs.at(n-1).toLatin1()=='.'){
                ui->result->setText("wrong input!");
            }
            else{
                QString qr = QString::number(result,'f',2);
                ui->result->setText(qr);
                printf("%lf ",result);
                for(i = 0,j = 1;i < n, j < n-1;i++,j++){
                    if(x.at(i).toLatin1() =='+' || x.at(i).toLatin1() =='-' || x.at(i).toLatin1() =='*' || x.at(i).toLatin1() =='/'){
                        if(x.at(j).toLatin1() =='+' || x.at(j).toLatin1() =='-' || x.at(j).toLatin1() =='*' || x.at(j).toLatin1() =='/' || x.at(j).toLatin1() ==')')
                            ui->result->setText("wrong input!");
                    }
                    if(i < n-3){
                        if(x.at(i).toLatin1() =='.' && x.at(i+2).toLatin1() =='.')
                            ui->result->setText("wrong input!");
                    }
            }
        }
      }
    }
}
