#include "mainwindow.hh"
#include <QApplication>


bool MainWindow::create_file_browser()
{

    QVBoxLayout* centralLayout = new QVBoxLayout();
    this->centralWidget()->setLayout(centralLayout);

    header_widget_ = new QWidget(this);
    header_layout_ = new QHBoxLayout(header_widget_);
    welcome_label_ = new QLabel("Welcome", header_widget_);

    get_current_date(welcome_label_);

    header_layout_->addWidget(welcome_label_);
    centralLayout->addWidget(header_widget_);

    button_widget_ = new QWidget(this);
    button_layout_ = new QGridLayout(button_widget_);

    select_existing_file_btn_ = new QPushButton("Use an existing file", button_widget_);
    create_new_file_btn_ = new QPushButton("Create a new file", button_widget_);
    use_existing_file_info_ = new QLabel(OPEN_EXISTING_FILE_MSG, button_widget_);
    create_new_file_info_ = new QLabel(NEW_FILE_CREATION_MSG, button_widget_);

    button_layout_->addWidget(select_existing_file_btn_, 1, 0);
    button_layout_->addWidget(create_new_file_btn_, 1, 1);

    button_layout_->addWidget(use_existing_file_info_, 0, 0);
    button_layout_->addWidget(create_new_file_info_, 0, 1);

    connect(create_new_file_btn_, &QPushButton::clicked, this, &MainWindow::create_file);


    disclaimer_widget_ = new QWidget(this);
    disclaimer_layout_ = new QHBoxLayout(disclaimer_widget_);

    disclaimer_text = new QLabel("*Files not created with this application are not quaranteed to work", button_widget_);
    disclaimer_layout_->addWidget(disclaimer_text);

    // Set the alignment of button_widget to center vertically
    centralLayout->addWidget(header_widget_);
    centralLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    centralLayout->addWidget(button_widget_);
    centralLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    centralLayout->addWidget(disclaimer_widget_);

    return true;
}

void MainWindow::get_current_date(QLabel* text)
{
    // Get the current_time since EPOC
    const time_t CURRENT_TIME = time(nullptr);
    //Localtime takes a pointer to CURRENT_TIME
    struct tm* timeinfo = localtime(&CURRENT_TIME);
    //Get the current hour from the struct returned by localtime
    int current_hour = timeinfo->tm_hour;

    print_greeting(current_hour, text);
}

void MainWindow::print_greeting(int current_hour,QLabel* welcome_label)
{

    QString time_of_day = "";
    std::string user = "Test User";

    if (current_hour >= 6 && current_hour < 9) {
        time_of_day = "morning";
    }
    else if (current_hour >= 9 && current_hour < 12) {
        time_of_day = "day";
    }
    else if (current_hour >= 12 && current_hour < 16) {
        time_of_day = "afternoon";
    }
    else if (current_hour >= 16 && current_hour < 24) {
        time_of_day = "evening";
    }
    else {
        time_of_day = "night";
    }

    welcome_label->setText("Good " + time_of_day + "!\r\nSelect what you would like to do below:");
    welcome_label->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
}

void MainWindow::create_file()
{
    QString fileName = "testing_this";
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", fileName);

    this->setCentralWidget(nullptr);
}
