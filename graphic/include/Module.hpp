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

# include <iostream>

class Module : public QDockWidget {

	private:
		QWidget *_widget;

	protected:

	public:
		Module(QString const &, QWidget *, int, int, int, int);
		Module(Module const &);
		Module &operator=(Module const &);
		virtual ~Module();

		virtual void keyPressEvent(QKeyEvent *) override;
};

#endif /* !MODULE_H_ */
