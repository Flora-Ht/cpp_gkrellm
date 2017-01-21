##
## Makefile for  in /home/grange_c/rendu/cpp_gkrellm/
##
## Made by Benjamin Grange
## Login   <grange_c@epitech.eu>
##
## Started on  Sat Jan 21 11:28:02 2017 Benjamin Grange
## Last update Sat Jan 21 12:55:19 2017 Benjamin Grange
##

SUBDIRS	:= graphic text

all:
	for dir in $(SUBDIRS); do make --no-print-directory -C $$dir; done

debug:
	for dir in $(SUBDIRS); do make --no-print-directory -C $$dir debug; done

clean:
	for dir in $(SUBDIRS); do make --no-print-directory -C $$dir clean; done

fclean:
	for dir in $(SUBDIRS); do make --no-print-directory -C $$dir fclean; done

re:
	for dir in $(SUBDIRS); do make --no-print-directory -C $$dir re; done

graphic: libmodule
	make --no-print-directory -C graphic

libmodule:
	make --no-print-directory -C libmodule

text: libmodule
	make --no-print-directory -C text

.PHONY: all graphic libmodule text clean fclean re

.SILENT: all clean fclean re graphic libmodule text
