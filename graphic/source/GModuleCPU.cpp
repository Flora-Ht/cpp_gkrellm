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
		_bars = new std::vector<QProgressBar *>;
		
		_monitorModule = new ModuleCPU();
		try {
			_monitorModule->retrieveInformations();
		}
		catch (ModuleException &e) {
		}
		
		QWidget *wid = new QWidget(this);
		_layout = new QVBoxLayout();
		ModuleCPU *mod = static_cast<ModuleCPU *>(_monitorModule);
		
		std::vector<CPU> cpus = mod->getCPUs();
		
		QTimer *timer = new QTimer(this);
		QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updatePercentBars()));
		timer->start(2000);
		
		std::vector<CPU>::const_iterator it;
		unsigned int i = 0;
		for (it = cpus.begin(); it != cpus.end(); ++it) {
			QLabel *label = new QLabel("", this);
			std::stringstream ss;
			ss << "Vendor: " << it->_vendor << " ; ";
			ss << "Name: " << it->_name << std::endl;
			ss << "Mhz: " << it->_mhz;
			
			QProgressBar *percent = new QProgressBar();
			percent->setRange(0, 100);
			percent->setVisible(true);;
			percent->setValue((int)it->_percent);
			_bars->push_back(percent);
			
			_layout->addWidget(percent);
			
			label->setText(QString::fromStdString(ss.str()));
			label->move(0, 30 * (i + 1));
			_layout->addWidget(label);
			++i;
		}
		
		wid->setLayout(_layout);
		
		setWidget(wid);
		show();
	}

GModuleCPU::~GModuleCPU() {
	
	delete _layout;
	delete _bars;
}

void GModuleCPU::updatePercentBars() {

	ModuleCPU *mod = static_cast<ModuleCPU *>(_monitorModule);

	try {
		mod->retrieveInformations();
	}
	catch (ModuleException &e) {
	}
	
	std::vector<CPU> cpus = mod->getCPUs();

	std::vector<CPU>::const_iterator it;
	unsigned int i = cpus.size() - 1;
	for (it = cpus.begin(); it != cpus.end(); ++it) {
		(*_bars)[i]->setValue((int)it->_percent);
		--i;
	}
	update();
}
