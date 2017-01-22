/*
 * =====================================================================================
 *
 *       Filename:  GModuleCPU.cpp
 *
 *    Description:
 *
 *        Created:  01/22/2017 03:38:07 AM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#include "GModuleCPU.hpp"

GModuleCPU::GModuleCPU(QWidget *parent, int x, int y)
	: GModule("CPUs", parent, x, y, 300, 200) {
		
		_monitorModule = new ModuleCPU();
		try {
			_monitorModule->retrieveInformations();
		}
		catch (ModuleException &e) {
		}
		
		QWidget *wid = new QWidget(this);
		QVBoxLayout* layout = new QVBoxLayout();
		ModuleCPU *mod = static_cast<ModuleCPU *>(_monitorModule);
		
		std::vector<CPU> cpus = mod->getCPUs();
		// size_t size = cpus.size();
		
		
		std::vector<CPU>::const_iterator it;
		unsigned int i = 0;
		for (it = cpus.begin(); it != cpus.end(); ++it) {
			QLabel *label = new QLabel("", this);
			std::stringstream ss;
			ss << "Vendor: " << it->_vendor << " ; ";
			ss << "Name: " << it->_name << std::endl;
			ss << "Mhz: " << it->_mhz;
			label->setText(QString::fromStdString(ss.str()));
			label->move(0, 30 * (i + 1));
			layout->addWidget(label);
			++i;
		}
		
		wid->setLayout(layout);
		
		setWidget(wid);
		show();
	}

GModuleCPU::~GModuleCPU() {
	
}
