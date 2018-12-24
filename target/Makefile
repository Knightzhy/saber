.PHONY: all mrproper clean

TOP := $(shell cd .. && pwd)
CWD := $(shell pwd)
BUILD := $(CWD)/build
STAGING := $(TOP)/staging
SOURCES := /home/knightwu/software/thirdparty/sources

MKDIR := mkdir -p
CMAKE := cmake
CP := cp -af
RM := rm -f
LN := ln -f
TOUCH := touch

define M
._$(1): $(foreach D,$(3),._$(D))
	@echo $(1)
	$(RM) -R $(BUILD)/$$(basename $$(basename $2))
	$(MKDIR) $(BUILD) && cd $(BUILD) && tar -xaf $(SOURCES)/$2
	cd $(BUILD)/$$(basename $$(basename $2)) && \
		./configure --prefix=$$(STAGING) $(4) && $$(MAKE) $(5) && $$(MAKE) $(6) install
	$(TOUCH) $$@
endef

all: mrproper \
	.httpd

mrproper:

clean:
	${RM} ._*
	${RM} -R ${BUILD}
	${RM} -R ${STAGING}

.httpd: ._apr ._expat
#	._apr-util ._pcre ._openssl ._libxml2 ._nghttp2

expat_package:= libexpat-R_2_2_1.tar.gz
._expat:
	$(RM) -R $(BUILD)/$(basename $(basename $(notdir $(expat_package))))
	$(MKDIR) $(BUILD) && cd $(BUILD) && tar -xaf $(SOURCES)/$(expat_package)
	cd $(BUILD)/$(basename $(basename $(notdir $(expat_package))))/expat && \
	   $(CMAKE) . -DCMAKE_INSTALL_PREFIX=$(STAGING) \
	              -DBUILD_tools=OFF \
	              -DBUILD_example=OFF \
	              -DBUILD_tests=OFF \
	              -DBUILD_shared=ON \
	              -DBUILD_doc=OFF && \
	              $(MAKE) && $(MAKE) install
	$(TOUCH) $@


$(eval $(call M,apr,apr-1.6.3.tar.bz2,util-linux,--enable-threads --enable-posix-shm))
$(eval $(call M,util-linux,util-linux-2.21.2.tar.xz,,--without-ncurses --disable-nls,-C libuuid,-C libuuid))
$(eval $(call M,apr-util,apr-util-1.6.1.tar.bz2,apr expat libiconv mysql openssl sqlite3 util-linux,--with-apr=$(STAGING) --with-expat=$(STAGING) --with-crypto --without-ldap --with-openssl=$(STAGING) --with-sqlite3=$(STAGING) --with-mysql=$(STAGING) --with-iconv=$(STAGING)))
