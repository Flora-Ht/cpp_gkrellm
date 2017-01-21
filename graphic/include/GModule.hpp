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

# include <QKeyEvent>
# include <QHBoxLayout>
# include <QWidget>
# include <QDockWidget>
# include <QString>

# include "IMonitorModule.hpp"

class GModule : public QDockWidget {

	private:
		QWidget *_widget;
		IMonitorModule *monitorModule;

	protected:
		int _x;
		int _y;
		int _width;
		int _height;

	public:
		GModule(QString const &, QWidget *, int, int);
		GModule(GModule const &);
		GModule &operator=(GModule const &);
		virtual ~GModule();

		virtual void keyPressEvent(QKeyEvent *) override;
};

#endif /* !MODULE_H_ */
