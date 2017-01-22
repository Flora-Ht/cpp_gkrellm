/*
 * =====================================================================================
 *
 *       Filename:  GModuleNetwork.hpp
 *
 *    Description:
 *
 *        Created:  01/22/2017 08:50:26 AM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#ifndef GMODULENETWORK_H_
# define GMODULENETWORK_H_

# include <QTimer>
# include <vector>
# include <sstream>
# include "GModule.hpp"
# include "ModuleNetwork.hpp"

class GModuleNetwork : public GModule {
	Q_OBJECT

	private:
		std::vector<QLabel *> *_interfaces;
		std::vector<QLabel *> *_speed;

	protected:

	public:
		GModuleNetwork(QWidget *, int, int);
		GModuleNetwork(GModuleNetwork const &);
		GModuleNetwork &operator=(GModuleNetwork const &);
		~GModuleNetwork();
		
	public slots:
		void updateInterfaces();
};

#endif /* !GMODULENETWORK_H_ */
