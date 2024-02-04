#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    create_file_browser();
    set_menu_styles();
}

MainWindow::~MainWindow()
{
    delete ui;
}








