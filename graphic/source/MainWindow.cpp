/*
 * =====================================================================================
 *
 *       Filename:  MainWindow.cpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 12:18:58 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */

#include "MainWindow.hpp"

MainWindow::MainWindow()
	: QMainWindow(nullptr, Qt::Window) {

		setWindowTitle("MyGkrellm");
		setFocusPolicy(Qt::StrongFocus);

		statusBar();
		statusBar()->addPermanentWidget(new QLabel("MyGkrellm ready to use."));

		addDockWidget(Qt::LeftDockWidgetArea, new GModuleHostname(this, 2, 0));
	}

MainWindow::~MainWindow() {
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Q) {
		close();
	}
	QMainWindow::keyPressEvent(event);
}
