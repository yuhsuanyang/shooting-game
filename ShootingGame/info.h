#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class info;
}

class info : public QWidget
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = 0);
    ~info();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::info *ui;
    QLabel *tutor;

};

#endif // INFO_H
