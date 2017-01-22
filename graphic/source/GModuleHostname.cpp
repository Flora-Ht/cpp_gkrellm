/*
 * =====================================================================================
 *
 *       Filename:  GModuleHostName.cpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 06:26:37 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */

#include "GModuleHostname.hpp"

GModuleHostname::GModuleHostname(QWidget *parent, int x, int y)
	: GModule("HostName", parent, x, y, 300, 200),
	_labelHost(new QLabel("", this)),
	_labelUser(new QLabel("", this)) {
		
		_monitorModule = new ModuleHostname();
		try {
			_monitorModule->retrieveInformations();
		}
		catch (ModuleException &e) {
			_labelHost->setText("An error has occured.");
			_labelUser->setText("An error has occured.");
		}
		
		QWidget *wid = new QWidget(this);
		QVBoxLayout* layout = new QVBoxLayout();
		ModuleHostname *mod = static_cast<ModuleHostname *>(_monitorModule);
		
		QString hostName = QString::fromStdString(mod->getHost());
		_labelHost->setText(hostName);
		_labelHost->move(_width / 2 - hostName.length() * 2, 30);
		
		QString userName = QString::fromStdString(mod->getUser());
		_labelUser->setText(userName);
		_labelUser->move(_width / 2 - userName.length() * 2, 60);
		
		layout->addWidget(_labelHost);
		layout->addWidget(_labelUser);
		wid->setLayout(layout);
		// _widget->setLayout(layout);
		
		// _widget->resize(_width, _height);
		// setWidget(_widget);
		setWidget(wid);
		show();
		// move(x, y);
	}

GModuleHostname::~GModuleHostname() {
	
	delete _labelHost;
	delete _labelUser;
}
