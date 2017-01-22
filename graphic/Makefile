#---------------------------------------------------------------------------------
#
# MAKEFILE - MyGkrellm
#
#---------------------------------------------------------------------------------

NAME		:= my_grekllmg

QT_LIBS		= Core Gui Widgets

CXX 		= g++

INCDIR		:= include
INCMODULEDIR	:= ../libmodule/include/
SRCDIR		:= source
LDFLAGS		:= -L.. -lmodule

CXXFLAGS	+= -g -Wall -Werror -Wextra -Wfatal-errors -std=c++11 -fPIC
CXXFLAGS	+= -I$(INCDIR) -I/usr/include/qt -I$(INCMODULEDIR)
CXXFLAGS	+= $(foreach lib, $(QT_LIBS), -I/usr/include/qt/Qt$(lib))
LIBS		= $(foreach lib,$(QT_LIBS),-lQt5$(lib))


SOURCES		= main.cpp \
			  MainWindow.cpp \
			  SideBar.cpp \
			  GModule.cpp \
			  GModuleHostname.cpp \
			  GModuleDate.cpp \
			  GModuleOS.cpp \
			  GModuleCPU.cpp \
			  GModuleRAM.cpp \
			  GModuleNetwork.cpp

HPPFILES	= MainWindow.hpp \
			  SideBar.hpp \
			  GModule.hpp \
			  GModuleHostname.hpp \
			  GModuleDate.hpp \
			  GModuleOS.hpp \
			  GModuleCPU.hpp \
			  GModuleRAM.hpp \
			  GModuleNetwork.hpp

SOURCES 	:= $(addprefix $(SRCDIR)/, $(SOURCES))
HPPFILES	:= $(addprefix $(INCDIR)/, $(HPPFILES))

OFILES	=	$(SOURCES:.cpp=.oxx) \
	$(HPPFILES:.hpp=.moc.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(CXX) $(OFILES) $(LIBS) -o $@ $(CXXFLAGS) $(LDFLAGS)
	cp $(NAME) ../$(NAME)

clean:
	echo "Cleaning .o/.moc files..."
	rm -rf $(OFILES)
	rm -rf $(INCDIR)/*.moc.cpp

fclean: clean
	echo "Cleaning executable..."
	rm -rf $(NAME)
	rm -rf ../$(NAME)

re: fclean all
	
run: $(NAME)
	./$(NAME)

apply_debug:
		$(eval DEBUG_FLAG := -D_DEBUG)
		
debug:		apply_debug $(NAME)
	
%.oxx: %.cpp
	echo "=>" $(notdir $<)
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDE)

%.moc.cpp: %.hpp
	@echo "=>" $(notdir $<)
	@moc $< $(DEFINES) $(INCLUDE) -o $@ --no-notes

%.moc.o: %.moc.cpp
	@echo "=>" $(notdir $<)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

.PRECIOUS: %.moc.cpp

.PHONY: all clean fclean re run debug
.SILENT: all $(NAME) clean fclean re run debug $(OFILES)
