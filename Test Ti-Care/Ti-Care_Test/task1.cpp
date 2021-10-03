#include "task1.h"

Task1::Task1()
{
    testo = "Stringa di esempio!";
}

void Task1::EseguiTask1()
{
    if(testo != ""){
        std::cout << testo << std::endl;
    }
}

Task1::~Task1()
{

}
