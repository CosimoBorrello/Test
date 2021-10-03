#include "task2.h"
#include <QFileInfo>

Task2::Task2()
{
    nomeFile = "";
}

void Task2::EseguiTask2()
{
    QString File = QString::fromStdString(nomeFile);
    if(QFileInfo(File).exists() || File == ""){
        //The file exists
    }
    else{
        std::cout << "Il file non esiste!" << std::endl;
    }
}

Task2::~Task2()
{

}
