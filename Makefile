#
# Author Feng Gao
#
# Email: gfree.wind@gmail.com
#
#

.PHONY: all install clean

include Makefile.def

ifeq ($(plat), )
$(error "make {plat=linux|...|}")
endif

all:
	@echo "plat=$(plat)" > Makefile.def
	@echo "prefix=$(prefix)" >> Makefile.def
	@cd main && $(MAKE)

install:
	@cd main && $(MAKE) install

clean:
	@cd main && $(MAKE) clean
	@cd bin && rm -f *
	@cd lib && rm -f *

3rd:
