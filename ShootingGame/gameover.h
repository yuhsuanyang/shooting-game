#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class gameover;
}

class gameover : public QWidget
{
    Q_OBJECT

public:
    explicit gameover(QWidget *parent = 0);
    ~gameover();
    QLabel *r;
    QLabel *n;

private:
    Ui::gameover *ui;
    QLabel *s;
};

#endif // GAMEOVER_H
