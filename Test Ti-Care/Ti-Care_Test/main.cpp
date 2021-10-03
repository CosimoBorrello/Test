/*
 * Il programma esegue sequenzialmente con periodicità diverse due tasks.
 * Il Task1 stampa a video una frase.
 * Il Task2 verifica la presenza di un file in una path indicata.
 * Sia la frase che la path di destinazione possono essere inserite dall'utente attraverso l'interfaccia accessibile cliccando sulla SystemTrayIcon del programma.
*/

#include <QApplication>
#include <iostream>
#include "gui.h"
#include "task1.h"
#include "task2.h"
#include <QTimer>
#include <QObject>

// La frase e la path inserite dall'utente sono assegnate a due variabili globali: TestoT1, TestoT2.

std::string TestoT1 = "";
std::string TestoT2 = "";

int PeriodoT1 = 10000;
int PeriodoT2 = 30000;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    GUI gui;

    /*
     * CREAZIONE DEI TASK E DEI RISPETTIVI TIMER
     * I tasks sono sequenziali e se le variabili TestoT1 e TestoT2 vengono aggiornate durante un periodo di un timer,
     * si aspetterà il completamento dello stesso prima di aggiornare la variabile interessata.
    */

    //Task1
    Task1 task1;
    QTimer *timerTask1 = new QTimer();
    QObject::connect(timerTask1, &QTimer::timeout, [&task1]() {task1.EseguiTask1(); if (TestoT1 != "") {task1.testo = TestoT1;}});
    timerTask1->start(PeriodoT1);

    //Task2
    Task2 task2;
    QTimer *timerTask2 = new QTimer();
    QObject::connect(timerTask2, &QTimer::timeout, [&task2]() {task2.EseguiTask2(); if (TestoT2 != "") {task2.nomeFile = TestoT2;}});
    timerTask2->start(PeriodoT2);

    return app.exec();
}
