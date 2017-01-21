/*
 * =====================================================================================
 *
 *       Filename:  GModuleDate.hpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 08:29:49 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#ifndef GMODULEDATE_H_
# define GMODULEDATE_H_

# include <QLabel>
# include <QTimer>
# include <sstream>
# include "GModule.hpp"
# include "ModuleDate.hpp"

class GModuleDate : public GModule {
	Q_OBJECT

	private:
		QLabel *_date;
		QLabel *_time;

	protected:

	public:
		GModuleDate(QWidget *, int, int);
		GModuleDate(GModuleDate const &);
		GModuleDate &operator=(GModuleDate const &);
		virtual ~GModuleDate();
		

	private slots:
		void updateModuleTime();
};

#endif /* !GMODULEDATE_H_ */
