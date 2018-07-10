#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    setWindowTitle(tr("Instructor"));
    tutor=new QLabel(this);
    tutor->setPixmap(QPixmap(":/res/instructor.png"));
    tutor->setGeometry(0,0,1280,720);
}

info::~info()
{
    delete ui;
}

void info::on_pushButton_2_clicked()
{
    tutor->setPixmap(QPixmap(":/res/rules.png"));
}

void info::on_pushButton_clicked()
{
    tutor->setPixmap(QPixmap(":/res/instructor.png"));
}
