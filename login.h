#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMouseEvent>
#include <QTimer>

struct UserInfoStu{
    QString userName;
    QString passwd;
};

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT
    
public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    void init();
    void get_user_info();
    void configWindow();

    void init_sql();

protected:
    void mousePressEvent(QMouseEvent *e);

    void mouseMoveEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

signals:
    void close();
    
private slots:
    void on_btn_login_clicked();

    void on_btn_regist_clicked();

    void on_btn_edit_clicked();

    void slot_minWindow();

    void slot_closeWindow();

    void slot_getKeyBoard();

    void slot_timer1();

    void slot_timer2();

    void on_cBox_account_activated(int index);

public:
    UserInfoStu user_info_stu;
    QSqlDatabase db;

private:
    Ui::Login *ui;

    bool m_Drag;
    QPoint m_point;
    QTimer *timer1, *timer2;
    QStringList userPasswd;         //用户密码
};

#endif // LOGIN_H
