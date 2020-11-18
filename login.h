#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "secdialog.h"
#include "signup.h"
#include "keychain.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_SignUp_clicked();

private:
    Ui::Login *ui;
    SecDialog *secDialog;
    SignUp *signUp;
};
#endif // LOGIN_H
