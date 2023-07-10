#include "principal.h"
#include "ui_principal.h"

static QSqlDatabase bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");

principal::principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::principal)
{
    ui->setupUi(this);
    ui->topBar->hide();

    bancoDeDados.setDatabaseName("C:/Users/Milton/Desktop/sistemaPlural/bancoPlural/bancoPlural.db");
    if(!bancoDeDados.open())
    {
        qDebug()<<"Não foi possivel abrir o banco de dados";
    }
    else
    {
        qDebug()<<"Banco de dados aberto!";
    }

}

principal::~principal()
{
    delete ui;
}

void principal::on_pushButtonConfirm_clicked()
{
    QString username = ui->lineEditUser->text();
    QString senha = ui->lineEditSenha->text();

    if(!bancoDeDados.isOpen())
    {
        qDebug()<<"Banco de dados não está aberto";
        return;
    }

    QSqlQuery query;
    if (query.exec("select * from tb_login where username='"+username+"' and senha='"+senha+"' "))
    {
        int cont=0;
        while (query.next())
        {
            cont++;
        }
        if (cont > 0)
        {
            this->close();


            fm_principal f_principal;
            f_principal.setModal(true);
            f_principal.setWindowState(Qt::WindowMaximized);
            f_principal.exec();


        }
        else
        {
            ui->topBar->show();
            ui->label_error->setText("USUARIO OU SENHA INCORRETA!");
            ui->lineEditUser->clear();
            ui->lineEditSenha->clear();
            ui->lineEditUser->setFocus();

        }
    }
}


void principal::on_pushButtonCloseError_clicked()
{
    ui->topBar->close();
}

