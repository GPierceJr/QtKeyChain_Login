#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class SecDialog; }
QT_END_NAMESPACE

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = 0);
    ~SecDialog();

private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
