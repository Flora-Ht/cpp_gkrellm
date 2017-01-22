/*
 * =====================================================================================
 *
 *       Filename:  GModuleOS.hpp
 *
 *    Description:
 *
 *        Created:  01/21/2017 10:37:18 PM
 *
 *         Author:  Flora Huot, flora.huot@epitech.eu
 *
 * =====================================================================================
 */ 

#ifndef GMODULEOS_H_
# define GMODULEOS_H_

# include "GModule.hpp"
# include "ModuleOS.hpp"

class GModuleOS : public GModule {

	private:
		QLabel *_os;
		QLabel *_version;

	protected:

	public:
		GModuleOS(QWidget *, int, int);
		GModuleOS(GModuleOS const &);
		GModuleOS &operator=(GModuleOS const &);
		~GModuleOS();
};

#endif /* !GMODULEOS_H_ */
