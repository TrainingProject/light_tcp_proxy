#
# Author Feng Gao
#
# Email: gfree.wind@gmail.com
#
#

.PHONY: all install clean 3rd

include Makefile.def

ifeq ($(plat), )
$(error "make {plat=linux|...|}")
endif

all:
	@echo "plat=$(plat)" > Makefile.def
	@echo "prefix=$(prefix)" >> Makefile.def
	@cd mm && $(MAKE)
	@cd proxy && $(MAKE)
	@cd main && $(MAKE)

install:
	@cd mm && $(MAKE) install
	@cd proxy && $(MAKE) install
	@cd main && $(MAKE) install

clean:
	@cd mm && $(MAKE) clean
	@cd proxy && $(MAKE) clean
	@cd main && $(MAKE) clean
	@cd bin && rm -f *
	@cd lib && rm -f *

3rd:
	@cd 3rd && tar -jxf iptables-1.4.16.2.tar.bz2
	@cd 3rd/iptables-1.4.16.2 && ./configure --enable-libipq && make && make install
