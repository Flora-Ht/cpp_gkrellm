/*
 * =====================================================================================
 *
 *       Filename:  GModuleOS.cpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 10:37:51 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#include "GModuleOS.hpp"

GModuleOS::GModuleOS(QWidget *parent, int x, int y)
	: GModule("OS", parent, x, y, 200, 100),
	_os(new QLabel("", this)),
	_version(new QLabel("", this)) {
		
		QWidget *wid = new QWidget(this);
		QVBoxLayout *layout = new QVBoxLayout();
		
		_monitorModule = new ModuleOS();
		try {
			_monitorModule->retrieveInformations();
		}
		catch (ModuleException &e) {
			std::stringstream s;
			s << "Error: ModuleOS: " << e.what();
			QLabel *error = new QLabel(QString::fromStdString(s.str()));
			layout->addWidget(error);
			wid->setLayout(layout);
			setWidget(wid);
			show();
			return ;
		}
		
		ModuleOS *mod = static_cast<ModuleOS *>(_monitorModule);
		
		QString os = QString::fromStdString(mod->getOS());
		_os->setText(os);
		_os->move(_width / 2 - os.length() * 2, 30);
		
		QString version = QString::fromStdString(mod->getVersion());
		_version->setText(version);
		_version->move(_width / 2 - version.length() * 2, 60);
		
		layout->addWidget(_os);
		layout->addWidget(_version);
		wid->setLayout(layout);
		
		setWidget(wid);
		show();
	}

GModuleOS::~GModuleOS() {
	
	delete _os;
	delete _version;
}
