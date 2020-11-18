#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include "keychain.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SignUp; }
QT_END_NAMESPACE

class SignUp : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_pushButton_CreateAccount_clicked();

private:
    Ui::SignUp *ui;
};
#endif // SIGNUP_H
