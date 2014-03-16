/** 
 * @mainpage
 * 	PhaseVis is an application to visualize two-dimensional vector fields.
 *  	@author	 Patryk Stupka
 * 	@date	 2014.01.18
 * 	@version 1.0-rc1
 */

#include "GUI/PhaseVis.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PhaseVis window;
    //window -> setAttribute(Qt::WA_DeleteOnClose); //IMPORTANT FOR POINTERS!!!
    window.show();
    return app.exec();
}
