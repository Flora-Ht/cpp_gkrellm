/*
 * =====================================================================================
 *
 *       Filename:  GModuleRAM.cpp
 *
 *    Description:
 *
 *        Created:  01/22/2017 04:45:03 AM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */

#include "GModuleRAM.hpp"

GModuleRAM::GModuleRAM(QWidget *parent, int x, int y)
	: GModule("RAM", parent, x, y, 300, 200) {

		QWidget *wid = new QWidget(this);
		QVBoxLayout *layout = new QVBoxLayout();
		
		_monitorModule = new ModuleRAM();
		try {
			_monitorModule->retrieveInformations();
		}
		catch (ModuleException &e) {
			std::stringstream s;
			s << "Error: ModuleRAM: " << e.what();
			QLabel *error = new QLabel(QString::fromStdString(s.str()));
			layout->addWidget(error);
			wid->setLayout(layout);
			setWidget(wid);
			show();
			return ;
		}

		ModuleRAM *mod = static_cast<ModuleRAM *>(_monitorModule);

		QTimer *timer = new QTimer(this);
		QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateBars()));
		timer->start(1000);

		_ram = new QLabel("", this);
		std::stringstream ss;
		ss.precision(2);
		ss << "Ram: " << mod->toGigabyte(mod->getTotalRam() - mod->getFreeRam() - mod->getBufferRam());
		ss << "/" << mod->toGigabyte(mod->getTotalRam()) << "GB";
		_ram->setText(QString::fromStdString(ss.str()));
		
		_freeRam = new QProgressBar();
		_freeRam->setRange(0, 100);
		_freeRam->setVisible(true);
		if (mod->getTotalRam() > 0) {
			double percentRam = (((float)mod->getTotalRam() - (float)mod->getFreeRam() - (float)mod->getBufferRam()) / (float)mod->getTotalRam()) * 100;
			_freeRam->setValue((int)percentRam);
		} else {
			_freeRam->setValue(0);
		}

		_swap = new QLabel("", this);
		ss.str("");
		ss << "Swap: " << mod->toGigabyte(mod->getTotalSwap() - mod->getTotalSwap());
		ss << "/" << mod->toGigabyte(mod->getTotalSwap()) << "GB";
		_swap->setText(QString::fromStdString(ss.str()));
		
		_freeSwap = new QProgressBar();
		_freeSwap->setRange(0, 100);
		_freeSwap->setVisible(true);
		if (mod->getTotalSwap() > 0) {
			double percentSwap = (((float)mod->getTotalSwap() - (float)mod->getTotalSwap()) / (float)mod->getTotalSwap()) * 100;
			_freeSwap->setValue((int)percentSwap);
		} else {
			_freeSwap->setValue(0);
		}

		layout->addWidget(_ram);
		layout->addWidget(_freeRam);
		layout->addWidget(_swap);
		layout->addWidget(_freeSwap);
		wid->setLayout(layout);

		setWidget(wid);
		show();
	}

GModuleRAM::~GModuleRAM() {

	delete _ram;
	delete _freeRam;
	delete _swap;
	delete _freeSwap;
}

void GModuleRAM::updateBars() {

	ModuleRAM *mod = static_cast<ModuleRAM *>(_monitorModule);

	try {
		mod->retrieveInformations();
	}
	catch (ModuleException &e) {
		return ;
	}

	if (mod->getTotalRam() > 0) {
		double percentRam = (((float)mod->getTotalRam() - (float)mod->getFreeRam() - (float)mod->getBufferRam()) / (float)mod->getTotalRam()) * 100;
		_freeRam->setValue((int)percentRam);
	} else {
		_freeRam->setValue(0);
	}
	if (mod->getTotalSwap() > 0) {
		double percentSwap = (((float)mod->getTotalSwap() - (float)mod->getTotalSwap()) / (float)mod->getTotalSwap()) * 100;
		_freeSwap->setValue((int)percentSwap);
	} else {
		_freeSwap->setValue(0);
	}
	update();
}

