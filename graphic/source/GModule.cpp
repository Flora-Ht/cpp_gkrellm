/*
 * =====================================================================================
 *
 *       Filename:  GModule.cpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 03:41:09 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */

#include "GModule.hpp"

GModule::GModule(QString const &name, QWidget *parent, int x, int y)
	: QDockWidget(name, parent, Qt::Window) {

		setFocusPolicy(Qt::StrongFocus);

		_x = x;
		_y = y;
		_widget = new QWidget(this, Qt::Dialog);
		_widget->setWindowTitle(name);
	}

GModule::~GModule() {
	
	delete _widget;
}

/* ===================================================================================== */

void GModule::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_A) {
		close();
	}
	QWidget::keyPressEvent(event);
}
