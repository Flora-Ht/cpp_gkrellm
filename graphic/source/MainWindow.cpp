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
	: QMainWindow(nullptr, Qt::Dialog), _area(new QMdiArea) {

		resize(MainWindow::width * 2, MainWindow::height);
		setWindowTitle("MyGkrellm");
		setFocusPolicy(Qt::StrongFocus);

		statusBar();
		statusBar()->addPermanentWidget(new QLabel("MyGkrellm ready to use."));

		setCentralWidget(_area);
		QMdiSubWindow *sideBar = _area->addSubWindow(new SideBar(this, this), Qt::Dialog);
		sideBar->resize(MainWindow::width, 150);
		QMdiSubWindow *sub = _area->addSubWindow(new GModuleHostname(this, 0, 0), Qt::Dialog);
		sub->resize(MainWindow::width, 100);
		QMdiSubWindow *sub2 = _area->addSubWindow(new GModuleDate(this, 0, 0), Qt::Dialog);
		sub2->resize(MainWindow::width, 100);
		QMdiSubWindow *sub3 = _area->addSubWindow(new GModuleOS(this, 0, 0), Qt::Dialog);
		sub3->resize(MainWindow::width, 100);
		// _area->addSubWindow(new GModuleHostname(this, 2, 40), Qt::Dialog);
		// addDockWidget(Qt::LeftDockWidgetArea, new SideBar(this, this));
		// addDockWidget(Qt::LeftDockWidgetArea, new GModuleHostname(this, 2, 40));
		// addDockWidget(Qt::RightDockWidgetArea, new GModuleDate(this, 2, 140));
		// addDockWidget(Qt::RightDockWidgetArea, new GModuleOS(this, 2, 240));
	}

MainWindow::~MainWindow() {
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Q) {
		close();
	}
	QMainWindow::keyPressEvent(event);
}

void MainWindow::addNewModule(GModule *mod) {

	(void)mod;
	std::cout << "New module asked." << std::endl;
	// addDockWidget(Qt::LeftDockWidgetArea, mod);
	// QMdiSubWindow *sub = _area->addSubWindow(new GModuleOS(this, 0, 0), Qt::Dialog);
	// sub->resize(MainWindow::width, 100);
	update();
}

QMdiArea *MainWindow::getArea() const {

	return _area;
}
