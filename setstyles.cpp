#include "mainwindow.hh"

#include <QApplication>

void MainWindow::set_menu_styles()
{
    button_layout_->setAlignment(select_existing_file_btn_, Qt::AlignCenter);
    button_layout_->setAlignment(create_new_file_btn_, Qt::AlignCenter);

    set_label_style(use_existing_file_info_);
    set_label_style(create_new_file_info_);

    header_layout_->setAlignment(welcome_label_, Qt::AlignHCenter);
    welcome_label_->setStyleSheet("font-size: 20px; font-weight: bold;");

    // Create a QPalette object for the buttons
    QPalette palette;
    palette.setColor(QPalette::ButtonText, Qt::white);

    set_btn_style(select_existing_file_btn_, palette);
    set_btn_style(create_new_file_btn_, palette);

}

void MainWindow::set_label_style(QLabel* label)
{
    label->setWordWrap(true);
    label->setStyleSheet("font-weight: bold;margin: 10px;font-size:12px");
    label->setAlignment(Qt::AlignCenter);
}

void MainWindow::set_btn_style(QPushButton * btn, QPalette palette)
{

    btn->setStyleSheet("QPushButton { background-color: #002D62;"
                       "border-radius: 5px;"
                       "padding: 10px; font-weight: bold; }"
                       "QPushButton:hover { background-color: #0066b2; }");
    btn->setPalette(palette);
}
