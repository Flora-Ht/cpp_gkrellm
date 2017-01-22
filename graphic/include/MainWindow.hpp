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

# include <iostream>
# include <QKeyEvent>
# include <QMainWindow>
# include <QLabel>
# include <QStatusBar>
# include <QWidget>
# include <QMdiArea>
# include <QMdiSubWindow>

# include "SideBar.hpp"
# include "GModule.hpp"
# include "GModuleHostname.hpp"
# include "GModuleDate.hpp"
# include "GModuleOS.hpp"

class QStatusBar;

class MainWindow : public QMainWindow {
	Q_OBJECT

	private:
		QMdiArea *_area;

	protected:

	public:
		MainWindow();
		MainWindow(MainWindow const &);
		MainWindow &operator=(MainWindow const &);
		virtual ~MainWindow();

		static const unsigned int width = 300;
		static const unsigned int height = 1000;
		
		virtual void keyPressEvent(QKeyEvent *) override;
		
		QMdiArea *getArea() const;
		void addNewModule(GModule *);
};

#endif /* !MAINWINDOW_H_ */
