/*
 * =====================================================================================
 *
 *       Filename:  Module.hpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 03:41:24 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */

#ifndef MODULE_H_
# define MODULE_H_

# include <iostream>
# include <sstream>
# include <QDockWidget>
# include <QEvent>
# include <QKeyEvent>
# include <QLabel>
# include <QMdiSubWindow>
# include <QString>
# include <QVBoxLayout>
# include <QWindowStateChangeEvent> 

# include "IMonitorModule.hpp"

class GModule : public QDockWidget {
	Q_OBJECT

	private:

	protected:
		IMonitorModule *_monitorModule;
		QString _name;
		int _x;
		int _y;
		int _width;
		int _height;
		bool _closed;

	public:
		GModule(QString const &, QWidget *, int, int, int, int);
		GModule(GModule const &);
		GModule &operator=(GModule const &);
		virtual ~GModule();

		// virtual void keyPressEvent(QKeyEvent *) override;
		// virtual bool event(QEvent *) override;
};

#endif /* !MODULE_H_ */
