/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 12:08:37 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#include <iostream>
#include <QApplication>
#include <QMdiArea>

#include "MainWindow.hpp"

int main(int ac, char **av) {

	QApplication app(ac, av);
	
	MainWindow window;
	// QMdiArea *mdi = new QMdiArea(&window);
	// window.setCentralWidget(mdi);
	
	window.show();
	
	return app.exec();
}
