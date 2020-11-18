#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>

SignUp::SignUp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);

    // password masking
    ui->lineEdit_newPassword->setEchoMode(ui->lineEdit_newPassword->Password);
    ui->lineEdit_confirmPassword->setEchoMode(ui->lineEdit_confirmPassword->Password);

}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_CreateAccount_clicked(){
    QString new_username = ui->lineEdit_newUsername->text();
    QString new_password = ui->lineEdit_newPassword->text();
    QString confirm_password = ui->lineEdit_confirmPassword->text();

    QKeychain::ReadPasswordJob user_check( QLatin1String("login") );
    user_check.setAutoDelete(false);
    user_check.setKey(new_username);
    QEventLoop user_loop;
    user_check.connect( &user_check, SIGNAL(finished(QKeychain::Job*)), &user_loop, SLOT(quit()) );
    user_check.start();
    user_loop.exec();
    if ( !user_check.error()) {
        QMessageBox::warning(this, "Login", "Username is already taken. Please pick another.");
    }
    else if(new_password != confirm_password){
        QMessageBox::warning(this, "Login", "Error: Passwords don't match");
    }
    else{

        QKeychain::WritePasswordJob job( QLatin1String("login") );
        job.setAutoDelete(false);
        job.setKey(new_username);
        job.setTextData(new_password);
        QEventLoop loop;
        job.connect( &job, SIGNAL(finished(QKeychain::Job*)), &loop, SLOT(quit()) );
        job.start();
        loop.exec();
        if ( job.error() ) {
            QMessageBox::warning(this, "Login", "Failed to create account. Please try again.");
        }
        else{

            // account created successfully
            close();

        }

    }
}

