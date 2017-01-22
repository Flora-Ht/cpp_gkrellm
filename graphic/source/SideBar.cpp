/*
 * =====================================================================================
 *
 *       Filename:  SideBar.cpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 10:50:13 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#include "SideBar.hpp"

SideBar::SideBar(QWidget *parent, MainWindow *win)
	: QDockWidget("Menu", parent, Qt::Dialog | Qt::CustomizeWindowHint),
	_window(win),
	_moduleHostnameButton(nullptr), _moduleDateButton(nullptr), _moduleOSButton(nullptr) {

		setFeatures(QDockWidget::NoDockWidgetFeatures);
		
		QWidget *wids = new QWidget(this);
		QVBoxLayout* layout = new QVBoxLayout();
		
		_moduleHostnameButton = new QPushButton("Add new Hostname Module", this);
		connect(_moduleHostnameButton, SIGNAL(pressed()), this, SLOT(addHostnameModule()));
		_moduleDateButton = new QPushButton("Add new Date Module", this);
		connect(_moduleDateButton, SIGNAL(pressed()), this, SLOT(addDateModule()));
		_moduleOSButton = new QPushButton("Add new OS Module", this);
		connect(_moduleOSButton, SIGNAL(pressed()), this, SLOT(addOSModule()));
		_moduleCPUButton = new QPushButton("Add new CPU Module", this);
		connect(_moduleCPUButton, SIGNAL(pressed()), this, SLOT(addCPUModule()));
		_moduleRAMButton = new QPushButton("Add new RAM Module", this);
		connect(_moduleRAMButton, SIGNAL(pressed()), this, SLOT(addRAMModule()));
		
		layout->addWidget(_moduleHostnameButton);
		layout->addWidget(_moduleDateButton);
		layout->addWidget(_moduleOSButton);
		layout->addWidget(_moduleCPUButton);
		layout->addWidget(_moduleRAMButton);
		
		wids->setLayout(layout);
		setWidget(wids);
		
		show();
	}

SideBar::~SideBar() {

	delete _moduleHostnameButton;
	delete _moduleDateButton;
	delete _moduleOSButton;
}

void SideBar::addHostnameModule() {

	QMdiSubWindow *sub = _window->getArea()->addSubWindow(new GModuleHostname(_window, 0, 0), Qt::Dialog);
	sub->resize(MainWindow::width, 100);
	sub->show();
}

void SideBar::addDateModule() {

	QMdiSubWindow *sub = _window->getArea()->addSubWindow(new GModuleDate(_window, 0, 0), Qt::Dialog);
	sub->resize(MainWindow::width, 100);
	sub->show();
}

void SideBar::addOSModule() {

	QMdiSubWindow *sub = _window->getArea()->addSubWindow(new GModuleOS(_window, 0, 0), Qt::Dialog);
	sub->resize(MainWindow::width, 100);
	sub->show();
}

void SideBar::addCPUModule() {

	QMdiSubWindow *sub = _window->getArea()->addSubWindow(new GModuleCPU(_window, 0, 0), Qt::Dialog);
	sub->resize(MainWindow::width, 300);
	sub->show();
}

void SideBar::addRAMModule() {

	QMdiSubWindow *sub = _window->getArea()->addSubWindow(new GModuleRAM(_window, 0, 0), Qt::Dialog);
	sub->resize(MainWindow::width, 200);
	sub->show();
}
