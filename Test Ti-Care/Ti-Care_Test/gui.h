#ifndef GUI_H
#define GUI_H

#include "gui.h"
#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QMainWindow>
#include <QLineEdit>
#include <QLineEdit>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QIcon>

class GUI : public QMainWindow
{
    Q_OBJECT
public:
    GUI(QWidget *parent=nullptr);

private:
    QSystemTrayIcon *traySystemIcon;
};

#endif // GUI_H
