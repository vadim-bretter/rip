#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QRegExp>
#include <QMessageBox>
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    display();
    connect(ui->openFBut, SIGNAL( clicked() ), SLOT( openInput() ));
    connect(ui->pushRipmd, SIGNAL( clicked() ), SLOT( clickedRipemd() ));
}

void MainWindow::display()
{
    ui->openFBut->setVisible( true );
    ui->openF->setVisible( true );
    ui->pushRipmd->setVisible( true );
    ui->textOut->setVisible( true );
}

void MainWindow::openInput()
{
    QString str = QFileDialog::getOpenFileName( this, QString::fromLocal8Bit( "Выбрать файл для хешировнаия" ) );
    if ( !str.isEmpty() ) {
        ui->openF->setText( str );
        ui->openF->setVisible( true );
        ui->pushRipmd->setVisible( true );
    }
}


void MainWindow::clickedRipemd()
{
    ui->textOut->setVisible( true );
    QString str;
    str = Ripemd( ui->openF->text());
    ui->textOut->setText( str );

}

MainWindow::~MainWindow()
{
    delete ui;
}
