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
		
		QWidget *wid = new QWidget(this);
		QVBoxLayout *layout = new QVBoxLayout();
		
		_monitorModule = new ModuleCPU();
		try {
			_monitorModule->retrieveInformations();
		}
		catch (ModuleException &e) {
			std::stringstream s;
			s << "Error: ModuleCPU: " << e.what();
			QLabel *error = new QLabel(QString::fromStdString(s.str()));
			layout->addWidget(error);
			wid->setLayout(layout);
			setWidget(wid);
			show();
			return ;
		}
		
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
			
			layout->addWidget(percent);
			
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
	
	delete _bars;
}

void GModuleCPU::updatePercentBars() {

	ModuleCPU *mod = static_cast<ModuleCPU *>(_monitorModule);

	try {
		mod->retrieveInformations();
	}
	catch (ModuleException &e) {
		return ;
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
