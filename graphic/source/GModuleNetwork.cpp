/*
 * =====================================================================================
 *
 *       Filename:  GMdoduleNetwork.cpp
 *
 *    Description:
 *
 *        Created:  01/22/2017 08:51:42 AM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#include "GModuleNetwork.hpp"

GModuleNetwork::GModuleNetwork(QWidget *parent, int x, int y)
	: GModule("Network", parent, x, y, 300, 200) {
		
		QWidget *wid = new QWidget(this);
		QVBoxLayout *layout = new QVBoxLayout();
		
		_monitorModule = new ModuleNetwork();
		try {
			_monitorModule->retrieveInformations();
		}
		catch (ModuleException &e) {
			std::stringstream s;
			s << "Error: ModuleNetwork: " << e.what();
			QLabel *error = new QLabel(QString::fromStdString(s.str()));
			layout->addWidget(error);
			wid->setLayout(layout);
			setWidget(wid);
			show();
			return ;
		}
		
		ModuleNetwork *mod = static_cast<ModuleNetwork *>(_monitorModule);
		
		QTimer *timer = new QTimer(this);
		QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateInterfaces()));
		timer->start(2000);
		
		std::vector<NetworkInterface> is = mod->getNetworkInterfaces();
		_interfaces = new std::vector<QLabel *>;
		_speed = new std::vector<QLabel *>;
	
		std::vector<NetworkInterface>::const_iterator it;
		for (it = is.begin(); it != is.end(); ++it) {
			QLabel *label = new QLabel(QString::fromStdString(it->_name), this);
			_interfaces->push_back(label);
			
			QLabel *speed = new QLabel("", this);
			std::stringstream ss;
			ss << "DL: " << mod->getDownloadSpeed(*it);
			ss << " ; UL: " << mod->getUploadSpeed(*it);
			speed->setText(QString::fromStdString(ss.str()));
			_speed->push_back(speed);

			layout->addWidget(label);
			layout->addWidget(speed);
		}


		wid->setLayout(layout);

		setWidget(wid);
		show();
	}

GModuleNetwork::~GModuleNetwork() {

	delete _interfaces;
	delete _speed;
}

void GModuleNetwork::updateInterfaces() {

	ModuleNetwork *mod = static_cast<ModuleNetwork *>(_monitorModule);

	try {
		mod->retrieveInformations();
	}
	catch (ModuleException &e) {
		return ;
	}

	std::vector<NetworkInterface> is = mod->getNetworkInterfaces();
	std::vector<NetworkInterface>::const_iterator it;
	unsigned int i = is.size() - 1;
	for (it = is.begin(); it != is.end(); ++it) {
		std::stringstream ss;
		ss << "DL: " << mod->getDownloadSpeed(*it);
		ss << " ; UL: " << mod->getUploadSpeed(*it);
		(*_speed)[i]->setText(QString::fromStdString(ss.str()));
		--i;
	}
	update();
}
