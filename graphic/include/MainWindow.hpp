/*
 * =====================================================================================
 *
 *       Filename:  MainWindow.hpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 12:17:12 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#ifndef MAINWINDOW_H_
# define MAINWINDOW_H_

# include <QKeyEvent>
# include <QMainWindow>
# include <QLabel>
# include <QStatusBar>
# include <QWidget>

# include "GModule.hpp"
# include "GModuleHostname.hpp"

class QStatusBar;

class MainWindow : public QMainWindow {
	Q_OBJECT

	private:

	protected:

	public:
		MainWindow();
		MainWindow(MainWindow const &);
		MainWindow &operator=(MainWindow const &);
		virtual ~MainWindow();

		virtual void keyPressEvent(QKeyEvent *) override;
};

#endif /* !MAINWINDOW_H_ */
