#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>

class SystemTrayIcon : public QWidget
{
    Q_OBJECT
public:
    //explicit SystemTrayIcon(QWidget *parent = 0);
    explicit SystemTrayIcon(QStringList strList, QIcon icon, QWidget *parent = 0);

    void create_sysTrayMenu();          //创建托盘菜单
    void create_sysTrayIcon();          //创建托盘菜单的图标
    void create_sysTrayMenuAct();       //创建点击托盘菜单项的act行为


signals:

public slots:

    void slot_sys_tray_iconActivated(QSystemTrayIcon::ActivationReason reason);//系统托盘触发槽函数


public:
    QAction *actFixed;                  //固定位置

private:

    QWidget *pWidget;                   //父对象

    QSystemTrayIcon *mSysTrayIcon;        //系统托盘
    QMenu *mSysTrayMenu;                  //系统托盘显示菜单
    QAction *act_sys_tray_min;                    //最小化
    QAction *act_sys_tray_normal;                 //正常
    QAction *act_sys_tray_exit;                   //退出
    QStringList m_strList;              //托盘信息
    QIcon m_icon;                       //托盘图标

};

#endif // SYSTEMTRAYICON_H
