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
	: QDockWidget("", parent, Qt::Dialog | Qt::CustomizeWindowHint),
	_window(win),
	_moduleHostnameButton(nullptr), _moduleDateButton(nullptr), _moduleOSButton(nullptr) {

		resize(500, 1020);
		move(1450, 20);
		setFeatures(QDockWidget::NoDockWidgetFeatures);
		
		QWidget *wids = new QWidget(this);
		QVBoxLayout* layout = new QVBoxLayout();
		
		_moduleHostnameButton = new QPushButton("Add new Hostname Module", this);
		connect(_moduleHostnameButton, SIGNAL(pressed()), this, SLOT(addHostnameModule()));
		_moduleDateButton = new QPushButton("Add new Date Module", this);
		connect(_moduleDateButton, SIGNAL(pressed()), this, SLOT(addDateModule()));
		_moduleOSButton = new QPushButton("Add new OS Module", this);
		connect(_moduleOSButton, SIGNAL(pressed()), this, SLOT(addOSModule()));
		
		layout->addWidget(_moduleHostnameButton);
		layout->addWidget(_moduleDateButton);
		layout->addWidget(_moduleOSButton);
		
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

	_window->addNewModule(new GModuleHostname(_window, rand() % 1400, rand() % 1000));
}

void SideBar::addDateModule() {

	_window->addNewModule(new GModuleDate(_window, rand() % 1400, rand() % 1000));
}

void SideBar::addOSModule() {

	_window->addNewModule(new GModuleOS(_window, rand() % 1400, rand() % 1000));
}
