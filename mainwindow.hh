#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <windows.h>
#include <ctime>
#include <iostream>
#include <QLineEdit>
#include <QFileDialog>

const int BTN_WIDTH = 100;
const QString OPEN_EXISTING_FILE_MSG = "Open an exising file by clicking here. If you do not have a file created with this application before, please create a new file.";
const QString  NEW_FILE_CREATION_MSG= "Create a new file by entering the filename below and clicking here. Beware that if a file of the same name exists already, it is cleared.";
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool create_file_browser();
    void get_current_date(QLabel* welcome_label);
    void print_greeting(int hour,QLabel* welcome_label);
    void create_file();
    void set_menu_styles();
    void set_label_style(QLabel* label);
    void set_btn_style(QPushButton* btn, QPalette palette);

private:
    Ui::MainWindow *ui;

    QGridLayout* button_layout_ = nullptr;

    QWidget* header_widget_ = nullptr;
    QHBoxLayout* header_layout_ = nullptr;
    QLabel* welcome_label_ = nullptr;

    QWidget* button_widget_ = nullptr;

    QPushButton* select_existing_file_btn_ = nullptr;
    QPushButton* create_new_file_btn_ = nullptr;

    QLabel* use_existing_file_info_ = nullptr;
    QLabel* create_new_file_info_ = nullptr;

    QWidget* disclaimer_widget_ = nullptr;
    QHBoxLayout* disclaimer_layout_ = nullptr;

    QLabel* disclaimer_text = nullptr;


};
#endif // MAINWINDOW_HH
