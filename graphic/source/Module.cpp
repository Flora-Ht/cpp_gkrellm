/*
 * =====================================================================================
 *
 *       Filename:  Module.cpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 03:41:09 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */

#include "Module.hpp"

Module::Module(QString const &name, QWidget *parent, int x, int y, int width, int height)
	: QDockWidget(name, parent, Qt::Window) {

		setFocusPolicy(Qt::StrongFocus);

		_widget = new QWidget(this, Qt::Dialog);
		_widget->setWindowTitle(name);
		setWidget(_widget);
		_widget->resize(width, height);
		_widget->move(x, y);
	}

Module::~Module() {
	
	delete _widget;
}

/* ===================================================================================== */

void Module::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_A) {
		close();
	}
	QWidget::keyPressEvent(event);
}
