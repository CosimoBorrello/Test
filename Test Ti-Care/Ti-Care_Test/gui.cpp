#include "gui.h"

extern std::string TestoT1;
extern std::string TestoT2;


// Impostazioni per la geometria dell'interfaccia.
int larghezza = 1920;
int altezza = 1080;
int larghezza_finestra = 320;
int altezza_finestra = 240;
int larghezza_adattata = larghezza - larghezza_finestra - (larghezza * 0.02);
int altezza_adattata = altezza - altezza_finestra - (altezza * 0.08);

GUI::GUI(QWidget *parent) : QMainWindow(parent)
{
    traySystemIcon = new QSystemTrayIcon();
    traySystemIcon->setIcon(QIcon(":/icona.png"));
    traySystemIcon->show();

    // Interfaccia grafica relativa al Task1.
    QHBoxLayout *Task1 = new QHBoxLayout;
    QLineEdit *InputTask1 = new QLineEdit;
    QPushButton *bottoneT1 = new QPushButton("Modifica!");
    QLabel * labelT1 = new QLabel("Task1");
    Task1->addWidget(labelT1);
    Task1->addWidget(InputTask1);
    Task1->addWidget(bottoneT1);
    connect(bottoneT1, &QPushButton::clicked, [InputTask1]()
    {
        TestoT1 = InputTask1->text().toStdString();
    });

    // Interfaccia grafica relativa al Task2.
    QHBoxLayout *Task2 = new QHBoxLayout;
    QLineEdit *InputTask2 = new QLineEdit;
    QPushButton *bottoneT2 = new QPushButton("Modifica!");
    QLabel * labelT2 = new QLabel("Task2");
    Task2->addWidget(labelT2);
    Task2->addWidget(InputTask2);
    Task2->addWidget(bottoneT2);
    connect(bottoneT2, &QPushButton::clicked, [InputTask2]()
    {
        TestoT2 = InputTask2->text().toStdString();
    });

    // Interfaccia finestra principale.
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(Task1);
    mainLayout->addLayout(Task2);
    QWidget *Finestra = new QWidget();
    Finestra->setStyleSheet("background-color:rgb(212,199,185);");
    Finestra->setLayout(mainLayout);
    Finestra->resize(larghezza_finestra, altezza_finestra);
    Finestra->move(larghezza_adattata, altezza_adattata);
    Finestra->setWindowFlags(Qt::FramelessWindowHint);
    Finestra->setWindowFlags(Qt::SubWindow);
    Finestra->setWindowFlags(Qt::WindowStaysOnTopHint);
    Finestra->setWindowTitle("Pannello di controllo");

    connect(traySystemIcon, &QSystemTrayIcon::activated, [Finestra]()
    {
        if (Finestra->isVisible()) {
            Finestra->hide();
        }else{
            Finestra->show();
        }
    });

    // Tasto chiusura programma.
    QHBoxLayout *Chiusura = new QHBoxLayout;
    QPushButton *Chiudi = new QPushButton("Termina Programma");
    Chiusura->addWidget(Chiudi);
    mainLayout->addLayout(Chiusura);
    connect(Chiudi, &QPushButton::clicked, [Finestra]()
    {
            Finestra->close();
    });
}
