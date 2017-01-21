#---------------------------------------------------------------------------------
#
# MAKEFILE - MyGkrellm
#
#---------------------------------------------------------------------------------

NAME		= graphic

QT_LIBS		= Core Gui Widgets

CXX 		= g++

CXXFLAGS	+= -g -Wall -Werror -Wextra -Wfatal-errors -std=c++11 -fPIC
CXXFLAGS	+= -Iinclude/ -I/usr/include/qt
CXXFLAGS	+= $(foreach lib, $(QT_LIBS), -I/usr/include/qt/Qt$(lib))
LIBS		= $(foreach lib,$(QT_LIBS),-lQt5$(lib))


SOURCES		= source/main.cpp \
			  source/MainWindow.cpp \
			  source/Module.cpp

HPPFILES	= include/MainWindow.hpp \
			  include/Module.hpp

OFILES	=	$(SOURCES:.cpp=.oxx) \
	$(HPPFILES:.hpp=.moc.o)

all: $(NAME)

$(NAME): $(OFILES)
	@$(CXX) $(OFILES) $(LIBS) -o $@ $(CXXFLAGS)

clean:
	@rm -rf $(OFILES)
	@rm -rf include/*.moc.cpp

fclean: clean
	@rm -rf $(NAME)

re: fclean all

%.oxx: %.cpp
	@echo "=>" $(notdir $<)
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDE)

%.moc.cpp: %.hpp
	@echo "=>" $(notdir $<)
	@moc $< $(DEFINES) $(INCLUDE) -o $@ --no-notes

%.moc.cpp: %.h
	@echo "=>" $(notdir $<)
	@moc $< $(DEFINES) $(INCLUDE) -o $@ --no-notes

%.moc.o: %.moc.cpp
	@echo "=>" $(notdir $<)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

.PRECIOUS: %.moc.cpp

.PHONY: all $(OUT) clean fclean re
