/*
 * =====================================================================================
 *
 *       Filename:  GModuleDate.cpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 08:29:40 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#include "GModuleDate.hpp"

GModuleDate::GModuleDate(QWidget *parent, int x, int y)
	: GModule("Date & Time", parent, x, y, 200, 100),
	_date(new QLabel("", this)), _time(new QLabel("", this)) {

		QWidget *wid = new QWidget(this);
		QVBoxLayout *layout = new QVBoxLayout();
		
		_monitorModule = new ModuleDate();
		try {
			_monitorModule->retrieveInformations();
		}
		catch (ModuleException &e) {
			std::stringstream s;
			s << "Error: ModuleDateTime: " << e.what();
			QLabel *error = new QLabel(QString::fromStdString(s.str()));
			layout->addWidget(error);
			wid->setLayout(layout);
			setWidget(wid);
			show();
			return ;
		}
		
		ModuleDate *mod = static_cast<ModuleDate *>(_monitorModule);
		
		QTimer *timer = new QTimer(this);
		QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateModuleTime()));
		timer->start(1000);
		
		std::stringstream ss;
		ss << mod->getDay() << "." << mod->getMonth() << "." << mod->getYear();
		QString date = QString::fromStdString(ss.str());
		_date->setText(date);
		_date->move(_width / 2 - date.length() * 2, 30);
		
		updateModuleTime();
		
		layout->addWidget(_date);
		layout->addWidget(_time);
		wid->setLayout(layout);
		
		setWidget(wid);
		show();
	}

GModuleDate::~GModuleDate() {

	delete _date;
	delete _time;
}

/* ===================================================================================== */

void GModuleDate::updateModuleTime() {

	if (!_closed) {
		ModuleDate *mod = static_cast<ModuleDate *>(_monitorModule);

		try {
			mod->retrieveInformations();
		}
		catch (ModuleException &e) {
			return ;
		}

		std::stringstream ss;
		if (mod->getHour() < 10) {
			ss << "0";
		}
		ss << mod->getHour() << ":";
		if (mod->getMinute() < 10) {
			ss << "0";
		}
		ss << mod->getMinute() << ":";
		if (mod->getSecond() < 10) {
			ss << "0";
		}
		ss << mod->getSecond();
		QString time = QString::fromStdString(ss.str());
		_time->setText(time);
		_time->move(_width / 2 - time.length() * 2, 60);
		update();
	}
}
