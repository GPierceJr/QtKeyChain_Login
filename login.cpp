#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QPixmap>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    // add a picture to the login screen
    //QPixmap pix(<image path>);
    //int w = ui->label_pic->width();
    //int h = ui->label_pic->height();
    //ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    // store a test account
    /*
    QKeychain::WritePasswordJob job( QLatin1String("login_basic") );
    job.setAutoDelete(false);
    job.setKey( "test" );
    job.setTextData( "testpass" );
    QEventLoop loop;
    job.connect( &job, SIGNAL(finished(QKeychain::Job*)), &loop, SLOT(quit()) );
    job.start();
    loop.exec();
    if ( job.error() ) {
        QMessageBox::warning(this, "Login", "Failed to set test account");
    }
    */

    // password masking
    ui->lineEdit_password->setEchoMode(ui->lineEdit_password->Password);

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_Login_clicked(){
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QKeychain::ReadPasswordJob job( QLatin1String("login_basic") );
    job.setAutoDelete(false);
    job.setKey(username);
    QEventLoop loop;
    job.connect( &job, SIGNAL(finished(QKeychain::Job*)), &loop, SLOT(quit()) );
    job.start();
    loop.exec();

    QString found_password = job.textData();

    if ( job.error() ) {
        QMessageBox::warning(this, "Login", "Username and/or password is not correct");
    }
    else if(found_password == password){
        //QMessageBox::information(this, "Login", "Username and/or password is correct");
        hide();
        secDialog = new SecDialog(this);
        secDialog->show();
    }
    else{
        QMessageBox::warning(this, "Login", "Username and/or password is not correct");
    }

    /*
    if(username == "test" && password == "test"){
        QMessageBox::information(this, "Login", "Username and password is correct");
        hide();
        secDialog = new SecDialog(this);
        secDialog->show();
    }
    else{
        QMessageBox::warning(this, "Login", "Username/password is not correct");
    }
    */
}


void Login::on_pushButton_SignUp_clicked(){
    //hide();
    signUp = new SignUp(this);
    signUp->show();
}
