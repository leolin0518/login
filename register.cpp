#include "register.h"
#include "ui_register.h"
//#include "login.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    setWindowTitle(tr("注册"));

    //connect((Login *)parent,SIGNAL(transmitdb(QSqlDatabase)),this,SLOT(receivedb(QSqlDatabase)));

}

Register::~Register()
{
    delete ui;
}

void Register::setParent(Login *dialog)
{
    if(dialog != NULL){
        pWidget = dialog;
    }
}


//创建一个名为userInfo的表，id为主键 顺序为:ID 用户名 密码 email 历史
QString create_sql      = "create table userInfo (chatid int primary key, name varchar(30), password varchar(30), email varchar(30), history int)";
//选中名为userInfo的表
QString select_table    = "select tbl_name userRegiste from sqlite_master where type = 'table'";
//获取表中的最大ID，以chatid
QString select_max_sql  = "select max(chatid) from userInfo";
//向表userInfo中插入数据  顺序为:用户名 密码 email
QString insert_sql      = "insert into userInfo values (?, ?, ?)";
//选中userInfo表中的name列
QString select_sql      = "select name from userInfo";



//注册函数
void Register::on_registerCheckButton_clicked()
{
    pWidget->user_info_stu.userName = ui->lineEditName->text();
    pWidget->user_info_stu.passwd = ui->lineEditPassword->text();
    pWidget->user_info_stu.email = ui->lineEditEmail->text();
    qDebug() << "333:" << pWidget->user_info_stu.userName << pWidget->user_info_stu.passwd
             << pWidget->user_info_stu.email;
    this->close();

//    bool is_use_pwd_check_flag=false;  //密码有效标志
//    bool is_use_name_exist_flag = false;       //判断用户是否存在

//    //int new_user_id = sql_max_id + 1;
//    QString new_user_password = NULL;
//    QString new_user_name = NULL;
//    QString newemail = ui->lineEditEmail->text();

//    QString new_user_password1 = ui->lineEditPassword->text();
//    QString new_user_name1 = ui->lineEditPasswordCheck->text();
//    qDebug() << new_user_password1 << "/" << new_user_name1 << "/" << newemail;;



//    //检查密码是否一致或为空 start
//    if(ui->lineEditName->text()=="")//用户名为空
//    {
//        is_use_pwd_check_flag = false;
//        QMessageBox::warning(this,tr("警告"),tr("用户名为空!"));
//        return;
//    }
//    if(ui->lineEditPassword->text()=="" || ui->lineEditPasswordCheck->text()=="")//密码为空
//    {
//        is_use_pwd_check_flag = false;
//        QMessageBox::warning(this,tr("警告"),tr("密码为空!"));
//    }
//    else if(ui->lineEditPassword->text() != ui->lineEditPasswordCheck->text())//两次密码相同
//    {
//        is_use_pwd_check_flag = false;
//        QMessageBox::warning(this,tr("警告"),tr("两次密码不同!"));
//    }
//    else if(ui->lineEditPassword->text() == ui->lineEditPasswordCheck->text())//两次密码相同
//    {
//        is_use_pwd_check_flag = true;
//    }
//    else
//    {
//        qDebug()<<"[D]passwd err";
//        is_use_pwd_check_flag = false;
//    }
    //检查密码是否一致或为空 end


/**********************************以下为数据库的操作*****************************************/

//    //查询最大id start
//    sql_max_id = 0;
//    sql_query.prepare(select_max_sql);
//    if(!sql_query.exec())
//    {
//        qDebug()<<"查询最大id error";
//    }
//    else
//    {
//        while(sql_query.next())
//        {
//            sql_max_id = sql_query.value(0).toInt();
//            qDebug()<<QString("[D]max chatid:%1").arg(sql_max_id);
//        }
//    }
//    //查询最大id end
//    QSqlDatabase db;
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("database.db");
//    if (!db.open())
//    {
//        qDebug() << "database open fail in register!";
//    }
//    else
//    {
//        qDebug() << "database open success in register!";
//        QSqlQuery sql_query;

//        //查询表user里面,name列 (select name from user) start
//        if(!sql_query.exec(select_sql))
//        {
//            qDebug()<<"选中表error in regitster.cpp";
//        }
//        else
//        {
//            while(1)
//            {
//                if(sql_query.next())//name列有数据
//                {
//                    QString name_tmp = sql_query.value("name").toString();
//                    qDebug()<<QString("[D]name_tmp=%1").arg(name_tmp);

//                    if( ui->lineEditName->text() == name_tmp ) //查询到表中已经存在当前输入的名字
//                    {
//                        qDebug()<<"[D]name existed in table";
//                        QMessageBox::warning(this,tr("警告"),tr("用户名已存在!"));
//                        is_use_name_exist_flag = false;
//                        break;
//                    }
//                    else
//                    {
//                        is_use_name_exist_flag = true;
//                    }
//                }
//                else//name列为空
//                {
//                    is_use_name_exist_flag = true;
//                    break;
//                }
//            }
//        }
//       //查询表user里面,name列 (select name from user) end



//       // new_user_id = sql_max_id + 1;//sql_max_id为当前表中最大ID，插入新的id即为原sql_max_id+1
//        if(is_use_name_exist_flag==true)
//            new_user_name = ui->lineEditName->text();
//        else
//            return;

//        if(is_use_pwd_check_flag==true)
//            new_user_password = ui->lineEditPassword->text();
//        else
//            return;

//        //数据库表中插入数据
//        //插入数据 顺序为: 用户名 密码 email
//        sql_query.prepare(insert_sql);
//        sql_query.addBindValue(new_user_name);            //name
//        sql_query.addBindValue(new_user_password);        //passwd
//        sql_query.addBindValue(newemail);                 //email
//        if(!sql_query.exec())
//        {
//            qDebug()<<sql_query.lastError();
//        }
//        else
//        {
//            qDebug()<<"[D]inserted!";
//        }
//        db.close();
//        this->close();

//    }
}
